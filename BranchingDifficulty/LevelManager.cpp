#include "LevelManager.h"


LevelManager::LevelManager()
{
}


LevelManager::~LevelManager()
{
}

std::vector<Platform*> LevelManager::level1()
{
	block.clear();

	Platform* floor = new Platform(Rect(-10, -10, 20, 10));
	floor->color = Colour(200, 0, 0);

	block.push_back(floor);

	return block;
}
