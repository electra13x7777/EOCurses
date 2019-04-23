// File: equip.h
// Author: Alex Barney
//
// Description: Prototypes an Etrian Odyssey equip

struct __attribute__((__packed__)) equip
{
	char* classes; // char to represent who can equip [9]
	char* name;
	int stats[7]; // hp,tp,str,tex,vit,agi,luc
	int type;
	int atk;
	int def;
};

enum equip_e
{
	// Weapons //
	SWORD     = 0,
	STAFF     = 1,
	AXE       = 2,
	KATANA    = 3,
	BOW       = 4,
	WHIP      = 5,
	// Armor //
	BODY      = 6,
	SHIELD    = 7,
	HELMET    = 8,
	BOOT      = 9,
	// Accessories //
	ACCESSORY = 10
};

// Equip Functions //
struct equip* init_equip(char* classes, char* name, int hp, int tp, int st,
		int te, int vi,	int ag, int lu, int type, int atk, int def);
struct equip* parse_equip(int line);
struct equip* create_equip();
void remove_equip(struct equip *e);
void print_equip(struct equip *e);
