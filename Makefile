CC=gcc
CFLAGS=-Iinclude

all: foot

foot: src/main.c src/menu.c src/joueur.c
	$(CC) $(CFLAGS) src/main.c src/menu.c src/joueur.c -o foot

clean:
	rm -f foot
