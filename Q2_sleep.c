#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc,char const *argv[]){
	pid_t var = fork();
	if(var < 0){
		perror("Fork failed \n");
		exit(1);
	}
	if(!var){
		sleep(10);//This command executes sleep for 10s
		printf("In Child Process \n");
	}else{
		sleep(10);
		printf("In parent process \n");
	}
	return 0;
}