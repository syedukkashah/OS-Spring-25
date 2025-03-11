#include "stdio.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/wait.h"
int main(int argc, char* argv[]){
	/* Process Tree:
	         1
		/ \
	       2   3
	      / \
	     4   5
	*/
	printf("Root node pid : %d, ppid %d\n", getpid(), getppid());
	int i = fork();
	if(i==0)
		printf("Node 3 pid : %d, ppid: %d\n", getpid(), getppid());
	else{
		i = fork();
		if(i==0)
		{
			printf("node 2 pid:%d, ppid:%d\n", getpid(), getppid());
			i = fork();
			if(i==0)
				printf("node 4 pid %d, ppid %d\n", getpid(), getppid());
			else
			{
				i = fork();
				if(i==0)
					printf("node 5 pid %d, ppid %d", getpid(), getppid());
			}
		}
	}
	return 0;
}
