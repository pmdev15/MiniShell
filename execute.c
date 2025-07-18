#include"execute.h"

int execute(char **args,char **envp){
    pid_t pid;
    int status;

    pid = fork();

    if(pid == 0){ //Child Process
        //if(child_process(args,envp)){
        if(execvp(args[0],args)){ 
            //perror("execvp");
            printf("%s: command not found\n",args[0]);
            return 1;
        }
    }
    else if(pid < 0 ){ // ERROR Forking
        perror("fork");
        return 1;
    }
    else{ //Parent Process
        do{
            waitpid(pid,&status,WUNTRACED);
        }while(!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

//Attempt tp execute command by searching paths and th pwd
//int child_process(char **args,char **envp){

//}