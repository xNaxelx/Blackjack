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

void GameObject::MoveUpdate()
{
	if (isMoving)
	{
		double vectorLength = sqrt(pow(destination.x - transform.x, 2) + pow(destination.y - transform.y, 2));
		if ( vectorLength * (float)timer->GetDeltaTime() > speed)
		{
			transform.x += ((destination.x - transform.x) / vectorLength) * speed * ((float)timer->GetDeltaTime() / 1000.0F);
			transform.y += ((destination.y - transform.y) / vectorLength) * speed * ((float)timer->GetDeltaTime() / 1000.0F);
		}
		else
		{
			transform.x = destination.x;
			transform.y = destination.y;
		}
	}
}

void GameObject::MoveDueToInput(float vectorX, float vectorY)
{
	transform.x += vectorX * speed * ((float)timer->GetDeltaTime() / 1000.0F);
	transform.y += vectorY * speed * ((float)timer->GetDeltaTime() / 1000.0F);
}

void GameObject::MoveTo(int x, int y)
{
	destination.x = x;
	destination.y = y;

	isMoving = true;
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