// File: party.h
// Author: Alex Barney
//
// Description: Prototypes an Etrian Odyssey party

struct pmap
{
	//struct pmap *next;
	struct class *c;
	int pos;
};

struct party
{
	struct pmap *p1;
	struct pmap *p2;
	struct pmap *p3;
	struct pmap *p4;
	struct pmap *p5;
	//struct class *front[3];
	//struct class *back[3];
};

enum party_pos
{
	FRONT = 0,
	BACK  = 1
};

// Functions //
struct pmap* init_pmap(struct class *c, int pos);
//struct pmap* append_pmap();
struct party* init_party();
struct party* parse_party(char *fn);
void print_party(struct party *p);
void remove_party(struct party *p);
void remove_party_member(struct class *c);
