#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#define SIGCOPY SIGUSR1
#define SIGPASTE SIGUSR2
char text[50] = " ";
void copy(int sig)
{
    strcpy(text, "ABDUULAH");
    printf("text copied: %s\n", text);
}
void paste(int sig)
{
    printf("text pasted: %s\n", text);
}
int main()
{
    char ch;
    if (signal(SIGCOPY, copy) == SIG_ERR)
    {
        printf("Error Occured, handler\n");
        return 1;
    }
    if (signal(SIGPASTE, paste) == SIG_ERR)
    {
        printf("\nError Occured, handler");
        return 1;
    }
    printf("Press 'c' to copy and 'v' to paste\n");
    scanf(" %c", &ch);
    while (ch)

    {
        if (ch == 'c')
        {
            raise(SIGCOPY);
        }
        else if (ch == 'v')
        {
            raise(SIGPASTE);
        }
        scanf(" %c", &ch);
    }
    return 0;
}