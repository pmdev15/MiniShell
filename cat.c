#include"cat.h"

FILE *fd;

int cat(char **args){
    if(!args[1]){   // todo - handle ctrl+d
        char *line = reads();fscanf(fd,"%s",line);
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
        return EXIT_FAILURE;
        }
        char c;
        while((c = getc(fd)) != EOF){
            fprintf(stdout,"%c",c);   
        }
        fclose(fd);
    }   
    return 0;
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