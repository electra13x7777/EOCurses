// File: class.c
// Author: Alex Barney
//
// Description: Defines class.h.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "class.h"
#include "equip.h"

#define BUFFER 999

// Function: init_equipment
// Return: struct equipment*
// Description: Creates a new instance of an equipment structure
struct equipment* init_equipment()
{
	struct equipment *new =(struct equipment*)malloc(sizeof(struct equipment*));
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
		//pos-=1;
		//c = (struct class*) realloc(c, sizeof(c)+56);
		//c->equipment[pos] = e;
		switch(pos)
		{
			case(1):
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
		}
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
	struct class *new = (struct class*) malloc(80);
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
	add_equip(new, parse_equip(1), 1);
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
