#include<stdio.h>
#include"utils.h"


int main(int argc,char **argv,char **envp){

	cmdin_t cmdin;
	cmdin.argc = argc;
	cmdin.argv = argv;
	cmdin.envp = envp;

	init(cmdin);

	return 0;
}
