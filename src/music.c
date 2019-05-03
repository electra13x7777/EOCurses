// File: music.c
// Author: Alex Barney
//
// Description: Plays music files

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <AL/alut.h>

//
//
// ADD LOOP POINT
void play_song(const char *fn)
{
	ALenum err;
	ALint status;
	ALuint src;
	ALuint buf = alutCreateBufferFromFile(fn);
	if(buf == AL_NONE)
	{
		err = alutGetError();
		fprintf(stderr, "File Load Error: %s\n", alutGetErrorString(err));
		alutExit();
		exit(1);
	}
	alGenSources(1, &src);
	alSourcei(src, AL_BUFFER, buf);
	alSourcePlay(src);
	err = alGetError();
	if(err != ALUT_ERROR_NO_ERROR)
	{
		fprintf(stderr, "%s\n", alGetString(err));
		alutExit();
		exit(1);
	}
	do
	{
		alutSleep(0.1f);
		alGetSourcei(src, AL_SOURCE_STATE, &status);
	}
	while(status == AL_PLAYING);
}

void play_sfx()
{
	return;
}

// Function: play_audio
// Return: void*
// Description: Wrapper for play_song for threading purposes
void* play_audio(void** args)
{
	int argc = *((int*) args[0]);
	char **argv = *((char**) args[1]);
	if(!alutInit(argc, argv))
	{
		ALenum error = alutGetError();
	}
	play_song(argv[1]);
}

/*
int main(int argc, char **argv)
{
	argc = 2;
	if(!alutInit(&argc, argv))
	{
		ALenum error = alutGetError();
	}
	if(argc != 2)
	{
		alutExit();
		exit(1);
	}
	char *fn = "src/utils/initialstrike.wav";
	argv[1] = fn;
	play_song(argv[1]);
}*/
