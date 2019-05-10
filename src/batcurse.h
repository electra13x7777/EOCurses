// File: batcurse.h
// Author: Alex Barney
//
// Description: Prototypes subroutines to draw battles in curses

void party_printw(WINDOW **pwninarr, struct party *p, uint8_t fbias, int y, int x);
void enemy_printw(WINDOW *ewin, struct enemy *e, uint8_t numen, int y, int x);
void command_printw();
void turns_printw();
void hud_printw();
void* draw_battle();
