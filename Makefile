CC=gcc
CFLAGS=-lm -O2

eocalc: src/eocalc.c
	$(CC) src/eocalc.c $(CFLAGS) -o pkg/eocalc

#eoctest: src/eoctest.c
#	$(CC) $(CFLAGS) -o pkg/eoctest src/eoctest.c src/eocalc.c
