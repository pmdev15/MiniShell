#ifndef BUILTINS_H
#define BUILTINS_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int builts(char **args);

char *pwd(void);
int change_dir(char **args);
char **echo(char **args);
void quit(void);

#endif