﻿#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <memory>
#include "engine/Time.h"
#include "engine/Texture.h"
#include "gameplay/Card.h"
#include "engine/UpdateSystem.h"
#include "gameplay/SkinSystem.h"
#include "gameplay/CardDeck.h"
#include "engine/Button.h"

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 800;

SDL_Window* window;
std::shared_ptr<SDL_Renderer> renderer; 
TTF_Font* font = NULL;

Time mainTimer;
UpdateSystem updateSystem;
SkinSystem skinSystem;

bool Init()
{
	if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return false;
	}
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
	{
		printf("Warning: Linear texture filtering not enabled!\n");
	}

	window = SDL_CreateWindow("BlackJack", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	renderer.reset(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC), [](SDL_Renderer* renderer) { SDL_DestroyRenderer(renderer); });
	//SDL_RenderSetScale(renderer.get(), 0.15, 0.15);
	if (renderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}
	SDL_SetRenderDrawColor(renderer.get(), 0x0, 0x0, 0x0, 0xFF);

	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
		return false;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		return false;
	}

	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}

	mainTimer.InitTime();
	skinSystem = SkinSystem("resource/Card texture packs", "resource/Card back textures", renderer.get(), &mainTimer, &updateSystem);

	return true;
}

void Close()
{
	//TTF_CloseFont(font);
	font = NULL;

	SDL_DestroyWindow(window);
	window = NULL;
	renderer.~shared_ptr();	
	renderer = NULL;

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* args[])
{
	if (!Init())
	{
		printf("Failed to initialize!\n");

		Close();

		return -1;
	}
	
	Texture table;
	table.LoadTextureFromFile("resource/table.png", renderer.get(), 1, SCREEN_WIDTH, SCREEN_HEIGHT);

	CardDeck cardDeck(1000, 50, *skinSystem.GetAllCardsVector(), &updateSystem);
	
	Button changeSkinButton(50, 50, 1, 200, 80, "resource/CHANGE_SKIN.png", renderer.get(), &mainTimer, boost::bind(&SkinSystem::ChangeSkins, &skinSystem));
	updateSystem.Attach(&changeSkinButton);
	Button changeShirtSkinButton(50, 180, 1, 200, 80, "resource/CHANGE_SHIRT.png", renderer.get(), &mainTimer, boost::bind(&SkinSystem::ChangeShirtSkins, &skinSystem));
	updateSystem.Attach(&changeShirtSkinButton);
	//Card card(CARD_SUIT_CLUB, CARD_RANK_10, 0, 0, 1, 188, 291, "resource/Card texture packs/1/Club01.png", renderer.get(), &mainTimer);
	//updateSystem.Attach(&card);
	//card.MoveTo(400, 400);
	//card.speed = 1000;

	bool quit = false;
	SDL_Event event;

	while (!quit)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT) { quit = true; }
			updateSystem.NotifyHandleEvent(&event);
			//if (event.button.state == SDL_PRESSED) { card.showShirt = !card.showShirt; }
		}
		mainTimer.UpdateTime();


		SDL_SetRenderDrawColor(renderer.get(), 0x0, 0x0, 0x0, 0xFF);
		SDL_RenderClear(renderer.get());
		table.Render(0, 0, renderer.get());

		updateSystem.NotifyUpdateMove();
		updateSystem.NotifyUpdateTextures(renderer.get());
		
		//card.RenderTexture(renderer.get());

		SDL_RenderPresent(renderer.get());
	}	


	Close();
	
	return 0;
}
