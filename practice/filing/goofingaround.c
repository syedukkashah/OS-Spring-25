#include "fcntl.h"
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "sys/wait.h"
#include "sys/types.h"
int main(){
	int fd = open("sample.txt", O_CREAT | O_WRONLY, 0644); //user rw, group & others read
	if (fd == -1)
	{
		perror("error creating file");
		return 1;
	}
	printf("File opened with file descriptor %d\n", fd);
	close(fd);
	return 0;
}

