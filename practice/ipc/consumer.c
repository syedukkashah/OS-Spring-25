#include "stdio.h"
#include "fcntl.h"
#include "sys/mman.h"
#include "sys/stat.h"
#include "sys/shm.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
int main()
{
	const int SIZE = 4096; //size of shared mem obj
	const char* name  = "OS"; //must be same name used in the producer 
	char* ptr;
	int fd;
	fd = shm_open(name, O_RDONLY, 0666); //open the shared mem obj
	if(fd == -1)
	{
		perror("shm_open");
		exit(1);
	}
	ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, fd, 0); //mem map the shared mem obj
	if (ptr == MAP_FAILED){
		perror("mmap");
		exit(1);
	}
	printf("Read from shared memory: %s\n", ptr); //reading from shared mem
	
	//clean up
	if (munmap(ptr, SIZE) == -1){
		perror("munmap");
		exit(1);
	}
	if(close(fd) == -1){
		perror("close");
		exit(1);
	}
	return 0;
}

