#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "equip.h"

#define BUFFER 999

// Function: init_equip
// Return: struct equip*
// Description: Creates a new instance of an equip structure
struct equip* init_equip(char* classes, char* name, int hp, int tp, int st,
		int te, int vi, int ag, int lu, int type, int atk, int def)
{
	struct equip *new = (struct equip*) malloc(56);
	new->classes = classes;
	new->name = name;
	new->stats[0] = hp;
	new->stats[1] = tp;
	new->stats[2] = st;
	new->stats[3] = te;
	new->stats[4] = vi;
	new->stats[5] = ag;
	new->stats[6] = lu;
	new->type = type;
	new->atk = atk;
	new->def = def;
	return new;
}

// Function: parse_equip
// Return: struct equip*
// Description: Parses equips.txt to create a new equip structure
struct equip* parse_equip(int line)
{
	char str[BUFFER*3];
	FILE *fp;
	fp = fopen("src/equips.txt", "r");
	//printf("file opened\n");
	int count = 0;
	int pos = 0;
	char* classes;// = (char*) malloc(sizeof(BUFFER));
	char* name;// = (char*) malloc(sizeof(BUFFER));
	char* type;
	char* hp;
	char* tp;
	char* st;
	char* te;
	char* vi;
	char* ag;
	char* lu;
	char* atk;
	char* def;
	if(fp != NULL)
	{
		while(count<line)
		{
			fgets(str, sizeof(str), fp);
			count++;
		}
		char *tok = strtok(str, ",");

		while(pos != 12)
		{
			if(pos == 0)
			{
				classes = tok;
			}
			if(pos == 1)
			{
				name = tok;
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
			if(pos == 9)
			{
				atk = tok;
			}
			if(pos == 10)
			{
				def = tok;
			}
			if(pos == 11)
			{
				type = tok;
			}
			pos++;
			tok = strtok(NULL, ",");
		}
	}
	fclose(fp);
	return init_equip(classes, name, atoi(hp), atoi(tp), atoi(st), atoi(te),
			atoi(vi), atoi(ag), atoi(lu), atoi(type), atoi(atk), atoi(def));
}

// Function: remove_equip
// Return: void
// Description: Frees an allocated equip
void remove_equip(struct equip *e)
{
	free(e);
}

// Function: create_equip
// Return: struct equip*
// Description: Wrapes around init_equip to have the user create an equip
struct equip* create_equip()
{
	int type, hp, tp, st, te, vi, ag, lu, atk, def;
	char name[BUFFER];
	char classes[BUFFER];

	printf("Equip Creator\n");
	printf("Enter Type: ");
	scanf("%d", &type);
	getchar();
	printf("Enter Name: ");
	scanf("%s", name);
	getchar();
	printf("Enter HP: ");
	scanf("%d", &hp);
	getchar();
	printf("Enter TP: ");
	scanf("%d", &tp);
	getchar();
	printf("Enter STR: ");
	scanf("%d", &st);
	getchar();
	printf("Enter TEC: ");
	scanf("%d", &te);
	getchar();
	printf("Enter VIT: ");
	scanf("%d", &vi);
	getchar();
	printf("Enter AGI: ");
	scanf("%d", &ag);
	getchar();
	printf("Enter LUC: ");
	scanf("%d", &lu);
	getchar();
	printf("Enter ATK: ");
	scanf("%d", &atk);
	getchar();
	printf("Enter DEF: ");
	scanf("%d", &def);
	getchar();
	printf("Enter Equipable Classes: ");
	scanf("%s", classes);
	getchar();
	printf("\n");

	return init_equip(classes, name, hp, tp, st, te, vi, ag, lu, type, atk, def);
}

// Function: print_equip
// Return: void
// Description: Prints a given equip structure
void print_equip(struct equip *e)
{
	printf("TYPE: %d\n", e->type);
	printf("NAME: %s\n", e->name);
	printf("HP: %d\n", e->stats[0]);
	printf("TP: %d\n", e->stats[1]);
	printf("STR: %d\n", e->stats[2]);
	printf("TEC: %d\n", e->stats[3]);
	printf("VIT: %d\n", e->stats[4]);
	printf("AGI: %d\n", e->stats[5]);
	printf("LUC: %d\n", e->stats[6]);
	printf("ATK: %d\n", e->atk);
	printf("DEF: %d\n", e->def);
	printf("EQUIPED BY: %s\n", e->classes);
}

/*
int main()
{
	//printf("%d\n", sizeof(int)*10 + sizeof(char*)*2);
	print_equip(parse_equip(1));
	//printf("%d\n", sizeof(init_equip("ALDS", "Sword", 1,1,1,1,1,1,1,2,3,4)));
}*/
