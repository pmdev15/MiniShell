#ifndef EXECUTE_H
#define EXECUTE_H

#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<signal.h>

#define MAX_INPUT 1024

int execute(char **args,char **envp);
int child_process(char **args,char **envp);

char *get_path(char **envp);
char **split_paths(char *paths,int *count);

#endif