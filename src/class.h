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
/*
	// Main Stats //
	//int hp;
	//int tp; // tp
	int str; // strength
	int tec; // technique
	int vit; // vitality
	int agi; // agility
	int luc; // luck
	*/
	// Battle Stats //
	//int atk; // attack
	//int def; // defense
	// Equipment //
	/*int e1; // slot 1
	int e2; // slot 2
	int e3; // slot 3
	int e4; // slot 4*/

