#ifndef CAT_H
#define CAT_H

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h> // header file for ORDONLY and others

#include"utils.h"

#define MAX_INPUT 1024
#define READ O_RDONLY

int cat(char **args);
char *reads();

#endif