// File: party.c
// Author: Alex Barney
//
// Description: Defines party.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "party.h"
#include "equip.h"
#include "class.h"

#define BUFFER 999

// Function: init_pmap
// Return: struct pmap*
// Description: Creates a new instance of a pmap structure
struct pmap* init_pmap(struct class *c, int pos)
{
	struct pmap *new = (struct pmap*) malloc(sizeof(struct pmap*));
	new->c = c;
	new->pos = pos;
	return new;
}

// Function: init_party()
// Return: struct party*
// Description: Creates a new instance of a party structure
struct party* init_party()
{
	struct party *new = (struct party*) malloc(40); //48
	/*new->front[0] = NULL;
	new->front[1] = NULL;
	new->front[2] = NULL;
	new->back[0] = NULL;
	new->back[1] = NULL;
	new->back[2] = NULL;*/
	return new;
}

// Function: parse_party
// Return: struct party*
// Description: Wraps around parse_class to build a party
struct party* parse_party(char *fn)
{
	//printf("test");
	char str[BUFFER];
	//FILE *fp = fopen(fn, "r");
	int count = 0;
	int pos = 0;
	int num = 6;
	int f = 0;
	int b = 0;
	/*
	int pos1, pos2, pos3, pos4, pos5;

	while(fp != NULL)
	{
		while(count<num)
		{
			fgets(str, sizeof(str), fp);
			count++;
		}
		char *tok = strtok(str, ",");

		while(pos != 5)
		{
			if(pos == 0)
			{
				pos1 = atoi(tok);
			}
			if(pos == 1)
			{
				pos2 = atoi(tok);
			}
			if(pos == 2)
			{
				pos3 = atoi(tok);
			}
			if(pos == 3)
			{
				pos4 = atoi(tok);
			}
			if(pos == 4)
			{
				pos5 = atoi(tok);
			}
			pos++;
			strtok(NULL, ",");
		}
	}
	fclose(fp);
	printf("file closed");
	int partypos[5] = {pos1, pos2, pos3, pos4, p5};
*/
	int partypos[5] = {0,0,0,1,1}; // Test Array
	struct party *p = init_party();
	struct pmap *p1 = init_pmap(parse_class(fn, 1), partypos[0]);
	char p1name[BUFFER*2];
	strcpy(p1name, p1->c->name);
	struct pmap *p2 = init_pmap(parse_class(fn, 2), partypos[1]);
	char p2name[BUFFER*2];
	strcpy(p2name, p2->c->name);
	struct pmap *p3 = init_pmap(parse_class(fn, 3), partypos[2]);
	char p3name[BUFFER*2];
	strcpy(p3name, p3->c->name);
	struct pmap *p4 = init_pmap(parse_class(fn, 4), partypos[3]);
	char p4name[BUFFER*2];
	strcpy(p4name, p4->c->name);
	struct pmap *p5 = init_pmap(parse_class(fn, 5), partypos[4]);
	char p5name[BUFFER*2];
	strcpy(p5name, p5->c->name);
	getchar();
	//char p6name[BUFFER*2];
	//strcpy(p6name, p5->c->name); //Awful solution but fixes buffer issue
	p->p1 = p1;
	p->p2 = p2;
	p->p3 = p3;
	p->p4 = p4;
	p->p5 = p5;
	p->p1->c->name = p1name;
	p->p2->c->name = p2name;
	p->p3->c->name = p3name;
	p->p4->c->name = p4name;

	p->p1->c->equips = parse_equipment(p->p1->c, 1, 1, 1, 1);
	p->p2->c->equips = parse_equipment(p->p2->c, 1, 1, 1, 1);
	p->p3->c->equips = parse_equipment(p->p3->c, 1, 1, 1, 1);
	p->p4->c->equips = parse_equipment(p->p4->c, 1, 1, 1, 1);
	p->p5->c->equips = parse_equipment(p->p5->c, 1, 1, 1, 1);
	return p;
}

//
//
//
void print_party(struct party *p)
{
	print_class(p->p1->c);
	printf("\n");
	print_class(p->p2->c);
	printf("\n");
	print_class(p->p3->c);
	printf("\n");
	print_class(p->p4->c);
	printf("\n");
	print_class(p->p5->c);
}

//
// remove_class calls makes this segfault
//
void remove_party(struct party *p)
{
	remove_class(p->p1->c);
	remove_class(p->p2->c);
	remove_class(p->p3->c);
	remove_class(p->p4->c);
	remove_class(p->p5->c);
	free(p->p1);
	free(p->p2);
	free(p->p3);
	free(p->p4);
	free(p->p5);
	free(p);
}

/*
int main()
{
	struct party *p = parse_party("src/party.txt");
	print_class(p->p1->c);
	printf("\n");
	print_class(p->p2->c);
	printf("\n");
	print_class(p->p3->c);
	printf("\n");
	print_class(p->p4->c);
	printf("\n");
	print_class(p->p5->c);
	remove_party(p);
	//printf("%d\n", sizeof(p->p1) + sizeof(p->p2) + sizeof(p->p3) + sizeof(p->p4) + sizeof(p->p5));
	// FRONT [NULL][NULL][NULL]
	// BACK  [NULL][NULL][NULL]
}*/
