#include "product.h"
#include <stdio.h>


struct product products[MAX_PRODUCTS];
int product_count = 0;
void adding_product(struct product newProduct) {
    if(product_count < MAX_PRODUCTS) {
        products[product_count] = newProduct;
        printf("Product with id: %d added\n", newProduct.id);
        product_count++;
    } else {
        printf("Cannot add more products\n");
    }

}
void display_product()
{
    for(int i=0;i<product_count;i++)
    {
        printf("(Product ID: %d)", products[i].id);
        printf("-(Name: %s)", products[i].name);
        printf("-(Description: %s)", products[i].des);
        printf("-(Quantity: %d)", products[i].q);
        printf("-(Price: %d)", products[i].price);
        printf("-(Net Price: %d)\n", products[i].net_price);
    }

}
void updatig_product(int id)
{
    for(int i=0;i<product_count;i++)
    {
        if(products[i].id == id)
        {
            printf("Enter new name: ");
            scanf("%s", products[i].name);
            printf("Enter new description: ");
            scanf("%s", products[i].des);
            printf("Enter new quantity: ");
            scanf("%d", &products[i].q);
            printf("Enter new price: ");
            scanf("%d", &products[i].price);
            printf("Enter new net price: ");
            scanf("%d", &products[i].net_price);
        }
        // else 
        // {
        //     printf("Product not found\n");
        // }
    }
}
void deleting_product(int id)
{
    for(int i=0;i<product_count;i++)
    {
        if(products[i].id == id)
        {
            for(int j=i;j<product_count-1;j++)
            {
                products[j] = products[j+1];
            }
            product_count--;
        }
        else 
        {
            printf("Product not found\n");
        }
    }
}

