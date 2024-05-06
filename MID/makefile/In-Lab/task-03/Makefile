CC := gcc
CFLAGS := -Wall -std=c99

all: main
	@echo "Final executable 'main' created!"

main: main.o event_res.o
	$(CC) $(CFLAGS) $^ -o $@
	@echo "Linking complete!"

build: main.o event_res.o
	@echo "Object files created!"

execute: main
	@echo "Executing 'main'..."
	./main

clean:
	@echo "Removing object files and executable..."
	del -f main.exe main.o event_res.o

build_main: main.o
	@echo "Object file for main created."

build_event_res.o: event_res.o
	@echo "Object file for product created."


clean_main:
	@echo "Removing object file for main..."
	del -f main.o

clean_event_res.o:
	@echo "Removing object file for product..."
	del -f event_res.o


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled $< into $@"
