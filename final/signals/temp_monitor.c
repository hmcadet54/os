#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define SIGTEMP SIGUSR1
#define SIGTSTART SIGUSR2
#define SIGEND SIGINT
int temp;
int ran_temp()
{
    srand(time(NULL));
    temp = rand() % 31 + 70;
    return temp;
}
void handle_raise_temp(int sigm)
{
printf("Warning: Critical temperature condition detected! Temperature:%d°C\n",temp);
}
void handler_start(int sigm)

{
    int check = ran_temp();
    while (check > 0)
    {
        if (check > 90)
        {
            raise(SIGTEMP);
        }
        check = ran_temp();
        printf("Current temperature: %d°C\n", check);
        sleep(1);
    }
}
void handler_end(int sigm)
{
    printf("Program Stopped !\n");
    raise(SIGKILL);
}
int main()
{
    char c;
    if (signal(SIGTSTART, handler_start) == SIG_ERR)
    {
        printf("Error!, starting handler...\n");
        return 1;
    }
    if (signal(SIGEND, handler_end) == SIG_ERR)
    {
        printf("Error!, Ending handler...\n");
        return 1;
    }
    if (signal(SIGTEMP, handle_raise_temp) == SIG_ERR)
    {
        printf("Error!, Checking handler...\n");
        return 1;
    }

    printf("Press 'CTRL+C' to Stop Monitoring and 's' to Start Monitoring \n");
    int result = scanf(" %c", &c);
    while (result == 1)
    {
        if (c == 'c')
        {
            raise(SIGEND);
        }
        else if (c == 's')
        {
            raise(SIGTSTART);
        }
        result = scanf(" %c", &c);
    }
    return 0;
}