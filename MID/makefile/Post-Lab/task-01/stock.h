#ifndef STOCK_HEADER
#define STOCK_HEADER

#define MAX_STOCK 100


#include "stdio.h"

// int count=0;
struct stock
{
	int id;
	char product_name[10];
    int available_quantity;
};

void adding_stock(struct stock);
void display_stock();
void updatig_stock(int id);
void deleting_stock(int id);


#endif