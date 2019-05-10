// File: batcurse.c
// Author: Alex Barney
//
// Description: Defines battle drawing subroutines

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <AL/alut.h>
#include <pthread.h>
#include <ncurses.h>

//#include "attack.h"
#include "class.h"
#include "equip.h"
#include "enemy.h"
#include "party.h"
#include "music.h"
#include "batcurse.h"

#define COMMANDS "Attack","Defend","Skills","Items","Boost","Escape"

// Function: party_printw
// Return: void
// Description:
void party_printw(WINDOW **pwinarr, struct party *p, uint8_t fbias, int y, int x)
{
	char temp[999];

	if(fbias == 1)
	{
		pwinarr[0] = newwin(5, 16, y + 13, x + 20);
		pwinarr[1] = newwin(5, 16, y + 13, x + 40);
		pwinarr[2] = newwin(5, 16, y + 13, x + 60);
		pwinarr[3] = newwin(5, 16, y + 18, x + 30);
		pwinarr[4] = newwin(5, 16, y + 18, x + 50);
	}
	else
	{
		pwinarr[0] = newwin(5, 16, y + 13, x + 30);
		pwinarr[0] = newwin(5, 16, y + 13, x + 50);
		pwinarr[0] = newwin(5, 16, y + 18, x + 20);
		pwinarr[0] = newwin(5, 16, y + 18, x + 40);
		pwinarr[0] = newwin(5, 16, y + 18, x + 60);
	}

	box(pwinarr[0], 1, 1);
	box(pwinarr[1], 1, 1);
	box(pwinarr[2], 1, 1);
	box(pwinarr[3], 1, 1);
	box(pwinarr[4], 1, 1);

	mvwaddstr(pwinarr[0], 1, 2, p->p1->c->name);
	sprintf(temp, "%d HP", p->p1->c->stats[0]);
	mvwaddstr(pwinarr[0], 2, 2, temp);
	sprintf(temp, "%d TP", p->p1->c->stats[2]);
	mvwaddstr(pwinarr[0], 3, 2, temp);
	wrefresh(pwinarr[0]);
	noecho();

	mvwaddstr(pwinarr[1], 1, 2, p->p2->c->name);
	sprintf(temp, "%d HP", p->p2->c->stats[0]);
	mvwaddstr(pwinarr[1], 2, 2, temp);
	sprintf(temp, "%d TP", p->p2->c->stats[2]);
	mvwaddstr(pwinarr[1], 3, 2, temp);
	wrefresh(pwinarr[1]);
	noecho();

	mvwaddstr(pwinarr[2], 1, 2, p->p3->c->name);
	sprintf(temp, "%d HP", p->p3->c->stats[0]);
	mvwaddstr(pwinarr[2], 2, 2, temp);
	sprintf(temp, "%d TP", p->p3->c->stats[2]);
	mvwaddstr(pwinarr[2], 3, 2, temp);
	wrefresh(pwinarr[2]);
	noecho();

	mvwaddstr(pwinarr[3], 1, 2, p->p4->c->name);
	sprintf(temp, "%d HP", p->p4->c->stats[0]);
	mvwaddstr(pwinarr[3], 2, 2, temp);
	sprintf(temp, "%d TP", p->p4->c->stats[2]);
	mvwaddstr(pwinarr[3], 3, 2, temp);
	wrefresh(pwinarr[3]);
	noecho();

	mvwaddstr(pwinarr[4], 1, 2, p->p5->c->name);
	sprintf(temp, "%d HP", p->p5->c->stats[0]);
	mvwaddstr(pwinarr[4], 2, 2, temp);
	sprintf(temp, "%d TP", p->p5->c->stats[2]);
	mvwaddstr(pwinarr[4], 3, 2, temp);
	wrefresh(pwinarr[4]);
	noecho();

}

//
//
//
void enemy_printw(WINDOW *ewin, struct enemy *e, uint8_t numen, int y, int x)
{
	char temp[999];

	if(numen == 1)
	{
		ewin = newwin(5, 16, y + 4, x + 40);
	}
	if(numen == 2)
	{
		//enemy1 = newwin(5, 16, max_y + 4, max_x + 40);
	}
	if(numen == 3)
	{
		//enemy1 = newwin(5, 16, max_y + 4, max_x + 40);
	}

	box(ewin, 1, 1);

	mvwaddstr(ewin, 1, 2, ename);
	sprintf(temp, "%d HP", e->hp);
	mvwaddstr(ewin, 2, 2, temp);
	wrefresh(ewin);
	noecho();
}

//
//
//
void command_printw(){}

//
//
//
void hud_printw(){}

void* draw_battle()
{
/*	getmaxyx(stdscr, LINES, COLS);
	int max_x = COLS;//getmaxx(stdscr);
	int max_y = LINES;//getmaxy(stdscr);
	WINDOW *mainwin;
	WINDOW *command;
	WINDOW *class1;
	WINDOW *class2;
	WINDOW *class3;
	WINDOW *class4;
	WINDOW *class5;
	WINDOW *enemy1;
	WINDOW *turnw;
	WINDOW *textw;
	WINDOW *skillw;

	struct party *p = parse_party("src/party.txt");
	struct enemy *e = parse_enemy(Fenrir_e);
	char ename[2000];
	sprintf(ename, "%s", e->name);
	// Set Array For Enemy + Class //
	//char enemybox[2][7] = {e->name,(char*) e->hp};

	//char classbox[3][16] = {"Landsknecht", "200/200HP", "48/48TP"};
	//{"Class", "200/200", "Attack", "Defend"};

	char item_e[7];
	char item_c[3];
	char commands_c[6];

	initscr(); // init ncurses
	//mainwin = newwin();
	command = newwin(8, 11, max_y + 4, max_x + 1); // instantiate window
	turnw = newwin(3, 11, max_y + 1, max_x + 1);
	textw = newwin(3, 56, max_y + 1, max_x + 20);
	box(class1, 1, 1); // set default window borders
	box(class2, 1, 1); // set default window borders
	box(class3, 1, 1); // set default window borders
	box(class4, 1, 1); // set default window borders
	box(class5, 1, 1); // set default window borders
	box(enemy1, 1, 1); // set default window borders
	box(command, 0, 0); // set default window borders
	box(turnw, 0, 0); // set default window borders
	box(textw, 1, 0); // set default window borders
	// Print Class 1


	mvwaddstr(turnw, 1, 2, "Turn: 1");
	wrefresh(turnw); // update screen
	wrefresh(textw); // update screen

	// print class commands
	for(int i = 0; i < 6; i++)
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
	int j = 0;
	int k = 0;
	int pos;
	while((pos = wgetch(command)) != 'q')
	{
		// pad
		sprintf(commands_c, "%-7s", commandbox[i]);
		mvwprintw(command, i+1, 2, "%s", commands_c);
		// increment and decrement
		int turn = 1;
		switch(pos)
		{
			case(KEY_UP):
				i--;
				i = (i<0) ? 5 : i;
				break;
			case(KEY_DOWN):
				i++;
				i = (i>5) ? 0 : i;
				break;
			case('z'):
				if(commandbox[i] == commandbox[0])
				{
					switch(j)
					{
						case(0):
							//wattron(class1, A_STANDOUT);
							//sprintf(temp, "%-7s", p->p1->c->name);
							//mvwaddstr(class1, 1, 2, p->p1->c->name);//c->name);
							//wattroff(class1, A_STANDOUT);

							mvwaddstr(textw, 1, 2, p->p1->c->name);//c->name);
							wrefresh(textw); // update screen
							e->hp -= p->p1->c->atk;
							break;
						case(1):
							mvwaddstr(textw, 1, 2, p->p2->c->name);//c->name);
							wrefresh(textw); // update screen
							e->hp -= p->p2->c->atk;
							break;
						case(2):
							mvwaddstr(textw, 1, 2, p->p3->c->name);//c->name);
							wrefresh(textw); // update screen
							e->hp -= p->p3->c->atk;
							break;
						case(3):
							mvwaddstr(textw, 1, 2, p->p4->c->name);//c->name);
							wrefresh(textw); // update screen
							e->hp -= p->p4->c->atk;
							break;
						case(4):
							mvwaddstr(textw, 1, 2, p->p5->c->name);//c->name);
							wrefresh(textw); // update screen
							e->hp -= p->p5->c->atk;
							turn++;
							sprintf(temp, "Turn: %d ", turn);
							mvwaddstr(turnw, 1, 2, temp);
							wrefresh(turnw);
							break;
						case(5):
							switch(k)
							{
								case(0):
									p->p1->c->stats[0] -= e->at;
									if(p->p1->c->stats[0] > 0)
										sprintf(temp, "%d ", p->p1->c->stats[0]);
									else
									{
										sprintf(temp, "    %s   ", "DEAD");
										p->p1->c->stats[0] = 0;
									}
									mvwaddstr(class1, 2, 2, temp);
									wrefresh(class1);
								case(1):
									p->p2->c->stats[0] -= e->at;
									if(p->p2->c->stats[0] > 0)
										sprintf(temp, "%d ", p->p2->c->stats[0]);
									else
									{
										sprintf(temp, "    %s   ", "DEAD");
										p->p2->c->stats[0] = 0;
									}
									mvwaddstr(class2, 2, 2, temp);
									wrefresh(class2);
								case(2):
									p->p3->c->stats[0] -= e->at;
									if(p->p3->c->stats[0] > 0)
										sprintf(temp, "%d ", p->p3->c->stats[0]);
									else
									{
										sprintf(temp, "    %s   ", "DEAD");
										p->p3->c->stats[0] = 0;
									}
									mvwaddstr(class3, 2, 2, temp);
									wrefresh(class3);
								case(3):
									p->p4->c->stats[0] -= e->at;
									if(p->p4->c->stats[0] > 0)
										sprintf(temp, "%d ", p->p4->c->stats[0]);
									else
									{
										sprintf(temp, "    %s   ", "DEAD");
										p->p4->c->stats[0] = 0;
									}
									mvwaddstr(class4, 2, 2, temp);
									wrefresh(class4);
								case(4):
									p->p5->c->stats[0] -= e->at;
									if(p->p5->c->stats[0] > 0)
										sprintf(temp, "%d ", p->p5->c->stats[0]);
									else
									{
										sprintf(temp, "    %s   ", "DEAD");
										p->p5->c->stats[0] = 0;
									}
									mvwaddstr(class5, 2, 2, temp);
									wrefresh(class5);
							}
							k++;
							j = 0;
							break;
					}
				}
				if(commandbox[i] == commandbox[2])
				{

				}
				sprintf(temp, "%d ", e->hp);
				mvwaddstr(enemy1, 2, 2, temp);
				wrefresh(enemy1);
				j++;
				break;
		}
		// highlight next element
		wattron(command, A_STANDOUT);
		sprintf(commands_c, "%-7s", commandbox[i]);
		mvwprintw(command, i+1, 2, "%s", commands_c);
		wattroff(command, A_STANDOUT);
	}
	printw("%s", p->p1->c->name);
	printw("%d", p->p1->c->stats[0]);
	delwin(command);
	delwin(class1);
	delwin(class2);
	delwin(class3);
	delwin(class4);
	delwin(class5);
	delwin(enemy1);
	endwin();*/
}
