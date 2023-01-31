#include "Texture.h" 

Texture::Texture()
{
	texture = NULL;
}

Texture::~Texture()
{
	Free();
}

bool Texture::LoadTextureFromFile(std::string path, SDL_Renderer* renderer, int positionX, int positionY, int animationTilesCount, int width, int heigth)
{
	Free();

	SDL_Surface* loadedSurface(IMG_Load(path.c_str()));
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
		return false;
	}
	else
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (texture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
			return false;
		}
		else
		{
			this->animationTilesCount = animationTilesCount;
			this->currentAnimationTile = animationTilesCount;
			tilesRectangle.resize(animationTilesCount);

			for (int i = 0; i < animationTilesCount; i++)
			{
				tilesRectangle[i].x = width * i;
				tilesRectangle[i].y = 0;
				tilesRectangle[i].w = width;
				tilesRectangle[i].h = heigth;
			}
		}

		SDL_FreeSurface(loadedSurface);
	}

	return true;
}

bool Texture::PrepareTextureFromText(std::string textureText, TTF_Font* font ,SDL_Color textColor, SDL_Renderer* renderer)
{
	Free();

	SDL_Surface* textSurface = TTF_RenderText_Solid(font, textureText.c_str(), textColor);
	if (textSurface != NULL)
	{
		texture = SDL_CreateTextureFromSurface(renderer, textSurface);
		if (texture == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
		}
		else
		{
			tilesRectangle.resize(1);
			tilesRectangle[0] = { 0, 0, textSurface->w, textSurface->h };
		}

		SDL_FreeSurface(textSurface);
	}
	else
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}


	return texture != NULL;
}

void Texture::Free()
{
	if (texture != NULL)
	{
		SDL_DestroyTexture(texture);
		texture = NULL;
	}
}

void Texture::Render(int x, int y, SDL_Renderer* renderer, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	SDL_Rect renderQuad = { x, y, tilesRectangle[0].w, tilesRectangle[0].h };

	SDL_RenderCopyEx(renderer, texture, &tilesRectangle[currentAnimationTile % animationTilesCount], &renderQuad, angle, center, flip);

	if (animationTilesCount > 1 && (delay++ % 8 == 0))
	{
		currentAnimationTile++;
	}
}

int Texture::getWidth()
{
	return tilesRectangle[0].w;
}

int Texture::getHeight()
{
	return tilesRectangle[0].h;
}