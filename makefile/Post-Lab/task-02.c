#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc <= 1)
    {
        printf("Error: No parameters provided.\n");
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "cpu") == 0)
        {
            // Code to monitor CPU usage
            printf("CPU usage\n");
        }
        else if (strcmp(argv[i], "memory") == 0)
        {
            // Code to monitor memory usage
            printf("Memory usage\n");
        }
        else if (strcmp(argv[i], "disk") == 0)
        {
            // Code to monitor disk space
            printf("Disk space\n");
        }
        else
        {
            printf("Error: Invalid parameter '%s'.\n", argv[i]);
        }
    }

    return 0;
}
