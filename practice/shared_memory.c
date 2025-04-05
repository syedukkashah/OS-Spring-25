#include "stdio.h"
#include "unistd.h"
#include "fcntl.h"
#include "stdlib.h"
#include "sys/wait.h"
#include "string.h"
#include "sys/types.h"
#include "sys/shm.h"
#include "sys/stat.h"
#include "sys/mman.h"
int main()
{
	const int size = 4096; //declare size of shared mem obj
	int fd;
	char* msg_0 = "hello"; //msgs to be written
	char* msg_1 = "world";
	char* ptr;
	const char* name = "OS";
	fd = shm_open(name, O_CREAT|O_RDWR, 0666); //create a shared mem obj
	ftruncate(fd, size); //modify size of mem obj
	ptr = (char*)mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED,fd, 0); //mem mapping
	sprintf(ptr, "%s", msg_0); //write msg to shared mem
	ptr += strlen(msg_0); //inc ptr
	sprintf(ptr, "%s", msg_1);
	return 0;
}

