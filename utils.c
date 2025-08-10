#include"utils.h"

void init(cmdin_t cmdin){
	char *input = NULL;
	char **args = NULL;
	
	char host[MAX_INPUT] = "";
	char *logname = getenv("LOGNAME");
	gethostname(host,sizeof(host));

	while(true){
		shell_prompt(host,logname);
		input = read_line();
		args = parse(input);
		
		/* Add command to history */
		addHistory(input);
		//size_t status = exec(args,cmdin.envp);
		exec(args,cmdin.envp);

	}
	free_buffer(input);
	free_buffers(args);
}

void shell_prompt(char *host,char *logname){
	char *pwd = getcwd(NULL,0);
	char *home = "/home/user";
	char dir[1024];
	if(!strncmp(pwd,home,10)){
		strcpy(dir,"~");
		strcat(dir,pwd+10);
	}
	else{
		strcpy(dir,pwd);
	}
	printf("%s@%s:%s$ ",logname,host,dir);
}

int exec(char **args,char **envp){
	int status = builts(args,envp);
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
	size_t bufsize = 0; 

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