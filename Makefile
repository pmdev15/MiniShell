TARGET = shell.out
OBJ = main.c parser.c utils.c builtins.c execute.c makedir.c
CC = gcc
CFLAGS = -Wall -Wextra 

all:
	$(CC) $(CFLAGS) -g -o $(TARGET) $(OBJ)

clean:
	rm -f *-o
fclean:clean
	rm -f $(TARGET)
rm: fclean all