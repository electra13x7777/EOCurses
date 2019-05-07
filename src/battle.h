// File: battle.h
// Author: Alex Barney
//
// Description: Main turn based battle logic of the game

/*
Turn X
Atk		E1    E2    E3
Def
Skl
Itm
Esc
	  P1      P2      P3
	      P4      P5
*/
/*
struct bq //battleQueue
{
	struct battleQueue *next; // next in queue
	void* val; // void pointer to Class or Enemy structure
};
*/
// Functions //
int* turn_order(int arr[]);
void start_battle(); // called to start battle routine
int battle(); // main battle routine | returns 1 for win 0 for loss
void attack_order(); // orders attacks in a turn by agility
void update_steps(); // adds a step for each turn in a battle


