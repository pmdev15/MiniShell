#include"execute.h"

int execute(char **args,char **envp){
    pid_t pid;
    int status;

    pid = fork();

    
    if(pid < 0 ){ // ERROR Forking
        perror("fork");
        return 1;
    }
    if(pid == 0){ //Child Process
        if(child_process(args,envp)){
        //if(execvp(args[0],args)){ 
            //perror("execve");
            printf("%s: command not found\n",args[0]);
            return 1;
        }
    }
    else{ //Parent Process
        if (waitpid(pid, &status, 0) == -1) {
            perror("waitpid");
            return 1;
        }
        if (WIFSIGNALED(status)) {
            printf("Process terminated by signal: %d\n", WTERMSIG(status));
        }
    }

    return 1;
}

//Attempt tp execute command by searching paths and the pwd
int child_process(char **args,char **envp){
     char* path_string = get_path(envp);
    int num_paths;
    char** path_list = split_paths(path_string, &num_paths);

    // access() execve()
    for (int i = 0; i < num_paths; i++) {
        char full_path[MAX_INPUT];
        snprintf(full_path, sizeof(full_path), "%s/%s", path_list[i], args[0]);

        if (access(full_path, X_OK) == 0) {
            execve(full_path, args, envp);
        }
    }

    //for (int i = 0; path_list[i]; i++)
    //    free(path_list[i]);
    free(path_string);
    free(path_list);

    // Try executing the command in the current working directory
    char* cwd = NULL;
    cwd = getcwd(NULL, 0);
    if(cwd == NULL) {
        perror("getcwd");
        return 1;
    }

    char full_cwd_path[MAX_INPUT];
    snprintf(full_cwd_path, sizeof(full_cwd_path), "%s/%s", cwd, args[0]);
    execve(full_cwd_path, args, envp);

    //perror("execve");
    
    return 1;
}

char *get_path(char **envp){
    for(size_t i=0;envp[i];i++){
        if(!strncmp(envp[i],"PATH=",5)){
            return strdup(envp[i]+5);
        }
    }
    return NULL;
}

//split the PATH into individual paths
char **split_paths(char *paths,int *count){ //here return type is char **
                                           //but we can also return count by int *
    char **result = NULL;
    char *token = NULL;
    size_t path_len = strlen(paths);
    char path_copy[path_len];

    strncpy(path_copy,paths,sizeof(path_copy));
    path_copy[sizeof(path_copy)-1] = '\0';

    token = strtok(path_copy,":");
    *count = 0;

    while(!token){
        result = (char **)realloc(result,((*count+1) * sizeof(char *)));
        if(!result){
            perror("realloc");
            return NULL;
        }

        result[*count] = strdup(token);
        if(!result[*count]){
            perror("strdup");
            return NULL;
        }

        (*count)++;
        token = strtok(NULL,":");
    }
    return result;
}