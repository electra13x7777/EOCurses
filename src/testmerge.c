// File: Battle.c
// Author: Alex Barney
//
// Description: Definition of the main battle logic of the game

#include <stdio.h>
#include <stdlib.h>

#define foreach(i, arr) \
	            for(int j = 1, \
						k = 0, \
						size = sizeof(arr)/sizeof(*arr); \
						j && k != size; \
						j = !j, k++) \
				for(i = arr + k; j; j = !j)

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

void mmerge(int *vals, int lef, int mid, int rig)
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
void mmsort(int *vals, int left, int right)
{
	if(right > left)
	{
		int mid = left + (right - left) / 2;
		mmsort(vals, left, mid);
		mmsort(vals, mid+1, right);
		mmerge(vals, left, mid, right);
	}
}

int main()
{
	int *i;
	int arr[6] = {3,7,21,8,4,9};
	int size = sizeof(arr)/sizeof(arr[0]);
	//msort(arr, 0, size-1);
	mmsort(arr, 0, size-1);
	foreach(i, arr)
	{
		printf("%d\n", *i);
	}
}
