#pragma once
#include "Renderer.h"
#include <iostream>

class Menu
{
public:
	Menu();
	~Menu();

	void Render(Renderer & r);
	void RenderEnd(Renderer & r);
	void LoadTextStart(Renderer& r);
	void LoadTextEnd(Renderer& r);
	void LoadImage(SDL_Renderer * rend);
	void Destroy();

private:
	TTF_Font* headerFont;
	TTF_Font* nameFont;
	TTF_Font* keyFont;

	SDL_Texture* imageTexture;
	SDL_Texture* headerTexture;
	SDL_Texture* keyTexture;
	SDL_Texture* nameTexture;
	SDL_Surface* solidHeader;
	SDL_Surface* solidKey;
	SDL_Surface* solidName;
	SDL_Rect imageRect;
	SDL_Rect headerRect;
	SDL_Rect keyRect;
	SDL_Rect nameRect;

	SDL_Surface* winSurface;
	SDL_Surface* returnSurface;
	SDL_Surface* infoSurface;
	SDL_Rect winRect;
	SDL_Rect returnRect;
	SDL_Rect infoRect;

	int screen = 1;
	SDL_Color textColor = { 255, 255, 255, 255 }; // white
	SDL_Color keyColour = { 255,255,0,255 };

};

