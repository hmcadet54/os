#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
int main()
{

    int fd = open("task01.txt", O_RDONLY);
    int n = 0;
    char token;

    if (fd == -1)
    {
        fprintf(stderr, "Failed to open file for reading!\n");
        return 1;
    }
    char read_buffer[100];
    ssize_t bytes_read;
    while (bytes_read = read(fd, read_buffer, sizeof(read_buffer)) > 0)
    {
        token = strtok(read_buffer, " ");
        while (token != NULL)
        {
            n++;
            token = strtok(NULL, " ");
        }
        if (bytes_read == -1)
        {
            fprintf(stderr, "Failed to read from file!\n");
            close(fd);
            return 1;
        }
        printf("The Total words are: %d", n);

    }
        close(fd);

}