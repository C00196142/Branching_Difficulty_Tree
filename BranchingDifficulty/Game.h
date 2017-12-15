// PURPOSE : HEADER FILE THAT DEFINES FUNCTIONS VARIABLES ETC. THAT ARE USED IN THE GAME.CPP
#pragma once

#include <vector>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>
#include "Renderer.h"
#include "GameObject.h"
#include "InputManager.h"
#include "EventListener.h"
#include "Player.h"
#include "LevelManager.h"

// The game object which manages the game loop
class Game :public EventListener
{
	InputManager inputManager;
	Renderer renderer;

	std::vector<GameObject*> gameObjects;

	//time of last update;
	unsigned int lastTime;

	bool record = false;
	bool pause;
	bool quit;
	bool mainMenu;
	bool endMenu;
	bool changeLevel = false;
	Player* player = new Player();

	std::vector <Platform*> blocks;
	LevelManager levels;

	Rect collision;
	Colour fadeColor;
	int r, g, b, a;


public:
	enum gameStage { lvl1, lvl2A, lvl2B, 
					 lvl3A, lvl3B,lvl3C, lvl3D, lvl3E, lvl3F, lvl3G,
					 lvl4ATime, lvl4BTime, lvl4AFall, lvl4BFall, lvl4AEnemy, lvl4BEnemy};
	int stage = 0;
	Game();
	~Game();

	bool init();
	void destroy();
	void update();
	void render();
	void loop();
	void nextLevel();
	void onEvent(EventListener::Event);
};

