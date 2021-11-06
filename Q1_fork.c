#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
//Header files for the fork() call
int main(int argc,char const *argv[]){
	pid_t var = fork();
	// one process gets divided into two processes,the parent method is the main process which calls it and the new process is the child process;
	//fork() takes in no parameters and returns 0 for the child process and non zero positive value for the parent process
	//Negative var means no id was provided
	f(var < 0){
		perror("Fork failed \n");
		exit(1);
	}
	if(var == 0){
		printf("In child process\n");
	}else{
		printf("In parent process\n");
	}
}