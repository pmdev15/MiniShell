#ifndef PARSER_H
#define PARSER_H

#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

#define MAX_INPUT 1024
#define DELIM " \t\r\n\a"

char **parse(char *input);


#endif /* PARSER_H */
