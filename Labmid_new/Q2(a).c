#include<stdio.h>
#include<unistd.h>
int main(){
printf("node:12 , pid = %d, ppid =%d\n",getpid(),getppid());
int i = fork();
if(i==0){
	printf("node:10 , pid = %d, ppid =%d\n",getpid(),getppid());
	int i=fork();
		if(i==0){
			printf("node:15 , pid = %d, ppid =%d\n",getpid(),getppid());
		}
	
}
else{
	i = fork();
	if(i==0){
		printf("node:20 , pid = %d, ppid =%d\n",getpid(),getppid());
		i=fork();
		if(i==0){
			printf("node:50 , pid = %d, ppid =%d\n",getpid(),getppid());
		}
		else{
			i=fork();
			if(i==0){
				printf("node:55 , pid = %d, ppid =%d\n",getpid(),getppid());
			}else{
				i=fork();
				if(i==0){
				printf("node:90 , pid = %d, ppid =%d\n",getpid(),getppid());
			}else{	
				i=fork();
				if(i==0){
				printf("node:70 , pid = %d, ppid =%d\n",getpid(),getppid());
			}else{
				i=fork();
				if(i==0){
				printf("node:45 , pid = %d, ppid =%d\n",getpid(),getppid());
			}else{
			}
		}
	}
}}}}
return 0;
}
