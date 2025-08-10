#ifndef CAT_H
#define CAT_H

#include<fcntl.h> // header file for ORDONLY and others

#include"utils.h"

#define MAX_INPUT 1024
#define READ "r+"
#define WRITE "w+"
#define APPEND "a+"

int cat(char **args);
size_t fileSize(FILE *fd);
char *reads();

#endif