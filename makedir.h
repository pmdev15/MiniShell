#ifndef MAKEDIR_H
#define MAKEDIR_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>

#define MAX_PATH_LEN 256

int check_dir(char *path);
int makedir(char **args);
int single_dir(char *path);
int nest_dir(char *path);

#endif