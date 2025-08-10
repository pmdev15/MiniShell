#include"history.h"

void addHistory(char *line){
    FILE* fd;

    fd = fopen(".history","a");
    if(!fd){
        perror("fd");
    }
    fputs(line,fd);
    fputc('\n',fd);
    fflush(fd);
    fclose(fd);
}

int displayHistory(){
    
    FILE* fd;
    
    fd = fopen(".history","r");
    char *data = NULL;
    data = (char *)malloc(MAX_INPUT * sizeof(char));
    int i = 0;
    while(fgets(data,MAX_INPUT,fd)){
        printf("%d. %s",++i,data);
        if(i == MAX_INPUT){
            data = realloc(data,MAX_INPUT);
            if(!data){
                perror("realloc");
            }
        }
    }
    fclose(fd);
    return 0;
}