CC = clang
CFLAGS=-Wall -g -lmenu -lncurses -I$(IDIR)
SRCDIR = ./src/
IDIR = ./include/

SOURCES = $(SRCDIR)*.c \
		  $(SRCDIR)utils/*.c \
		  $(SRCDIR)windows/*.c \
		  $(SRCDIR)entities/*c \
		  $(SRCDIR)entities/items/*.c

all: clean rogue

rogue: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o $@

run:
	./rogue

clean:
	rm -f rogue
