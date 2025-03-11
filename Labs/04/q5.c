#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "sys/wait.h"
#include "sys/types.h"
int main(int argc, char* argv[])
{
	pid_t child = fork();
	if(child<0)
	{
		printf("Child fork failed.\n");
		return 1;
	}
	if(child==0){
		printf("Listing all files...");
		execlp("ls", "ls", "-l", (char *)NULL);
		perror("execlp failed.\n");
		exit(1);
	}
	else{
		printf("Parent process waiting for child process...\n");
		wait(NULL);
		printf("Parent process: Child has completed");
	}
	return 0;
}

