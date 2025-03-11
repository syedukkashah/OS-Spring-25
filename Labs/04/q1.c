#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/wait.h"
int main(int argc, char* argv[])
{
	pid_t c1, c2;
	c1 = fork();

	if(c1<0)
	{	printf("child 1 fork failed");
		return 1;
	}
	if(c1==0)
	{
		printf("child1 process ID -> %d\n", getpid());
		printf("parent process ID -> %d\n", getppid());
		return 0;
	}
	c2 = fork();
	if(c2<0)
	{
		printf("child 2 fork failed");
		return 1;
	}
	if(c2==0)
	{
		printf("child2 process ID -> %d\n", getpid());
		printf("parent process ID -> %d\n", getppid());
		return 0;
	}
	wait(NULL);
	wait(NULL);
	return 0;
}




