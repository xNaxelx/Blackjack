#include "GameObject.h"

void GameObject::UpdateTexture(SDL_Renderer* renderer)
{
	texture.Render(transform.x, transform.y, renderer);
}

//void GameObject::HandleEvent(SDL_Event &event)
//{
//	
//}

GameObject::GameObject()
{
	transform.x = 0;
	transform.y = 0;
	speed = 0;
}

GameObject::GameObject(int x, int y, int animFramesCount, int width, int height, std::string texturePath, SDL_Renderer* renderer, Time* timer)
{
	transform.x = x;
	transform.y = y;
	transform.w = width;
	transform.h = height;
	texture.LoadTextureFromFile(texturePath, renderer, x, y, animFramesCount, width, height);
	this->timer = timer;
}

GameObject::~GameObject()
{
	texture.~Texture();
}

void GameObject::Move(float vectorX, float vectorY)
{
	transform.x += vectorX * speed * ((float)timer->GetDeltaTime() / 1000.0F);
	transform.y += vectorY * speed * ((float)timer->GetDeltaTime() / 1000.0F);
}

void GameObject::Render(SDL_Renderer* renderer, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE)
{
	texture.Render(transform.x, transform.y, renderer, angle, center, flip);
}

int GameObject::GetX()
{
	return transform.x;
}

int GameObject::GetY()
{
	return transform.y;
}

int GameObject::GetWidth()
{
	return transform.w;
}

int GameObject::GetHeight()
{
	return transform.h;
}