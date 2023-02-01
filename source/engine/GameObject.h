#pragma once

#include <SDL.h>
#include "Texture.h"
#include "Observer.h"
#include <string>
#include "Time.h"

class GameObject : public IObserver
{
public:
	float speed = 480.0F;
	Time* timer;

	void RenderTexture(SDL_Renderer* renderer) override;
	//void HandleEvent(SDL_Event &event) override;

	GameObject(int x, int y, int animFramesCount, int width, int height, std::string texturePath, SDL_Renderer* renderer, Time* timer);
	~GameObject();

	void virtual Move(float vectorX, float vectorY);

	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();
protected:
	SDL_Rect transform;

	Texture* texture;
};

