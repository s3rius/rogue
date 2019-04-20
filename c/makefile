CC = gcc
CFLAGS=-Wall -Werror -g -lncurses -I$(IDIR)
SRCDIR = ./src/
IDIR = ./include/

SOURCES = $(SRCDIR)*.c

all: clean rogue run

rogue: 
	$(CC) $(SOURCES) $(CFLAGS) -o $@

run:
	./rogue

clean:
	rm -f rogue
