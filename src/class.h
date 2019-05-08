// File: class.h
// Author: Alex Barney
//
// Description: Prototypes an Etrian Odyssey class

struct __attribute__((__packed__)) equipment
{
	struct equip *e1;
	struct equip *e2;
	struct equip *e3;
	struct equip *e4;
};

struct __attribute__((__packed__)) class
{
	char* name; // class name
	int stats[7]; //hp,tp,str,tec,vit,agi,luc
	uint8_t skills[21]; // ints to denote invested skillpoints
	struct equipment *equips;
	//int equip[4]; // Weapons, Shields, Armor, Accesories
	int lv; // level
	int atk; // attack
	int def; // defense
	int exp; // experience points
	uint8_t sp; // number of skill points
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
		int vi, int ag, int lu);
struct class* parse_class(char *fn, int line);
struct class* create_class();
struct equipment* init_equipment();
struct equipment* parse_equipment(struct class *c,int l1,int l2,int l3,int l4);
void add_equip(struct class *c, struct equip *e, int pos);
//void set_equips(struct equipment *e);
void remove_class();
void print_class(struct class *c);
// levels and skills //
void add_exp(struct class *c, unsigned int exp);
void invest_sp(struct class *c, int pos);
