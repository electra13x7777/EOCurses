// File: party.h
// Author: Alex Barney
//
// Description: Prototypes an Etrian Odyssey party

struct party
{
	struct class *front[3];
	struct class *back[3];
};

enum party_pos
{
	FRONT = 0,
	BACK  = 1
};

// Functions //
struct party* init_party();
struct party* parse_party(char *fn);
void print_party(struct party *p);
void remove_party(struct party *p);
void remove_party_member(struct class *c);
