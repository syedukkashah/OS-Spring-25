### Q6a)

```markdown
# Creating an Ordinary Pipe in C

This program demonstrates **Inter-Process Communication (IPC)** using a **pipe** in C. It forks a child process and uses a unidirectional pipe to send a message from the parent to the child.

---

## Original Code

```c
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void) {
    char write_msg[BUFFER_SIZE] = "Greetings";
    char read_msg[BUFFER_SIZE];
    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1) {
        // create a pipe
        fprintf(stderr, "Pipe failed");
        return 1;
    }

    pid = fork();
    if (pid < 0) {
        // error occurred
        fprintf(stderr, "Fork Failed");
        return 1;
    }

    if (pid > 0) {
        // parent process
        close(fd[READ_END]);
        write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
        close(fd[WRITE_END]);
    } else {
        // child process
        close(fd[WRITE_END]);  // close the unused end
        read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf("read %s\n", read_msg);
        close(fd[READ_END]);
    }

    return 0;
}
```

---

## In-Lab Instructions

### Task 1: Compile and Execute the Code

**Compilation:**

```bash
gcc -o pipe_demo pipe_demo.c
```

**Execution:**

```bash
./pipe_demo
```

**Tip:** Open a second terminal window and use the `ps` or `top` command to observe the parent and child **process IDs** during execution.

Example output:

```
read Greetings
```

---

### Task 2: Modify the Code to Accept `write_msg` from User Input

**Updated Code with User Input:**

```c
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

int main(void) {
    char write_msg[BUFFER_SIZE];
    char read_msg[BUFFER_SIZE];
    int fd[2];
    pid_t pid;

    // Get input from user
    printf("Enter a message to send through the pipe: ");
    fgets(write_msg, BUFFER_SIZE, stdin);

    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe failed");
        return 1;
    }

    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "Fork Failed");
        return 1;
    }

    if (pid > 0) {
        // parent process
        close(fd[READ_END]);
        write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
        close(fd[WRITE_END]);
    } else {
        // child process
        close(fd[WRITE_END]);
        read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf("Child received: %s\n", read_msg);
        close(fd[READ_END]);
    }

    return 0;
}
```
### Q6c)
```markdown
#  POSIX Shared Memory IPC (Producer & Consumer)

This lab demonstrates Inter-Process Communication (IPC) using **POSIX shared memory** with a **producer** writing messages and a **consumer** reading them.

---

##  Producer Code (POSIX Shared Memory)

```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    const int SIZE = 4096;               // size in bytes of shared memory object
    const char *name = "OS";             // name of the shared memory object
    const char *message_0 = "Hello";
    const char *message_1 = "World!";
    int fd;
    char *ptr;

    // Create the shared memory object
    fd = shm_open(name, O_CREAT | O_RDWR, 0666);
    ftruncate(fd, SIZE); // configure the size

    // Map memory object
    ptr = (char *)mmap(0, SIZE, PROT_WRITE, MAP_SHARED, fd, 0);

    // Write messages
    sprintf(ptr, "%s", message_0);
    ptr += strlen(message_0);
    sprintf(ptr, "%s", message_1);
    ptr += strlen(message_1);

    return 0;
}
```

 **Compile with:**

```bash
gcc producer.c -o producer -lrt
```

---

##  Consumer Code (POSIX Shared Memory)

```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    const int SIZE = 4096;
    const char *name = "OS";
    int fd;
    char *ptr;

    // Open existing shared memory object
    fd = shm_open(name, O_RDONLY, 0666);

    // Map memory object
    ptr = (char *)mmap(0, SIZE, PROT_READ, MAP_SHARED, fd, 0);

    // Read and display message
    printf("%s\n", (char *)ptr);

    // Cleanup
    shm_unlink(name);

    return 0;
}
```

🛠 **Compile with:**

```bash
gcc consumer.c -o consumer -lrt
```

---

## In-Lab Tasks

### Task 1: Compile and Execute

1. Compile the producer and consumer code as shown above.
2. Run the **producer** first:
   ```bash
   ./producer
   ```
3. Then run the **consumer**:
   ```bash
   ./consumer
   ```

---

### Task 2: Run-Time Error When Reversing Order

If you run the **consumer first**, it throws a run-time error:

```
shm_open: No such file or directory
```

**Reason:** The consumer tries to open a shared memory object that doesn't exist yet because the producer hasn’t created it.

---

### Task 3: Run Both Concurrently

1. Modify both programs to simulate concurrency (e.g., using delays or `sleep()`).
2. Run them in separate terminals.
3. Make sure the consumer does not unlink shared memory until it has finished reading.

---

### Task 4: Modify Producer to Send Two Messages

Change producer code:

```c
sprintf(ptr, "%s\n", message_0);
ptr += strlen(message_0) + 1;
sprintf(ptr, "%s\n", message_1);
```

---

### Task 5: Modify Consumer to Read Second Message

Change consumer code:

```c
printf("First message: %s\n", ptr);
ptr += strlen(ptr) + 1;
printf("Second message: %s\n", ptr);
```

---
