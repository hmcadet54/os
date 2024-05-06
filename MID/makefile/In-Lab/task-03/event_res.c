#include "event_res.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct event events[MAX_RES];
int event_count = 0;
void adding_event(struct event newEvent)
{
    if (event_count < MAX_RES)
    {
        int eventExists = 0;

        for (int i = 0; i < event_count; i++)
        {
            if ((strcmp(events[i].place, newEvent.place) == 0) && (strcmp(events[i].event_date, newEvent.event_date) == 0))
            {
                printf("Event already exists\n");
                eventExists = 1;
                break;
            }
        }

        if (!eventExists)
        {
            events[event_count] = newEvent;
            event_count++;
            printf("Event added successfully\n");
        }
    }
    else
    {
        printf("Cannot add more events\n");
    }
}
void display_event()
{
    for (int i = 0; i < event_count; i++)
    {
        printf("(Event ID: %d)", events[i].id);
        printf("-(Name: %s)", events[i].name);
        printf("-(Place: %s)", events[i].place);
        printf("-(event_date: %s)\n", events[i].event_date);
    }
}
void updatig_event(int id)
{
    for (int i = 0; i < event_count; i++)
    {
        if (events[i].id == id)
        {
            printf("Enter new name: ");
            scanf("%s", events[i].name);
            printf("Enter new place: ");
            scanf("%s", events[i].place);
            printf("Enter new event_date: ");
            scanf("%s", events[i].event_date);
        }
        // else
        // {
        //     printf("Product not found\n");
        // }
    }
}
void deleting_event(int id)
{
    for (int i = 0; i < event_count; i++)
    {
        if (events[i].id == id)
        {
            for (int j = i; j < event_count - 1; j++)
            {
                events[j] = events[j + 1];
            }
            event_count--;
        }
        else
        {
            printf("Event not found\n");
        }
    }
}
