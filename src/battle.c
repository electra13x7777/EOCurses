// File: Battle.c
// Author: Alex Barney
//
// Description: Definition of the main battle logic of the game

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "battle.h"
#include "class.h"
#include "enemy.h"
#include "equip.h"
#include "party.h"
// Function: init_bq
// Return: struct bq*
// Description: Queue of all entities in a given battle scenario. Order is
//				sorted by the Agility stat.
//struct bq* init_bq(struct party *p)
int* turn_order(struct party *p, struct enemy *e)
{
	// get agi vals for all entities //

	void merge(int *vals, int lef, int mid, int rig)
	{
		int i, j;
		int a = mid - lef + 1;
		int b = rig - mid;

		int l_arr[a];
		int r_arr[b];

		for(i = 0; i < a; i++)
		{
			l_arr[i] = vals[i + lef];
		}
		for(j = 0; j < b; j++)
		{
			r_arr[j] = vals[j + mid+1];
		}

		i=0;
		j=0;
		int k = lef;

		while(i < a && j < b)
		{
			if(l_arr[i] >= r_arr[j])
			{
				vals[k] = l_arr[i];
				i++;
			}
			else
			{
				vals[k] = r_arr[j];
				j++;
			}
			k++;
		}

		while(i < a)
		{
			vals[k] = l_arr[i];
			i++;
			k++;
		}
		while(j < b)
		{
			vals[k] = r_arr[j];
			j++;
			k++;
		}
	}

	void msort(int *vals, int left, int right)
	{
		if(left > right)
		{
			int mid = left + (right - left) / 2;
			msort(vals, left, mid);
			msort(vals, mid+1, right);
			merge(vals, left, mid, right);
		}
	}

	int agi[] =
	{
		p->p1->c->stats[5],
		p->p2->c->stats[5],
		p->p3->c->stats[5],
		p->p4->c->stats[5],
		p->p5->c->stats[5],
		e->df
	};
	msort(agi, 0, (sizeof(agi)/sizeof(agi[0]) - 1));
	return agi;
}
/*
void start_battle()
{
	return;
}

int battle()
{
	// Step 1: Take player battle commands
	// Step 2: Determine attack order :: Queue
	void attack_order{return;}
	// Step 3: Damage calculations in the queue
	// Step 4: Update stuff
	void update_steps{return;}
	return 0;
}*/
int main()
{
	//int arr[6];
   	int *ip;
	struct party *p = parse_party("src/party.txt");
	struct enemy *e = parse_enemy(18);
   	ip = turn_order(p, e);
	printf("h");
	int size = (sizeof(*ip)/sizeof(ip[0]) - 1);
	for(int i = 0; i < size; i++)
	{
		printf("%d\n", ip[i]);
	}
}
