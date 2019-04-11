#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "enemy.h"

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

struct enemy* parse()
{
	char str[999];
	FILE *fp;
	fp = fopen("enemies.txt", "r");
	printf("%s\n", "File Opened");
	int count = 0;
	char *name;
    char *hp;
   	char *at;
   	char *df;
	if(fp != NULL)
	{
		fgets(str, sizeof(str), fp);
		printf("%s\n", str);
		char *tok = strtok(str, ",");
		while(count != 4)
		{
			if(count == 0)
			{
				name = tok;
				printf("%s\n", tok);
			}
			if(count == 1)
			{
				hp = tok;
				printf("%s\n", tok);
			}
			if(count == 2)
			{
				at = tok;
				printf("%s\n", tok);
			}
			if(count == 3)
			{
				df = tok;
				printf("%s\n", tok);
			}
			count++;
			printf("%d\n", count);
			tok = strtok(NULL, ",");
		}
	}
	fclose(fp);
	printf("%s\n", "File Closed");
	return init_enemy(name, atoi(hp), atoi(at), atoi(df));
}

void print_enemy(struct enemy *e)
{
	printf("Name: %s\n", e->name);
	printf("Health: %d\n", e->hp);
	printf("Attack: %d\n", e->at);
	printf("Defense: %d\n", e->df);
}

int main()
{
	printf("\n");
	struct enemy *treerat = parse();//init_enemy("Treerat", 19, 10, 14);
	print_enemy(treerat);
}
