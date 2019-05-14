CC=gcc
CFLAGS=-g -lm -O2
ALFLAGS=-lalut -lopenal -lpthread

all: eoctest eocurses printeocbuild

eoctest: src/eoctest.c
	$(CC) $(CFLAGS) $(ALFLAGS) -o pkg/eoctest.eoc src/eoctest.c src/attack.c src/enemy.c src/equip.c src/class.c src/party.c src/merge.c src/music.c

eocurses: src/eocurses.c
	$(CC) $(CFLAGS) $(ALFLAGS) -lncurses -o pkg/eocurses.eoc src/eocurses.c src/enemy.c src/equip.c src/class.c src/party.c src/music.c

printeocbuild:
	@echo '************* EOCurses Build Successful *************'
