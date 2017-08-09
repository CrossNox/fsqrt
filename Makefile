CFLAGS= -g -std=c99 -Wall -Wconversion -Wtype-limits -Wshadow -Wpointer-arith -Wunreachable-code -Werror -MMD -O0
EXEC=sr
CC=gcc

all: $(EXEC)

$(EXEC):
	$(CC) sr.c $(CFLAGS) -o $(EXEC) -lm

.PHONY: clean

clean:
	rm $(EXEC)
