#include "AudioMixer.h"

AudioMixer::AudioMixer(std::string pathCRsound)
{
	loadedSound = Mix_LoadWAV(pathCRsound.c_str());
	if (loadedSound == NULL)
	{
		printf("Failed to load collision reaction sound effect! SDL_mixer Error: %s\n", Mix_GetError());
	}
}

AudioMixer::~AudioMixer()
{
	Mix_FreeChunk(loadedSound);
	loadedSound = NULL;
}

void AudioMixer::PlaySound(Mix_Chunk* sound)
{
	Mix_PlayChannel(-1, sound, 0);
}