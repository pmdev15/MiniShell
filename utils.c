#include"utils.h"

int exec(char **args){
    for (size_t i = 0;args[i]; i++){
			printf("ARGS: %s\n",args[i]);
		}
}