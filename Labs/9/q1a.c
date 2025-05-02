#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sigint_handler(int signum)
{
    fprintf(stderr, "[sigaction] caught SIGINT (%d). now exiting.\n", signum);
    exit(0);
}

int main()
{
    struct sigaction sa;
    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);    //no other signals blocked during handler operation
    sa.sa_flags = SA_RESTART;    //will restart syscalls if interrupted

    sigaction(SIGINT, &sa, NULL);

    fprintf(stderr, "code#1a running...press ctrl+c to exit.\n");
    while (1)
    {
        pause();
    }
    return 0;
}
