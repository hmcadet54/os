#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 27
int main(void) {
	char c;
	int shmid;
	key_t key;
	char *shm, *s;

	key = 2211;
	shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666))
	shm = shmat(shmid, NULL, 0))
	s = shm;
	int i=fork();
	if(i==0){
		s[0]='.';
		s[1]='_';
		s[2]='_';
		s[3]='_';
		s[4]='.';
		s[5]='.';
		s[6]='.';
		s[7]='_';
		while(s[8]!='*'){
			sleep(1);
		}	
	}else{
		wait(NULL);
		printf("Message Received\n");
		for(s=shm[9];s!='/0';s++){
			printf("%c ",*s);
		}
	}
}
