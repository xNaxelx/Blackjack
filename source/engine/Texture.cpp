#include "Texture.h" 

Texture::Texture()
{
	texture = NULL;
}

Texture::~Texture()
{
	Free();
}

bool Texture::LoadFromFile(std::string path, SDL_Renderer* renderer, int positionX, int positionY, int framesCount, int width, int heigth)
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

		texture.reset(SDL_CreateTextureFromSurface(renderer, loadedSurface), [](SDL_Texture* texture) {});
		if (texture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
			return false;
		}
		else
		{
			this->framesCount = framesCount;
			this->currentFrame = framesCount;
			spriteClips.resize(framesCount);

			for (int i = 0; i < framesCount; i++)
			{
				spriteClips[i].x = width * i;
				spriteClips[i].y = 0;
				spriteClips[i].w = width;
				spriteClips[i].h = heigth;
			}
		}

		SDL_FreeSurface(loadedSurface);
	}

	return true;
}

bool Texture::LoadFromRenderedText(std::string textureText, TTF_Font* font ,SDL_Color textColor, SDL_Renderer* renderer)
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
			spriteClips.resize(1);
			spriteClips[0] = { 0, 0, textSurface->w, textSurface->h };
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
	SDL_Rect renderQuad = { x, y, spriteClips[currentFrame % framesCount].w, spriteClips[currentFrame % framesCount].h };

	SDL_RenderCopyEx(renderer, texture, &spriteClips[currentFrame % framesCount], &renderQuad, angle, center, flip);

	if (framesCount > 1 && (delay++ % 8 == 0))
	{
		currentFrame++;
	}
}

int Texture::getWidth()
{
	return spriteClips[0].w;
}

int Texture::getHeight()
{
	return spriteClips[0].h;
}