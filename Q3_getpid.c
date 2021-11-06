#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
//Header files for the fork() call
int main(int argc,char const *argv[]){
	pid_t var = fork();
	// one process gets divided into two processes,the parent method is the main process which calls it and the new process is the child process;
	//fork() takes in no parameters and returns 0 for the child process and non zero positive value for the parent process

	//getpid() : get process id, getppid() : get parent process id
	if(var < 0){
		perror("Fork failed \n");
		exit(1);
	}
	if(!var){
		printf("In child process. Child_id: %d, parent_id: %d \n",getpid(),getppid());
	}else{
		printf("In parent process. Parent Process_id: %d, child_id: %d \n",getpid(),var);
	}
}