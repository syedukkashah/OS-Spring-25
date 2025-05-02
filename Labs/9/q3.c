#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

void usr1_handler(int signum)
{
    //identifying the thread which caught the signal
    printf("thread %lu caught SIGUSR1\n", (unsigned long)pthread_self());
}

void *worker(void *arg)
{
    //register handler in this thread
    signal(SIGUSR1, usr1_handler);
    pause();  //waiting for signals
    return NULL;
}

int main()
{
    pthread_t tid[3];
    //register handler in main thread as well
    signal(SIGUSR1, usr1_handler);

    //3 worker threads spawned
    for (int i = 0; i < 3; i++)
    {
        if (pthread_create(&tid[i], NULL, worker, NULL) != 0)
        {
            perror("pthread_create");
            exit(1);
        }
    }

    sleep(1);  //threads given time to set-up

    //send SIGUSR1 to the process (any one thread may catch it)
    kill(getpid(), SIGUSR1);
    //send SIGUSR1 specifically to the 3rd thread
    pthread_kill(tid[2], SIGUSR1);

    //waiting for all threads to finish (they will exit after catching)
    for (int i = 0; i < 3; i++)
    {
        pthread_join(tid[i], NULL);
    }

    return 0;
}
