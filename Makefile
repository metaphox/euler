CFLAGS = -Wall -g
CC = gcc

SRC = $(wildcard *.c)
PROGS = $(patsubst %.c,%,$(SRC))

all: $(PROGS)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(PROGS)
