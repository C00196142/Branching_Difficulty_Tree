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
#include "FinishLine.h"
#include "Menu.h"

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
	Menu* startMenu = new Menu();
	std::vector <Platform*> blocks;
	LevelManager levels;
	FinishLine* finish = new FinishLine(Rect(0, 0, 0, 0));

	int r, g, b, a;

public:
	enum gameStage { menu, lvl1, lvl2A, lvl2B, 
					lvl3A, lvl3B, lvl3C, lvl3D, lvl3E, lvl3F, lvl3G,
					lvl4Eenemy, lvl4HEnemy, lvl4EFall, lvl4HFall, lvl4ETime, lvl4HTime, end };
	int stage = 0;
	Game();
	~Game();

	bool init();
	void destroy();
	void update();
	void render();
	void loop();
	void changeStage();
	void onEvent(EventListener::Event);
};
