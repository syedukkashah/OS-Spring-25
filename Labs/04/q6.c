#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "signal.h"
void signal_handler(int sig)
{
	printf("Alarm Triggered!\n");
	exit(0);
}
int main(){
	signal(SIGALRM, signal_handler);
	alarm(5);
	printf("Starting sleep loop...\n");
	for(int i=1; i<=10; i++)
	{
		printf("Second %d\n", i);
		sleep(1);
	}
	return 0;
}

