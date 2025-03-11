#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/wait.h"
int main(int argc, char* argv[])
{
	pid_t c1;
	c1 = fork();
	if(c1<0)
	{
		printf("child process fork failed");
		return 1;
	}
	if(c1==0)
	{
		for(int i=1; i<=100; i++)
			printf("I am a child process\n");
		return 0;
	}
	if(c1>0)
	{
		for(int i=1; i<=100; i++)
			printf("I am a parent process\n");
	}
	wait(NULL);
	return 0;
}
