#pragma once

#include "Platform.h"
#include "FallingPlatform.h"
#include "Collectible.h"
#include "Enemy.h"
#include "Spikes.h"

class LevelManager
{
public:
	LevelManager();
	~LevelManager();

	//Control the platforms in each level
	std::vector<Platform*> block;
	std::vector<FallingPlatform*> fallBlock;
	std::vector<Collectible*> collectible;
	std::vector<Enemy*> enemy;
	std::vector<Spikes*> spikes;

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
	std::vector<FallingPlatform*> level4E_fallBlock();
	std::vector<Platform*> level4E_time();

	std::vector<Platform*> level4H_enemy();
	std::vector<Platform*> level4H_fall();
	std::vector<Platform*> level4H_time();

	//Control the collectibles in each level
	std::vector<Collectible*> c2A();
	std::vector<Collectible*> c2B();

	std::vector<Collectible*> c3A();
	std::vector<Collectible*> c3B();
	std::vector<Collectible*> c3C();
	std::vector<Collectible*> c3D();
	std::vector<Collectible*> c3E();
	std::vector<Collectible*> c3F();
	std::vector<Collectible*> c3G();

	//Control the enemies in each level
	std::vector<Enemy*> enemy3A();
	std::vector<Enemy*> enemy3B();
	std::vector<Enemy*> enemy3C();
	std::vector<Enemy*> enemy3D();
	std::vector<Enemy*> enemy3E();
	std::vector<Enemy*> enemy3F();
	std::vector<Enemy*> enemy3G();

	std::vector<Enemy*> enemy4E_enemy();
	std::vector<Spikes*> spikes4E();
	std::vector<Enemy*> enemy4H_enemy();
	std::vector<Spikes*> spikes4H();
};

