#pragma once

#include "Platform.h"

class LevelManager
{
public:
	LevelManager();
	~LevelManager();

	std::vector<Platform*> block;

	std::vector<Platform*> level1();
	std::vector<Platform*> level2A();
	std::vector<Platform*> level2B();
	std::vector<Platform*> level3A();
};

