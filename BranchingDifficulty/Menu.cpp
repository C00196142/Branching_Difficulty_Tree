#include "Menu.h"
Menu::Menu()
{
	headerRect.w = 700;
	headerRect.h = 150;
	headerRect.x = 60;
	headerRect.y = 0;

	keyRect.w = 400;
	keyRect.h = 100;
	keyRect.x = 180;
	keyRect.y = 240;

	nameRect.w = 520;
	nameRect.h = 35;
	nameRect.x = 0;
	nameRect.y = 565;
}
Menu::~Menu()
{

}
void Menu::LoadTextStart(Renderer& r)
{
	
	
	/*if (TTF_Init() == -1)
	{
		std::cout << " Failed to initialize TTF : " << SDL_GetError() << std::endl;
	}*/

	//headerFont = TTF_OpenFont("Amatic-Bold.ttf", 300);
	//keyFont = TTF_OpenFont("Amatic-Bold.ttf", 600);
	//nameFont = TTF_OpenFont("Amatic-Bold.ttf", 140);

	//// Load our fonts, with a huge size
	//// Error check
	//if (headerFont == nullptr)
	//{
	//	std::cout << " Failed to load font : " << SDL_GetError() << std::endl;
	//}
	//if (keyFont == nullptr)
	//{
	//	std::cout << " Failed to load font : " << SDL_GetError() << std::endl;
	//}
	//if (nameFont == nullptr)
	//{
	//	std::cout << " Failed to load font : " << SDL_GetError() << std::endl;
	//}

	//solidHeader = TTF_RenderText_Solid(headerFont, "Thomas Was Alone", textColor);

	//SDL_QueryTexture(headerTexture, NULL, NULL, &headerRect.w, &headerRect.h);
	//SDL_QueryTexture(keyTexture, NULL, NULL, &keyRect.w, &keyRect.h);
	//SDL_QueryTexture(nameTexture, NULL, NULL, &nameRect.w, &nameRect.h);

	//headerTexture = r.SurfaceToTexture(solidHeader);
	//keyTexture = r.SurfaceToTexture(solidKey);
	//nameTexture = r.SurfaceToTexture(solidName);


	//headerRect.w = 700;
	//headerRect.h = 150;
	//headerRect.x = 60;
	//headerRect.y = 0;

	//keyRect.w = 400;
	//keyRect.h = 100;
	//keyRect.x = 180;
	//keyRect.y = 240;

	//nameRect.w = 520;
	//nameRect.h = 35;
	//nameRect.x = 0;
	//nameRect.y = 565;
}
void Menu::LoadTextEnd(Renderer& r)
{

}

void Menu::Render(Renderer& r) 
{
	r.drawText(headerTexture, headerRect);
	r.drawText(keyTexture, keyRect);
	r.drawText(nameTexture, nameRect);
}
void Menu::RenderEnd(Renderer& r) 
{

}