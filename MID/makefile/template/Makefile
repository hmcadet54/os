all: hello

hello: main.o display.o
	gcc main.o display.o -o hello

main.o: main.c
	gcc -c main.c

display.o: display.c 
	gcc -c display.c

clean:
	rm -rf *.o hello

