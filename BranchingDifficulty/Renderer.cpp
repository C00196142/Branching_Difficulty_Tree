// PURPOSE : MAIN CLASS FOR RENDERING OBJECTS.
#include <iostream>
using namespace std;
#define SDL_MAIN_HANDLED

#ifdef __APPLE__
#include "SDL2/SDL.h"
#elif defined(_WIN64) || defined(_WIN32)
#include "SDL.h"
#endif

#include "Renderer.h"




Renderer::Renderer() :sdl_renderer(NULL)
{

}

bool Renderer::init(const Size2D& winSize, const char* title) {

	// Initialize SDL2
	int e = SDL_Init(SDL_INIT_EVERYTHING);
	windowSize = winSize;
	if (e != 0) {
		// problem with SDL?...
		cout << "Could not init SDL: " << SDL_GetError() << std::endl;
		return false;
	}

	// Create an application window with the following settings:
	window = SDL_CreateWindow(
		// window title
		title,

		// initial x position
		SDL_WINDOWPOS_UNDEFINED,

		// initial y position
		SDL_WINDOWPOS_UNDEFINED,

		// width, in pixels
		(int)winSize.w,

		// height, in pixels
		(int)winSize.h,

		// flags - see below
		SDL_WINDOW_OPENGL
	);

	// Check that the window was successfully created
	if (window == NULL) {
		// In the case that the window could not be made...
		cout << "Could not create window: " << SDL_GetError() << std::endl;
		return false;
	}

	sdl_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (sdl_renderer == NULL) {
		// In the case that the renderer could not be made...
		cout << "Could not create renderer: " << SDL_GetError() << std::endl;
		return false;
	}

	arrowTexture = IMG_LoadTexture(sdl_renderer, "checkpoint.png");

	back = IMG_LoadTexture(sdl_renderer, "red.bmp");
	image = IMG_LoadTexture(sdl_renderer, "Image.bmp");
	endBack = IMG_LoadTexture(sdl_renderer, "blue.bmp");

	SDL_SetRenderDrawBlendMode(sdl_renderer, SDL_BLENDMODE_BLEND);

	return true;
}

//draw a rect in pixel coordinates
void Renderer::drawRect(const Rect& r, const Colour& c) {
	SDL_SetRenderDrawColor(sdl_renderer, c.r, c.g, c.b, c.a);
	SDL_Rect sr;
	sr.h = (int)r.size.h;
	sr.w = (int)r.size.w;
	sr.x = (int)r.pos.x;
	sr.y = (int)r.pos.y;
	SDL_RenderFillRect(sdl_renderer, &sr);

}
void Renderer::drawRectOutline(const Rect& r, const Colour& c) {
	SDL_SetRenderDrawColor(sdl_renderer, c.r, c.g, c.b, c.a);
	SDL_Rect sr;
	sr.h = (int)r.size.h;
	sr.w = (int)r.size.w;
	sr.x = (int)r.pos.x;
	sr.y = (int)r.pos.y;
	SDL_RenderDrawRect(sdl_renderer, &sr);

}
void Renderer::drawWorldRectOutline(const Rect &r, const Colour &c)
{
	drawRectOutline(worldToScreen(r), c);
}

//draw a rect in world coordinates
void Renderer::drawWorldRect(const Rect &r, const Colour &c)
{
	drawRect(worldToScreen(r), c);
}





void Renderer::drawText(SDL_Texture* texture, SDL_Rect rect)
{

	SDL_RenderCopy(sdl_renderer, texture, nullptr, &rect);
}
void Renderer::loadImage()
{
	SDL_Rect rect;
	rect.x = 540;
	rect.y = 460;
	rect.w = 267;
	rect.h = 140;

	SDL_Rect backRect;
	backRect.x = 0;
	backRect.y = 0;
	backRect.w = 800;
	backRect.h = 600;


	if (image == nullptr)
	{
		//std::cout << "image failed to load" << std::endl;
	}
	if (back == nullptr)
	{
		//std::cout << "image failed to load" << std::endl;
	}
	SDL_RenderCopy(sdl_renderer, back, NULL, &backRect);
	SDL_RenderCopy(sdl_renderer, image, NULL, &rect);

}
void Renderer::loadImageEnd()
{

	SDL_Rect backRect;
	backRect.x = 0;
	backRect.y = 0;
	backRect.w = 800;
	backRect.h = 600;

	if (endBack == nullptr)
	{
		
	}
	SDL_RenderCopy(sdl_renderer, endBack, NULL, &backRect);

}
//function to load all text

//swap buffers
void Renderer::present() {
	SDL_RenderPresent(sdl_renderer);
}



void Renderer::clear(const Colour& col) {
	SDL_SetRenderDrawColor(sdl_renderer, col.r, col.g, col.b, col.a);
	SDL_RenderClear(sdl_renderer);

}
Point2D Renderer::worldToScreen(const Point2D &p)
{
	float vpTop = viewportBottomLeft.y + viewportSize.h;
	float x = (p.x - viewportBottomLeft.x)* windowSize.w / viewportSize.w;
	float y = (vpTop - p.y)* windowSize.h / viewportSize.h;

	return Point2D(x, y);
}
Rect Renderer::worldToScreen(const Rect &r)
{
	Point2D p = worldToScreen(r.pos);
	float sw = r.size.w*(windowSize.w / viewportSize.w);
	float sh = -r.size.h*(windowSize.h / viewportSize.h);

	return Rect(p, Size2D(sw, sh));
}
void Renderer::setViewPort(const Rect &r)
{
	viewportBottomLeft = r.pos;
	viewportSize = r.size;
}

void Renderer::drawRotateableImage(SDL_Texture * surface, double rotation, SDL_Point* origin, bool flip, SDL_Rect* pos)
{
	SDL_Rect tempR = {};
	tempR.x = pos->x + 10;
	tempR.y = pos->y + 11;
	tempR.x = tempR.x * 40;
	tempR.y = tempR.y * 40;
	tempR.w = pos->w * 40;
	tempR.h = pos->h * 10;
	SDL_Point tempOrigin;
	tempOrigin = (*origin);
	tempOrigin.x = tempR.w / 2;
	tempOrigin.y = tempR.h / 2;
	double tempRotate = rotation *-1;
	SDL_RenderCopyEx(sdl_renderer, arrowTexture, NULL, (&tempR), tempRotate, (&tempOrigin), SDL_RendererFlip::SDL_FLIP_NONE);
}

SDL_Texture*Renderer::SurfaceToTexture(SDL_Surface* surf)
{
	SDL_Texture* text;

	text = SDL_CreateTextureFromSurface(sdl_renderer, surf);

	SDL_FreeSurface(surf);

	return text;
}
//Destroys SDL_Window and SDL_Renderer
void Renderer::destroy() {
	SDL_DestroyRenderer(sdl_renderer);
	SDL_DestroyWindow(window);

}

Renderer::~Renderer()
{
}

