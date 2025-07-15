TARGET = shell
OBJ = main.c parser.c utils.c builtins.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all:
	$(CC) -o $(TARGET) $(OBJ)

clean:
	rm -f *-o
fclean:clean
	rm -f $(TARGET)
rm: fclean all