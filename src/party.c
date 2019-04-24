// File: party.c
// Author: Alex Barney
//
// Description: Defines party.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "party.h"
#include "equip.h"
#include "class.h"

#define BUFFER 999

// Function: init_party()
// Return: struct party*
// Description: Creates a new instance of a party structure
struct party* init_party()
{
	struct party *new = (struct party*) malloc(48);
	new->front[0] = NULL;
	new->front[1] = NULL;
	new->front[2] = NULL;
	new->back[0] = NULL;
	new->back[1] = NULL;
	new->back[2] = NULL;
	return new;
}

// Function: parse_party
// Return: struct party*
// Description: Wraps around parse_class to build a party
struct party* parse_party(char *fn)
{
	printf("test");
	char str[BUFFER];
	FILE *fp = fopen(fn, "r");
	int count = 0;
	int pos = 0;
	int num = 6;
	int f = 0;
	int b = 0;
	int p1, p2, p3, p4, p5;
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
				p1 = atoi(tok);
			}
			if(pos == 1)
			{
				p2 = atoi(tok);
			}
			if(pos == 2)
			{
				p3 = atoi(tok);
			}
			if(pos == 3)
			{
				p4 = atoi(tok);
			}
			if(pos == 4)
			{
				p5 = atoi(tok);
			}
			pos++;
			strtok(NULL, ",");
		}
	}
	fclose(fp);
	printf("file closed");
	int partypos[5] = {p1, p2, p3, p4, p5};
	struct party *p = init_party();

	for(int i = 0; i < 5; i++)
	{
		if(partypos[i] == FRONT)
		{
			p->front[f] = parse_class(fn, i);
			f++;
		}
		else
		{
			p->back[b] = parse_class(fn, i);
			b++;
		}
	}
	return p;
}

//
//
//
void print_party(struct party *p)
{
	return;
}

//
//
//
void remove_party(struct party *p)
{
	return;
}


int main()
{
	struct party *p = parse_party("src/party.txt");
	print_class(p->front[0]);
	//printf("%d\n", sizeof(struct class*) *6);
	// FRONT [NULL][NULL][NULL]
	// BACK  [NULL][NULL][NULL]
}

