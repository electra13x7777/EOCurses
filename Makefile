CC=gcc
CFLAGS=-g -lm -O2
ALFLAGS=-lalut -lopenal -lpthread

#eocalc: src/eocalc.c
#	$(CC) src/eocalc.c $(CFLAGS) -o pkg/eocalc

eoctest: src/eoctest.c
	$(CC) $(CFLAGS) $(ALFLAGS) -o pkg/eoctest src/eoctest.c src/eocalc.c src/enemy.c src/equip.c src/class.c src/party.c src/music.c

#eoctest: src/eocurses.c
#	$(CC) $(CFLAGS) -lncurses -o pkg/eocurses src/eocurses.c src/eocalc.c src/enemy.c src/equip.c src/class.c

