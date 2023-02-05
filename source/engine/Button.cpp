#include "Button.h"

Button::Button(int x, int y, int animFramesCount, int width, int height, std::string texturePath, SDL_Renderer* renderer, Time* timer, boost::function<void()> buttonFunctional)
	: GameObject(x, y, animFramesCount, width, height, texturePath, renderer, timer)
{
	this->buttonFunctional = buttonFunctional;
}

void Button::HandleEvent(SDL_Event* event)
{
	if (event->type == SDL_MOUSEBUTTONDOWN && event->button.button == SDL_BUTTON_LEFT)
	{
		if (event->button.x > transform.x && event->button.x < transform.x + transform.w &&
			event->button.y > transform.y && event->button.y < transform.y + transform.h)
		{
			buttonFunctional();
			printf("skin changed\n");
		}
	}
}