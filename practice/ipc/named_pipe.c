#include "sys/types.h"
#include "fcntl.h"
#include "stdio.h"
#include "unistd.h"
#include "sys/shm.h"
#include "sys/mman.h"
#include "stdlib.h"
#include "sys/stat.h"
#include "string.h"
#define FIFO_FILE "/tmp/myfifo"
#define BUFFSIZE 4096
int main(){
	int fd;
	char buffer[BUFFSIZE];
	ssize_t num_bytes;
	mkfifo(FIFO_FILE, O_WRONLY);
	if (fd == -1){
		perror("open");
		exit(EXIT_FAILURE);
	}
	while(1){ //producer loop
		printf("Producer: Enter a msg (or 'exit' to quit): ");
		fgets(buffer, BUFFSIZE, stdin);
		num_bytes = write(fd, buffer, strlen(buffer));
		if(num_bytes == -1){
			perror("Write");
			exit(EXIT_FAILURE);
		}
		if(strncmp(buffer, "exit", 4) == 0){
			break;
		}
	}
	close (fd);
	unlink(FIFO_FILE);
	return 0;
}
