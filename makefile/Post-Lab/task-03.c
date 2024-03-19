#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Error: Invalid number of parameters.\n");
        return 1;
    }
    int i = 0;
    int start_time[3] = {0, 0, 0};
    int end_time[3] = {0, 0, 0};

    char *time_1 = argv[1];
    char *time_2 = argv[2];

    char *delims = ":";
    char *ptr = strtok(time_1, delims);
    while (ptr != NULL)
    {
        start_time[i] = atoi(ptr);
        ptr = strtok(NULL, delims);
        i++;
    }
    i = 0;
    ptr = strtok(time_2, delims);
    while (ptr != NULL)
    {
        end_time[i] = atoi(ptr);
        ptr = strtok(NULL, delims);
        i++;
    }

    int duration_seconds = (end_time[0] - start_time[0]) * 3600 + (end_time[1] - start_time[1]) * 60 + (end_time[2] - start_time[2]);
    int duration_hours=0, duration_minutes=0;
    if (duration_seconds >= 3600)
    {
        duration_hours = duration_seconds / 3600;
        duration_seconds = duration_seconds % 3600;
    }
    if (duration_seconds >= 60)
    {
        duration_minutes = duration_seconds / 60;
        duration_seconds = duration_seconds % 60;
    }
    if (duration_seconds < 0)
    {
        printf("Invalid time input\n");
        return 1;
    }
    else
    {
        printf("Duration: %d hours, %d minutes, %d seconds\n", duration_hours, duration_minutes, duration_seconds);
    }

    return 0;
}
