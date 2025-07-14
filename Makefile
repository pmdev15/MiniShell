TARGET = shell
OBJ = main.c parser.c utils.c
CC = gcc

all:
	$(CC) -o $(TARGET) $(OBJ)

clean:
	rm -f *-o
fclean:clean
	rm -f $(TARGET)
rm: fclean all