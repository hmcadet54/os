#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
void handler_c(int sig_c)
{
    fprintf(stdout, "signal id cought (%d)\n", sig_c);
    raise(SIGKILL);
}
int main()
{
    if (signal(SIGINT, handler_c) == SIG_ERR)
    {
        printf("error setting up handler\n");
        return 1;
    }
    printf("CTRL+C to send a signal\n");
    while (1)
    {
        sleep(1);
    }
}