OBJS = main.o vector.o array.o test.o
CC = gcc
CFLAGS = -Wall -Werror -Wextra -c -g -std=c11
VPATH = headers

%.o : %.c
	$(CC) $(CFLAGS) $^

a.out : $(OBJS)
	$(CC) $(OBJS) -o $@

clean:
	rm -f $(OBJS) a.out