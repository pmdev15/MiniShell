#include"parser.h"

char **parse(char *input){
	size_t buffer_size = MAX_INPUT;
	char **tokens = (char **)malloc(buffer_size*sizeof(char *));
	char *token = NULL;
	size_t token_lenght = 0;

	if(!tokens){
		perror("ERROR ALLOCATING MEMORY\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(input,DELIM);
	while(token!=NULL){
		tokens[token_lenght] = token;
		token_lenght++;

		if(token_lenght >= buffer_size){
			buffer_size*=2;
			tokens = (char **)realloc(tokens,buffer_size*sizeof(char *));
			if(!tokens){
				perror("ERROR ALLOCATING MEMORY");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL,DELIM);
	}
	tokens[token_lenght] = NULL; // '\0' NULL Terminate
	

	return tokens;
}
