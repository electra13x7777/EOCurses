// File: merge.c
// Author: Alex Barney
//
// Description: sorting algorithms to be utilized in the game

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/*
#include "class.h"
#include "equip.h"
#include "enemy.h"
#include "party.h"
*/
#ifndef foreach
#define foreach(i, arr) \
	            for(int j = 1, \
						k = 0, \
						size = sizeof(arr)/sizeof(*arr); \
						j && k != size; \
						j = !j, k++) \
				for(i = arr + k; j; j = !j)
#endif
// Function: init_bq
// Return: struct bq*
// Description: Queue of all entities in a given battle scenario. Order is
//				sorted by the Agility stat.
//struct bq* init_bq(struct party *p)
//{
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
		if(l_arr[i] <= r_arr[j])
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
	if(left < right)
	{
		int mid = left + (right - left) / 2;
		msort(vals, left, mid);
		msort(vals, mid+1, right);
		merge(vals, left, mid, right);
	}
}

void merge_dec(int *vals, int lef, int mid, int rig)
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
void msort_dec(int *vals, int left, int right)
{
	if(right > left)
	{
		int mid = left + (right - left) / 2;
		msort_dec(vals, left, mid);
		msort_dec(vals, mid+1, right);
		merge_dec(vals, left, mid, right);
	}
}
