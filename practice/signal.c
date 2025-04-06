#include "stdio.h"
#include "signal.h"
#include "unistd.h"

void sigint_handler(int signum){
	printf("Caught SIGINT signal (%d)\n", signum);
}
int main(){
	if(signal(SIGINT, sigint_handler) == SIG_ERR){
		printf("Error setting up signal handler for SIGINT\n");
		return 1;
	}
	printf("Press Ctrl+C to send a SIGINT signal");
	while(1)
		sleep(1);
	return 0;
}

