#include"utils.h"

void init(char **envp){
	char *input = NULL;
	size_t input_size = 0;

	char **args;
	
	while(true){
		printf("[bash]$ ");
		input = read_line();
		args = parse(input);
		
		size_t status = exec(args);
	}
	free_buffer(input);
	free_buffers(args);
}

int exec(char **args){
    for (size_t i = 0;args[i]; i++){
			printf("ARGS: %s\n",args[i]);
		}
	int status = builts(args);
	return status;
}
// NOTE :- donot use ctrl + d with read (only with readline cuz getline)
char *read_l(void){
	size_t bufsize = MAX_INPUT;
	char *buffer = (char *)malloc(bufsize*sizeof(char));
	size_t pos = 0;
	int c;
	if(!buffer){
		perror("readline");
		exit(EXIT_FAILURE);
	}
	while (true){
		// Read a character
		c = getchar();

		//if we hit EOF, replace it with a NULL char and return it
		if(c == EOF || c == '\n'){
			buffer[pos] = '\0';
			return buffer;
		}
		else{
			buffer[pos] = c;
		}
		pos++;
		reallocate(buffer,pos,bufsize);
	}
}

// same as above but using builtin C func - getline
char *read_line(void){
	char *buffer = NULL;
	ssize_t bufsize = 0; // ssize_t = signed size_t
						 // cuz incase cannot allocate buffer

	if(getline(&buffer,&bufsize,stdin) == -1){
		if(feof(stdin)){
			exit(EXIT_SUCCESS);
		}
		else{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}
	return buffer;
}

// if we have exceeded the buffer
void reallocate(char *buffer,size_t pos,size_t bufsize){
	if(pos>=bufsize){
		bufsize *= 2;
		buffer = realloc(buffer,bufsize);
		if(!buffer){
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}
}

//free buffer
void free_buffer(char *buffer){
	if(!buffer)
		return;
	free(buffer);
}
void free_buffers(char **buffer){
	if(!buffer)
		return;
	for(size_t i = 0;buffer[i];i++){
		free(buffer[i]); // free each token
	}
	free(buffer); //free token array
}