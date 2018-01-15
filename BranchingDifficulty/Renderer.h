#pragma once
#define SDL_MAIN_HANDLED
#ifdef __APPLE__
#include "SDL2/SDL.h"
#elif defined(_WIN64) || defined(_WIN32)
#include "SDL.h"
#include "SDL_image.h"
//#include "SDL_ttf.h"
#include <string>
#endif


#include "BasicTypes.h"



//Responsible for all drawing operations
//abstracts away specfic SDL specific drawing functions
class Renderer {

	// size of window in pixels
	Size2D windowSize;
	//position of window in world coordinates
	//change these if you want to zoom or pan
	Point2D viewportBottomLeft;
	Size2D viewportSize;


	SDL_Window *window;
	SDL_Renderer *sdl_renderer;
	SDL_Texture *img;
	SDL_Texture* arrowTexture;


public:
	Renderer();
	bool init(const Size2D&, const char*);
	void drawRect(const Rect&, const Colour&);
	void drawWorldRect(const Rect&, const Colour&);

	void drawRectOutline(const Rect&, const Colour&);
	void drawWorldRectOutline(const Rect&, const Colour&);
	void drawText(SDL_Texture * texture, SDL_Rect rect);
	void loadImage();
	void loadImageEnd();
	void present();
	void clear(const Colour&);
	SDL_Texture* SurfaceToTexture(SDL_Surface* surf);
	Point2D worldToScreen(const Point2D&);
	Rect worldToScreen(const Rect&);
	bool startLoaded = true;
	void setViewPort(const Rect&);
	void drawRotateableImage(SDL_Texture * surface, double rotation, SDL_Point * origin, bool flip, SDL_Rect * pos);
	SDL_Texture* image;
	SDL_Texture* back;
	SDL_Texture* endImage;
	SDL_Texture* endBack;
	SDL_Texture* background;
	void destroy();
	~Renderer();
};

