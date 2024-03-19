#include "stock.h"
#include <stdio.h>


struct stock stocks[MAX_STOCK];
int stock_count = 0;
void adding_stock(struct stock new_stock) {
    if(stock_count < MAX_STOCK) {
        stocks[stock_count] = new_stock;
        printf("Product with id: %d added\n", new_stock.id);
        stock_count++;
    } else {
        printf("Cannot add more stocks\n");
    }

}
void display_stock()
{
    for(int i=0;i<stock_count;i++)
    {
        printf("(Product ID: %d)", stocks[i].id);
        printf("-(Name: %s)", stocks[i].product_name);
        printf("-(AvailableQuantity: %d)", stocks[i].available_quantity);
    }

}
void updatig_stock(int id)
{
    for(int i=0;i<stock_count;i++)
    {
        if(stocks[i].id == id)
        {
            printf("Enter new product_name: ");
            scanf("%s", stocks[i].product_name);
            printf("Enter new ContactNumber: ");
            scanf("%d", &stocks[i].available_quantity);

        }
        // else 
        // {
        //     printf("Product not found\n");
        // }
    }
}
void deleting_stock(int id)
{
    for(int i=0;i<stock_count;i++)
    {
        if(stocks[i].id == id)
        {
            for(int j=i;j<stock_count-1;j++)
            {
                stocks[j] = stocks[j+1];
            }
            stock_count--;
        }
        else 
        {
            printf("Product not found\n");
        }
    }
}

