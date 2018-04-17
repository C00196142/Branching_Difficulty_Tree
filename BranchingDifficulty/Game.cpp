#include <iostream>
#include "LTimer.h"
#include "Game.h"
using namespace std;

const int SCREEN_FPS = 100;
const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;


//The Constructor for the game
Game::Game()
{
	pause = false;
	quit = false;
}

struct fileLog {

	unsigned int time;
	int fallDeaths;
	int enemyDeaths;

	int ttc;
	int fda;
	int eda;

	string levelS;

};
fileLog logRecords;
std::vector<fileLog> logs;

//The Destructor for the game
Game::~Game()
{
}

//the initializing function for the game
//is only called once at the beginning
//
//it sets all the important standard values like the size of the window
//or the values for the starting screen
bool Game::init() 
{
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

	splashScreen = true;
	mainMenu = false;
	Rect vpRect(vpBottomLeft, vpSize);
	renderer.setViewPort(vpRect);

	//setting the background colour in the mainMenu
	r = 150;
	g = 0;
	b = 102;

	lastTime = LTimer::gameTime();

	//All the Events we need in the game
	//the first are events regarding to the game (window)
	//the others are events regarding the main character (interaction with the keyboard for moving and jumping)
	inputManager.AddListener(EventListener::Event::RESTART, this);
	inputManager.AddListener(EventListener::Event::START, this);
	inputManager.AddListener(EventListener::Event::QUIT, this);
	inputManager.AddListener(EventListener::Event::LEFT, player);
	inputManager.AddListener(EventListener::Event::RIGHT, player);
	inputManager.AddListener(EventListener::Event::STOP, player);
	inputManager.AddListener(EventListener::Event::JUMP, player);
	inputManager.AddListener(EventListener::Event::SUPERJUMP, player);

	return true;

}

//function for quitting the game and clearing everything out
void Game::destroy()
{
	//empty out the game object vector before quitting
	for (std::vector<GameObject*>::iterator i = gameObjects.begin(); i != gameObjects.end(); i++) 
	{
		delete *i;
	}
	gameObjects.clear();
	renderer.destroy();
}


//calls update on all game entities
//running like a loop in the game and checking all the events that could happen during playing the game 
void Game::update()
{
	changeStage();
	moveEnemy();
	levelVariables();

	player->setInAir(true);
	player->setOnPlatform(false);

	//Check collision between player and Platforms
	for (int i = 0; i < blocks.size(); i++)
	{
		player->PlatformCollision(blocks[i]->floor);
	}

	for (int i = 0; i < fallingBlocks.size(); i++)
	{
		player->PlatformCollision(fallingBlocks[i]->fallFloor);
	}

	for (int i = 0; i < fallingBlocks.size(); i++)
	{
		if (stage == lvl4E_fall)
		{
			fallingBlocks[i]->PlayerCollision(player->rect, 125, 175);
		}
		else if (stage == lvl4H_fall)
		{
			fallingBlocks[i]->PlayerCollision(player->rect, 75, 125);
		}
	}

	//Check collision between player and enemy
	if (stage == lvl3A || stage == lvl3B || stage == lvl3C || stage == lvl3D ||
		stage == lvl3E || stage == lvl3F || stage == lvl3G)
	{
		for (int e = 0; e < enemies.size(); e++)
		{
			player->enemyCollision(enemies[e]->enemy);
		}
	}

	//Check collision between player and spikes
	for (int s = 0; s < spikes.size(); s++)
	{
		player->enemyCollision(spikes[s]->spikes);
	}


	//Check collision between player and collectibles
	for (int j = 0; j < collectibles.size(); j++)
	{
		player->collectibleCollision(collectibles[j]->collectible);
	}

	for (int j = 0; j < collectibles.size(); j++)
	{
		collectibles[j]->collectibleCollision(player->rect);
	}
	
	if (stage == lvl4E_enemy || stage == lvl4H_enemy)
	{
		spiketime++;
	}

	//millis since game started
	unsigned int currentTime = LTimer::gameTime();

	//time since last update
	unsigned int deltaTime = currentTime - lastTime;

	//Convert each variable to a logRecord to be recorded
	logRecords.levelS = levelString;
	logRecords.time = duration;
	logRecords.enemyDeaths = player->enemyDeaths;
	logRecords.fallDeaths = player->fallDeaths;
	logRecords.ttc = timeToComplete;
	logRecords.fda = fallDeathsAllowed;
	logRecords.eda = enemyDeathsAllowed;

	if (splashScreen == true)
	{
		mainMenu = false;
		duration = (clock() - start) / (int)CLOCKS_PER_SEC;
		cout << duration << endl;
		if (duration >= 3)
		{
			splashScreen = false;
			mainMenu = true;
		}
	}


	//if we are not in the mainMenu we update the gameObjects
	if (!mainMenu && !endMenu && !splashScreen)
	{
		for (std::vector<GameObject*>::iterator i = gameObjects.begin(); i != gameObjects.end(); i++) 
		{
			(*i)->Update(deltaTime);
		}
	}

	//save the curent time for next frame
	lastTime = currentTime;
}


//calls render on all game entities
//this function draws all the Objects in the gaming Window OR calls the drawing-functions of the gameObjects
void Game::render()
{
	// prepare for new frame
	renderer.clear(Colour(r, g, b, a));

	
	if (splashScreen)
	{
		renderer.loadSplashImage();
	}

	//if we are in the mainMenu draw the mainMenu
	else if (mainMenu)
	{
		renderer.loadMenuImage();
	}
	else if (endMenu)
	{
		renderer.loadImageEnd();
	}

	//if we are not in the mainMenu call the render(drawing)-function of the gameObjects
	else
	{
		for (std::vector<GameObject*>::iterator i = gameObjects.begin(), e = gameObjects.end(); i != e; i++) 
		{
			(*i)->Render(renderer);
		}

	}

	// display the new frame (swap buffers)
	renderer.present();
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

		inputManager.ProcessInput(mainMenu);
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

	// if the event START happens we start the game and change the screen to the tutorial level

	if (evt == EventListener::Event::START && mainMenu) 
	{
		mainMenu = false;

		stage = tutorial;
		changeLevel = true;
		start = clock();
		cout << "Tutorial" << endl;
		//Start Recording
		Record();
	}



	// if the event QUIT happens we quit the game
	if (evt == EventListener::Event::QUIT) 
	{
		quit = true;
	}
	if (evt == EventListener::Event::RESTART)
	{
		splashScreen = true;
		endMenu = false;
		stage = splash;

	}

}

//in this function  we change the stage
//if the player hits the portal or leaves the mainMenu
void Game::changeStage()
{
	//checking which stage we are on
	switch (stage)
	{
	case splash:
		break;
	case menu:
		break;
	case tutorial:
		if (changeLevel)
		{
			
			blocks = levels.tutorial();

			for (int i = 0; i < blocks.size(); i++)
			{
				gameObjects.push_back(blocks[i]);
			}
			finish = new FinishLine(Rect(9, -3, 1, 1));
			finish->color = Colour(255, 255, 255);

			player->ChangePos(-9.5, 0);

			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			

			changeLevel = false;
		}
		if (!player->alive)
		{
			player->resetPlayer(-9.5, 0);
		}
		//Change to SECOND level
		if (finish->levelComplete == true)
		{
			changeLevel = true;
			stage = lvl1;
			cout << "Level 1" << endl;
			player->fallDeaths = 0;
			start = clock();
		}
		break;
	case lvl1:
		//if the player reaches the finish level we set somewhere else in the code the variable changeLevel to true
		if (changeLevel)
		{
			gameObjects.clear();
			blocks = levels.level1();

			for (int i = 0; i < blocks.size(); i++)
			{
				gameObjects.push_back(blocks[i]);
			}
			finish = new FinishLine(Rect(9, -6, 1, 1));
			finish->color = Colour(255, 255, 255);

			player->ChangePos(-9.5, 0);

			gameObjects.push_back(finish);
			gameObjects.push_back(player);

			changeLevel = false;
		}
		// If player dies move them back to the start level
		if (!player->alive)
		{
			player->resetPlayer(-9.5, 0);
		}

		//Change to SECOND level
		if (finish->levelComplete == true && duration > timeToComplete)
		{
			//Add stats at the end of the level
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl2A;
			cout << "Level 2A" << endl;
			player->fallDeaths = 0;
			start = clock();
		}
		else if (finish->levelComplete == true && duration <= timeToComplete)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl2B;
			cout << "Level 2B" << endl;
			player->fallDeaths = 0;
			start = clock();
		}
		break;
	case lvl2A:
		if (changeLevel)
		{
			gameObjects.clear();
			//adds in the platforms that the player jumps on
			blocks = levels.level2A();
			for (int i = 0; i < blocks.size(); i++)
			{
				gameObjects.push_back(blocks[i]);
			}
			//adds in the collectibles for the player to collect
			player->maxCollectibles = 4;
			collectibles = levels.c2A();
			for (int j = 0; j < collectibles.size(); j++)
			{
				gameObjects.push_back(collectibles[j]);
			}			

			player->ChangePos(-10, 0);

			finish = new FinishLine(Rect(20, -1.5, 1, 1));//-5
			finish->color = Colour(255, 255, 255);
			gameObjects.push_back(finish);

			gameObjects.push_back(player);
			changeLevel = false;
		}
		//The finish line moves on screen when all collectibles are collected
		if (player->collectibles >= player->maxCollectibles)
		{
			finish->finish.pos.x = 9;
		}
		//Player Dies if they fall off the world
		if (!player->alive)
		{
			player->resetPlayer(-10, 0);
		}
		//Change to THIRD level
		if (finish->levelComplete == true && duration > timeToComplete && player->fallDeaths > fallDeathsAllowed)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl3A;
			cout << "Level 3A" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
			start = clock();
		}
		else if (finish->levelComplete == true && duration > timeToComplete && player->fallDeaths <= fallDeathsAllowed)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl3B;
			cout << "Level 3B" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
			start = clock();
		}
		else if (finish->levelComplete == true && duration <= timeToComplete && player->fallDeaths > fallDeathsAllowed)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl3C;
			cout << "Level 3C" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
			start = clock();
		}
		else if (finish->levelComplete == true && duration <= timeToComplete && player->fallDeaths <= fallDeathsAllowed)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl3D;
			cout << "Level 3D" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
			start = clock();
		}
		break;
	case lvl2B:
		if (changeLevel)
		{
			gameObjects.clear();
			blocks = levels.level2B();
			for (int i = 0; i < blocks.size(); i++)
			{
				gameObjects.push_back(blocks[i]);
			}
			//adds in the collectibles for the player to collect
			player->maxCollectibles = 6;
			collectibles = levels.c2B();
			for (int j = 0; j < collectibles.size(); j++)
			{
				gameObjects.push_back(collectibles[j]);
			}

			finish = new FinishLine(Rect(20, -1.5, 1, 1));//-5
			finish->color = Colour(255, 255, 255);

			player->ChangePos(-10, 0);

			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			changeLevel = false;
		}
		//The finish line moves on screen when all collectibles are collected
		if (player->collectibles >= player->maxCollectibles)
		{
			finish->finish.pos.x = 9;
		}
		if (!player->alive)
		{
			player->resetPlayer(-10, 0);
		}
		//Change to THIRD level
		if (finish->levelComplete == true && duration > timeToComplete && player->fallDeaths > fallDeathsAllowed)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl3D;
			cout << "Level 3D" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
			start = clock();

		}
		else if (finish->levelComplete == true && duration > timeToComplete && player->fallDeaths <= fallDeathsAllowed)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl3E;
			cout << "Level 3E" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
			start = clock();
		}
		else if (finish->levelComplete == true && duration <= timeToComplete && player->fallDeaths > fallDeathsAllowed)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl3F;
			cout << "Level 3F" << endl;

			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
			start = clock();
		}
		else if (finish->levelComplete == true && duration <= timeToComplete && player->fallDeaths <= fallDeathsAllowed)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl3G;
			cout << "Level 3G" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
			start = clock();
		}
		break;
	case lvl3A:
		if (changeLevel)
		{
			gameObjects.clear();
			blocks = levels.level3A();
			for (int i = 0; i < blocks.size(); i++)
			{
				gameObjects.push_back(blocks[i]);
			}
			//adds in the collectibles for the player to collect
			player->maxCollectibles = 2;
			collectibles = levels.c3A();
			for (int j = 0; j < collectibles.size(); j++)
			{
				gameObjects.push_back(collectibles[j]);
			}
			//Loads in enemies from the level Manager
			enemies = levels.enemy3A();
			for (int e = 0; e < enemies.size(); e++)
			{
				gameObjects.push_back(enemies[e]);
			}

			finish = new FinishLine(Rect(20, 5, 1, 1));
			finish->color = Colour(255, 255, 255);

			player->ChangePos(-8, 4);

			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			changeLevel = false;
		}
		//The finish line moves on screen when all collectibles are collected
		if (player->collectibles >= player->maxCollectibles)
		{
			finish->finish.pos.x = 9;
		}
		//Change to FINAL level
		if (finish->levelComplete == true && player->enemyDeaths <= enemyDeathsAllowed)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl4E_enemy;
			cout << "Level 4E_Enemy" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
		}
		else if (finish->levelComplete == true && player->fallDeaths <= fallDeathsAllowed && player->enemyDeaths > enemyDeathsAllowed)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl4E_fall;
			cout << "Level 4E_fall" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
		}
		else if (finish->levelComplete == true && duration <= timeToComplete && player->fallDeaths > fallDeathsAllowed && player->enemyDeaths > enemyDeathsAllowed)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl4E_time;
			cout << "Level 4E_time" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
		}
		else if (finish->levelComplete == true && duration <= timeToComplete && player->fallDeaths > fallDeathsAllowed && player->enemyDeaths > enemyDeathsAllowed)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl4E_enemy;
			cout << "Level 4E_Enemy" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
		}
		if (!player->alive)
		{
			player->resetPlayer(-8, 4);
		}
		break;
	case lvl3B:
		if (changeLevel)
		{
			gameObjects.clear();
			blocks = levels.level3B();
			for (int i = 0; i < blocks.size(); i++)
			{
				gameObjects.push_back(blocks[i]);
			}
			//adds in the collectibles for the player to collect
			player->maxCollectibles = 2;
			collectibles = levels.c3B();
			for (int j = 0; j < collectibles.size(); j++)
			{
				gameObjects.push_back(collectibles[j]);
			}

			//Loads in enemies from the level Manager
			enemies = levels.enemy3B();
			for (int e = 0; e < enemies.size(); e++)
			{
				gameObjects.push_back(enemies[e]);
			}

			player->ChangePos(-8, 4);

			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			changeLevel = false;
		}
		//The finish line moves on screen when all collectibles are collected
		if (player->collectibles >= player->maxCollectibles)
		{
			finish->finish.pos.x = 9;
		}
		//Change to FINAL level
		if (finish->levelComplete == true && duration <= timeToComplete)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl4E_time;
			cout << "Level 4E_Time" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
		}
		else if (finish->levelComplete == true && player->fallDeaths <= fallDeathsAllowed && duration > timeToComplete)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl4E_enemy;
			cout << "Level 4E_enemy" << endl;
			player->fallDeaths = 0;
			player->collectibles = 0;
		}
		else if (finish->levelComplete == true && player->fallDeaths <= fallDeathsAllowed && player->enemyDeaths > enemyDeathsAllowed && duration > timeToComplete)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl4E_fall;
			cout << "Level 4E_fall" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
		}
		if (!player->alive)
		{
			player->resetPlayer(-8, 4);
		}
		break;

	case lvl3C:
		if (changeLevel)
		{
			gameObjects.clear();
			blocks = levels.level3C();
			for (int i = 0; i < blocks.size(); i++)
			{
				gameObjects.push_back(blocks[i]);
			}
			//adds in the collectibles for the player to collect
			player->maxCollectibles = 2;
			collectibles = levels.c3C();
			for (int j = 0; j < collectibles.size(); j++)
			{
				gameObjects.push_back(collectibles[j]);
			}
			//Loads in enemies from the level Manager
			enemies = levels.enemy3C();
			for (int e = 0; e < enemies.size(); e++)
			{
				gameObjects.push_back(enemies[e]);
			}

			finish = new FinishLine(Rect(20, 5, 1, 1));
			finish->color = Colour(255, 255, 255);

			player->ChangePos(-8, 4);

			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			changeLevel = false;
		}
		//The finish line moves on screen when all collectibles are collected
		if (player->collectibles >= player->maxCollectibles)
		{
			finish->finish.pos.x = 9;
		}
		//Change to FINAL level
		if (finish->levelComplete == true && player->fallDeaths <= fallDeathsAllowed)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl4E_fall;
			cout << "Level 4E_Fall" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
		}
		else if (finish->levelComplete == true && player->enemyDeaths <= enemyDeathsAllowed && player->fallDeaths > fallDeathsAllowed)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl4E_enemy;
			cout << "Level 4E_enemy" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
		}
		else if (finish->levelComplete == true && duration <= timeToComplete && player->enemyDeaths > enemyDeathsAllowed && player->fallDeaths > fallDeathsAllowed)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl4E_time;
			cout << "Level 4E_time" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
		}
		if (!player->alive)
		{
			player->resetPlayer(-8, 4);
		}
		break;
	case lvl3D:
		if (changeLevel)
		{
			gameObjects.clear();
			blocks = levels.level3D();
			for (int i = 0; i < blocks.size(); i++)
			{
				gameObjects.push_back(blocks[i]);
			}
			//adds in the collectibles for the player to collect
			player->maxCollectibles = 6;
			collectibles = levels.c3D();
			for (int j = 0; j < collectibles.size(); j++)
			{
				gameObjects.push_back(collectibles[j]);
			}
			//Loads in enemies from the level Manager
			enemies = levels.enemy3D();
			for (int e = 0; e < enemies.size(); e++)
			{
				gameObjects.push_back(enemies[e]);
			}

			finish = new FinishLine(Rect(20, 5, 1, 1));
			finish->color = Colour(255, 255, 255);

			player->ChangePos(-8, 4);

			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			changeLevel = false;
		}
		//The finish line moves on screen when all collectibles are collected
		if (player->collectibles >= player->maxCollectibles)
		{
			finish->finish.pos.x = 9;
		}
		//Change to FINAL level
		if (finish->levelComplete == true && duration <= timeToComplete)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl4E_time;
			cout << "Level 4E_Time" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
		}
		else if (finish->levelComplete == true && player->fallDeaths <= fallDeathsAllowed && duration > timeToComplete)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl4E_fall;
			cout << "Level 4E_Fall" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
		}
		else if (finish->levelComplete == true && player->enemyDeaths <= enemyDeathsAllowed && player->fallDeaths > fallDeathsAllowed && duration > timeToComplete)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl4E_enemy;
			cout << "Level 4E_Enemy" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
		}
		if (!player->alive)
		{
			player->resetPlayer(-8, 4);
		}
		break;

	case lvl3E:
		if (changeLevel)
		{
			gameObjects.clear();
			blocks = levels.level3E();
			for (int i = 0; i < blocks.size(); i++)
			{
				gameObjects.push_back(blocks[i]);
			}
			//adds in the collectibles for the player to collect
			player->maxCollectibles = 5;
			collectibles = levels.c3E();
			for (int j = 0; j < collectibles.size(); j++)
			{
				gameObjects.push_back(collectibles[j]);
			}
			//Loads in enemies from the level Manager
			enemies = levels.enemy3E();
			for (int e = 0; e < enemies.size(); e++)
			{
				gameObjects.push_back(enemies[e]);
			}
			finish = new FinishLine(Rect(20, 5, 1, 1));
			finish->color = Colour(255, 255, 255);

			player->ChangePos(-8, 4);

			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			changeLevel = false;
		}
		//The finish line moves on screen when all collectibles are collected
		if (player->collectibles >= player->maxCollectibles)
		{
			finish->finish.pos.x = 9;
		}
		//Change to FINAL level
		if (finish->levelComplete == true && duration <= timeToComplete)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl4H_time;
			cout << "Level 4H_Time" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
		}
		else if (finish->levelComplete == true && player->fallDeaths <= fallDeathsAllowed && duration > timeToComplete)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl4H_fall;
			cout << "Level 4H_Fall" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
		}
		else if (finish->levelComplete == true && player->enemyDeaths <= enemyDeathsAllowed && player->fallDeaths > fallDeathsAllowed && duration > timeToComplete)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl4E_enemy;
			cout << "Level 4E_Enemy" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
		}
		if (!player->alive)
		{
			player->resetPlayer(-8, 4);
		}
		break;
	case lvl3F:
		if (changeLevel)
		{
			gameObjects.clear();
			blocks = levels.level3F();
			for (int i = 0; i < blocks.size(); i++)
			{
				gameObjects.push_back(blocks[i]);
			}
			//adds in the collectibles for the player to collect
			player->maxCollectibles = 5;
			collectibles = levels.c3F();
			for (int j = 0; j < collectibles.size(); j++)
			{
				gameObjects.push_back(collectibles[j]);
			}
			//Loads in enemies from the level Manager
			enemies = levels.enemy3F();
			for (int e = 0; e < enemies.size(); e++)
			{
				gameObjects.push_back(enemies[e]);
			}
			finish = new FinishLine(Rect(20, 5, 1, 1));
			finish->color = Colour(255, 255, 255);

			player->ChangePos(-8, 4);

			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			changeLevel = false;
		}
		//The finish line moves on screen when all collectibles are collected
		if (player->collectibles >= player->maxCollectibles)
		{
			finish->finish.pos.x = 9;
		}
		//Change to FINAL level
		if (finish->levelComplete == true && player->enemyDeaths <= enemyDeathsAllowed)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl4H_enemy;
			cout << "Level 4H_Enemy" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
		}
		else if (finish->levelComplete == true && duration <= timeToComplete && player->enemyDeaths > enemyDeathsAllowed)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl4H_time;
			cout << "Level 4H_Time" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
		}
		else if (finish->levelComplete == true && player->fallDeaths <= fallDeathsAllowed && duration > timeToComplete && player->enemyDeaths > enemyDeathsAllowed)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl4H_fall;
			cout << "Level 4H_Fall" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
		}
		if (!player->alive)
		{
			player->resetPlayer(-8, 4);
		}
		break;
	case lvl3G:
		if (changeLevel)
		{
			gameObjects.clear();
			blocks = levels.level3G();
			for (int i = 0; i < blocks.size(); i++)
			{
				gameObjects.push_back(blocks[i]);
			}
			//adds in the collectibles for the player to collect
			player->maxCollectibles = 6;
			collectibles = levels.c3G();
			for (int j = 0; j < collectibles.size(); j++)
			{
				gameObjects.push_back(collectibles[j]);
			}
			//Loads in enemies from the level Manager
			enemies = levels.enemy3G();
			for (int e = 0; e < enemies.size(); e++)
			{
				gameObjects.push_back(enemies[e]);
			}

			finish = new FinishLine(Rect(20, 5, 1, 1));
			finish->color = Colour(255, 255, 255);

			player->ChangePos(-8, 4);

			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			changeLevel = false;
		}
		//The finish line moves on screen when all collectibles are collected
		if (player->collectibles >= player->maxCollectibles)
		{
			finish->finish.pos.x = 9;
		}
		//Change to FINAL level
		if (finish->levelComplete == true && player->fallDeaths <= fallDeathsAllowed)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl4H_fall;
			cout << "Level 4H_Fall" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
		}
		else if (finish->levelComplete == true && player->enemyDeaths <= enemyDeathsAllowed && player->fallDeaths > fallDeathsAllowed)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl4H_enemy;
			cout << "Level 4H_Enemy" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
		}
		else if (finish->levelComplete == true && duration <= timeToComplete && player->enemyDeaths > enemyDeathsAllowed && player->fallDeaths > fallDeathsAllowed)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			changeLevel = true;
			stage = lvl4H_time;
			cout << "Level 4H_time" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
		}
		if (!player->alive)
		{
			player->resetPlayer(-8, 4);
		}
		break;
	case lvl4E_enemy:
		if (changeLevel)
		{
			gameObjects.clear();
			blocks = levels.level4E_enemy();
			for (int i = 0; i < blocks.size(); i++)
			{
				gameObjects.push_back(blocks[i]);
			}
			//Loads in spikes from the level Manager
			spikes = levels.spikes4E();
			for (int s = 0; s < spikes.size(); s++)
			{
				gameObjects.push_back(spikes[s]);
			}

			//Loads in enemies from the level Manager
			enemies = levels.enemy4E_enemy();
			for (int e = 0; e < enemies.size(); e++)
			{
				gameObjects.push_back(enemies[e]);
			}

			finish = new FinishLine(Rect(9, -1, 1, 1));
			finish->color = Colour(255, 255, 255);

			player->ChangePos(-10, 0);

			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			changeLevel = false;
		}
		if (finish->levelComplete == true)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			inputManager.start = 2;
			changeLevel = true;
			stage = end;
		}
		if (!player->alive)
		{
			player->resetPlayer(-10, 0);
		}
		break;
	case lvl4E_fall:
		if (changeLevel)
		{
			gameObjects.clear();
			blocks = levels.level4E_fall();
			for (int i = 0; i < blocks.size(); i++)
			{
				gameObjects.push_back(blocks[i]);
			}

			fallingBlocks = levels.level4E_fallBlock();
			for (int i = 0; i < fallingBlocks.size(); i++)
			{
				gameObjects.push_back(fallingBlocks[i]);
			}

			finish = new FinishLine(Rect(9, 2, 1, 1));
			finish->color = Colour(255, 255, 255);

			player->ChangePos(-10, 0);

			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			changeLevel = false;
		}
		if (finish->levelComplete == true)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			inputManager.start = 2;
			changeLevel = true;
			stage = end;
		}
		if (!player->alive)
		{
			player->resetPlayer(-10, 0);
		}
		break;
	case lvl4E_time:
		if (changeLevel)
		{
			gameObjects.clear();
			blocks = levels.level4E_time();
			for (int i = 0; i < blocks.size(); i++)
			{
				gameObjects.push_back(blocks[i]);
			}

			finish = new FinishLine(Rect(9, 4, 1, 1));
			finish->color = Colour(255, 255, 255);

			player->ChangePos(-10, 6);

			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			changeLevel = false;
		}
		if (finish->levelComplete == true)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			inputManager.start = 2;
			changeLevel = true;
			stage = end;
		}
		if (!player->alive)
		{
			player->resetPlayer(-10, 6);
		}
		break;
	case lvl4H_enemy:
		if (changeLevel)
		{
			gameObjects.clear();
			blocks = levels.level4H_enemy();
			for (int i = 0; i < blocks.size(); i++)
			{
				gameObjects.push_back(blocks[i]);
			}
			//Loads in enemies from the level Manager
			enemies = levels.enemy4H_enemy();
			for (int e = 0; e < enemies.size(); e++)
			{
				gameObjects.push_back(enemies[e]);
			}

			//Loads in spikes from the level Manager
			spikes = levels.spikes4H();
			for (int s = 0; s < spikes.size(); s++)
			{
				gameObjects.push_back(spikes[s]);
			}

			finish = new FinishLine(Rect(9, -1, 1, 1));
			finish->color = Colour(255, 255, 255);

			player->ChangePos(-10, 0);

			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			changeLevel = false;
		}
		if (finish->levelComplete == true)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			inputManager.start = 2;
			changeLevel = true;
			stage = end;
		}
		if (!player->alive)
		{
			player->resetPlayer(-10, 0);
		}
		break;
	case lvl4H_fall:
		if (changeLevel)
		{
			gameObjects.clear();
			blocks = levels.level4H_fall();
			for (int i = 0; i < blocks.size(); i++)
			{
				gameObjects.push_back(blocks[i]);
			}

			fallingBlocks = levels.level4H_fallBlock();
			for (int i = 0; i < fallingBlocks.size(); i++)
			{
				gameObjects.push_back(fallingBlocks[i]);
			}

			finish = new FinishLine(Rect(9, 2, 1, 1));
			finish->color = Colour(255, 255, 255);

			player->ChangePos(-10, 0);

			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			changeLevel = false;
		}
		if (finish->levelComplete == true)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			inputManager.start = 2;
			changeLevel = true;
			stage = end;
		}
		if (!player->alive)
		{
			player->resetPlayer(-10, 0);
		}
		break;
	case lvl4H_time:
		if (changeLevel)
		{
			gameObjects.clear();
			blocks = levels.level4H_time();
			for (int i = 0; i < blocks.size(); i++)
			{
				gameObjects.push_back(blocks[i]);
			}

			finish = new FinishLine(Rect(9, 5, 1, 1));
			finish->color = Colour(255, 255, 255);

			player->ChangePos(-10, 6);

			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			changeLevel = false;
		}
		if (finish->levelComplete == true)
		{
			if (record)
			{
				logs.push_back(logRecords);
			}
			inputManager.start = 2;
			changeLevel = true;
			stage = end;
		}
		if (!player->alive)
		{
			player->resetPlayer(-10, 6);
		}
		break;
	case end:
		if (changeLevel)
		{
			gameObjects.clear();
			endMenu = true;
			changeLevel = false;
			//Finish Recording
			Record();
		}

		break;

	default:
		break;
	}
	finish->NextLevel(player->rect);
}

//Sets the positions and speeds of the enemies
void Game::moveEnemy()
{
	if (stage == lvl3A)
	{
		for (int e = 0; e < enemies.size(); e++)
		{
							//(xMin, xMax, speed)
			enemies.at(0)->Move(4, 7, 0.015);
		}
	}
	else if (stage == lvl3B)
	{
		for (int e = 0; e < enemies.size(); e++)
		{
			enemies.at(0)->Move(4, 7, 0.005);
			enemies.at(1)->Move(-2, -1, 0.005);
		}
	}
	else if (stage == lvl3C)
	{
		for (int e = 0; e < enemies.size(); e++)
		{
			enemies.at(0)->Move(3, 7, 0.0025);
			enemies.at(1)->Move(-2, -1, 0.005);
			enemies.at(2)->Move(-4, 0, 0.0025);
			enemies.at(3)->Move(-6, -5, 0.005);
		}
	}
	else if (stage == lvl3D)
	{
		for (int e = 0; e < enemies.size(); e++)
		{
			enemies.at(0)->Move(5, 8, 0.010);
			enemies.at(1)->Move(-4, -1, 0.010);

		}
	}
	else if (stage == lvl3E)
	{
		for (int e = 0; e < enemies.size(); e++)
		{
			enemies.at(0)->Move(3, 7, 0.015);
			enemies.at(1)->Move(-4, -1, 0.010);
		}
	}
	else if (stage == lvl3F)
	{
		for (int e = 0; e < enemies.size(); e++)
		{
			enemies.at(0)->Move(3, 7, 0.010);
			enemies.at(1)->Move(-4, -1, 0.010);
			enemies.at(2)->Move(-8, -5, 0.010);
		}
	}
	else if (stage == lvl3G)
	{
		for (int e = 0; e < enemies.size(); e++)
		{
			enemies.at(0)->Move(3, 7, 0.010);
			enemies.at(1)->Move(-4, -1, 0.010);
			enemies.at(2)->Move(-8, -5, 0.010);
		}
	}
	else if (stage == lvl4E_enemy)
	{
		for (int e = 0; e < enemies.size(); e++)
		{
			enemies.at(0)->Move(-9, -7, 0.0025);
			enemies.at(1)->Move(-5, -3, 0.0025);
			enemies.at(2)->Move(-2, 0, 0.0025);
			enemies.at(3)->Move(2, 6, 0.0025);
		}

		for (int s = 0; s < spikes.size(); s++)
		{
			spikes.at(0)->Move(-10, 10.5, 0.05);
			spikes.at(1)->Move(-12, 10.5, 0.075);
		}

	}
	else if (stage == lvl4H_enemy)
	{
		for (int e = 0; e < enemies.size(); e++)
		{
			enemies.at(0)->Move(-9, -7, 0.005);
			enemies.at(1)->Move(-5, -3, 0.005);
			enemies.at(2)->Move(-2, 0, 0.005);
			enemies.at(3)->Move(2, 4, 0.005);
			enemies.at(4)->Move(5, 6, 0.005);
		}
		for (int s = 0; s < spikes.size(); s++)
		{
			spikes.at(0)->Move(-10, 10.5, 0.1);
			spikes.at(1)->Move(-12, 10.5, 0.125);
		}
	}
}

// Sets the variables for each level
void Game::levelVariables()
{
	if (stage == lvl1)
	{
		levelString = "Level 1";
		timeToComplete = 25;
		fallDeathsAllowed = 0;
		enemyDeathsAllowed = 0;
		duration = (clock() - start) / (int)CLOCKS_PER_SEC;
		cout << duration << endl;
	}
	else if (stage == lvl2A)
	{
		levelString = "Level 2A";
		timeToComplete = 50;
		fallDeathsAllowed = 2;
		enemyDeathsAllowed = 0;
		duration = (clock() - start) / (int)CLOCKS_PER_SEC;
		cout << duration << endl;
	}
	else if (stage == lvl2B)
	{
		levelString = "Level 2B";
		timeToComplete = 50;
		fallDeathsAllowed = 2;
		enemyDeathsAllowed = 0;
		duration = (clock() - start) / (int)CLOCKS_PER_SEC;
		cout << duration << endl;
	}
	else if (stage == lvl3A)
	{
		levelString = "Level 3A";
		timeToComplete = 40;
		fallDeathsAllowed = 3;
		enemyDeathsAllowed = 3;
		duration = (clock() - start) / (int)CLOCKS_PER_SEC;
		cout << duration << endl;
	}
	else if (stage == lvl3B)
	{
		levelString = "Level 3B";
		timeToComplete = 40;
		fallDeathsAllowed = 2;
		enemyDeathsAllowed = 2;
		duration = (clock() - start) / (int)CLOCKS_PER_SEC;
		cout << duration << endl;
	}
	else if (stage == lvl3C)
	{
		levelString = "Level 3C";
		timeToComplete = 45;
		fallDeathsAllowed = 2;
		enemyDeathsAllowed = 4;
		duration = (clock() - start) / (int)CLOCKS_PER_SEC;
		cout << duration << endl;
	}
	else if (stage == lvl3D)
	{
		levelString = "Level 3D";
		timeToComplete = 40;
		fallDeathsAllowed = 2;
		enemyDeathsAllowed = 3;
		duration = (clock() - start) / (int)CLOCKS_PER_SEC;
		cout << duration << endl;
	}
	else if (stage == lvl3E)
	{
		levelString = "Level 3E";
		timeToComplete = 50;
		fallDeathsAllowed = 2;
		enemyDeathsAllowed = 3;
		duration = (clock() - start) / (int)CLOCKS_PER_SEC;
		cout << duration << endl;
	}
	else if (stage == lvl3F)
	{
		levelString = "Level 3F";
		timeToComplete = 50;
		fallDeathsAllowed = 2;
		enemyDeathsAllowed = 4;
		duration = (clock() - start) / (int)CLOCKS_PER_SEC;
		cout << duration << endl;
	}
	else if (stage == lvl3G)
	{
		levelString = "Level 3G";
		timeToComplete = 60;
		fallDeathsAllowed = 2;
		enemyDeathsAllowed = 5;
		duration = (clock() - start) / (int)CLOCKS_PER_SEC;
		cout << duration << endl;
	}
	else if (stage == lvl4E_time)
	{
		levelString = "Level 4E Time";
		timeToComplete = 45;
		fallDeathsAllowed = 0;
		enemyDeathsAllowed = 0;
		duration = (clock() - start) / (int)CLOCKS_PER_SEC;
		cout << duration << endl;
	}
	else if (stage == lvl4H_time)
	{
		levelString = "Level 4H Time";
		timeToComplete = 40;
		fallDeathsAllowed = 0;
		enemyDeathsAllowed = 0;
		duration = (clock() - start) / (int)CLOCKS_PER_SEC;
		cout << duration << endl;
	}
	else if (stage == lvl4E_fall)
	{
		timeToComplete = 0;
		fallDeathsAllowed = 0;
		enemyDeathsAllowed = 0;
		levelString = "Level 4E Fall";
	}
	else if (stage == lvl4H_fall)
	{
		timeToComplete = 0;
		fallDeathsAllowed = 0;
		enemyDeathsAllowed = 0;
		levelString = "Level 4H Fall";
	}
	else if (stage == lvl4E_enemy)
	{
		timeToComplete = 0;
		fallDeathsAllowed = 0;
		enemyDeathsAllowed = 0;
		levelString = "Level 4E Enemy";
	}
	else if (stage == lvl4H_enemy)
	{
		timeToComplete = 0;
		fallDeathsAllowed = 0;
		enemyDeathsAllowed = 0;
		levelString = "Level 4H Enemy";
	}
}
//Outputs the stats to an excel file
void Game::Record()
{
	//Start recording
	if (!record)
	{
		//Recording
		std::cout << "Recording" << std::endl;
		record = true;
	}
	//Stop recording
	else
	{
		record = false;
		std::cout << "Logging" << std::endl;
		std::string filename;
		auto t = std::time(nullptr);
		tm t_m;
		localtime_s(&t_m, &t);
		std::ostringstream oss;
		//Formats time
		oss << std::put_time(&t_m, "%d-%m-%Y-%H-%M-%S");
		filename = "EventLog";
		filename += oss.str();
		//Excel format
		filename += ".csv";
		ofstream file;
		file.open(filename.c_str());

		for (int i = 0; i < logs.size(); i++)
		{
			file << logs.at(i).levelS << ", ";
			file <<  "Time: " << logs.at(i).time << "/" << logs.at(i).ttc <<  ", " ;
			file <<  "Enemy Deaths: " << logs.at(i).enemyDeaths << "/" << logs.at(i).eda << ", ";
			file <<  "Fall Deaths: " << logs.at(i).fallDeaths << "/" << logs.at(i).fda << ", ";

			file << "\n";
		}

		//Close file and empty 
		file.close();
		logs.clear();
		std::cout << "File written" << std::endl;
	}
	
}

