// File: eocalc.c
// Author: Alex Barney
//
// Description: Damage calculator for Etrian Odyssey.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

#include "enemy.h"
#include "class.h"
#include "attack.h"

#define BUFFER 999

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
/*
int main()
{
	printf("Working on a stable build\n");
	printf("To test current functionality run pkg/eoctest\n");
}*/
