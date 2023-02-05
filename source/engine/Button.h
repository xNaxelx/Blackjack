#pragma once
	
#include "GameObject.h"
#include <functional>
#include <boost/function.hpp>
#include <boost/bind.hpp>



class Button : public GameObject
{
public:
	Button(int x, int y, int animFramesCount, int width, int height, std::string texturePath, SDL_Renderer* renderer, 
		Time* timer, boost::function<void()> buttonFunctional);
	void HandleEvent(SDL_Event* event) override;
private:
	boost::function<void()> buttonFunctional;
};

