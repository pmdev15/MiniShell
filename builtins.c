#include"builtins.h"

int builts(char **args){
    if(!strcmp(args[0],"pwd")){ //strcmp gives 0 if equal
        printf("%s\n",pwd());
    }
    return 1;
}

char *pwd(void){
    char *dir = getcwd(NULL,0);
    return dir;
}