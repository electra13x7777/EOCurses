// File: class.h
// Author: Alex Barney
//
// Description: Prototypes an Etrian Odyssey class

struct __attribute__((__packed__)) class
{
	char* name; // class name
	int stats[7]; //hp,tp,str,tec,vit,agi,luc
	int equip[4]; // Weapons, Shields, Armor, Accesories
	int lv; // level
	int atk; // attack
	int def; // defense
};

enum classpos
{
	ALC = 1,
	DAR = 2,
	LAN = 3,
	SUR = 4,
	TRO = 5,
	MED = 6,
	RON = 7,
	HEX = 8,
	PRO = 9
};

// Class Functions //
struct class* init_class(char* name, int lv, int hp, int tp, int st, int te,
		int vi, int ag, int lu, int e1, int e2, int e3, int e4);
struct class* create_class();
void remove_class();
void print_class(struct class *c);
