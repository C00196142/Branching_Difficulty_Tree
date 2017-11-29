#include <iostream>
#include "Game.h"
#include "LTimer.h"

const int SCREEN_FPS = 100;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

using namespace std;
Game::Game()
{
	pause = false;
	quit = false;
}


Game::~Game()
{
}

//the initializing function for the game
//is only called once at the beginning
//
//it sets all the important standard values like the size of the window
//or the values for the starting screen
bool Game::init() {

	Size2D winSize(800, 600);

	//creates our renderer, which looks after drawing and the window
	renderer.init(winSize, "Branching Difficulty Tree");

	//set up the viewport
	//we want the vp centred on origin and 20 units wide
	float aspectRatio = winSize.w / winSize.h;

	//viewpoint attributes
	//width says how the window is divided into Units (here the 600px wide window is divided into 20 Units so)
	float vpWidth = 20;

	//here we set the point x=0 y=0  to the mid of the window
	Size2D vpSize(vpWidth, vpWidth / aspectRatio);
	Point2D vpBottomLeft(-vpSize.w / 2, -vpSize.h / 2);

	Rect vpRect(vpBottomLeft, vpSize);
	renderer.setViewPort(vpRect);

	return true;

}

//function for quitting the game and clearing everything out
void Game::destroy()
{
	//empty out the game object vector before quitting
	for (std::vector<GameObject*>::iterator i = gameObjects.begin(); i != gameObjects.end(); i++) {
		delete *i;
	}
	gameObjects.clear();
	renderer.destroy();
}

//calls update on all game entities
//running like a loop in the game and checking all the events that could happen during playing the game 
void Game::update()
{

}
//calls render on all game entities
//this function draws all the Objects in the gaming Window OR calls the drawing-functions of the gameObjects
void Game::render()
{

}

//loop function
//it loops the whole game and includes the
//update and render game entities
void Game::loop()
{
	//to cap framerate
	LTimer capTimer;

	int frameNum = 0;

	//game loop
	while (!quit) {
		capTimer.start();

		//inputManager.ProcessInput();
		update();
		render();

		//time since start of frame
		int frameTicks = capTimer.getTicks();
		if (frameTicks < SCREEN_TICKS_PER_FRAME)
		{
			//Wait remaining time before going to next frame
			SDL_Delay(SCREEN_TICKS_PER_FRAME - frameTicks);
		}
	}
}

//this function handles the events
//if a specific event happens the game should react on it
//\param[in] we give the function the event that happens
void Game::onEvent(EventListener::Event evt)
{

}

//in this function  we change the stage
//if the player hits the portal or leaves the mainMenu
void Game::nextLevel()
{
	//checking which stage we are on
	switch (stage)
	{
	case lvl1:
		//if the player reaches the portal we set somewhere else in the code the variable changeLevel to true
		if (changeLevel)
		{

		}
	}
}
