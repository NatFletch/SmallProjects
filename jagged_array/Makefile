OBJS = main.o jagged_array.o
CC = gcc
CFLAGS = -Wall -Werror -c -g -std=c11

a.out : $(OBJS)
	$(CC) $(OBJS) -o a.out

main.o : main.c
	$(CC) $(CFLAGS) main.c

jagged_array.o : jagged_array.c
	$(CC) $(CFLAGS) jagged_array.c

clean :
	rm -f a.out
	rm -f $(OBJS)