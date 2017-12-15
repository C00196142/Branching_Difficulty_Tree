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

	Platform* floor1 = new Platform(Rect(-10, -10, 5, 10));
	floor1->color = Colour(200, 0, 0);

	Platform* floor2 = new Platform(Rect(-2, -7, 5, 10));
	floor2->color = Colour(200, 0, 0);

	block.push_back(floor1);
	block.push_back(floor2);

	return block;
}
