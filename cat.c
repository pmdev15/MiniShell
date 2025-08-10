#include"cat.h"


int cat(char **args){
    FILE *fd;

    if(!args[1]){   // todo - handle ctrl+d
        char *line = reads();
        while(line!=NULL){
            fprintf(stdout,"%s",line);
            line = reads();
        }
    }
    else if(args[1][0] == '-'){

    }
    else{
        char *file_name = args[1];
        fd = fopen(file_name,"r");
        if(!fd){
        fprintf(stderr,"%s No such file or directory!\n",file_name);
        return 1;
        }
        char *data = NULL;
        size_t size = fileSize(fd);
        data = (char *)malloc(size * sizeof(char));
        while(fgets(data,MAX_INPUT,fd)){
            fprintf(stdout,"%s",data);   
        }
        fflush(fd);
        fclose(fd);
    }   
    return 0;
}

//For already opened file
size_t fileSize(FILE *fd){
    struct stat st;
    if (fstat(fileno(fd), &st) == 0) { // Get status from file descriptor
        return st.st_size;
    } else {
        perror("Error getting file status from file pointer");
        return -1;
    }
}

// todo - Handle ctrl+d
char *reads(void){
	char *buffer = NULL;
	size_t bufsize = 0; 

	if(getline(&buffer,&bufsize,stdin) == -1){
		if(feof(stdin)){
			return NULL;
		}
		else{
		    perror("reads");
		}
	}
	return buffer;
}