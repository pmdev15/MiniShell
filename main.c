#include<stdio.h>
#include"utils.h"


void shell_loop(char **envp){
	char *input = NULL;
	size_t input_size = 0;

	char **args;
	
	while(true){
		printf("[bash]$ ");
		if(getline(&input,&input_size,stdin) == -1){ // End of file (EOF), ctrl+D
			perror("getline");
			break;
		}
		args = parse(input);
		
		size_t status = exec(args);
	}
}

int main(int argc,char **argv,char **envp){
	(void)argc;
	(void)argv;

	shell_loop(envp);

	return 0;
}
