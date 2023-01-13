CC = gcc
# CFLAGS += -Wall -Wextra -Werror

my_mastermind: my_mastermind.o helper_functions.o
	$(CC) -o my_mastermind my_mastermind.o helper_functions.o

helper_functions.o: helper_functions.c my_mastermind.h
	$(CC) -O -c helper_functions.c

my_mastermind.o: my_mastermind.c my_mastermind.h
	$(CC) -O -c my_mastermind.c

clean:
	rm -f *.o

fclean: clean
	rm -f my_mastermind

re: fclean all