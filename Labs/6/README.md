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
