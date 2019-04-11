// File: eocalc// Author: Alex Barney
//
// Description: Damage calculator for Etrian Odyssey,Etrian Odyssey 2,
//              and Etrian Odyssey 3.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "enemy.h"

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
	printf("%s\n", "File Opened");
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
		printf("Enemy Data: %s", str);
		char *tok = strtok(str, ",");
		printf("Parsing...\n");
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
	printf("Parsing Complete\n");
	fclose(fp);
	printf("%s\n\n", "File Closed");
	return init_enemy(name, atoi(hp), atoi(at), atoi(df));
}

// Function: print_enemy
// Return: void
// Description: Prints a given enemy structure
void print_enemy(struct enemy *e)
{
	printf("Name: %s\n", e->name);
	printf("Health: %d\n", e->hp);
	printf("Attack: %d\n", e->at);
	printf("Defense: %d\n", e->df);
}

int main()
{
	//init_enemy("Treerat", 19, 10, 14);
	struct enemy *e = parse_enemy(Golem_e);
	print_enemy(e);
}
