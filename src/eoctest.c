// File: eoctest.c
// Author: Alex Barney
//
// Description: Testing functions

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
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
#include "merge.h"
#include "music.h"

#define BUFFER 999

#define foreach(i, arr) \
	for(int j = 1, \
			k = 0, \
			size = sizeof(arr)/sizeof(*arr); \
		j && k != size; \
		j = !j, k++) \
	for(i = arr + k; j; j = !j)

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
	struct equipment *eq = parse_equipment(c,1,1,1,1);
	c->equips = eq;
	print_class(c);
	remove_class(c);
}

// Tests Manual Class Creation //
void test_class_creator()
{
	struct class *c = create_class();
	struct equipment *eq = parse_equipment(c,1,1,1,1);
	c->equips = eq;
	print_class(c);
	remove_class(c);
}

// Test Class With Equip //
void test_class_with_equip()
{
	struct class *c = init_class("Landsknecht", 30, 200, 48, 39, 27, 39, 31, 39);
	//struct equip *e = parse_equip(1);
	struct equipment *eq = parse_equipment(c,2,3,4,5);
	//set_equips(eq);
	c->equips = eq;
	printf("CLASS\n");
	print_class(c);
	printf("EQUIP\n");
	print_equip(c->equips->e1);
	print_equip(c->equips->e2);
	print_equip(c->equips->e3);
	print_equip(c->equips->e4);
	remove_class(c);
}

// Test Class Unequip //
void test_class_unequip()
{
	struct class *c = parse_class("src/party.txt", 1);
	struct equipment *eq = parse_equipment(c,2,3,4,5);
	c->equips = eq;
	print_class(c);
	print_equip(c->equips->e1);
	printf("\nUNEQUIPPING!\n");
	un_equip(c, 1);
	print_class(c);
	print_equip(c->equips->e1);
	remove_class(c);
}

// Test Party Parsing //
void test_party_parser()
{
	struct party *p = parse_party("src/party.txt");
	print_party(p);
	remove_party(p);
}

// Simple Battle Simulation (DEPRECATED) //
void sim()
{
	int turn = 1;
	clock_t t = clock();
	struct class *l = init_class("Landsknecht", 30, 200, 48, 39, 27, 39, 31, 39);
	struct equipment *eq = parse_equipment(l,1,1,1,1);
	l->equips = eq;
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

// Test Turn Order //
void test_turn_order()
{
	int *i;
	struct party *p = parse_party("src/party.txt");
	struct enemy *e = parse_enemy(18);
	int arr[] =
	{
		p->p1->c->stats[5],
		p->p2->c->stats[5],
		p->p3->c->stats[5],
		p->p4->c->stats[5],
		p->p5->c->stats[5],
		e->df
	};
	msort_dec(arr, 0, (sizeof(arr)/sizeof(arr[0]) -1));
	foreach(i, arr)
	{
		printf("%d\n", *i);
	}
	remove_party(p);
}

void test_skill_points()
{
	int *i;
	struct class *c = parse_class("src/party.txt", 1);
	struct equipment *eq = parse_equipment(c,1,1,1,1);
	c->equips = eq;
	c->sp = 20;
	for(int i = 0; i < 20; i++)
	{
		c->skills[i] = 0;
		//printf("%d\n", c->skills[i]);
	}
	//memset(c->skills, 0, 21);
	uint8_t arr[21];
	invest_sp(c, 4);
	printf("Skillpoints: %d\n", c->sp);
	printf("Axes: %d\n", c->skills[4]);
	if(c->skills[4] >= 1)
		printf("	Crush is now available!\n");
	invest_sp(c, 4);
	printf("Skillpoints: %d\n", c->sp);
	printf("Axes: %d\n", c->skills[4]);
	invest_sp(c, 4);
	printf("Skillpoints: %d\n", c->sp);
	printf("Axes: %d\n", c->skills[4]);
	if(c->skills[4] >= 3)
		printf("	Stunner is now available!\n");
	invest_sp(c, 4);
	printf("Skillpoints: %d\n", c->sp);
	printf("Axes: %d\n", c->skills[4]);
	invest_sp(c, 4);
	printf("Skillpoints: %d\n", c->sp);
	printf("Axes: %d\n", c->skills[4]);
	invest_sp(c, 5);
	printf("Skillpoints: %d\n", c->sp);
	printf("Swords: %d\n", c->skills[5]);
	if(c->skills[5] >= 1)
		printf("	Cleaver is now available!\n");
	invest_sp(c, 5);
	printf("Skillpoints: %d\n", c->sp);
	printf("Swords: %d\n", c->skills[5]);
	invest_sp(c, 5);
	printf("Skillpoints: %d\n", c->sp);
	printf("Swords: %d\n", c->skills[5]);
	invest_sp(c, 5);
	printf("Skillpoints: %d\n", c->sp);
	printf("Swords: %d\n", c->skills[5]);
	invest_sp(c, 5);
	printf("Skillpoints: %d\n", c->sp);
	printf("Swords: %d\n", c->skills[5]);
	if(c->skills[5] >= 5)
		printf("	Tornado is now available!\n");
	if(c->skills[4] == 5 && c->skills[5] == 5)
	{
		printf("	2-Hit is now available!\n");
	}
	invest_sp(c, 6);
	printf("Skillpoints: %d\n", c->sp);
	printf("2-Hit: %d\n", c->skills[6]);
	invest_sp(c, 6);
	printf("Skillpoints: %d\n", c->sp);
	printf("2-Hit: %d\n", c->skills[6]);
	invest_sp(c, 6);
	printf("Skillpoints: %d\n", c->sp);
	printf("2-Hit: %d\n", c->skills[6]);
	printf("Swords: %d\n", c->skills[5]);
	if(c->skills[5] == 5 && c->skills[6] == 3)
	{
		printf("	Allslash is now available!\n");
	}
	invest_sp(c, 13);
	printf("Skillpoints: %d\n", c->sp);
	printf("Allslash: %d\n", c->skills[13]);
	//memcpy(arr, c->skills, 21);
	/*foreach(i, c->skills)
	{
		printf("%d\n", *i);
	}
	printf("\n%d", c->sp);*/
	remove_class(c);
}

// Test Adding Exp //
void test_add_exp()
{
	struct class *c = parse_class("src/party.txt", 1);
	struct equipment *eq = parse_equipment(c,1,1,1,1);
	c->equips = eq;
	c->lv = 1;
	c->exp = 0;
	c->sp = 3;
	printf("EXP: %d\n", c->exp);
	printf("LV: %d\n", c->lv);
	printf("Skillpoints: %d\n", c->sp);
	int nxtlv = add_exp(c, 148);
	printf("EXP: %d\n", c->exp);
	printf("LV: %d\n", c->lv);
	printf("Skillpoints: %d\n", c->sp);
	printf("EXP needed to get to lv%d: %d\n", c->lv+1, nxtlv);
	remove_class(c);
}

// Test Everything //
void test_all()
{
	// test parsing all enemies //
	int test_all_enemy_parser()
	{
		printf("BEGIN TESTING ENEMY PARSER\n");
		for(int i = 1; i <= 18; i++)
		{
			struct enemy *e = parse_enemy(i);
			print_enemy(e);
			remove_enemy(e);
		}
		return 1;
	}

	// test parsing all equips //
	int test_all_equip_parser()
	{
		printf("\nBEGIN TESTING EQUIP PARSER\n");
		for(int i = 1; i <= 6; i++)
		{
			struct equip *e = parse_equip(i);
			print_equip(e);
			remove_equip(e);
		}
		return 1;
	}

	// test parsing all classes //
	int test_all_class_parser()
	{
		printf("\nBEGIN TESTING CLASS PARSER\n");
		for(int i = 1; i <= 5; i++)
		{
			struct class *c = parse_class("src/party.txt", i);
			struct equipment *eq = parse_equipment(c,1,1,1,1);
			c->equips = eq;
			print_class(c);
			remove_class(c);
		}
		return 1;
	}

	int test_all_party_unequip()
	{
		struct party *p = parse_party("src/party.txt");
		struct equipment *eq1 = parse_equipment(p->p1->c,2,3,4,5);
		//struct equipment *eq2 = parse_equipment(p->p2->c,2,3,4,5);
		//struct equipment *eq3 = parse_equipment(p->p3->c,2,3,4,5);
		//struct equipment *eq4 = parse_equipment(p->p4->c,2,3,4,5);
		//struct equipment *eq5 = parse_equipment(p->p5->c,2,3,4,5);
		printf("\nEQUIPPING P1\n");
		p->p1->c->equips = eq1;
		print_class(p->p1->c);
		print_equip(p->p1->c->equips->e1);
		print_equip(p->p1->c->equips->e2);
		print_equip(p->p1->c->equips->e3);
		print_equip(p->p1->c->equips->e4);
		printf("\nEQUIPPING P2\n");
		p->p2->c->equips = eq1;
		print_class(p->p2->c);
		print_equip(p->p2->c->equips->e1);
		print_equip(p->p2->c->equips->e2);
		print_equip(p->p2->c->equips->e3);
		print_equip(p->p2->c->equips->e4);
		printf("\nEQUIPPING P3\n");
		p->p3->c->equips = eq1;
		print_class(p->p3->c);
		print_equip(p->p3->c->equips->e1);
		print_equip(p->p3->c->equips->e2);
		print_equip(p->p3->c->equips->e3);
		print_equip(p->p3->c->equips->e4);
		printf("\nEQUIPPING P4\n");
		p->p4->c->equips = eq1;
		print_class(p->p4->c);
		print_equip(p->p4->c->equips->e1);
		print_equip(p->p4->c->equips->e2);
		print_equip(p->p4->c->equips->e3);
		print_equip(p->p4->c->equips->e4);
		printf("\nEQUIPPING P5\n");
		p->p5->c->equips = eq1;
		print_class(p->p5->c);
		print_equip(p->p5->c->equips->e1);
		print_equip(p->p5->c->equips->e2);
		print_equip(p->p5->c->equips->e3);
		print_equip(p->p5->c->equips->e4);
		printf("\nUNEQUIPPING P1\n");
		un_equip(p->p1->c, 1);
		un_equip(p->p1->c, 2);
		un_equip(p->p1->c, 3);
		un_equip(p->p1->c, 4);
		printf("\nUNEQUIPPING P2\n");
		un_equip(p->p2->c, 1);
		un_equip(p->p2->c, 2);
		un_equip(p->p2->c, 3);
		un_equip(p->p2->c, 4);
		printf("\nUNEQUIPPING P3\n");
		un_equip(p->p3->c, 1);
		un_equip(p->p3->c, 2);
		un_equip(p->p3->c, 3);
		un_equip(p->p3->c, 4);
		printf("\nUNEQUIPPING P4\n");
		un_equip(p->p4->c, 1);
		un_equip(p->p4->c, 2);
		un_equip(p->p4->c, 3);
		un_equip(p->p4->c, 4);
		printf("\nUNEQUIPPING P5\n");
		un_equip(p->p5->c, 1);
		un_equip(p->p5->c, 2);
		un_equip(p->p5->c, 3);
		un_equip(p->p5->c, 4);
		/*remove_class(p->p1->c);
		remove_class(p->p2->c);
		remove_class(p->p3->c);
		remove_class(p->p4->c);
		remove_class(p->p5->c);
		free(p);
		remove_party(p); DOUBLE FREE*/
		return 1;
	}

	clock_t t = clock();
	int taep = test_all_enemy_parser();
	double en_time = (double)(clock() - t)/CLOCKS_PER_SEC;
	int taeqp = test_all_equip_parser();
	double eq_time = (double)(clock() - t)/CLOCKS_PER_SEC;
	int tacp = test_all_class_parser();
	double cl_time = (double)(clock() - t)/CLOCKS_PER_SEC;
	int tapue = test_all_party_unequip();
	double pa_time = (double)(clock() - t)/CLOCKS_PER_SEC;
	printf("\nTEST ALL RESULTS\n");
	printf("ENEMY PARSING: ");
	if(taep == 1)
	{
		printf("PASSED | ");
		printf("Runtime: %.6fs\n", en_time);
	}
	else
	{
		printf("FAILED\n");
	}
	printf("EQUIP PARSING: ");
	if(taeqp == 1)
	{
		printf("PASSED | ");
		printf("Runtime: %.6fs\n", eq_time-en_time);
	}
	else
	{
		printf("FAILED\n");
	}
	printf("CLASS PARSING: ");
	if(tacp == 1)
	{
		printf("PASSED | ");
		printf("Runtime: %.6fs\n", cl_time-eq_time);
	}
	else
	{
		printf("FAILED\n");
	}
	printf("PARTY EQ/UNEQ: ");
	if(tapue == 1)
	{
		printf("PASSED | ");
		printf("Runtime: %.6fs\n", pa_time-cl_time);
	}
	else
	{
		printf("FAILED\n");
	}
}

// Print Credits //
void print_credits()
{
	printf("Project: EOCurses\n");
	printf("Description: A port of Etrian Odyssey to curses\n");
	printf("License: GNU General Public License v3.0\n");
	printf("Author: Alex Barney\n");
	printf("Website: http://www.alexbarney.xyz\n");
	printf("Upstream URL: https://github.com/electra13x7777/EOCurses\n");
}

enum tests
{
	EXT,
	ENP,
	EQP,
	EQC,
	TCP,
	TCC,
	CWE,
	CUE,
	TPP,
	TMP,
	TBS,
	TTO,
	TSP,
	TAE,
	TAL,
	PT,
	PC
};

int main(int argc, char **argv)
{
	int t;
	TEST:
	printf("EOCURSES TEST SUITE\n");
	printf("1  | Test Enemy Parser\n");
	printf("2  | Test Equip Parser\n");
	printf("3  | Test Equip Creator\n");
	printf("4  | Test Class Parser\n");
	printf("5  | Test Class Creator\n");
	printf("6  | Test Class With Equip\n");
	printf("7  | Test Class Unequip\n");
	printf("8  | Test Party Parser\n");
	printf("9  | Test Music Playback\n");
	printf("10 | Test Battle Simulation (DEPRECATED)\n");
	printf("11 | Test Turn Order\n");
	printf("12 | Test Skill Points\n");
	printf("13 | Test Adding Exp\n");
	printf("14 | Test Everything\n");
	printf("15 | Print Tests\n");
	printf("16 | Print Credits\n");
	printf("0  | Exit Test Suite\n");
	while(1)
	{
		printf("Please enter an integer to run the desired test: ");
		scanf("%d", &t);
		printf("\n");

		if(t == EXT)
		{
			exit(0);
		}
		if(t == ENP)
		{
			test_enemy_parser();
		}
		if(t == EQP)
		{
			test_equip_parser();
		}
		if(t == EQC)
		{
			test_equip_creator();
		}
		if(t == TCP)
		{
			test_class_parser();
		}
		if(t == TCC)
		{
			test_class_creator();
		}
		if(t == CWE)
		{
			test_class_with_equip();
		}
		if(t == CUE)
		{
			test_class_unequip();
		}
		if(t == TPP)
		{
			test_party_parser();
		}
		if(t == TMP)
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
		if(t == TBS)
		{
			sim();
		}
		if(t == TTO)
		{
			test_turn_order();
		}
		if(t == TSP)
		{
			test_skill_points();
		}
		if(t == TAE)
		{
			test_add_exp();
		}
		if(t == TAL)
		{
			test_all();
		}
		if(t == PT)
		{
			goto TEST;
		}
		if(t == PC)
		{
			print_credits();
		}
		printf("\n");
	}
}
