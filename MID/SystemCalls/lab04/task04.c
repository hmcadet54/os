#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void calculateFactorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    printf("The factorial from child-1: %d\n",fact);

}

void calculateFibonacci(int n) {
    int a = 0, b = 1, c;
    printf("The fabonacci from child-2: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");

}

void printPrimes(int n) {
    printf("The Prime numbers from child-3: ");
    
    int i, j, flag;
    for (i = 2; i <= n; i++) {
        flag = 0;
        for (j = 2; j <= i / 2; j++) {
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            printf("%d ", i);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    int number = atoi(argv[1]);

    pid_t pid1, pid2, pid3;

    pid1 = fork();

    if (pid1 == 0) {
        calculateFactorial(number);
    } else {
        pid2 = fork();

        if (pid2 == 0) {
            calculateFibonacci(number);
        } else {
            pid3 = fork();

            if (pid3 == 0) {
                printPrimes(number);
            } else {
                wait(NULL);
                wait(NULL);
                wait(NULL);
                printf("All child processes have completed their tasks.\n");
            }
        }
    }

    return 0;
}
