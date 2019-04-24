#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ncurses.h>

#include "attack.h"
#include "class.h"
#include "equip.h"
#include "enemy.h"

int main()
{
	WINDOW *command;
	WINDOW *classw;
	struct class *c = init_class("Landsknecht", 30, 200, 48, 39, 27, 29, 31, 39);
	char *cname = c->name;
	static const char *names[] = {"Landsknecht"};
	char *chp = (char*)(c->stats[0]);
	printf("%s\n", cname);
	struct enemy *e = parse_enemy(Fenrir_e);

	// Set Array For Enemy + Class //
	//char enemybox[2][7] = {e->name,(char*) e->hp};

	char commandbox[2][7] = {"Attack", "Defend"};
	char classbox[3][16] = {"Landsknecht", "200/200HP", "48/48TP"};
	//{"Class", "200/200", "Attack", "Defend"};

	char item_e[7];
	char item_c[3];
	char commands_c[2];

	initscr(); // init ncurses
	classw = newwin(5, 16, 12, 1);
	command = newwin(4, 16, 17, 1); // instantiate window
	box(classw, 1, 1); // set default window borders
	box(command, 0, 0); // set default window borders
	// Print Class 1
	mvwaddstr(classw, 1, 2, c->name);//c->name);
	char temp[999];
	sprintf(temp, "%d HP", c->stats[0]);
	mvwaddstr(classw, 2, 2, temp);//c->stats[0]);
	sprintf(temp, "%d TP", c->stats[2]);
	mvwaddstr(classw, 3, 2, temp);
	wrefresh(classw); // update screen
	noecho(); // disable echoing

	// print class commands
	for(int i = 0; i < 2; i++)
	{
		if(i == 0)
		{
			wattron(command, A_STANDOUT); // highlight first element
		}
		else
		{
			wattroff(command, A_STANDOUT);
		}
		sprintf(commands_c, "%-7s", commandbox[i]);
		mvwprintw(command, i+1, 2, "%s", commands_c);
	}

	wrefresh(command); // update screen
	noecho(); // disable echoing
	keypad(command, TRUE); // enable keboard
	curs_set(0); // hide cursor

	// get input
	int i = 0;
	int pos;
	while((pos = wgetch(command)) != 'q')
	{
		// pad
		sprintf(commands_c, "%-7s", commandbox[i]);
		mvwprintw(command, i+1, 2, "%s", commands_c);
		// increment and decrement
		switch(pos)
		{
			case(KEY_UP):
				i--;
				i = (i<0) ? 1 : i;
				break;
			case(KEY_DOWN):
				i++;
				i = (i>1) ? 0 : i;
				break;
		}
		// highlight next element
		wattron(command, A_STANDOUT);
		sprintf(commands_c, "%-7s", commandbox[i]);
		mvwprintw(command, i+1, 2, "%s", commands_c);
		wattroff(command, A_STANDOUT);
	}
	printw("%s", c->name);
	printw("%d", c->stats[0]);
	delwin(command);
	endwin();
}
