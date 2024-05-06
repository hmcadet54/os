#ifndef PRODUCT_HEADER
#define PRODUCT_HEADER

#define MAX_PRODUCTS 10


#include "stdio.h"

// int count=0;
struct product
{
	int id;
	char name[10];
	char des[50];
	int q;
	int price;
	int net_price;
};

void adding_product(struct product);
void display_product();
void updatig_product(int id);
void deleting_product(int id);


#endif