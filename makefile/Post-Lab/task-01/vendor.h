#ifndef VENDOR_HEADER
#define VENDOR_HEADER

#define MAX_VENDOR 10


#include "stdio.h"

// int count=0;
struct vendor
{
	int id;
	char name[10];
    char contact_person[10];
    int contact_number;
};

void adding_vendor(struct vendor);
void display_vendor();
void updatig_vendor(int id);
void deleting_vendor(int id);


#endif