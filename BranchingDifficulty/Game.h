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
#include "Enemy.h"
#include "Collectible.h"
#include <time.h>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

// The game object which manages the game loop
class Game :public EventListener
{
	InputManager inputManager;
	Renderer renderer;
	std::vector<GameObject*> gameObjects;

	//time of last update;
	unsigned int lastTime;
	float time;

	bool record = false;
	bool pause;
	bool quit;
	bool splashScreen;
	bool mainMenu;
	bool endMenu;
	bool changeLevel = false;
	Player* player = new Player();
	Menu* startMenu = new Menu();

	std::vector <Platform*> blocks;
	std::vector <FallingPlatform*> fallingBlocks;
	std::vector <Collectible*> collectibles;
	std::vector<Enemy*> enemies;
	std::vector<Spikes*> spikes;

	int numCollect = 0;
	LevelManager levels;

	FinishLine* finish = new FinishLine(Rect(1000, 0, 0, 0));

	int r, g, b, a;

	bool moveUp = true;
	bool moveRight = false;

	clock_t start;
	int duration;
	int timeToComplete;
	int enemyDeathsAllowed;
	int fallDeathsAllowed;
	float spiketime;

	string levelString = " ";

public:
	enum gameStage { splash, menu, tutorial, lvl1, lvl2A, lvl2B, 
					lvl3A, lvl3B, lvl3C, lvl3D, lvl3E, lvl3F, lvl3G,
					lvl4E_enemy, lvl4E_fall, lvl4E_time, lvl4H_enemy, lvl4H_fall, lvl4H_time, end };
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
	void moveEnemy();
	void levelVariables();
	void Record();
	
};
