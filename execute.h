#ifndef EXECUTE_H
#define EXECUTE_H

#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int execute(char **args,char **envp);
int child_process(char **args,char **envp);

#endif