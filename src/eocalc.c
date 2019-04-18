// File: eocalc.c
// Author: Alex Barney
//
// Description: Damage calculator for Etrian Odyssey.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

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

// Function: create_class
// Return: struct class*
// Description: Wraps around init_class to have a user create a class
struct class* create_class()
{
	char name[BUFFER];
	int lv, hp, tp, str, tec, vit, agi, luc;
	int e1, e2, e3, e4;

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
	printf("Enter Equip 1: ");
	scanf("%d", &e1);
	getchar();
	printf("Enter Equip 2: ");
	scanf("%d", &e2);
	getchar();
	printf("Enter Equip 3: ");
	scanf("%d", &e3);
	getchar();
	printf("Enter Equip 4: ");
	scanf("%d", &e4);
	getchar();
	printf("\n");

	return init_class(name, lv, hp, tp, str, tec, vit, agi, luc, e1, e2, e3, e4);
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

int main()
{
	printf("Working on a stable build\n");
	printf("To test current functionality run pkg/eoctest\n");
}
