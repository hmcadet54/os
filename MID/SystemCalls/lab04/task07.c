#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3;

    pid1 = fork();

    if (pid1 == 0) {
        // First child process
        printf("First child process\n");
        exit(0);
    } 
    else if (pid1>0)
    {
        pid2 = fork();

        if (pid2 == 0) {
            // Second child process
            printf("Second child process\n");
            exit(0);
        } 
	   else if (pid2>0)
	   {
            pid3 = fork();

            if (pid3 == 0) {
                
                printf("Third child process\n");
                exit(0);
            } 
		  else if (pid3>0)
		  {
                
                wait(NULL); 
                wait(NULL);
                wait(NULL); 
                printf("Parent process terminates.\n");
                printf("Parent process\n");
            }
		  else
		  {
			perror("fork");
			exit(EXIT_FAILURE);
		  }
        }
	   else 
	   {
		perror("fork");
		exit(EXIT_FAILURE);
	   }
    }
       else 
	   {
		perror("fork");
		exit(EXIT_FAILURE);
	   }

    return 0;
}
