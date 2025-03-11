#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "sys/wait.h"
#include "sys/types.h"
int main(){
	pid_t p = fork();
	if(p<0){
		printf("fork failed\n");
		return 1;
	}
	if(p==0)
		execlp("ls", "ls", "-l", NULL);
	else{
		printf("Parent waiting for child process to terminate...\n");
		wait(NULL);
	}
	return 0;
}
