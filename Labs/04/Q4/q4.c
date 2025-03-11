#include "stdio.h"
#include "fcntl.h"
#include "unistd.h"
int main(int argc, char* argv[])
{
	if(argc<2)
	{
		printf("File name required");
		return 1;
	}
	int input, output;
	input = open(argv[1], O_RDONLY);
	if(input==-1)
	{
		printf("Error opening %s", argv[1]);
		return 1;
	}
	char buffer[100];
	ssize_t bytesRead;
	output = open("output.txt", O_WRONLY | O_CREAT);
	if(output==-1)
	{
		printf("Error opening output.txt");
		return 1;
	}
	while((bytesRead = read(input, buffer, sizeof(buffer)))>0){ // returns 0 if eof, -1 if error, >0 -> num of bytes read. Loop only works if bytes were read and terminates if eof reached or error occurs
								    // We loop since the file might not be read entirely if it's larger than the buffer. Loop ensures large files are properly read

		ssize_t bytesWritten = write(output, buffer, bytesRead);
		if(bytesWritten==-1)
		{
			printf("Error writing to output.txt");
			close(input);
			close(output);
			return 1;
		}
	}
		if(bytesRead==-1)
			printf("Error reading input.txt\n");
		close(input);
		close(output);
		printf("File copied successfully");
		return 0;
}




	
