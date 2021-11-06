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
		printf("In Child Process \n");
		printf("Contents of the /tmp directory \n");
		execl("/bin/ls","/bin/ls","/tmp",NULL);
		/*As command has now been shifted*/
		printf("This line will now not be executed \n");
	}else{
		printf("Inside parent process \n");
	}
	return 0;
}