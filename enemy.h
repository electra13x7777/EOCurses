// File: eo1_enemy.h
// Author: Alex Barney
//
// Description: Prototypes enemy structs for Etrian Odyssey 1

struct enemy
{
	char* name; // enemy name
	int hp; // enemy health
	int at; // enemy attack
	int df; // enemy defense
};
/*
struct enemy* treerat = (enemy*)malloc(sizeof(enemy*));
treerat->name = "Tree Rat";
treerat->hp = 19;
treerat->at = 10;
treerat->df = 14;
*/
