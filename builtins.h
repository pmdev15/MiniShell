#ifndef BUILTINS_H
#define BUILTINS_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#include<string.h>

const char *builtins[] = {"cd","exit","pwd","which","echo"};

int builts(char **args);

int pwd(void);
int change_dir(char **args);
int echo(char **args);
void quit(void);
int clear(void);
int which(char **args);

#endif