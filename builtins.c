#include"builtins.h"

int builts(char **args){
    if(!strcmp(args[0],"exit") || !strcmp(args[0],"quit")){ //strcmp gives 0 if equal
        quit();
    }
    else if(!strcmp(args[0],"pwd")){
        printf("%s\n",pwd());
    }
    else if(!strcmp(args[0],"echo")){

    }
    else if(!strcmp(args[0],"cd")){
        change_dir(args);
    }
    else if(!strcmp(args[0],"mkdir")){

    }
    else if(!strcmp(args[0],"cat")){

    }
    else if(!strcmp(args[0],"ls")){

    }
    else if(!strcmp(args[0],"which")){

    }
    else if(strcmp(args[0],"clear")){

    }
    else{   // Not a builtin command
        printf("%s :command not found\n",args[0]);
    }

    return 1;
}

char *pwd(void){
    char *dir = NULL;
    dir =  getcwd(NULL,0);
    if(dir == NULL){
        perror("getcwd");
    }
    return dir;
}

int change_dir(char **args){
    if(args[1]==NULL){
        printf("cd: expected argument \"cd [path]\"\n");    
    }
    int status = chdir(args[1]);
    if(!status)
        perror("cd");
}

char **echo(char **args){

}

void quit(void){
    exit(EXIT_SUCCESS);
}