#include"makedir.h"

int check_dir(char *path){
    struct stat sb;
    if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode)) {
        printf("Directory '%s' exists.\n",path);
    }
    else {
        printf("The directory does not exist or the path is invalid.\n");
        return 1;
    }
    return 0;
}

int makedir(char** args){
    char *path = NULL;
    //path = (char *)malloc(MAX_INPUT*sizeof(char)+1); // +1 for the null termination
    //if(!path){
    //    return 1;
    //}
    if(!args[1]){
        fprintf(stderr,"mkdir: missing operand");
    }
    else{
        if(!strcmp(args[1],"-p")){
            if(!args[2]){
                fprintf(stderr,"mkdir: missing operand");
            }
            else{
                path = strdup(args[2]);
                if(nest_dir(path) == -1){
                    fprintf(stderr, "error while trying to create '%s'\n%m\n", path);
                    //free(path);
                    return 1;
                }
            }
        }
        else{
            path = strdup(args[1]);
            if(single_dir(path) == -1){
                fprintf(stderr, "error while trying to create '%s'\n%m\n", path);
                free(path);
                return 1;
            } 
        }
    }
    free(path);
    return 0;
}
int single_dir(char *path){
    int status;
    mode_t mode;
    mode = 0755;
    status = mkdir(path, mode);
    return status;
}
int nest_dir(char *path){
    int status;
    mode_t mode;
    mode = 0755;
    char *cpypath = NULL;
    cpypath = strdup(path);
    char *short_path = NULL;
    char nex_path[MAX_PATH_LEN+1] = "";
    nex_path[0] = '\0';
    char *delim = "/";
    short_path = strtok(cpypath,delim);
    while(short_path){
        strcat(nex_path,short_path);
        status = mkdir(nex_path,mode);
        short_path = strtok(NULL,delim);
        strcat(nex_path,delim);
    }
    free(short_path);
    free(cpypath);
    return status;
}