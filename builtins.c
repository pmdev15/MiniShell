#include"builtins.h"

int builts(char **args,char **envp){
    (void)envp;
    if(args==0 ||args[0]==0){
        return 0;
    }
    else if(!strcmp(args[0],"exit") || !strcmp(args[0],"quit")){ //strcmp gives 0 if equal
        quit();
    }
    else if(!strcmp(args[0],"pwd")){
        return pwd();
    }
    else if(!strcmp(args[0],"echo")){
        return echo(args);
    }
    else if(!strcmp(args[0],"cd")){
        return change_dir(args);
    }
    else if(!strcmp(args[0],"mkdir")){
        return makedir(args);
    }
    else if(!strcmp(args[0],"ls")){

    }
    else if(!strcmp(args[0],"help")){

    }
    else if(!strcmp(args[0],"history")){
        return displayHistory();
    }
    else if(!strcmp(args[0],"which")){
        return which(args);
    }
    else if(!strcmp(args[0],"clear")){
        return clear();
    }
    else if(!strcmp(args[0],"cat")){
        return cat(args);
    }
    else{   // Not a builtin command
        printf("%s :command not found\n",args[0]);
        //execute(args,envp);
    }
    return 0;
}

int pwd(void){
    char *dir = NULL;
    dir =  getcwd(NULL,0);
    if(dir == NULL){
        perror("getcwd");
    }
    printf("%s\n",dir);
    return 0;
}

int change_dir(char **args){
    if(args[1]==NULL){
        printf("cd: expected argument \"cd [path]\"\n"); 
        return 1;   
    }
    int status = 0;
    if (!strcmp(args[1],"..")){
        status = chdir("..");
    }
    else if(!strcmp(args[1],"~")){
        status = chdir(getenv("HOME"));
    }
    else{
        status = chdir(args[1]);
    }
    if(status)
        perror("cd");
    return 0;
}

int clear(void){
    system("clear");
    // or printf("\e[1;1H\e[2J") //ANSI escape code to clear screen
    return 0;
}

//echo Hello world, echo -n Hello World,echo -s //donot separate args with space, echo $PATH
int echo(char **args){
    bool new_line = true;
    size_t i = 1;
    char sp = ' ';
    if(args[1] == NULL){
        printf("\n");
    }
    if(args[1] != NULL && !strcmp(args[1],"-n")){
        new_line = false;
        i++;
    }
    else if(args[1] != NULL && !strcmp(args[1],"-s")){
        i++;
        sp = '\0';
    }
    for(;args[i];i++){
        if(args[i][0]=='$'){ //Handle env var
            char *value = getenv(args[i]+1); //skip $ and get the variable
            if(value){
                printf("%s",value);
            }
            else{
                perror("getenv");
            }
        }
        else{
            printf("%s%c",args[i],sp);
        }
    }
    if(new_line && args[1]) printf("\n");
    return 0;

}

int which(char **args){
    if(args[1]==NULL){
        printf("which: expected arguments\n");
        return 1;
    }

    //List built in commands
    //for(size_t i=0;build[i];i++){
    //    if(!strcmp(args[i],build[i])){
    //        printf("%s: shell builtin commands\n",args[i]);
    //    }
    //}

    // Check external path
    //char *full_path;
    return 0;
}



void quit(void){
    exit(EXIT_SUCCESS);
}