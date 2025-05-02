
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sigint_handler(int signum)
{
    //msg printed & then terminate
    fprintf(stderr, "caught SIGINT (%d). now exiting.\n", signum);
    _exit(0);
}

int main()
{
    //register handler for ctrl+c
    signal(SIGINT, sigint_handler);
    fprintf(stderr, "code#1 running... please press ctrl+c to trigger SIGINT.\n");
    //forever loop, waiting for signals-
    while (1)
    {
        pause();
    }
    return 0;
}
