#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 27
int main(void) {
	char c;
	int shmid,counter;
	key_t key;
	char *shm, *s;

	key = 2211;
	shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666))
	shm = shmat(shmid, NULL, 0))
	s = shm;
	
	printf("Message Received\n");
	for(s=shm;s!='/0';s++){
		printf("%c",*s);
	}
	s++;
	printf("\nHello World\nHello Linux World\n");
	while(counter!=18){
		printf("Enter Hello Linux World One by One character\n");
		scanf("%c",*s++);
		counter++;
	}
	s[8]="*";	
}
