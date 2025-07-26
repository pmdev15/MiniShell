#ifndef BUILTINS_H
#define BUILTINS_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#include<string.h>

#include"execute.h"
#include"makedir.h"
#include"cat.h"

//char *build[] = {"cd","exit","pwd","which","echo","mkdir","ls","help","history","clear"};

int builts(char **args,char **envp);

int pwd(void);
int change_dir(char **args);
int echo(char **args);
void quit(void);
int clear(void);
int which(char **args);

#endif