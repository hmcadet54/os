#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t p1, p2;
    int sum = 0, n = 0, num = 0;
    float avg;
    FILE *file = fopen("task01.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    p1 = fork();
    if (p1 < 0) {
        // Fork failed
        printf("Fork failed.\n");
        return 1;
    } else if (p1 == 0) {
        // Child process 1
        while (fscanf(file, "%d", &num) == 1) {
            sum += num;
            n++;
        }
        printf("child-1=> sum=%d\n", sum);
    } else {
        // Parent process
        wait(NULL); // Wait for child-1 to finish

        p2 = fork();
        if (p2 < 0) {
            // Fork failed
            printf("Fork failed.\n");
            return 1;
        } else if (p2 == 0) {
            // Child process 2
            sum = 0; // Reset sum for child process 2
            fseek(file, 0, SEEK_SET); // Reset file pointer to start of file
            while (fscanf(file, "%d", &num) == 1) {
                sum += num;
                n++;
            }
            if (n != 0) {
                avg = (float)sum / n;
                printf("child-2=> avg=%.2f, n=%d\n", avg, n);
            } else {
                printf("child-2=> No numbers found in the file.\n");
            }
        } else {
            // Parent process
            wait(NULL); // Wait for child-2 to finish
        }
    }

    fclose(file);

    return 0;
}
