#ifndef UTILS_H
#define UTILS_H

#include<stdlib.h>
#include<stdbool.h>
#include<stdlib.h>
#include<sys/types.h>

#include"parser.h"
#include"builtins.h"

typedef struct CMD{
    int argc;
    char **argv;
    char **envp;
}cmdin_t;

void init(cmdin_t cmdsin);
void shell_prompt(char *host,char *logname);

int exec(char **args,char **envp);

char *read_l(void);
char *read_line(void);

void reallocate(char *buffer ,size_t pos ,size_t bufsize);

void free_buffer(char *buffer);
void free_buffers(char **buffer);

#endif