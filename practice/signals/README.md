This program demonstrates how to create multiple threads, register a signal handler, and send signals to either the **whole process** or **specific threads** using `kill()` and `pthread_kill()`. Here's a full line-by-line breakdown:

---

### 🔧 **Included Headers**

```c
#include <pthread.h>   // For threads
#include <stdio.h>     // For printf, fprintf
#include <unistd.h>    // For getpid(), getppid(), sleep()
#include <signal.h>    // For signal handling
#include <stdlib.h>    // For exit()
```

---

### 🧵 **Global Definitions**

```c
#define NUM_THREADS 4
pthread_t threads[NUM_THREADS];
```

* `NUM_THREADS` is a macro defining the number of threads (4 in this case).
* `threads[]` stores the IDs of created threads so you can later join or signal them.

---

### 🚨 **Signal Handler**

```c
void sigusr1_handler(int signum){
    int i = gettid(), j = getppid(), k = getpid();
    fprintf(stdout, "thread %u receievd SIGUSR1 signal (parent=%u)[pid=%u] {tid=%u} \n", pthread_self(), j,k,i);
}
```

* This function runs when **SIGUSR1** is received.
* It prints:

  * `pthread_self()` → POSIX thread ID
  * `getppid()` → parent process ID
  * `getpid()` → process ID
  * `gettid()` → kernel thread ID (Linux-specific; may need `syscall()`)

---

### 🧠 **Thread Function**

```c
void* thread_func(void* arg){
    while(1) sleep(1); // Infinite loop to keep thread alive
    return NULL;
}
```

* Each thread runs this function.
* It **sleeps forever** so it stays alive to demonstrate signal handling.
* Return is never reached.

---

### 🧵 **Main Function**

```c
int main(int argc, char* argv[]){
```

* Entry point.

```c
    signal(SIGUSR1, sigusr1_handler);
```

* Registers the `sigusr1_handler()` to handle `SIGUSR1`.

---

### 🔄 **Thread Creation Loop**

```c
    for(int i=0; i<NUM_THREADS; i++){
        if(pthread_create(&threads[i], NULL, thread_func, NULL)!=0)
            perror("pthread_create"); exit(EXIT_FAILURE);
    }
```

* Creates 4 threads.
* If any thread creation fails, it prints an error and exits.

---

### 📇 **Print Process and Thread Info**

```c
    int i = gettid(), j = getpid(), k = getppid();
    fprintf(stdout, "parent process ID: %u, process ID: %u, main() thread id: %u\n", k, j, i);
```

* Logs IDs for reference.

```c
    fprintf(stdout, "thread IDs: 0=%u, 1=%u, 2=%u, 3=%u", threads[0], threads[1], threads[2], threads[3]);
```

* Logs the POSIX thread IDs for each created thread.

---

### 📤 **Send Signals**

```c
    kill(j,SIGUSR1);
```

* Sends `SIGUSR1` to the **whole process**. Any thread can receive it.

```c
    pthread_kill(threads[2], SIGUSR1);
```

* Sends `SIGUSR1` to **thread 2** specifically.

---

### 🧼 **Join Threads**

```c
    for(int i =0; i<NUM_THREADS; i++){
        if(pthread_join(threads[i], NULL)!=0){
            perror("pthread_join");exit(EXIT_FAILURE);
        }
    }
```

* Waits for all threads to finish.
* Since threads run `while(1)`, they **never exit**, so the main thread **waits forever**.

---

### ✅ **Summary**

This program shows:

* How to handle signals with threads.
* The difference between `kill()` (process-wide) and `pthread_kill()` (targeted).
* Use of `pthread_create()`, `pthread_join()`, and signal registration.
* The threads sleep indefinitely to remain alive and receive signals.

---
Great set of questions — here’s a clear breakdown of each concept:

---

### 🧵 1. **POSIX Thread ID (`pthread_t`)**

* This is the **ID used in user space** by the POSIX Threads (pthreads) API.
* It's what `pthread_create()`, `pthread_join()`, and `pthread_self()` work with.
* **Returned by**: `pthread_self()`
* **Type**: `pthread_t` (opaque, platform-dependent — sometimes a pointer, sometimes a number).

---

### 🧠 2. **Kernel Thread ID (TID)**

* This is the **unique thread identifier in the Linux kernel**.

* It is used by system-level operations like sending signals or inspecting threads via `/proc`.

* **Returned by**: `gettid()`

  * ⚠️ Not part of POSIX — Linux-specific. On some systems you need:

    ```c
    #include <sys/syscall.h>
    pid_t tid = syscall(SYS_gettid);
    ```

* In Linux, every thread has a **TID** and the **main thread’s TID is equal to the PID**.

---

### 🧷 3. **`pthread_self()`**

* Returns the **calling thread’s POSIX thread ID** (of type `pthread_t`).
* Used when you want to identify yourself (e.g., in logs or signal handlers).
* Example:

  ```c
  pthread_t id = pthread_self();
  ```

---

### ⚙️ 4. **`gettid()`**

* Returns the **kernel thread ID (TID)** of the calling thread.
* Useful for debugging or when working with system-level tools or signals.
* Must use `syscall()` on many systems:

  ```c
  #include <sys/syscall.h>
  pid_t tid = syscall(SYS_gettid);
  ```

---

### 💥 5. **`kill()`**

* Sends a **signal to a process** by its **PID**.

* Syntax:

  ```c
  kill(pid, signal_number);
  ```

* Example:

  ```c
  kill(getpid(), SIGUSR1);
  ```

  This sends `SIGUSR1` to the entire process — **any thread** can receive it.

* If you want to send a signal to a **specific thread**, you must use:

  ```c
  pthread_kill(pthread_t thread, int signal);
  ```

---

### ✅ Summary Table

| Concept          | Description                                                     |
| ---------------- | --------------------------------------------------------------- |
| `pthread_t`      | POSIX thread ID (user-space thread ID) used in pthreads API.    |
| `pthread_self()` | Returns the current thread's POSIX thread ID.                   |
| `gettid()`       | Returns kernel thread ID (Linux-only, use `syscall`).           |
| `kill(pid, sig)` | Sends a signal to the whole process (any thread may handle it). |
| `pthread_kill()` | Sends a signal to a specific POSIX thread (targeted delivery).  |

---




