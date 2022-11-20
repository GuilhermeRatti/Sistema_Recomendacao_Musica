all: maker

CC = gcc
override CFLAGS += -ggdb3 -lm -Wall

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS)

maker: $(OBJS)
	$(CC) -o main $^ $(CFLAGS)

run:
	./main data

clean:
	@rm *.o main

val:
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgrind-out.txt ./main data
