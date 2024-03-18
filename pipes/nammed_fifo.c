#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>


int main() {
    const char *fifo_name = "/tmp/myfifo";
    mkfifo(fifo_name, 0666);

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {  // Child process
        int fd = open(fifo_name, O_WRONLY);
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        char message[] = "Hello from child!";
        write(fd, message, sizeof(message));
        close(fd);
    } else {  // Parent process
        int fd = open(fifo_name, O_RDONLY);
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }
        char received_message[100];
        read(fd, received_message, sizeof(received_message));
        printf("Parent process received: %s\n", received_message);
        close(fd);
    }

    return 0;
}
