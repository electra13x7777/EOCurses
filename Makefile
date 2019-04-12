CC=gcc
CFLAGS=-lm -O2

eocalc: src/eocalc.c
	$(CC) src/eocalc.c $(CFLAGS) -o pkg/eocalc
