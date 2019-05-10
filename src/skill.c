// File: skill.c
// Author: Alex Barney
//
// Description: Defines all skills in the game

#include <stdio.h>
#include <stdlib.h>

#include "skill.h"
#include "attack.h"

//////////////////////
// ALCHEMIST SKILLS //
//////////////////////

////////////////////////
// DARK HUNTER SKILLS //
////////////////////////

///////////////////////
// LANDSKNECT SKILLS //
///////////////////////
void la_hp_up(struct class *c)
{
	c->stats[0] += c->skills[0] * 10;
}

void la_tp_up(struct class *c)
{
	c->stats[1] += c->skills[1] * 10;
}

void la_atk_up(struct class *c)
{
	c->atk += c->skills[2] * 10;
}

void la_def_up(struct class *c)
{
	c->def += c->skills[3] * 10;
}

void la_axes(struct class *c)
{
	float axemul;
	return;
}

float la_swords(struct class *c)
{
	float swordmul;
	return;
}

void 2_hit(struct class *c)
{
	return;
}

void war_cry(struct class *c)
{
	return;
}

void hell_cry(struct class *c)
{
	return;
}

void arm_heal(struct class *c)
{
	return;
}

void flee(struct class *c)
{
	return;
}

void cleaver(struct class *c, struct enemy *e)
{
	int dmg = damage(c->atk, c->skills[11], (.1 + la_swords(c)), 0, 0, 1, e->df);
	e->hp -= dmg;
}
