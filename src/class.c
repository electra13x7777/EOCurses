// File: class.c
// Author: Alex Barney
//
// Description: Defines class.h.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "class.h"
#include "equip.h"

#define BUFFER 999

// Function: init_equipment
// Return: struct equipment*
// Description: Creates a new instance of an equipment structure
struct equipment* init_equipment()
{
	struct equipment *new = (struct equipment*) malloc(32);
	//new->e1 = NULL;
	//new->e2 = NULL;
	//new->e3 = NULL;
	//new->e4 = NULL;
	return new;
}

// Function: add_equip
// Return: void
// Description: Adds an equip structure to a class
//				pos = 1 - 4
void add_equip(struct class *c, struct equip *e, int pos)
{
	int can_equip = 0;
	for(int i = 0; i < strlen(e->classes); i++)
	{
		if(c->name[0] == e->classes[i])
		{
			can_equip = 1;
		}
	}
	if(can_equip)
	{
		/*
		int e1_b = c->equips->e1 != NULL;
		int e2_b = c->equips->e2 != NULL;
		int e3_b = c->equips->e3 != NULL;
		int e4_b = c->equips->e4 != NULL;
		void *temp;*/
		//pos-=1;
		//c = (struct class*) realloc(c, sizeof(c)+56);
		//c->equipment[pos] = e;
		/*switch(pos)
		{
			case(1):
				if(e2_b == 0)
				{
					c->equips->e1 = e;
					c->equips->e2 = NULL;
				}
				else
				{
					temp = (void*) c->equips->e2;
					c->equips->e1 = e;
					c->equips->e2 = (struct equip*) temp;
				}
				c->equips->e1 = e;
				break;
			case(2):
				c->equips->e2 = e;
				break;
			case(3):
				c->equips->e3 = e;
				break;
			case(4):
				c->equips->e4 = e;
				break;
		}*/
		// Update stats //
		c->stats[0] += e->stats[0];
		c->stats[1] += e->stats[1];
		c->stats[2] += e->stats[2];
		c->stats[3] += e->stats[3];
		c->stats[4] += e->stats[4];
		c->stats[5] += e->stats[5];
		c->stats[6] += e->stats[6];
		c->atk += e->stats[2] + e->atk;
		c->def += e->stats[4] + e->def;
	}
}



// Function: init_class
// Return: struct class*
// Description: Creates a new instance of a class structure
struct class* init_class(char *name, int lv, int hp, int tp, int st, int te,
		int vi, int ag, int lu)
{
	struct class *new = (struct class*) malloc(104);
	new->name = name;
	new->lv = lv;
	memset(new->stats, 0, 6);
	// set stats
	new->stats[0] = hp;
	new->stats[1] = tp;
	new->stats[2] = st;
	new->stats[3] = te;
	new->stats[4] = vi;
	new->stats[5] = ag;
	new->stats[6] = lu;
	// set battle stats
	new->atk = new->stats[2];
	new->def = new->stats[4];
	new->equips = init_equipment();
	// add equip
	//add_equip(new, parse_equip(1), 1);
	new->skills[0] = 0;
	new->skills[1] = 0;
	new->skills[2] = 0;
	new->skills[3] = 0;
	new->skills[4] = 0;
	new->skills[5] = 0;
	new->skills[6] = 0;
	new->skills[7] = 0;
	new->skills[8] = 0;
	new->skills[9] = 0;
	new->skills[10] = 0;
	new->skills[11] = 0;
	new->skills[12] = 0;
	new->skills[13] = 0;
	new->skills[14] = 0;
	new->skills[15] = 0;
	new->skills[16] = 0;
	new->skills[17] = 0;
	new->skills[18] = 0;
	new->skills[19] = 0;
	new->skills[20] = 0;
	return new;
}

// Function: parse_class
// Return: struct class*
// Decription: Parses a given file pointer and creates a new class structure
struct class* parse_class(char *fn, int line)
{
	char str[BUFFER*3];
	FILE *fp = fopen(fn, "r");
	int count = 0;
	int pos = 0;
	char* name;
	char* lv;
	char* hp;
	char* tp;
	char* st;
	char* te;
	char* vi;
	char* ag;
	char* lu;
	if(fp != NULL)
	{
		while(count<line)
		{
			fgets(str, sizeof(str), fp);
			count++;
		}
		char *tok = strtok(str, ",");

		while(pos != 9)
		{
			if(pos == 0)
			{
				name = tok;
			}
			if(pos == 1)
			{
				lv = tok;
			}
			if(pos == 2)
			{
				hp = tok;
			}
			if(pos == 3)
			{
				tp = tok;
			}
			if(pos == 4)
			{
				st = tok;
			}
			if(pos == 5)
			{
				te = tok;
			}
			if(pos == 6)
			{
				vi = tok;
			}
			if(pos == 7)
			{
				ag = tok;
			}
			if(pos == 8)
			{
				lu = tok;
			}
			pos++;
			tok = strtok(NULL, ",");
		}
	}
	fclose(fp);
	return init_class(name, atoi(lv), atoi(hp), atoi(tp), atoi(st), atoi(te),
			atoi(vi), atoi(ag), atoi(lu));
}

// Function: parse_equipment
// Return: struct equipment*
// Description: Parses equips into an equipment structure held in a class
struct equipment* parse_equipment(struct class *c,int l1,int l2,int l3,int l4)
{
	int check_can_equip(struct class *c, struct equip *e)
	{
		int can_equip = 0;
		for(int i = 0; i < strlen(e->classes); i++)
		{
			if(c->name[0] == e->classes[i])
			{
				can_equip = 1;
			}
		}
		return can_equip;
	}

	void update_stats(struct class *c, struct equip *e)
	{
		c->stats[0] += e->stats[0];
		c->stats[1] += e->stats[1];
		c->stats[2] += e->stats[2];
		c->stats[3] += e->stats[3];
		c->stats[4] += e->stats[4];
		c->stats[5] += e->stats[5];
		c->stats[6] += e->stats[6];
		c->atk += e->stats[2] + e->atk;
		c->def += e->stats[4] + e->def;
	}

	struct equipment *eq = init_equipment();
	struct equip *e1 = parse_equip(l1);
	char e1name[BUFFER*2];
	char e1classes[BUFFER*2];
	char e2name[BUFFER*2];
	char e2classes[BUFFER*2];
	char e3name[BUFFER*2];
	char e3classes[BUFFER*2];
	char e4name[BUFFER*2];
	char e4classes[BUFFER*2];
	if(check_can_equip(c, e1))
	{
		eq->e1 = e1;
		strcpy(e1name, eq->e1->name);
		strcpy(e1classes, eq->e1->classes);
		update_stats(c,e1);
	}
	struct equip *e2 = parse_equip(l2);
	if(check_can_equip(c, e2))
	{
		eq->e2 = e2;
		strcpy(e2name, eq->e2->name);
		strcpy(e2classes, eq->e2->classes);
		update_stats(c,e2);
	}
	struct equip *e3 = parse_equip(l3);
	if(check_can_equip(c, e3))
	{
		eq->e3 = e3;
		strcpy(e3name, eq->e3->name);
		strcpy(e3classes, eq->e3->classes);
		update_stats(c,e3);
	}
	struct equip *e4 = parse_equip(l4);
	if(check_can_equip(c, e4))
	{
		eq->e4 = e4;
		strcpy(e4name, eq->e4->name);
		strcpy(e4classes, eq->e4->classes);
		update_stats(c,e4);
	}
	eq->e1->name = e1name;
	eq->e1->classes = e1classes;
	eq->e2->name = e2name;
	eq->e2->classes = e2classes;
	eq->e3->name = e3name;
	eq->e3->classes = e3classes;
	eq->e4->name = e4name;
	eq->e4->classes = e4classes;
	return eq;
}

// Function: create_class
// Return: struct class*
// Description: Wraps around init_class to have a user create a class
struct class* create_class()
{
	char name[BUFFER];
	int lv, hp, tp, str, tec, vit, agi, luc;

	printf("Class Creator\n");
	printf("Enter Class: ");
	scanf("%s", name);
	getchar();
	printf("Enter Level: ");
	scanf("%d", &lv);
	getchar();
	printf("Enter HP: ");
	scanf("%d", &hp);
	getchar();
	printf("Enter TP: ");
	scanf("%d", &tp);
	getchar();
	printf("Enter STR: ");
	scanf("%d", &str);
	getchar();
	printf("Enter TEC: ");
	scanf("%d", &tec);
	getchar();
	printf("Enter VIT: ");
	scanf("%d", &vit);
	getchar();
	printf("Enter AGI: ");
	scanf("%d", &agi);
	getchar();
	printf("Enter LUC: ");
	scanf("%d", &luc);
	getchar();
	printf("\n");

	return init_class(name, lv, hp, tp, str, tec, vit, agi, luc);
}

// Function: remove_class
// Return: void
// Description: Frees an allocated class
void remove_class(struct class *c)
{

	if(c->equips->e1 != NULL)
	{
		remove_equip(c->equips->e1);
	}
	if(c->equips->e2 != NULL)
	{
		remove_equip(c->equips->e2);
	}
	if(c->equips->e3 != NULL)
	{
		remove_equip(c->equips->e3);
	}
	if(c->equips->e4 != NULL)
	{
		remove_equip(c->equips->e4);
	}
	//printf("%d\n", sizeof(c->equips->e1)*4);
	//printf("%d\n", c->equips->e2 != NULL);
	//remove_equip(c->equips->e1);
	free(c->equips);
	free(c);
}

// Function: print_class
// Return: void
// Description: Prints a given class structure
void print_class(struct class *c)
{
	printf("Class: %s\n", c->name);
	printf("Level: %d\n", c->lv);
	printf("Health: %d\n", c->stats[0]);
	printf("TP: %d\n", c->stats[1]);
	printf("STR: %d\n", c->stats[2]);
	printf("TEC: %d\n", c->stats[3]);
	printf("VIT: %d\n", c->stats[4]);
	printf("AGI: %d\n", c->stats[5]);
	printf("LUC: %d\n", c->stats[6]);
	printf("Attack: %d\n", c->atk);
	printf("Defense: %d\n", c->def);
}

void level_up(struct class *c)
{
	return;
}

void invest_sp(struct class *c, int pos)
{
	if(c->name[0] == 'L' && c->sp > 0)
	{
		switch(pos)
		{
			case(0): // la_hp_up
				if(c->skills[0] < 10)
				{
					c->skills[0] += 1;
					c->sp--;
				}
				break;
			case(1): // la_tp_up
				if(c->skills[1] < 10)
				{
					c->skills[1] += 1;
					c->sp--;
				}
				break;
			case(2): // la_atk_up
				if(c->skills[2] < 10)
				{
					c->skills[2] += 1;
					c->sp--;
				}
				break;
			case(3): // la_def_up
				if(c->skills[3] < 10)
				{
					c->skills[3] += 1;
					c->sp--;
				}
				break;
			case(4): // la_axes
				if(c->skills[4] < 10)
				{
					c->skills[4] += 1;
					c->sp--;
				}
				break;
			case(5): // la_swords
				if(c->skills[5] < 10)
				{
					c->skills[5] += 1;
					c->sp--;
				}
				break;
			case(6): // 2_hit
				if(c->skills[4] >= 5 && c->skills[5] >= 5)
				{
					if(c->skills[6] < 10)
					{
						c->skills[6] += 1;
						c->sp--;
					}
				}
				break;
			case(7): // war_cry
				if(c->skills[2] >= 3)
				{
					if(c->skills[7] < 10)
					{
						c->skills[7] += 1;
						c->sp--;
					}
				}
				break;
			case(8): // hell_cry
				if(c->skills[2] == 10)
				{
					if(c->skills[8] < 10)
					{
						c->skills[8] += 1;
						c->sp--;
					}
				}
				break;
			case(9): // arm_heal
				if(c->skills[3] >= 1)
				{
					if(c->skills[9] < 10)
					{
						c->skills[9] += 1;
						c->sp--;
					}
				}
				break;
			case(10): // flee
				if(c->skills[3] >= 5)
				{
					if(c->skills[10] < 10)
					{
						c->skills[10] += 1;
						c->sp--;
					}
				}
				break;
			case(11): // cleaver
				if(c->skills[5] >= 1)
				{
					if(c->skills[11] < 10)
					{
						c->skills[11] += 1;
						c->sp--;
					}
				}
				break;
			case(12): // tornado
				if(c->skills[5] >= 5)
				{
					if(c->skills[12] < 10)
					{
						c->skills[12] += 1;
						c->sp--;
					}
				}
				break;
			case(13): // allslash
				if(c->skills[5] >= 5 && c->skills[6] >= 3)
				{
					if(c->skills[13] < 10)
					{
						c->skills[13] += 1;
						c->sp--;
					}
				break;
			case(14): // blazer
				if(c->skills[5] >= 7 && c->skills[1] >= 3)
				{
					if(c->skills[14] < 10)
					{
						c->skills[14] += 1;
						c->sp--;
					}
				}
				break;
			case(15): // freezer
				if(c->skills[5] >= 7 && c->skills[1] >= 3)
				{
					if(c->skills[15] < 10)
					{
						c->skills[15] += 1;
						c->sp--;
					}
				}
				break;
			case(16): // shocker
				if(c->skills[5] >= 7 && c->skills[1] >= 3)
				{
					if(c->skills[16] < 10)
					{
						c->skills[16] += 1;
						c->sp--;
					}
				}
				break;
			case(17): // crush
				if(c->skills[4] >= 1)
				{
					if(c->skills[17] < 10)
					{
						c->skills[17] += 1;
						c->sp--;
					}
				}
				break;
			case(18): // stunner
				if(c->skills[5] >= 3)
				{
					if(c->skills[18] < 10)
					{
						c->skills[18] += 1;
						c->sp--;
					}
				}
				break;
			case(19): // silencer
				if(c->skills[5] >= 7)
				{
					if(c->skills[19] < 10)
					{
						c->skills[19] += 1;
						c->sp--;
					}
				}
				break;
			case(20): // mine
				if(c->skills[20] < 10)
				{
					c->skills[20] += 1;
					c->sp--;
				}
				break;
		}
	}
	}
}
