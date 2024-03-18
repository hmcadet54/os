#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipe_fd[2];
    pid_t pid;

    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {  // Child process
        close(pipe_fd[0]);  // Close read end
        char message[] = "Hello from child!";
        write(pipe_fd[1], message, sizeof(message));
        close(pipe_fd[1]);  // Close write end

	   
    } else {  // Parent process
        close(pipe_fd[1]);  // Close write end
        char received_message[100];
        read(pipe_fd[0], received_message, sizeof(received_message));
        printf("Parent process received: %s\n", received_message);
        close(pipe_fd[0]);  // Close read end
    }

    return 0;
}
