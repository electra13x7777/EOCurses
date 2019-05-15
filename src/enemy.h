// File: enemy.h
// Author: Alex Barney
//
// Description: Prototypes enemy structs for Etrian Odyssey 1

#define EOEF "enemies.txt"

// Struct: enemy
//
// Description: Stores name and relative stats for an enemy
struct __attribute__((__packed__)) enemy
{
	char* name; // enemy name
	int hp; // enemy health
	int at; // enemy attack
	int df; // enemy defense
};

// Enumeration: enemyval
//
// Description: Stores values for where enemy data is stored in enemies.txt
enum enemyval
{
	Treerat_e = 1,
	Woodfly_e = 2,
	Mole_e = 3,
	Clawbug_e = 4,
	Venomfly_e = 5,
	Hare_e = 6,
	Fender_e = 7,
	Mandrake_e = 8,
	Roller_e = 9,
	Clawfly_e = 10,
	Warbull_e = 11,
	Ragelope_e = 12,
	Kuyutha_e = 13,
	Stalker_e = 14,
	Wolf_e = 15,
	Skoll_e = 16,
	Golem_e = 17,
	Fenrir_e = 18
};

// Enemy Functions //
struct enemy* init_enemy(char* name, int hp, int at, int df);
struct enemy* parse_enemy(int line);
void remove_enemy(struct enemy *e);
void print_enemy(struct enemy *e);
