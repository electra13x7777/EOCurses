// File: music.h
// Author: Alex Barney
//
// Description: Prototypes music stuff

// Functions //
void play_song(const char *fn);
void play_sfx();
void* play_audio(void** args); // void pointer wrapper for threading purposes
