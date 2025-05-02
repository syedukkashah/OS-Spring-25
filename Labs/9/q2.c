#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

void child_handler(int signum)
{
    int status;
    //reap all the terminated children w/o blocking
    while (wait3(&status, WNOHANG, NULL) > 0)
    {
        printf("reaped child, exit status = %d\n", WEXITSTATUS(status));
    }
}

int main()
{
    //installing SIGCHLD handler
    signal(SIGCHLD, child_handler);

    //creating 3 children w/o waiting
    for (int i = 0; i < 3; i++)
    {
        if (fork() == 0)
        {
            sleep(1);         //simulating work
            exit(100 + i);    //child exits w/ distinct code
        }
    }

    //parent sleeps so children become zombies briefly.
    sleep(5);
    printf("parent exiting.\n");
  
    return 0;
}
