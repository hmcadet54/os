
#include "product.h"
#include "vendor.h"
#include "stock.h"

int main()
{
	int choice;
	int choice_product;
	int choice_vendor;
	int choice_stock;

	do
	{
		printf("1. Product Section\n");
		printf("2. Vendor Section\n");
		printf("3. Stock Section\n");
		printf("0. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		int id;

		switch (choice)
		{
		case 1:
			do
			{
				struct product newProduct;

				printf("1. Display Predefined Product\n");
				printf("2. Add Product\n");
				printf("3. Update Product\n");
				printf("4. Delete Product\n");
				printf("0. Exit\n");
				printf("Enter your choice: ");
				scanf("%d", &choice_product);

				switch (choice_product)
				{
				case 1:
					display_product();
					break;
				case 2:
					printf("Enter product id: ");
					scanf("%d", &newProduct.id);
					printf("Enter product name: ");
					scanf("%s", newProduct.name);
					printf("Enter product description: ");
					scanf("%s", newProduct.des);
					printf("Enter product quantity: ");
					scanf("%d", &newProduct.q);
					printf("Enter product price: ");
					scanf("%d", &newProduct.price);
					printf("Enter product net price: ");
					scanf("%d", &newProduct.net_price);
					adding_product(newProduct);
					break;
				case 3:
					printf("Enter product id to update: ");
					scanf("%d", &id);
					updatig_product(id);
					break;
				case 4:
					printf("Enter product id to delete: ");
					scanf("%d", &id);
					deleting_product(id);
					break;
				case 0:
					printf("Exiting product section...\n");
					break;
				default:
					printf("Invalid choice. Please try again.\n");
					break;
				}
			} while (choice_product != 0);
			// Add code for product section functionality
			break;
		case 2:

			do
			{
				struct vendor newVendor;

				printf("1. Display Predefined Vendor\n");
				printf("2. Add Vendor\n");
				printf("3. Update Vendor\n");
				printf("4. Delete Vendor\n");
				printf("0. Exit\n");
				printf("Enter your choice: ");
				scanf("%d", &choice_vendor);
				int id;

				switch (choice_vendor)
				{
				case 1:
					display_vendor();
					break;
				case 2:
					printf("Enter vendor id: ");
					scanf("%d", &newVendor.id);
					printf("Enter vendor name: ");
					scanf("%s", newVendor.name);
					printf("Enter vendor contact person: ");
					scanf("%s", newVendor.contact_person);
					printf("Enter vendor contact number: ");
					scanf("%d", &newVendor.contact_number);
					adding_vendor(newVendor);
					break;
				case 3:
					printf("Enter vendor id to update: ");
					scanf("%d", &id);
					updatig_vendor(id);
					break;
				case 4:
					printf("Enter vendor id to delete: ");
					scanf("%d", &id);
					deleting_vendor(id);
					break;
				case 0:
					printf("Exiting vendor section...\n");
					break;
				default:
					printf("Invalid choice. Please try again.\n");
					break;
				}
			} while (choice_vendor != 0);
			break;
		case 3:
			// Stock Section
			do
			{
				struct stock newStock;

				printf("1. Display Predefined Stock\n");
				printf("2. Add Stock\n");
				printf("3. Update Stock\n");
				printf("4. Delete Stock\n");
				printf("0. Exit\n");
				printf("Enter your choice: ");
				scanf("%d", &choice_stock);
				int id;

				switch (choice_stock)
				{
				case 1:
					display_stock();
					break;
				case 2:
					printf("Enter stock id: ");
					scanf("%d", &newStock.id);
					printf("Enter stock product name: ");
					scanf("%s", newStock.product_name);
					printf("Enter stock available quantity: ");
					scanf("%d", &newStock.available_quantity);
					adding_stock(newStock);
					break;
				case 3:
					printf("Enter stock id to update: ");
					scanf("%d", &id);
					updatig_stock(id);
					break;
				case 4:
					printf("Enter stock id to delete: ");
					scanf("%d", &id);
					deleting_stock(id);
					break;
				case 0:
					printf("Exiting stock section...\n");
					break;
				default:
					printf("Invalid choice. Please try again.\n");
					break;
				}
			} while (choice_stock != 0);
			break;
		case 0:
			printf("Exiting program...\n");
			break;
		default:
			printf("Invalid choice. Please try again.\n");
			break;
		}

		printf("\n");
	} while (choice != 0);

	return 0;
}
