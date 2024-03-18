#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Enter number of childs to create: ");
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        if (fork() == 0) {
            printf("Child Process %d with PID: %d\n", i+1, getpid());
            break;
        }
    }

    return 0;
}
