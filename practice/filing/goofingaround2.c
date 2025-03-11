#include "stdio.h"
#include "fcntl.h"
#include "unistd.h"
#include "stdlib.h"
#include "string.h"
int main(){
	int fd = open("sample.txt", O_RDONLY | O_WRONLY , 0644);
	if(fd==-1){
		perror("error opening file");
		return 1;
	}
	char *txt = "goofing around";
	ssize_t bytes_written = write(fd, txt, strlen(txt));
	if(bytes_written == -1)
		perror ("Error writing to file");
	else
		printf("Successfully wrote %ld bytes to file\n", bytes_written);
	close(fd);
	return 0;
}
