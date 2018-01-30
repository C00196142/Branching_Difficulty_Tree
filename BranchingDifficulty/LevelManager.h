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
	std::vector<Platform*> level3B();
	std::vector<Platform*> level3C();
	std::vector<Platform*> level3D();
	std::vector<Platform*> level3E();
	std::vector<Platform*> level3F();
	std::vector<Platform*> level3G();

	std::vector<Platform*> level4E_enemy();
	std::vector<Platform*> level4E_fall();
	std::vector<Platform*> level4E_time();

	std::vector<Platform*> level4H_enemy();
	std::vector<Platform*> level4H_fall();
	std::vector<Platform*> level4H_time();

	void blockMoveUp(float posY);

private:
	bool moveUp = true;
	bool moveRight = false;
};

