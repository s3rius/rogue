CC = gcc
CFLAGS=-Wall -g -lncurses -I$(IDIR)
SRCDIR = ./src/
IDIR = ./include/

SOURCES = $(SRCDIR)*.c

all: rogue run clean

rogue: 
	$(CC) $(SOURCES) $(CFLAGS) -o $@

run:
	./rogue

clean:
	rm rogue
