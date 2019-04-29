// File: eoctest.c
// Author: Alex Barney
//
// Description: Testing functions

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <AL/alut.h>

#include "class.h"
#include "equip.h"
#include "enemy.h"
#include "attack.h"
#include "party.h"
#include "music.h"

#define BUFFER 999

// Tests Enemy Parsing //
void test_enemy_parser()
{
	int val;
	printf("Please enter an integer value (see enemy.h for enum): ");
	scanf("%d", &val);
	struct enemy *e = parse_enemy(val);
	print_enemy(e);
	remove_enemy(e);
}

// Tests Equip Parsing //
void test_equip_parser()
{
	int val;
	printf("Please enter an integer value (see equip.h for enum): ");
	scanf("%d", &val);
	struct equip *e = parse_equip(val);
	print_equip(e);
	remove_equip(e);
}

// Tests Manual Equip Creation //
void test_equip_creator()
{
	struct equip *e = create_equip();
	print_equip(e);
	remove_equip(e);
}

// Tests Class Parsing //
void test_class_parser()
{
	int val;
	printf("Please enter an integer value (see party.txt for line numbers): ");
	scanf("%d", &val);
	struct class *c = parse_class("src/party.txt", val);
	print_class(c);
	remove_class(c);
}

// Tests Manual Class Creation //
void test_class_creator()
{
	struct class *c = create_class();
	print_class(c);
	remove_class(c);
}

// Test Class With Equip //
void test_class_with_equip()
{
	struct class *c = init_class("Landsknecht", 30, 200, 48, 39, 27, 39, 31, 39);
	//struct equip *e = parse_equip(1);
	struct equipment *eq = parse_equipment(c);
	//set_equips(eq);
	c->equips = eq;
	//add_equip(c,e,1);
	//add_equip(c,e,2);
	printf("CLASS\n");
	print_class(c);
	printf("EQUIP\n");
	/*if(c->equips->e1 != NULL)
	{
		print_equip(c->equips->e1);
	}*/
	/*if(c->equips->e1 != NULL)
	{
		print_equip(c->equips->e2);
	}*/
	print_equip(c->equips->e1);
	print_equip(c->equips->e2);
	print_equip(c->equips->e3);
	print_equip(c->equips->e4);
	remove_class(c);
}

// Test Party Parsing //
void test_party_parser()
{
	struct party *p = parse_party("src/party.txt");
	print_party(p);
	//remove_party(p);
}

// Simple Battle Simulation //
void sim()
{
	int turn = 1;
	clock_t t = clock();
	struct class *l = init_class("Landsknecht", 30, 200, 48, 39, 27, 39, 31, 39);
	print_class(l);
	printf("\n");
	struct enemy *e = parse_enemy(Golem_e);
	print_enemy(e);
	printf("\n");
	while(e->hp > 0 && l->stats[0] > 0)
	{
		printf("\nTurn %d\n\n", turn);
		//usleep(500000);
		printf("%s used All Slash\n", l->name);
		int cd = damage(l->atk, 3, .04, 1.1, 1.12, 2, e->df);
		//usleep(500000);
		printf("%s deals %d damage to %s\n", l->name, cd, e->name);
		e->hp -= cd;
		if(e->hp < 0)
		{
			e->hp = 0;
		}
		printf("\n");
		//usleep(500000);
		print_enemy(e);
		if(e->hp == 0)
		{
			printf("%s dies\n", e->name);
			break;
		}
		//usleep(500000);
		printf("\n%s attacks\n", e->name);
		int ed = ((int)(sqrt(e->at/l->def)) * e->at) - (l->def);
		//usleep(500000);
		printf("%s deals %d damage to %s\n\n", e->name, ed, l->name);
		l->stats[0] -= ed;
		if(l->stats[0] < 0)
		{
			l->stats[0] = 0;
		}
		print_class(l);
		if(l->stats[0] == 0)
		{
			printf("%s dies\n", l->name);
			break;
		}
		turn++;
	}
	remove_class(l);
	remove_enemy(e);
	printf("Runtime: %.6fs\n", (double)(clock() - t)/CLOCKS_PER_SEC);
}

int main(int argc, char **argv)
{
	int t;
	printf("EOCALC TEST SUITE\n");
	printf("1 | Test Enemy Parser\n");
	printf("2 | Test Equip Parser\n");
	printf("3 | Test Equip Creator\n");
	printf("4 | Test Class Parser\n");
	printf("5 | Test Class Creator\n");
	printf("6 | Test Class With Equip\n");
	printf("7 | Test Party Parser\n");
	printf("8 | Test Music Playback\n");
	printf("9 | Test Battle Simulation\n");
	printf("0 | Exit Test Suite\n");
	while(1)
	{
		printf("Please enter an integer to run the desired test: ");
		scanf("%d", &t);
		printf("\n");

		if(t == 0)
		{
			exit(0);
		}
		if(t == 1)
		{
			test_enemy_parser();
		}
		if(t == 2)
		{
			test_equip_parser();
		}
		if(t == 3)
		{
			test_equip_creator();
		}
		if(t == 4)
		{
			test_class_parser();
		}
		if(t == 5)
		{
			test_class_creator();
		}
		if(t == 6)
		{
			test_class_with_equip();
		}
		if(t == 7)
		{
			test_party_parser();
		}
		if(t == 8)
		{
			argc = 2;
			if(!alutInit(&argc, argv))
			{
				ALenum error = alutGetError();
			}
			if(argc != 2)
			{
				alutExit();
				exit(1);
			}
			char *fn = "src/utils/initialstrike.wav";
			argv[1] = fn;
			play_song(argv[1]);
			alutExit();
		}
		if(t == 9)
		{
			sim();
		}
		printf("\n");
	}
}
