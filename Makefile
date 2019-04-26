CC=gcc
CFLAGS=-lm -O2

#eocalc: src/eocalc.c
#	$(CC) src/eocalc.c $(CFLAGS) -o pkg/eocalc

eoctest: src/eoctest.c
	$(CC) $(CFLAGS) -o pkg/eoctest src/eoctest.c src/eocalc.c src/enemy.c src/equip.c src/class.c src/party.c

#eoctest: src/eocurses.c
#	$(CC) $(CFLAGS) -lncurses -o pkg/eocurses src/eocurses.c src/eocalc.c src/enemy.c src/equip.c src/class.c

