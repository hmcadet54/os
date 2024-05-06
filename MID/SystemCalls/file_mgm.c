#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h> //needed for open
#include <sys/stat.h>  //needed for open
#include <fcntl.h>     //needed for open
#include <string.h>

int main()
{

	int fd = open("file.txt", O_RDWR | O_CREAT | O_APPEND, 0644);
	char buffer[100];

	ssize_t bytes_written;
	char *text="Hwlo 12213123mdsddkfnsdfklnsad asodskasndas\n";
	bytes_written=write(fd, text, strlen(text));
	close(fd);

     fd=open("file.txt",O_RDONLY);
	ssize_t bytes_read=read(fd, buffer, sizeof(buffer));
	printf("Read %zd bytes: %s\n", bytes_read, buffer);

}