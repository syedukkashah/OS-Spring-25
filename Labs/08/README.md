Absolutely! Below is the complete `README.md` content including detailed answers for **part a)**, **part b)**, and **part c)** — all formatted properly in markdown for GitHub:

```markdown
# 🧵 Code Workout #2: Multithreading and Shared Counter in C

This exercise demonstrates the behavior of a shared global variable (`counter`) accessed by multiple threads in a multithreaded C program using `pthread`.

---

## 📄 Code

```c
#include <stdio.h>
#include <pthread.h>

static volatile int counter = 0;

void *mythread(void *arg) {
    printf("%s: begin\n", (char *)arg);
    int i;
    // int counter = 0;  // <-- Uncomment this for Part c
    for (i = 0; i < 1e6; i++) {
        counter = counter + 1;
    }
    printf("%s: done. Counter = %d\n", (char *)arg, counter);
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t p1, p2;

    printf("main: begin (counter = %d)\n", counter);
    pthread_create(&p1, NULL, mythread, "A");
    pthread_create(&p2, NULL, mythread, "B");

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("main: done with both (counter = %d)\n", counter);
    return 0;
}
```

---

## ✅ a) Compile and Run the Code

### 🛠️ Compilation
```bash
gcc -pthread -o thread_counter thread_counter.c
```

### ▶️ Execution
```bash
./thread_counter
```

### 💡 Sample Output
```
main: begin (counter = 0)
A: begin
B: begin
A: done. Counter = 1132870
B: done. Counter = 1587201
main: done with both (counter = 1587201)
```

---

## ❓ b) Why Are Both Threads Calculating Different Values of `counter`?

Although both threads are incrementing the same global `counter`, they **do not do it atomically**. The line:

```c
counter = counter + 1;
```

is **not a thread-safe** operation. It consists of three steps:
1. Load the value of `counter` from memory.
2. Increment the value.
3. Store it back to memory.

If both threads perform these steps simultaneously, they can overwrite each other's results, leading to **lost updates** and **data races**.

### 🔥 Result:
- Both threads interfere with each other's updates.
- The final value of `counter` is usually **less than 2,000,000**.
- Thread A and B may report different `counter` values depending on which one finishes last.

This is a classic case of a **race condition** due to the absence of synchronization.

---

## 🧪 c) Uncomment `int counter = 0;` at Line #9 and Re-run

When you uncomment the local declaration of `counter` inside `mythread()`:

```c
int counter = 0;
```

This line **shadows** the global `counter`, meaning each thread now has its own private `counter` variable.

### 🖥️ Sample Output
```
main: begin (counter = 0)
A: begin
B: begin
A: done. Counter = 1000000
B: done. Counter = 1000000
main: done with both (counter = 0)
```

### 🧠 How This Affects the Results

- Each thread works with its own **local** variable.
- No shared updates occur.
- The global `counter` in `main()` is never changed.
- Race conditions are avoided — but the threads no longer collaborate on a shared task.

This change eliminates synchronization issues but also **defeats the purpose of having a shared counter** between threads.

---

## 📌 Summary Table

| Case                          | Threads Use | Final Value in `main` | Race Condition? | Thread Output      |
|-------------------------------|-------------|------------------------|------------------|---------------------|
| Global shared `counter`       | Shared var  | Less than 2,000,000    | ✅ Yes           | Inconsistent values |
| Local `int counter = 0;`      | Local copy  | 0                      | ❌ No            | Always 1,000,000    |

---

## 🧰 Bonus Tip: Use a Mutex for Thread Safety

You can avoid data races while sharing variables by using a **mutex**:

```c
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

for (i = 0; i < 1e6; i++) {
    pthread_mutex_lock(&lock);
    counter++;
    pthread_mutex_unlock(&lock);
}
```

This ensures only one thread accesses `counter` at a time.

---

## 📚 Conclusion

This exercise demonstrates how improper handling of shared variables in multithreaded programs can lead to **race conditions**. Declaring local variables avoids the issue but sacrifices inter-thread communication. Proper synchronization techniques (like mutexes) are essential for writing correct and safe multithreaded code.

---
```

Let me know if you'd also like this written as a real GitHub project with the code and `Makefile`.
