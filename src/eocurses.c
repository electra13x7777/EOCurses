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

void* draw()
{
	getmaxyx(stdscr, LINES, COLS);
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

	struct party *p = parse_party("src/party.txt");
	//struct class *c = init_class("Landsknecht", 30, 200, 48, 39, 27, 29, 31, 39);
	//char *cname = c->name;
	//static const char *names[] = {"Landsknecht"};
	//char *chp = (char*)(c->stats[0]);
	printf("%d\n", max_x);
	struct enemy *e = parse_enemy(Fenrir_e);
	char ename[2000];
	sprintf(ename, "%s", e->name);
	// Set Array For Enemy + Class //
	//char enemybox[2][7] = {e->name,(char*) e->hp};

	char commandbox[2][7] = {"Attack", "Defend"};
	char classbox[3][16] = {"Landsknecht", "200/200HP", "48/48TP"};
	//{"Class", "200/200", "Attack", "Defend"};

	char item_e[7];
	char item_c[3];
	char commands_c[2];

	initscr(); // init ncurses
	//mainwin = newwin();
	class1 = newwin(5, 16, max_y + 13, max_x + 20);
	class2 = newwin(5, 16, max_y + 13, max_x + 40);
	class3 = newwin(5, 16, max_y + 13, max_x + 60);
	class4 = newwin(5, 16, max_y +18, max_x + 30);
	class5 = newwin(5, 16, max_y +18, max_x + 50);
	enemy1 = newwin(5, 16, max_y + 4, max_x + 40);
	command = newwin(4, 16, max_y + 4, max_x + 1); // instantiate window
	box(class1, 1, 1); // set default window borders
	box(class2, 1, 1); // set default window borders
	box(class3, 1, 1); // set default window borders
	box(class4, 1, 1); // set default window borders
	box(class5, 1, 1); // set default window borders
	box(enemy1, 1, 1); // set default window borders
	box(command, 0, 0); // set default window borders
	// Print Class 1
	mvwaddstr(class1, 1, 2, p->p1->c->name);//c->name);
	char temp[999];
	sprintf(temp, "%d HP", p->p1->c->stats[0]);
	mvwaddstr(class1, 2, 2, temp);//c->stats[0]);
	sprintf(temp, "%d TP", p->p1->c->stats[2]);
	mvwaddstr(class1, 3, 2, temp);
	wrefresh(class1); // update screen
	noecho(); // disable echoing

	mvwaddstr(class2, 1, 2, p->p2->c->name);//c->name);
	sprintf(temp, "%d HP", p->p2->c->stats[0]);
	mvwaddstr(class2, 2, 2, temp);//c->stats[0]);
	sprintf(temp, "%d TP", p->p2->c->stats[2]);
	mvwaddstr(class2, 3, 2, temp);
	wrefresh(class2); // update screen
	noecho(); // disable echoing

	mvwaddstr(class3, 1, 2, p->p3->c->name);//c->name);
	sprintf(temp, "%d HP", p->p3->c->stats[0]);
	mvwaddstr(class3, 2, 2, temp);//c->stats[0]);
	sprintf(temp, "%d TP", p->p3->c->stats[2]);
	mvwaddstr(class3, 3, 2, temp);
	wrefresh(class3); // update screen
	noecho(); // disable echoing

	mvwaddstr(class4, 1, 2, p->p4->c->name);//c->name);
	sprintf(temp, "%d HP", p->p4->c->stats[0]);
	mvwaddstr(class4, 2, 2, temp);//c->stats[0]);
	sprintf(temp, "%d TP", p->p4->c->stats[2]);
	mvwaddstr(class4, 3, 2, temp);
	wrefresh(class4); // update screen
	noecho(); // disable echoing

	mvwaddstr(class5, 1, 2, p->p5->c->name);//c->name);
	sprintf(temp, "%d HP", p->p5->c->stats[0]);
	mvwaddstr(class5, 2, 2, temp);//c->stats[0]);
	sprintf(temp, "%d TP", p->p5->c->stats[2]);
	mvwaddstr(class5, 3, 2, temp);
	wrefresh(class5); // update screen
	noecho(); // disable echoing

	mvwaddstr(enemy1, 1, 2, ename);//c->name);
	sprintf(temp, "%d HP", e->hp);
	mvwaddstr(enemy1, 2, 2, temp);//c->stats[0]);
	wrefresh(enemy1); // update screen
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
	int j = 0;
	int k = 0;
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

							e->hp -= p->p1->c->atk;
							break;
						case(1):
							e->hp -= p->p2->c->atk;
							break;
						case(2):
							e->hp -= p->p3->c->atk;
							break;
						case(3):
							e->hp -= p->p4->c->atk;
							break;
						case(4):
							e->hp -= p->p5->c->atk;
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
	endwin();
}
/*
void* play(void** args)
{
	int argc = *( (int*) args[0]);
	char **argv = *( (char**) args[1]);
	if(!alutInit(argc,argv))
	{
		ALenum error = alutGetError();
	}
	play_song(argv[1]);
}
*/
int main(int argc, char **argv)
{
	pthread_t curse_thread;
	pthread_t music_thread;
	pthread_t threads[2];
	int curse_pid = pthread_create(&curse_thread, NULL, &draw, NULL);
	argc = 2;
	char *fn = "src/utils/music/initialstrike.wav";
	argv[1] = fn;
	void* args[2] = {&argc, &argv};
	int music_pid = pthread_create(&music_thread, NULL, &play_audio, args);
	threads[1] = curse_thread;
	threads[0] = music_thread;
	for(int i = 0; i < 2; i++)
	{
		pthread_join(threads[i], NULL);
	}
}
