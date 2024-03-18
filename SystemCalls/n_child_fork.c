#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int i;
    pid_t pid[4];

    for (i = 0; i < 4; i++) {
        pid[i] = fork();

        if (pid[i] < 0) {
            perror("Fork failed");
            exit(1);
        } else if (pid[i] == 0) {
            switch (i) {
                case 0:
                    execlp("ls", "ls", NULL);
                    break;
                case 1:
                    execlp("ps", "ps", NULL);
                    break;
                case 2:
                    execlp("whereis", "whereis", NULL);
                    break;
                case 3:
                    execlp("mkdir", "mkdir", "new_directory", NULL);
                    break;
                default:
                    break;
            }
            exit(0);
        }
    }

    for (i = 0; i < 4; i++) {
        wait(NULL);
    }

    printf("All child processes have completed.\n");

    return 0;
}

