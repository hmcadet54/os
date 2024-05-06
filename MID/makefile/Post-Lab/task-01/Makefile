CC := gcc
CFLAGS := -Wall -std=c99

all: main
	@echo "Final executable 'main' created!"

main: main.o product.o vendor.o stock.o
	$(CC) $(CFLAGS) $^ -o $@
	@echo "Linking complete!"

build: main.o product.o vendor.o stock.o
	@echo "Object files created!"

execute: main
	@echo "Executing 'main'..."
	./main

clean:
	@echo "Removing object files and executable..."
	del -f main.exe main.o product.o vendor.o stock.o

build_main: main.o
	@echo "Object file for main created."

build_product: product.o
	@echo "Object file for product created."

build_vendor: vendor.o
	@echo "Object file for vendor created."

build_stock: stock.o
	@echo "Object file for stock created."

clean_main:
	@echo "Removing object file for main..."
	del -f main.o

clean_product:
	@echo "Removing object file for product..."
	del -f product.o

clean_vendor:
	@echo "Removing object file for vendor..."
	del -f vendor.o

clean_stock:
	@echo "Removing object file for stock..."
	del -f stock.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $< into $@"
