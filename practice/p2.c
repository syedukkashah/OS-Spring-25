#include "stdio.h"
#include "unistd.h"
#include "sys/types.h"
#include "sys/wait.h"
int main(int agrc, char* argv[]){
	pid_t child = fork();
	int x = 10;
	if(child==0)
		x++;
	if(child>0)
		printf("%d",x);
	return 0;
}
