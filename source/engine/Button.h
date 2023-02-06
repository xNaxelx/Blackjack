#pragma once
	
#include "GameObject.h"
#include "AudioMixer.h"
#include <functional>
#include <boost/function.hpp>
#include <boost/bind.hpp>



class Button : public GameObject
{
public:
	Button(int x, int y, int animFramesCount, int width, int height, std::string texturePath, SDL_Renderer* renderer, 
		Time* timer, boost::function<void()> buttonFunctional, AudioMixer* sound = NULL);
	
	void HandleEvent(SDL_Event* event) override;
	void RenderTexture(SDL_Renderer* renderer) override;

	boost::function<void()> buttonFunctional;
	bool isHiden = false;
private:
	AudioMixer* sound;
};

