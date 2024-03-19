#include "vendor.h"
#include <stdio.h>


struct vendor vendors[MAX_VENDOR];
int vendor_count = 0;
void adding_vendor(struct vendor new_vendor) {
    if(vendor_count < MAX_VENDOR) {
        vendors[vendor_count] = new_vendor;
        printf("Product with id: %d added\n", new_vendor.id);
        vendor_count++;
    } else {
        printf("Cannot add more vendors\n");
    }

}
void display_vendor()
{
    for(int i=0;i<vendor_count;i++)
    {
        printf("(Product ID: %d)", vendors[i].id);
        printf("-(Name: %s)", vendors[i].name);
        printf("-(ContactPerson: %s)", vendors[i].contact_person);
        printf("-(ContactPerson: %d)", vendors[i].contact_number);
    }

}
void updatig_vendor(int id)
{
    for(int i=0;i<vendor_count;i++)
    {
        if(vendors[i].id == id)
        {
            printf("Enter new name: ");
            scanf("%s", vendors[i].name);
            printf("Enter new ContactPerson: ");
            scanf("%s", vendors[i].contact_person);
            printf("Enter new ContactNumber: ");
            scanf("%d", &vendors[i].contact_number);

        }
        // else 
        // {
        //     printf("Product not found\n");
        // }
    }
}
void deleting_vendor(int id)
{
    for(int i=0;i<vendor_count;i++)
    {
        if(vendors[i].id == id)
        {
            for(int j=i;j<vendor_count-1;j++)
            {
                vendors[j] = vendors[j+1];
            }
            vendor_count--;
        }
        else 
        {
            printf("Product not found\n");
        }
    }
}

