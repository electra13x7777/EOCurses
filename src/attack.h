// File: attack.h
// Author: Alex Barney
//
// Description: Prototypes damage calculation algorithms

//(Base dmg) x (Skill multiplier) x (Active-Passive multiplier) x (Charge multiplier) x (Elemental resistance)

int damage(int atk, int sp, float skillmul, float buffs, float passivies,
		int hits, int def);

void attack(struct enemy *e, struct class *c);
