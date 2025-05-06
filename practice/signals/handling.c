#define _XOPEN_SOURCE 700 //must appear before any includes
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
void sigint_handler(int signum)
{
    printf("CTRL+C (SIGINT) received. Exiting...\n");
    exit(signum);
}
int main(int argc, char* argv[])
{
    struct sigaction sa;
    sa.sa_handler = sigint_handler; //the handler function
    sigemptyset(&sa.sa_mask); //signals to block during handler execution (inits signal mask to be empty)
    sa.sa_flags = 0; //special behavior flags

    if(sigaction(SIGINT, &sa, NULL)==-1){ //sigaction takes SIGINT, ptr to new action struct and ptr to old action struct
        perror("sigaction");
        return EXIT_FAILURE;
    }
    while(1)
    {
        sleep(1);
    }
    return EXIT_SUCCESS;
}
/*
    Why sigaction() is Better Than signal()
    Provides more control over signal handling behavior
    Allows specification of which signals to block during handler execution
    Offers flags to modify default behavior
    More portable across different UNIX systems
    Standardized by POSIX
*/
