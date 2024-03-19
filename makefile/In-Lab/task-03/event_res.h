#ifndef EVENT_RES_HEADER
#define EVENT_RES_HEADER

#define MAX_RES 10


#include "stdio.h"

// int count=0;
struct event
{
	int id;
	char name[10];
    char place[10];
    char event_date[12];
};

void adding_event(struct event);
void display_event();
void updatig_event(int id);
void deleting_event(int id);


#endif