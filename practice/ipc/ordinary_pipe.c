#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "sys/types.h"
#include "string.h"
#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1
int main(void){
	char write_msg[BUFFER_SIZE] = "greetings";
	char read_msg[BUFFER_SIZE];
	int fd[2];
	pid_t pid;
	if(pipe(fd) == -1){ //create pipe
		fprintf(stderr, "pipe failed");
		return 1;
	}
	pid = fork(); //fork a process
	if(pid<0){
		fprintf(stderr, "fork failed");
		return 1;
	}
	if(pid>0){
		close(fd[READ_END]); //close read end of pipe 
		write(fd[WRITE_END], write_msg, strlen(write_msg) + 1); //write to write end of pipe 
		close(fd[WRITE_END]); //close write end of pipe 
	}
	else{ //child process
	      close(fd[WRITE_END]); //close the write end of pipe 
	      read(fd[READ_END], read_msg, BUFFER_SIZE); //read from the read end of the pipe 
	      printf("read %s", read_msg);
	      close(fd[READ_END]); //close the read end of the pipe 
	}
	return 0;
}
