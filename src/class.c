// File: class.c
// Author: Alex Barney
//
// Description: Defines class.h

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
	struct equipment *new = (struct equipment*) malloc(sizeof(struct equipment));//32
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

// Function: un_equip
// Return: void
// Description: sets equip structure to NONE and resets stats
//				pos = 1 - 4
void un_equip(struct class *c, int pos)
{
	switch(pos)
	{
		case(1):
			if(c->equips->e1 != NULL)
			{
				c->stats[0] -= c->equips->e1->stats[0];
				c->stats[1] -= c->equips->e1->stats[1];
				c->stats[2] -= c->equips->e1->stats[2];
				c->stats[3] -= c->equips->e1->stats[3];
				c->stats[4] -= c->equips->e1->stats[4];
				c->stats[5] -= c->equips->e1->stats[5];
				c->stats[6] -= c->equips->e1->stats[6];
				c->atk -= c->equips->e1->stats[2] + c->equips->e1->atk;
				c->def -= c->equips->e1->stats[4] + c->equips->e1->def;
				remove_equip(c->equips->e1);
				c->equips->e1 = parse_equip(1);
			}
			break;
		case(2):
			if(c->equips->e2 != NULL)
			{
				c->stats[0] -= c->equips->e2->stats[0];
				c->stats[1] -= c->equips->e2->stats[1];
				c->stats[2] -= c->equips->e2->stats[2];
				c->stats[3] -= c->equips->e2->stats[3];
				c->stats[4] -= c->equips->e2->stats[4];
				c->stats[5] -= c->equips->e2->stats[5];
				c->stats[6] -= c->equips->e2->stats[6];
				c->atk -= c->equips->e2->stats[2] + c->equips->e2->atk;
				c->def -= c->equips->e2->stats[4] + c->equips->e2->def;
				remove_equip(c->equips->e2);
				c->equips->e2 = parse_equip(1);
			}
			break;
		case(3):
			if(c->equips->e3 != NULL)
			{
				c->stats[0] -= c->equips->e3->stats[0];
				c->stats[1] -= c->equips->e3->stats[1];
				c->stats[2] -= c->equips->e3->stats[2];
				c->stats[3] -= c->equips->e3->stats[3];
				c->stats[4] -= c->equips->e3->stats[4];
				c->stats[5] -= c->equips->e3->stats[5];
				c->stats[6] -= c->equips->e3->stats[6];
				c->atk -= c->equips->e3->stats[2] + c->equips->e3->atk;
				c->def -= c->equips->e3->stats[4] + c->equips->e3->def;
				remove_equip(c->equips->e3);
				c->equips->e3 = parse_equip(1);
			}
			break;
		case(4):
			if(c->equips->e4 != NULL)
			{
				c->stats[0] -= c->equips->e4->stats[0];
				c->stats[1] -= c->equips->e4->stats[1];
				c->stats[2] -= c->equips->e4->stats[2];
				c->stats[3] -= c->equips->e4->stats[3];
				c->stats[4] -= c->equips->e4->stats[4];
				c->stats[5] -= c->equips->e4->stats[5];
				c->stats[6] -= c->equips->e4->stats[6];
				c->atk -= c->equips->e4->stats[2] + c->equips->e4->atk;
				c->def -= c->equips->e4->stats[4] + c->equips->e4->def;
				remove_equip(c->equips->e4);
				c->equips->e4 = parse_equip(1);
			}
			break;
	}
}


// Function: init_class
// Return: struct class*
// Description: Creates a new instance of a class structure
struct class* init_class(char *name, int lv, int hp, int tp, int st, int te,
		int vi, int ag, int lu)
{
	struct class *new = (struct class*) malloc(sizeof(struct class));//104
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

// Function: add_exp
// Return: void
// Description: Main logic for gaining exp (INTEGER USED IS NOT FINAL)
void add_exp(struct class *c, unsigned int exp)
{
	int cap = 40 * c->lv;
	c->exp += exp;
	while(c->exp >= cap)
	{
		c->lv++;
		c->sp++;
		cap = 40*c->lv;
	}
}

// Function: invest_sp
// Return: void
// Description: Main logic for investing skill points
void invest_sp(struct class *c, int pos)
{
	if(c->name[0] == 'A' && c->sp > 0) // Alchemist
	{

		switch(pos)
		{
			case(0): // al_tp_up
				if(c->skills[0] < 10)
				{
					c->skills[0] += 1;
					c->sp--;
				}
				break;
			case(1): // fire up
				if(c->skills[1] < 10)
				{
					c->skills[1] += 1;
					c->sp--;
				}
				break;
			case(2): // ice up
				if(c->skills[2] < 10)
				{
					c->skills[2] += 1;
					c->sp--;
				}
				break;
			case(3): // volt up
				if(c->skills[3] < 10)
				{
					c->skills[3] += 1;
					c->sp--;
				}
				break;
			case(4): // toxins
				if(c->skills[4] < 10)
				{
					c->skills[4] += 1;
					c->sp--;
				}
				break;
			case(5): // scavenge
				if(c->skills[0] >= 3)
				{
					if(c->skills[5] < 10)
					{
						c->skills[5] += 1;
						c->sp--;
					}
				}
				break;
			case(6): // tp_regen
				if(c->skills[0] == 10)
				{
					if(c->skills[6] < 10)
					{
						c->skills[6] += 1;
						c->sp--;
					}
				}
				break;
			case(7): // fire
				if(c->skills[1] >= 1)
				{
					if(c->skills[7] < 10)
					{
						c->skills[7] += 1;
						c->sp--;
					}
				}
				break;
			case(8): // flame
				if(c->skills[1] >= 5 && c->skills[8] >= 3)
				{
					if(c->skills[8] < 10)
					{
						c->skills[8] += 1;
						c->sp--;
					}
				}
				break;
			case(9): // inferno
				if(c->skills[8] >= 5)
				{
					if(c->skills[9] < 10)
					{
						c->skills[9] += 1;
						c->sp--;
					}
				}
				break;
			case(10): // ice
				if(c->skills[2] >= 1)
				{
					if(c->skills[10] < 10)
					{
						c->skills[10] += 1;
						c->sp--;
					}
				}
				break;
			case(11): // freeze
				if(c->skills[2] >= 5 && c->skills[8] >= 3)
				{
					if(c->skills[11] < 10)
					{
						c->skills[11] += 1;
						c->sp--;
					}
				}
				break;
			case(12): // cocytus
				if(c->skills[11] >= 5)
				{
					if(c->skills[12] < 10)
					{
						c->skills[12] += 1;
						c->sp--;
					}
				}
				break;
			case(13): // volt
				if(c->skills[3] >= 1)
				{
					if(c->skills[13] < 10)
					{
						c->skills[13] += 1;
						c->sp--;
					}
				}
				break;
			case(14): // thunder
				if(c->skills[3] >= 5 && c->skills[8] >= 3)
				{
					if(c->skills[14] < 10)
					{
						c->skills[14] += 1;
						c->sp--;
					}
				}
				break;
			case(15): // thor
				if(c->skills[14] >= 5)
				{
					if(c->skills[15] < 10)
					{
						c->skills[15] += 1;
						c->sp--;
					}
				}
				break;
			case(16): // poison
				if(c->skills[4] >= 1)
				{
					if(c->skills[16] < 10)
					{
						c->skills[16] += 1;
						c->sp--;
					}
				}
				break;
			case(17): // venom
				if(c->skills[4] >= 5)
				{
					if(c->skills[17] < 10)
					{
						c->skills[17] += 1;
						c->sp--;
					}
				}
				break;
			case(18): // sight
				if(c->skills[0] >= 5)
				{
					if(c->skills[18] < 10)
					{
						c->skills[18] += 1;
						c->sp--;
					}
				}
				break;
			case(19): // warp
				if(c->skills[0] >= 7)
				{
					if(c->skills[19] < 10)
					{
						c->skills[19] += 1;
						c->sp--;
					}
				}
				break;
			case(20): // chop
				if(c->skills[20] < 10)
				{
					c->skills[20] += 1;
					c->sp--;
				}
				break;
		}
	}
	if(c->name[0] == 'D' && c->sp > 0) // Dark Hunter
	{

		switch(pos)
		{
			case(0): // dh_hp_up
				if(c->skills[0] < 10)
				{
					c->skills[0] += 1;
					c->sp--;
				}
				break;
			case(1): // dh_tp_up
				if(c->skills[1] < 10)
				{
					c->skills[1] += 1;
					c->sp--;
				}
				break;
			case(2): // dh_atk_up
				if(c->skills[2] < 10)
				{
					c->skills[2] += 1;
					c->sp--;
				}
				break;
			case(3): // dh_whips
				if(c->skills[3] < 10)
				{
					c->skills[3] += 1;
					c->sp--;
				}
				break;
			case(4): // dh_swords
				if(c->skills[4] < 10)
				{
					c->skills[4] += 1;
					c->sp--;
				}
				break;
			case(5): // dh_boost_up
				if(c->skills[2] >= 3)
				{
					if(c->skills[5] < 10)
					{
						c->skills[5] += 1;
						c->sp--;
					}
				}
				break;
			case(6): // fury
				if(c->skills[2] >= 5)
				{
					if(c->skills[6] < 10)
					{
						c->skills[6] += 1;
						c->sp--;
					}
				}
				break;
			case(7): // cloak
				if(c->skills[1] >= 3)
				{
					if(c->skills[7] < 10)
					{
						c->skills[7] += 1;
						c->sp--;
					}
				}
				break;
			case(8): // viper
				if(c->skills[3] >= 1)
				{
					if(c->skills[8] < 10)
					{
						c->skills[8] += 1;
						c->sp--;
					}
				}
				break;
			case(9): // gag
				if(c->skills[3] >= 2)
				{
					if(c->skills[9] < 10)
					{
						c->skills[9] += 1;
						c->sp--;
					}
				}
				break;
			case(10): // shackles
				if(c->skills[3] >= 3)
				{
					if(c->skills[10] < 10)
					{
						c->skills[10] += 1;
						c->sp--;
					}
				}
				break;
			case(11): // cuffs
				if(c->skills[3] >= 4)
				{
					if(c->skills[11] < 10)
					{
						c->skills[11] += 1;
						c->sp--;
					}
				}
				break;
			case(12): // ecstasy
				if(c->skills[2] >= 5 && c->skills[3] >= 5)
				{
					if(c->skills[12] < 10)
					{
						c->skills[12] += 1;
						c->sp--;
					}
				}
				break;
			case(13): // climax
				if(c->skills[3] == 10)
				{
					if(c->skills[13] < 10)
					{
						c->skills[13] += 1;
						c->sp--;
					}
				}
				break;
			case(14): // hypnos
				if(c->skills[4] >= 1)
				{
					if(c->skills[14] < 10)
					{
						c->skills[14] += 1;
						c->sp--;
					}
				}
				break;
			case(15): // nerve
				if(c->skills[4] >= 2)
				{
					if(c->skills[15] < 10)
					{
						c->skills[15] += 1;
						c->sp--;
					}
				}
				break;
			case(16): // mirage
				if(c->skills[4] >= 3)
				{
					if(c->skills[16] < 10)
					{
						c->skills[16] += 1;
						c->sp--;
					}
				}
				break;
			case(17): // drain
				if(c->skills[4] >= 4)
				{
					if(c->skills[17] < 10)
					{
						c->skills[17] += 1;
						c->sp--;
					}
				}
				break;
			case(18): // bait
				if(c->skills[2] >= 5 && c->skills[4] >= 5)
				{
					if(c->skills[18] < 10)
					{
						c->skills[18] += 1;
						c->sp--;
					}
				}
				break;
			case(19): // petrify
				if(c->skills[4] == 10)
				{
					if(c->skills[17] < 10)
					{
						c->skills[17] += 1;
						c->sp--;
					}
				}
				break;
			case(20): // take
				if(c->skills[20] < 10)
				{
					c->skills[20] += 1;
					c->sp--;
				}
				break;
		}
	}
	if(c->name[0] == 'L' && c->sp > 0) // Landsknecht
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
	if(c->name[0] == 'S' && c->sp > 0) // Survivalist
	{

		switch(pos)
		{
			case(0):
				break;
			case(1):
				break;
			case(2):
				break;
			case(3):
				break;
			case(4):
				break;
			case(5):
				break;
			case(6):
				break;
			case(7):
				break;
			case(8):
				break;
			case(9):
				break;
			case(10):
				break;
			case(11):
				break;
			case(12):
				break;
			case(13):
				break;
			case(14):
				break;
			case(15):
				break;
			case(16):
				break;
			case(17):
				break;
			case(18):
				break;
			case(19):
				break;
			case(20):
				break;
		}
	}
	if(c->name[0] == 'T' && c->sp > 0) // Troubadour
	{

		switch(pos)
		{
			case(0):
				break;
			case(1):
				break;
			case(2):
				break;
			case(3):
				break;
			case(4):
				break;
			case(5):
				break;
			case(6):
				break;
			case(7):
				break;
			case(8):
				break;
			case(9):
				break;
			case(10):
				break;
			case(11):
				break;
			case(12):
				break;
			case(13):
				break;
			case(14):
				break;
			case(15):
				break;
			case(16):
				break;
			case(17):
				break;
			case(18):
				break;
			case(19):
				break;
			case(20):
				break;
		}
	}
	if(c->name[0] == 'M' && c->sp > 0) // Medic
	{

		switch(pos)
		{
			case(0):
				break;
			case(1):
				break;
			case(2):
				break;
			case(3):
				break;
			case(4):
				break;
			case(5):
				break;
			case(6):
				break;
			case(7):
				break;
			case(8):
				break;
			case(9):
				break;
			case(10):
				break;
			case(11):
				break;
			case(12):
				break;
			case(13):
				break;
			case(14):
				break;
			case(15):
				break;
			case(16):
				break;
			case(17):
				break;
			case(18):
				break;
			case(19):
				break;
			case(20):
				break;
		}
	}
	if(c->name[0] == 'R' && c->sp > 0) // Ronin
	{

		switch(pos)
		{
			case(0):
				break;
			case(1):
				break;
			case(2):
				break;
			case(3):
				break;
			case(4):
				break;
			case(5):
				break;
			case(6):
				break;
			case(7):
				break;
			case(8):
				break;
			case(9):
				break;
			case(10):
				break;
			case(11):
				break;
			case(12):
				break;
			case(13):
				break;
			case(14):
				break;
			case(15):
				break;
			case(16):
				break;
			case(17):
				break;
			case(18):
				break;
			case(19):
				break;
			case(20):
				break;
		}
	}
	if(c->name[0] == 'H' && c->sp > 0) // Hexer
	{

		switch(pos)
		{
			case(0):
				break;
			case(1):
				break;
			case(2):
				break;
			case(3):
				break;
			case(4):
				break;
			case(5):
				break;
			case(6):
				break;
			case(7):
				break;
			case(8):
				break;
			case(9):
				break;
			case(10):
				break;
			case(11):
				break;
			case(12):
				break;
			case(13):
				break;
			case(14):
				break;
			case(15):
				break;
			case(16):
				break;
			case(17):
				break;
			case(18):
				break;
			case(19):
				break;
			case(20):
				break;
		}
	}
	if(c->name[0] == 'P' && c->sp > 0) // Protector
	{

		switch(pos)
		{
			case(0):
				break;
			case(1):
				break;
			case(2):
				break;
			case(3):
				break;
			case(4):
				break;
			case(5):
				break;
			case(6):
				break;
			case(7):
				break;
			case(8):
				break;
			case(9):
				break;
			case(10):
				break;
			case(11):
				break;
			case(12):
				break;
			case(13):
				break;
			case(14):
				break;
			case(15):
				break;
			case(16):
				break;
			case(17):
				break;
			case(18):
				break;
			case(19):
				break;
			case(20):
				break;
		}
	}}
}
