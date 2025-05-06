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


