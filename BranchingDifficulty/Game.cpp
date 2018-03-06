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
	renderer.init(winSize, "Simple SDL App");

	//set up the viewport
	//we want the vp centred on origin and 20 units wide
	float aspectRatio = winSize.w / winSize.h;

	//viewpoint attributes
	//width says how the window is divided into Units (here the 600px wide window is divided into 20 Units so)
	float vpWidth = 20;

	//here we set the point x=0 y=0  to the mid of the window
	Size2D vpSize(vpWidth, vpWidth / aspectRatio);
	Point2D vpBottomLeft(-vpSize.w / 2, -vpSize.h / 2);

	mainMenu = true;
	Rect vpRect(vpBottomLeft, vpSize);
	renderer.setViewPort(vpRect);

	//setting the background colour in the mainMenu
	r = 150;
	g = 0;
	b = 102;

	lastTime = LTimer::gameTime();
	//time = 0;

	startMenu->LoadTextStart(renderer);
	startMenu->LoadTextEnd(renderer);
	//All the Events we need in the game
	//the first two are events regarding to the game (window)
	//the other five are events regarding the main character (interaction with the keyboard for moving and jumping)


	inputManager.AddListener(EventListener::Event::RESTART, this);
	inputManager.AddListener(EventListener::Event::START, this);
	inputManager.AddListener(EventListener::Event::QUIT, this);
	inputManager.AddListener(EventListener::Event::RECORD, this);
	inputManager.AddListener(EventListener::Event::LEFT, player);
	inputManager.AddListener(EventListener::Event::RIGHT, player);
	inputManager.AddListener(EventListener::Event::STOP, player);
	inputManager.AddListener(EventListener::Event::JUMP, player);
	inputManager.AddListener(EventListener::Event::SUPERJUMP, player);

	//numCollect = 0;
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
	timer();

	player->setInAir(true);
	player->setOnPlatform(false);

	//these for loops check if there is any collision with gameObjects (like platforms or water) and thomas 
	for (int i = 0; i < blocks.size(); i++)
	{
		player->PlatformCollision(blocks[i]->floor);
	}

	player->enemyCollision(enemy1->enemy);
	player->enemyCollision(enemy2->enemy);
	player->enemyCollision(enemy3->enemy);
	player->enemyCollision(enemy4->enemy);
	player->enemyCollision(enemy5->enemy);

	for (int j = 0; j < collectibles.size(); j++)
	{
		player->collectibleCollision(collectibles[j]->collectible);
	}

	for (int j = 0; j < collectibles.size(); j++)
	{
		collectibles[j]->collectibleCollision(player->rect);
	}
	
	

	//millis since game started
	unsigned int currentTime = LTimer::gameTime();

	//time since last update
	unsigned int deltaTime = currentTime - lastTime;


	//if we are not in the mainMenu we update the gameObjects
	if (!mainMenu && !endMenu)
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

	//if we are in the mainMenu draw the mainMenu
	if (mainMenu)
	{
		renderer.loadImage();
		startMenu->Render(renderer);
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

		inputManager.ProcessInput();
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

	// if the event START happens we start the game and change the screen to the first level
	if (evt == EventListener::Event::START) 
	{
		mainMenu = false;
		//stage = lvl1;
		stage = lvl2A;
		//stage = lvl3B;
		//stage = lvl4E_fall;
		changeLevel = true;
		start = clock();
	}

	// if the event QUIT happens we quit the game
	if (evt == EventListener::Event::QUIT) 
	{
		quit = true;
	}
	if (evt == EventListener::Event::RESTART)
	{
		mainMenu = true;
		endMenu = false;
		stage = menu;

	}

}

//in this function  we change the stage
//if the player hits the portal or leaves the mainMenu
void Game::changeStage()
{
	//checking which stage we are on
	switch (stage)
	{
	case menu:
		break;
	case lvl1:
		//if the player reaches the portal we set somewhere else in the code the variable changeLevel to true
		if (changeLevel)
		{
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
		if (!player->alive)
		{
			player->resetPlayer(-9.5, 0);
		}
		//Change to SECOND level
		if (finish->levelComplete == true && duration > 25)
		{
			changeLevel = true;
			stage = lvl2A;
			cout << "Time Taken: " << duration << " seconds out of 25" << endl;
			cout << "Level 2A" << endl;
			player->fallDeaths = 0;
			start = clock();
		}
		else if (finish->levelComplete == true && duration <= 25)
		{
			changeLevel = true;
			stage = lvl2B;
			cout << "Time Taken: " << duration << " seconds out of 25" <<  endl;
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
		if (finish->levelComplete == true && duration > 35 && player->fallDeaths > 3)
		{
			changeLevel = true;
			stage = lvl3A;
			cout << "Level 3A" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
			start = clock();
		}
		else if (finish->levelComplete == true && duration > 35 && player->fallDeaths <= 3)
		{
			changeLevel = true;
			stage = lvl3B;
			cout << "Level 3B" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
			start = clock();
		}
		else if (finish->levelComplete == true && duration <= 35 && player->fallDeaths > 3)
		{
			changeLevel = true;
			stage = lvl3C;
			cout << "Level 3C" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			player->collectibles = 0;
			start = clock();
		}
		else if (finish->levelComplete == true && duration <= 35 && player->fallDeaths <= 3)
		{
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
			finish = new FinishLine(Rect(9, -1.5, 1, 1));//-5
			finish->color = Colour(255, 255, 255);

			player->ChangePos(-10, 0);

			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			changeLevel = false;
		}
		if (!player->alive)
		{
			player->resetPlayer(-10, 0);
		}
		//Change to THIRD level
		if (finish->levelComplete == true && duration > 35 && player->fallDeaths > 3)
		{
			changeLevel = true;
			stage = lvl3D;
			cout << "Level 3D" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			start = clock();
		}
		else if (finish->levelComplete == true && duration > 35 && player->fallDeaths <= 3)
		{
			changeLevel = true;
			stage = lvl3E;
			cout << "Level 3E" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			start = clock();
		}
		else if (finish->levelComplete == true && duration <= 35 && player->fallDeaths > 3)
		{
			changeLevel = true;
			stage = lvl3F;
			cout << "Level 3F" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
			start = clock();
		}
		else if (finish->levelComplete == true && duration <= 35 && player->fallDeaths <= 3)
		{
			changeLevel = true;
			stage = lvl3G;
			cout << "Level 3G" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
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
			finish = new FinishLine(Rect(9, 5, 1, 1));
			finish->color = Colour(255, 255, 255);

			enemy1 = new Enemy(Rect(6, -2, 1, 1));
			enemy1->color = Colour(244, 66, 66);

			player->ChangePos(-8, 4);

			gameObjects.push_back(enemy1);
			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			changeLevel = false;
		}
		//Change to FINAL level
		if (finish->levelComplete == true && player->enemyDeaths <= 1)
		{
			changeLevel = true;
			stage = lvl4E_enemy;
			cout << "Level 4E_Enemy" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
		}
		else if (finish->levelComplete == true && player->fallDeaths <= 1 && player->enemyDeaths > 1)
		{
			changeLevel = true;
			stage = lvl4E_fall;
			cout << "Level 4E_fall" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
		}
		else if (finish->levelComplete == true && duration <= 40 && player->fallDeaths > 1 && player->enemyDeaths > 1)
		{
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
	case lvl3B:
		if (changeLevel)
		{
			gameObjects.clear();
			blocks = levels.level3B();
			for (int i = 0; i < blocks.size(); i++)
			{
				gameObjects.push_back(blocks[i]);
			}
			finish = new FinishLine(Rect(9, 5, 1, 1));
			finish->color = Colour(255, 255, 255);

			enemy1 = new Enemy(Rect(6, -2, 1, 1));
			enemy1->color = Colour(244, 66, 66);

			enemy2 = new Enemy(Rect(-2, 2, 1, 1));
			enemy2->color = Colour(244, 66, 66);

			player->ChangePos(-8, 4);

			gameObjects.push_back(enemy1);
			gameObjects.push_back(enemy2);
			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			changeLevel = false;
		}
		//Change to FINAL level
		if (finish->levelComplete == true && duration <= 40)
		{
			changeLevel = true;
			stage = lvl4E_time;
			cout << "Level 4E_Time" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
		}
		else if (finish->levelComplete == true && player->fallDeaths <= 2 && duration > 40)
		{
			changeLevel = true;
			stage = lvl4E_enemy;
			cout << "Level 4E_enemy" << endl;
			player->fallDeaths = 0;
		}
		else if (finish->levelComplete == true && player->fallDeaths <= 2 && player->enemyDeaths > 2 && duration > 40)
		{
			changeLevel = true;
			stage = lvl4E_fall;
			cout << "Level 4E_fall" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
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
			finish = new FinishLine(Rect(9, 5, 1, 1));
			finish->color = Colour(255, 255, 255);

			enemy1 = new Enemy(Rect(6, -2, 1, 1));
			enemy1->color = Colour(244, 66, 66);

			enemy2 = new Enemy(Rect(-2, 2, 1, 1));
			enemy2->color = Colour(244, 66, 66);

			enemy3 = new Enemy(Rect(-3, 0, 1, 1));
			enemy3->color = Colour(244, 66, 66);

			enemy4 = new Enemy(Rect(-5, 2, 1, 1));
			enemy4->color = Colour(244, 66, 66);

			player->ChangePos(-8, 4);

			gameObjects.push_back(enemy1);
			gameObjects.push_back(enemy2);
			gameObjects.push_back(enemy3);
			gameObjects.push_back(enemy4);

			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			changeLevel = false;
		}
		//Change to FINAL level
		if (finish->levelComplete == true && player->fallDeaths <= 2)
		{
			changeLevel = true;
			stage = lvl4E_fall;
			cout << "Level 4E_Fall" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
		}
		else if (finish->levelComplete == true && player->enemyDeaths <= 4 && player->fallDeaths > 2)
		{
			changeLevel = true;
			stage = lvl4E_enemy;
			cout << "Level 4E_enemy" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
		}
		else if (finish->levelComplete == true && duration <= 45 && player->enemyDeaths > 4 && player->fallDeaths > 2)
		{
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
			finish = new FinishLine(Rect(9, 5, 1, 1));
			finish->color = Colour(255, 255, 255);

			enemy1 = new Enemy(Rect(6, -2, 1, 1));
			enemy1->color = Colour(244, 66, 66);

			enemy2 = new Enemy(Rect(-3, 0, 1, 1));
			enemy2->color = Colour(244, 66, 66);

			player->ChangePos(-8, 4);

			gameObjects.push_back(enemy1);
			gameObjects.push_back(enemy2);
			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			changeLevel = false;
		}
		//Change to FINAL level
		if (finish->levelComplete == true && duration <= 40)
		{
			changeLevel = true;
			stage = lvl4E_time;
			cout << "Level 4E_Time" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
		}
		else if (finish->levelComplete == true && player->fallDeaths <= 2 && duration > 40)
		{
			changeLevel = true;
			stage = lvl4E_fall;
			cout << "Level 4E_Fall" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
		}
		else if (finish->levelComplete == true && player->enemyDeaths <= 3 && player->fallDeaths > 2 && duration > 40)
		{
			changeLevel = true;
			stage = lvl4E_enemy;
			cout << "Level 4E_Enemy" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
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
			finish = new FinishLine(Rect(9, 5, 1, 1));
			finish->color = Colour(255, 255, 255);

			enemy1 = new Enemy(Rect(6, -2, 1, 1));
			enemy1->color = Colour(244, 66, 66);

			enemy2 = new Enemy(Rect(-3, 0, 1, 1));
			enemy2->color = Colour(244, 66, 66);


			player->ChangePos(-8, 4);

			gameObjects.push_back(enemy1);
			gameObjects.push_back(enemy2);
			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			changeLevel = false;
		}
		//Change to FINAL level
		if (finish->levelComplete == true && duration <= 45)
		{
			changeLevel = true;
			stage = lvl4E_time;
			cout << "Level 4E_Time" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
		}
		else if (finish->levelComplete == true && player->fallDeaths <= 2 && duration > 45)
		{
			changeLevel = true;
			stage = lvl4E_fall;
			cout << "Level 4E_Fall" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;

		}
		else if (finish->levelComplete == true && player->enemyDeaths <= 3 && player->fallDeaths > 2 && duration > 45)
		{
			changeLevel = true;
			stage = lvl4E_enemy;
			cout << "Level 4E_Enemy" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
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

			finish = new FinishLine(Rect(9, 5, 1, 1));
			finish->color = Colour(255, 255, 255);

			enemy1 = new Enemy(Rect(6, -2, 1, 1));
			enemy1->color = Colour(244, 66, 66);

			enemy2 = new Enemy(Rect(-3, 0, 1, 1));
			enemy2->color = Colour(244, 66, 66);

			enemy3 = new Enemy(Rect(-6, 0, 1, 1));
			enemy3->color = Colour(244, 66, 66);

			player->ChangePos(-8, 4);

			gameObjects.push_back(enemy1);
			gameObjects.push_back(enemy2);
			gameObjects.push_back(enemy3);
			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			changeLevel = false;
		}
		//Change to FINAL level
		if (finish->levelComplete == true && player->enemyDeaths <= 3)
		{
			changeLevel = true;
			stage = lvl4E_enemy;
			cout << "Level 4E_Enemy" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
		}
		else if (finish->levelComplete == true && duration <= 45 && player->enemyDeaths > 3)
		{
			changeLevel = true;
			stage = lvl4E_time;
			cout << "Level 4E_Time" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
		}
		else if (finish->levelComplete == true && player->fallDeaths <= 2 && duration > 45 && player->enemyDeaths > 3)
		{
			changeLevel = true;
			stage = lvl4E_fall;
			cout << "Level 4E_Fall" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
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

			finish = new FinishLine(Rect(9, 5, 1, 1));
			finish->color = Colour(255, 255, 255);

			enemy1 = new Enemy(Rect(6, -2, 1, 1));
			enemy1->color = Colour(244, 66, 66);

			enemy2 = new Enemy(Rect(-3, 0, 1, 1));
			enemy2->color = Colour(244, 66, 66);

			enemy3 = new Enemy(Rect(-6, 0, 1, 1));
			enemy3->color = Colour(244, 66, 66);

			player->ChangePos(-8, 4);

			gameObjects.push_back(enemy1);
			gameObjects.push_back(enemy2);
			gameObjects.push_back(enemy3);
			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			changeLevel = false;
		}
		//Change to FINAL level
		if (finish->levelComplete == true && player->fallDeaths <= 2)
		{
			changeLevel = true;
			stage = lvl4E_fall;
			cout << "Level 4E_Fall" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
		}
		else if (finish->levelComplete == true && player->enemyDeaths <= 2 && player->fallDeaths > 2)
		{
			changeLevel = true;
			stage = lvl4E_enemy;
			cout << "Level 4E_Enemy" << endl;
			player->fallDeaths = 0;
			player->enemyDeaths = 0;
		}
		else if (finish->levelComplete == true && duration <= 40 && player->enemyDeaths > 2 && player->fallDeaths > 2)
		{
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
	case lvl4E_enemy:
		if (changeLevel)
		{
			gameObjects.clear();
			blocks = levels.level4E_enemy();
			for (int i = 0; i < blocks.size(); i++)
			{
				gameObjects.push_back(blocks[i]);
			}

			finish = new FinishLine(Rect(9, -1, 1, 1));
			finish->color = Colour(255, 255, 255);

			enemy1 = new Enemy(Rect(-7, -1, 1, 1));
			enemy1->color = Colour(244, 66, 66);

			enemy2 = new Enemy(Rect(-5, -1, 1, 1));
			enemy2->color = Colour(244, 66, 66);

			enemy3 = new Enemy(Rect(0, -1, 1, 1));
			enemy3->color = Colour(244, 66, 66);

			enemy4 = new Enemy(Rect(5, -1, 1, 1));
			enemy4->color = Colour(244, 66, 66);

			player->ChangePos(-10, 0);

			gameObjects.push_back(enemy1);
			gameObjects.push_back(enemy2);
			gameObjects.push_back(enemy3);
			gameObjects.push_back(enemy4);

			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			changeLevel = false;
		}
		if (finish->levelComplete == true)
		{
			changeLevel = true;
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

			finish = new FinishLine(Rect(9, 2, 1, 1));
			finish->color = Colour(255, 255, 255);

			player->ChangePos(-10, 0);

			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			changeLevel = false;
		}
		if (finish->levelComplete == true)
		{
			changeLevel = true;
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
			changeLevel = true;
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

			finish = new FinishLine(Rect(9, -1, 1, 1));
			finish->color = Colour(255, 255, 255);

			enemy1 = new Enemy(Rect(-7, -1, 1, 1));
			enemy1->color = Colour(244, 66, 66);

			enemy2 = new Enemy(Rect(-5, -1, 1, 1));
			enemy2->color = Colour(244, 66, 66);

			enemy3 = new Enemy(Rect(0, -1, 1, 1));
			enemy3->color = Colour(244, 66, 66);

			enemy4 = new Enemy(Rect(3, -1, 1, 1));
			enemy4->color = Colour(244, 66, 66);

			enemy5 = new Enemy(Rect(6, -1, 1, 1));
			enemy5->color = Colour(244, 66, 66);

			player->ChangePos(-10, 0);

			gameObjects.push_back(enemy1);
			gameObjects.push_back(enemy2);
			gameObjects.push_back(enemy3);
			gameObjects.push_back(enemy4);
			gameObjects.push_back(enemy5);

			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			changeLevel = false;
		}
		if (finish->levelComplete == true)
		{
			changeLevel = true;
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

			finish = new FinishLine(Rect(9, 2, 1, 1));
			finish->color = Colour(255, 255, 255);

			player->ChangePos(-10, 0);

			gameObjects.push_back(finish);
			gameObjects.push_back(player);
			changeLevel = false;
		}
		if (finish->levelComplete == true)
		{
			changeLevel = true;
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
			changeLevel = true;
		}
		if (!player->alive)
		{
			player->resetPlayer(-10, 6);
		}
		break;

	default:
		break;
	}
	finish->NextLevel(player->rect);
}

void Game::moveEnemy()
{
	if (stage == lvl3A)
	{
				//(xMin, xMax, speed)
		enemy1->Move(4, 7, 0.015);
	}
	else if (stage == lvl3B)
	{
		enemy1->Move(4, 7, 0.015);
		enemy2->Move(-2, -1, 0.015);
	}
	else if (stage == lvl3C)
	{
		enemy1->Move(3, 7, 0.010);
		enemy2->Move(-2, -1, 0.015);
		enemy3->Move(-4, 0, 0.010);
		enemy4->Move(-6, -5, 0.015);
	}
	else if (stage == lvl3D)
	{
		enemy1->Move(5, 8, 0.010);
		enemy2->Move(-4, -3, 0.010);
	}
	else if (stage == lvl3E)
	{
		enemy1->Move(3, 7, 0.015);
		enemy2->Move(-4, -3, 0.010);
	}
	else if (stage == lvl3F)
	{
		enemy1->Move(3, 7, 0.015);
		enemy2->Move(-4, -1, 0.015);
		enemy3->Move(-8, -5, 0.015);
	}
	else if (stage == lvl3G)
	{
		enemy1->Move(3, 7, 0.015);
		enemy2->Move(-4, -1, 0.015);
		enemy3->Move(-8, -5, 0.015);
	}
	else if (stage == lvl4E_enemy)
	{
		enemy1->Move(-9, -7, 0.010);
		enemy2->Move(-5, -3, 0.010);
		enemy3->Move(-2, 0, 0.010);
		enemy4->Move(2, 6, 0.010);
	}
	else if (stage == lvl4H_enemy)
	{
		enemy1->Move(-9, -7, 0.015);
		enemy2->Move(-5, -3, 0.015);
		enemy3->Move(-2, 0, 0.015);
		enemy4->Move(2, 4, 0.015);
		enemy5->Move(5, 6, 0.015);
	}
}

void Game::timer()
{
	if (stage == lvl1)
	{
		duration = (clock() - start) / (int)CLOCKS_PER_SEC;
		cout << duration << endl;
	}
	else if (stage == lvl2A)
	{
		duration = (clock() - start) / (int)CLOCKS_PER_SEC;
		//cout << duration << endl;
	}
	else if (stage == lvl2B)
	{
		duration = (clock() - start) / (int)CLOCKS_PER_SEC;
		cout << duration << endl;
	}
	else if (stage == lvl3A)
	{
		duration = (clock() - start) / (int)CLOCKS_PER_SEC;
		cout << duration << endl;
	}
	else if (stage == lvl3B)
	{
		duration = (clock() - start) / (int)CLOCKS_PER_SEC;
		cout << duration << endl;
	}
	else if (stage == lvl3C)
	{
		duration = (clock() - start) / (int)CLOCKS_PER_SEC;
		cout << duration << endl;
	}
	else if (stage == lvl3D)
	{
		duration = (clock() - start) / (int)CLOCKS_PER_SEC;
		cout << duration << endl;
	}
	else if (stage == lvl3E)
	{
		duration = (clock() - start) / (int)CLOCKS_PER_SEC;
		cout << duration << endl;
	}
	else if (stage == lvl3F)
	{
		duration = (clock() - start) / (int)CLOCKS_PER_SEC;
		cout << duration << endl;
	}
	else if (stage == lvl3G)
	{
		duration = (clock() - start) / (int)CLOCKS_PER_SEC;
		cout << duration << endl;
	}
	else if (stage == lvl4E_time)
	{
		duration = (clock() - start) / (int)CLOCKS_PER_SEC;
		cout << duration << endl;
	}
	else if (stage == lvl4H_time)
	{
		duration = (clock() - start) / (int)CLOCKS_PER_SEC;
		cout << duration << endl;
	}
}


