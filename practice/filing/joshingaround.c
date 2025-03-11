#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include "fcntl.h"
#include "string.h"
#define BUFFER_SIZE 1024
int main(){
	//file to file writing & reading
	int fd = open("josh.txt", O_CREAT| O_RDWR, 0644);
	if(fd == -1){
		perror("error opening file");
		return 1;
	}
	char* josh = "why is josh and why is he always around";
	ssize_t bytes_written = write(fd, josh, strlen(josh));
	if (bytes_written == -1)
	{
		perror("Error writing to file");
		return 1;
	}
	else 
		printf("successfully wrote %ld bytes to file\n", bytes_written);
	lseek(fd, 0, SEEK_SET); //next time read() is called it will read from the 0th byte from the file
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written2;
	int fd2 = open("josh2.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);

	while((bytes_read = read(fd, buffer, BUFFER_SIZE))>0)
	{
		bytes_written2 = write(fd2, buffer, bytes_read);
		if(bytes_written2 != bytes_read){
			perror("error writing to dest file");
			close(fd);
			close(fd2);
			return 1;
		}
	}
	if(bytes_read == -1)
	{
		perror("error reading from src file");
		return 1;
	}
	close(fd);
	close(fd2);
	printf("file copied\n");
	return 0;
}
	



