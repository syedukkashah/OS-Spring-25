#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "sys/types.h"
#include "sys/wait.h"
int main(int argc, char* argv[])
{
	pid_t c1;
	c1 = fork();
	if(c1<0)
	{
		printf("Child fork failed");
		return 1;
	}
	if(c1==0)
	{
		printf("Child process ID -> %d\n", getpid());
		printf("Parent process ID -> %d\n", getppid());
		printf("User ID -> %d\n", getuid());
		return 0;
	}
	wait(NULL);
	return 0;
}
