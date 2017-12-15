#pragma once

#include "Platform.h"

class LevelManager
{
public:
	LevelManager();
	~LevelManager();

	std::vector<Platform*> block;

	std::vector<Platform*> level1();
};

