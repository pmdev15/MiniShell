#ifndef UTILS_H
#define UTILS_H

#include<stdlib.h>
#include<stdbool.h>
#include<stdlib.h>
#include<sys/types.h>

#include"parser.h"
#include"builtins.h"

void init(char **envp);

int exec(char **args);

char *read_l(void);
char *read_line(void);

void reallocate(char *buffer ,size_t pos ,size_t bufsize);

void free_buffer(char *buffer);
void free_buffers(char **buffer);

#endif
