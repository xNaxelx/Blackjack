#pragma once

#include <SDL_mixer.h>
#include <iostream>

class AudioMixer
{
public:
	AudioMixer(std::string pathCRsound);
	~AudioMixer();

	void PlaySound(Mix_Chunk* sound);

	Mix_Chunk* loadedSound = NULL;
};

