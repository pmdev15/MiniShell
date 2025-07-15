#include<stdio.h>
#include"utils.h"


int main(int argc,char **argv,char **envp){

	// these are void casted to tell the complier not to complain about unused variables
	(void)argc;
	(void)argv;

	init(envp);

	return 0;
}
