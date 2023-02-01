#include "GameObject.h"

void GameObject::RenderTexture(SDL_Renderer* renderer)
{
	texture->Render(transform.x, transform.y, renderer);
}

//void GameObject::HandleEvent(SDL_Event &event)
//{
//	
//}

GameObject::GameObject(int x, int y, int animFramesCount, int width, int height, std::string texturePath, SDL_Renderer* renderer, Time* timer)
{
	transform.x = x;
	transform.y = y;
	transform.w = width;
	transform.h = height;

	texture = new Texture();
	texture->LoadTextureFromFile(texturePath, renderer, animFramesCount, width, height);
	this->timer = timer;
}

GameObject::~GameObject()
{
	texture->~Texture();
}

void GameObject::Move(float vectorX, float vectorY)
{
	transform.x += vectorX * speed * ((float)timer->GetDeltaTime() / 1000.0F);
	transform.y += vectorY * speed * ((float)timer->GetDeltaTime() / 1000.0F);
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