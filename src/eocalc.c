// File: eocalc.c
// Author: Alex Barney
//
// Description: Damage calculator for Etrian Odyssey.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "enemy.h"
#include "class.h"
#include "attack.h"

#define BUFFER 999

// Function: init_enemy
// Return: struct enemy*
// Description: Creates a new instance of an enemy structure
struct enemy* init_enemy(char* name, int hp, int at, int df)
{
	struct enemy *new = (struct enemy*) malloc(sizeof(struct enemy*));
	new->name = name;
	new->hp = hp;
	new->at = at;
	new->df = df;
	return new;
}

// Function: parse_enemy
// Return: struct enemy*
// Description: Creates a new instance of an enemy structure
struct enemy* parse_enemy(int line)
{
	char str[BUFFER];
	FILE *fp;
	fp = fopen("src/enemies.txt", "r");
	//printf("%s\n", "File Opened");
	int count = 0;
	int pos = 0;
	char *name;
	char *hp;
   	char *at;
   	char *df;
	if(fp != NULL)
	{
		while(count<line)
		{
			fgets(str, sizeof(str), fp);
			count++;
		}
		//printf("Enemy Data: %s", str);
		char *tok = strtok(str, ",");
		//printf("Parsing...\n");
		while(pos != 4)
		{
			if(pos == 0)
			{
				name = tok;
			//	printf("%s\n", tok);
			}
			if(pos == 1)
			{
				hp = tok;
			//	printf("%s\n", tok);
			}
			if(pos == 2)
			{
				at = tok;
			//	printf("%s\n", tok);
			}
			if(pos == 3)
			{
				df = tok;
			//	printf("%s\n", tok);
			}
			pos++;
			//printf("%d\n", pos);
			tok = strtok(NULL, ",");
		}
	}
	//printf("Parsing Complete\n");
	fclose(fp);
	//printf("%s\n\n", "File Closed");
	return init_enemy(name, atoi(hp), atoi(at), atoi(df));
}

// Function: remove_enemy
// Return: void
// Description: Frees an allocated enemy
void remove_enemy(struct enemy *e)
{
	free(e);
}

// Function: print_enemy
// Return: void
// Description: Prints a given enemy structure
void print_enemy(struct enemy *e)
{
	printf("Enemy: %s\n", e->name);
	printf("Health: %d\n", e->hp);
	printf("Attack: %d\n", e->at);
	printf("Defense: %d\n", e->df);
}

// Function: init_class
// Return: struct class*
// Description: Creates a new instance of a class structure
struct class* init_class(char *name, int lv, int hp, int tp, int st, int te,
		int vi, int ag, int lu, int e1, int e2, int e3, int e4)
{
	struct class *new = (struct class*) malloc(68);
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
	// set equips
	new->equip[0] = e1;
	new->equip[1] = e2;
	new->equip[2] = e3;
	new->equip[3] = e4;
	// set battle stats
	new->atk = new->stats[2] + new->equip[0];
	new->def = new->stats[4] + new->equip[1];
	return new;
}

// Function: remove_class
// Return: void
// Description: Frees an allocated class
void remove_class(struct class *c)
{
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

// Function: damage
// Return: int
// Description: Skill damage algorithm
int damage(int atk, int sp, float skillmul, float buffs, float passives,
		int hits, int def)
{
	int d = (int)((float)(atk * ((sp * skillmul) + (buffs * passives)) * sqrt(atk/def)));
	d *= hits;
	return d;
}

// PLACEHOLDER //
void attack(struct enemy *e, struct class *c)
{
	return;
}

int main()
{
	// test simulation
	struct class *l = init_class("Landsknecht", 30, 200, 48, 39, 27, 39, 31, 39, 45, 20, 0, 0);
	print_class(l);
	printf("\n");
	struct enemy *e = parse_enemy(Fenrir_e);
	print_enemy(e);
	printf("\n");
	printf("%s used All Slash\n", l->name);
	int cd = damage(l->atk, 3, .04, 1.1, 1.12, 2, e->df);
	printf("%s deals %d damage to %s\n", l->name, cd, e->name);
	e->hp -= cd;
	printf("\n");
	print_enemy(e);
	printf("\n%s attacks\n", e->name);
	int ed = ((int)(sqrt(e->at/l->def)) * e->at) - (l->def);
	printf("%s deals %d damage to %s\n\n", e->name, ed, l->name);
	l->stats[0] -= ed;
	print_class(l);
	remove_class(l);
	remove_enemy(e);
}
