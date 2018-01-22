#include "LevelManager.h"


LevelManager::LevelManager()
{
}


LevelManager::~LevelManager()
{
}

std::vector<Platform*> LevelManager::level1() //Complete
{
	block.clear();

	Platform* floor1 = new Platform(Rect(-10, -8, 2.5, 5));
	floor1->color = Colour(200, 0, 0);

	Platform* floor2 = new Platform(Rect(-7, -8, 2, 5));
	floor2->color = Colour(200, 0, 0);

	Platform* floor3 = new Platform(Rect(-4, -8, 3, 5));
	floor3->color = Colour(200, 0, 0);

	Platform* floor4 = new Platform(Rect(0, -8, 2, 6));
	floor4->color = Colour(200, 0, 0);

	Platform* floor5 = new Platform(Rect(3, -8, 2, 7.5));
	floor5->color = Colour(200, 0, 0);

	Platform* floor6 = new Platform(Rect(5.5, -8, 1, 2));
	floor6->color = Colour(200, 0, 0);

	Platform* floor7 = new Platform(Rect(8, -8, 2, 2));
	floor7->color = Colour(200, 0, 0);

	block.push_back(floor1);
	block.push_back(floor2);
	block.push_back(floor3);
	block.push_back(floor4);
	block.push_back(floor5);
	block.push_back(floor6);
	block.push_back(floor7);

	return block;
}

std::vector<Platform*> LevelManager::level2A()
{
	block.clear();

	Platform* floor1 = new Platform(Rect(-10, -8, 1, 5));
	floor1->color = Colour(200, 0, 200);

	Platform* floor2 = new Platform(Rect(-7, -8, 2, 5));
	floor2->color = Colour(200, 0, 200);

	Platform* floor3 = new Platform(Rect(-3, -8, 2, 6));
	floor3->color = Colour(200, 0, 200);

	Platform* floor4 = new Platform(Rect(3, -8, 2, 6.5));
	floor4->color = Colour(200, 0, 200);

	Platform* floor5 = new Platform(Rect(8, -8, 2, 6.5));
	floor5->color = Colour(200, 0, 200);

	Platform* floor6 = new Platform(Rect(0.5, -2, 2, 1));
	floor6->color = Colour(200, 0, 200);

	Platform* floor7 = new Platform(Rect(6, -2, 1.5, 1));
	floor7->color = Colour(200, 0, 200);

	Platform* floor8 = new Platform(Rect(-8, 0.5, 2, 1));
	floor8->color = Colour(200, 0, 200);

	Platform* floor9 = new Platform(Rect(-5, 2.5, 2, 1));
	floor9->color = Colour(200, 0, 200);

	Platform* floor10 = new Platform(Rect(-2.5, 0.5, 2, 1));
	floor10->color = Colour(200, 0, 200);

	block.push_back(floor1);
	block.push_back(floor2);
	block.push_back(floor3);
	block.push_back(floor4);
	block.push_back(floor5);
	block.push_back(floor6);
	block.push_back(floor7);
	block.push_back(floor8);
	block.push_back(floor9);
	block.push_back(floor10);

	return block;
}

std::vector<Platform*> LevelManager::level2B()
{
	block.clear();

	Platform* floor1 = new Platform(Rect(-10, -8, 1, 5));
	floor1->color = Colour(200, 0, 200);

	Platform* floor2 = new Platform(Rect(-7, -8, 2, 5));
	floor2->color = Colour(200, 0, 200);

	Platform* floor3 = new Platform(Rect(-3, -8, 2, 6));
	floor3->color = Colour(200, 0, 200);

	Platform* floor4 = new Platform(Rect(3, -8, 2, 6.5));
	floor4->color = Colour(200, 0, 200);

	Platform* floor5 = new Platform(Rect(8, -8, 2, 6.5));
	floor5->color = Colour(200, 0, 200);

	Platform* floor6 = new Platform(Rect(0.5, -2, 2, 1));
	floor6->color = Colour(200, 0, 200);

	Platform* floor7 = new Platform(Rect(5, 0, 1.5, 1)); 
	floor7->color = Colour(200, 0, 200);

	Platform* floor8 = new Platform(Rect(-2.5, 0.5, 2, 1));
	floor8->color = Colour(200, 0, 200);

	Platform* floor9 = new Platform(Rect(-6, 2.5, 2, 1)); 
	floor9->color = Colour(200, 0, 200);

	Platform* floor10 = new Platform(Rect(8, 2, 1.5, 1));
	floor10->color = Colour(200, 0, 200);


	block.push_back(floor1);
	block.push_back(floor2);
	block.push_back(floor3);
	block.push_back(floor4);
	block.push_back(floor5);
	block.push_back(floor6);
	block.push_back(floor7);
	block.push_back(floor8);
	block.push_back(floor9);
	block.push_back(floor10);

	return block;
}

std::vector<Platform*> LevelManager::level3A()
{
	block.clear();

	Platform* floor1 = new Platform(Rect(-9, 2, 2, 1));
	floor1->color = Colour(200, 0, 200);

	Platform* floor2 = new Platform(Rect(-6, 1, 2, 1));
	floor2->color = Colour(200, 0, 200);

	Platform* floor3 = new Platform(Rect(-4, -1, 2, 1));
	floor3->color = Colour(200, 0, 200);

	Platform* floor4 = new Platform(Rect(-2, 1, 2, 1));
	floor4->color = Colour(200, 0, 200);

	Platform* floor5 = new Platform(Rect(0, 2, 1, 1));
	floor5->color = Colour(200, 0, 200);

	Platform* floor6 = new Platform(Rect(1, 1, 1, 1));
	floor6->color = Colour(200, 0, 200);

	Platform* floor7 = new Platform(Rect(3, -1, 1, 1));
	floor7->color = Colour(200, 0, 200);

	Platform* floor8 = new Platform(Rect(3, -8, 5, 6));
	floor8->color = Colour(200, 0, 200);

	Platform* floor9 = new Platform(Rect(7, 3, 5, 2));
	floor9->color = Colour(200, 0, 200);

	Platform* floor10 = new Platform(Rect(4, 2, 1, 1));
	floor10->color = Colour(200, 0, 200);

	Platform* floor11 = new Platform(Rect(6, 3, 1, 1));
	floor11->color = Colour(200, 0, 200);

	block.push_back(floor1);
	block.push_back(floor2);
	block.push_back(floor3);
	block.push_back(floor4);
	block.push_back(floor5);
	block.push_back(floor6);
	block.push_back(floor7);
	block.push_back(floor8);
	block.push_back(floor9);
	block.push_back(floor10);
	block.push_back(floor11);

	return block;
}

std::vector<Platform*> LevelManager::level3B()
{
	block.clear();

	Platform* floor1 = new Platform(Rect(-9, 2, 2, 1));
	floor1->color = Colour(200, 0, 200);

	Platform* floor2 = new Platform(Rect(-6, 1, 2, 1));
	floor2->color = Colour(200, 0, 200);

	Platform* floor3 = new Platform(Rect(-4, -1, 2, 1));
	floor3->color = Colour(200, 0, 200);

	Platform* floor4 = new Platform(Rect(-2, 1, 2, 1));
	floor4->color = Colour(200, 0, 200);

	Platform* floor5 = new Platform(Rect(1, 1, 1, 1));
	floor5->color = Colour(200, 0, 200);

	Platform* floor6 = new Platform(Rect(3, -1, 1, 1));
	floor6->color = Colour(200, 0, 200);

	Platform* floor7 = new Platform(Rect(3, -8, 5, 6));
	floor7->color = Colour(200, 0, 200);

	Platform* floor8 = new Platform(Rect(7, 3, 5, 2));
	floor8->color = Colour(200, 0, 200);

	Platform* floor9 = new Platform(Rect(4, 2, 1, 1));
	floor9->color = Colour(200, 0, 200);

	Platform* floor10 = new Platform(Rect(6, 3, 1, 1));
	floor10->color = Colour(200, 0, 200);

	block.push_back(floor1);
	block.push_back(floor2);
	block.push_back(floor3);
	block.push_back(floor4);
	block.push_back(floor5);
	block.push_back(floor6);
	block.push_back(floor7);
	block.push_back(floor8);
	block.push_back(floor9);
	block.push_back(floor10);

	return block;
}

std::vector<Platform*> LevelManager::level3C()
{
	block.clear();

	Platform* floor1 = new Platform(Rect(-9, 2, 2, 1));
	floor1->color = Colour(200, 0, 200);

	Platform* floor2 = new Platform(Rect(-6, 1, 2, 1));
	floor2->color = Colour(200, 0, 200);

	Platform* floor3 = new Platform(Rect(-4, -1, 2, 1));
	floor3->color = Colour(200, 0, 200);

	Platform* floor4 = new Platform(Rect(-2, 1, 2, 1));
	floor4->color = Colour(200, 0, 200);

	Platform* floor5 = new Platform(Rect(1, 1, 1, 1));
	floor5->color = Colour(200, 0, 200);

	Platform* floor6 = new Platform(Rect(3, -1, 1, 1));
	floor6->color = Colour(200, 0, 200);

	Platform* floor7 = new Platform(Rect(3, -8, 5, 6));
	floor7->color = Colour(200, 0, 200);

	Platform* floor8 = new Platform(Rect(7, 3, 5, 2));
	floor8->color = Colour(200, 0, 200);

	Platform* floor9 = new Platform(Rect(4, 2, 1, 1));
	floor9->color = Colour(200, 0, 200);

	Platform* floor10 = new Platform(Rect(6, 3, 1, 1));
	floor10->color = Colour(200, 0, 200);

	block.push_back(floor1);
	block.push_back(floor2);
	block.push_back(floor3);
	block.push_back(floor4);
	block.push_back(floor5);
	block.push_back(floor6);
	block.push_back(floor7);
	block.push_back(floor8);
	block.push_back(floor9);
	block.push_back(floor10);

	return block;
}

std::vector<Platform*> LevelManager::level3D()
{
	block.clear();

	Platform* floor1 = new Platform(Rect(-9, 2, 2, 1));
	floor1->color = Colour(200, 0, 200);

	Platform* floor2 = new Platform(Rect(-7, -1, 2, 1));
	floor2->color = Colour(200, 0, 200);

	Platform* floor3 = new Platform(Rect(-4, -1, 2, 1));
	floor3->color = Colour(200, 0, 200);

	Platform* floor4 = new Platform(Rect(1, -8, 2, 2));
	floor4->color = Colour(200, 0, 200);

	Platform* floor5 = new Platform(Rect(1, 1, 1, 1));
	floor5->color = Colour(200, 0, 200);

	Platform* floor6 = new Platform(Rect(4, -1, 1, 1));
	floor6->color = Colour(200, 0, 200);

	Platform* floor7 = new Platform(Rect(3, -8, 7, 6));
	floor7->color = Colour(200, 0, 200);

	Platform* floor8 = new Platform(Rect(7, 3, 5, 2));
	floor8->color = Colour(200, 0, 200);

	Platform* floor9 = new Platform(Rect(4, 2, 1, 1));
	floor9->color = Colour(200, 0, 200);

	Platform* floor10 = new Platform(Rect(6, 3, 1, 1));
	floor10->color = Colour(200, 0, 200);

	Platform* floor11 = new Platform(Rect(1, -3, 1, 0.1));
	floor11->color = Colour(200, 0, 200);

	Platform* floor12 = new Platform(Rect(0, -5, 1, 0.1));
	floor12->color = Colour(200, 0, 200);

	Platform* floor13 = new Platform(Rect(-2, -8, 1, 3));
	floor13->color = Colour(200, 0, 200);

	Platform* floor14 = new Platform(Rect(-4, -8, 1, 2));
	floor14->color = Colour(200, 0, 200);

	block.push_back(floor1);
	block.push_back(floor2);
	block.push_back(floor3);
	block.push_back(floor4);
	block.push_back(floor5);
	block.push_back(floor6);
	block.push_back(floor7);
	block.push_back(floor8);
	block.push_back(floor9);
	block.push_back(floor10);
	block.push_back(floor11);
	block.push_back(floor12);
	block.push_back(floor13);
	block.push_back(floor14);

	return block;
}

std::vector<Platform*> LevelManager::level3E() 
											
{
	block.clear();

	Platform* floor1 = new Platform(Rect(-9, 2, 2, 1));
	floor1->color = Colour(200, 0, 200);

	Platform* floor2 = new Platform(Rect(-7, -1, 2, 1));
	floor2->color = Colour(200, 0, 200);

	Platform* floor3 = new Platform(Rect(-4, -1, 2, 1));
	floor3->color = Colour(200, 0, 200);

	Platform* floor4 = new Platform(Rect(1, -8, 2, 2));
	floor4->color = Colour(200, 0, 200);

	Platform* floor5 = new Platform(Rect(1, 1, 1, 1));
	floor5->color = Colour(200, 0, 200);

	Platform* floor6 = new Platform(Rect(4, -1, 1, 1));
	floor6->color = Colour(200, 0, 200);

	Platform* floor7 = new Platform(Rect(3, -8, 5, 6));
	floor7->color = Colour(200, 0, 200);

	Platform* floor8 = new Platform(Rect(7, 3, 5, 2));
	floor8->color = Colour(200, 0, 200);

	Platform* floor9 = new Platform(Rect(4, 2, 1, 1));
	floor9->color = Colour(200, 0, 200);

	Platform* floor10 = new Platform(Rect(6, 3, 1, 1));
	floor10->color = Colour(200, 0, 200);

	Platform* floor11 = new Platform(Rect(1, -3, 1, 0.1));
	floor11->color = Colour(200, 0, 200);

	Platform* floor12 = new Platform(Rect(0, -5, 1, 0.1));
	floor12->color = Colour(200, 0, 200);

	Platform* floor13 = new Platform(Rect(-2, -8, 1, 3));
	floor13->color = Colour(200, 0, 200);

	Platform* floor14 = new Platform(Rect(-4, -8, 1, 2));
	floor14->color = Colour(200, 0, 200);

	Platform* floor15 = new Platform(Rect(-7, -8, 2, 3));
	floor15->color = Colour(200, 0, 200);

	Platform* floor16 = new Platform(Rect(-10, -8, 1, 3));
	floor16->color = Colour(200, 0, 200);

	block.push_back(floor1);
	block.push_back(floor2);
	block.push_back(floor3);
	block.push_back(floor4);
	block.push_back(floor5);
	block.push_back(floor6);
	block.push_back(floor7);
	block.push_back(floor8);
	block.push_back(floor9);
	block.push_back(floor10);
	block.push_back(floor11);
	block.push_back(floor12);
	block.push_back(floor13);
	block.push_back(floor14);
	block.push_back(floor15);
	block.push_back(floor16);

	return block;
}

std::vector<Platform*> LevelManager::level3F()
{
	block.clear();

	Platform* floor1 = new Platform(Rect(-9, 2, 2, 1));
	floor1->color = Colour(200, 0, 200);

	Platform* floor2 = new Platform(Rect(-7, -1, 2, 1));
	floor2->color = Colour(200, 0, 200);

	Platform* floor3 = new Platform(Rect(-4, -1, 2, 1));
	floor3->color = Colour(200, 0, 200);

	Platform* floor4 = new Platform(Rect(1, -8, 2, 2));
	floor4->color = Colour(200, 0, 200);

	Platform* floor5 = new Platform(Rect(1, 1, 1, 1));
	floor5->color = Colour(200, 0, 200);

	Platform* floor6 = new Platform(Rect(4, -1, 1, 1));
	floor6->color = Colour(200, 0, 200);

	Platform* floor7 = new Platform(Rect(3, -8, 7, 6));
	floor7->color = Colour(200, 0, 200);

	Platform* floor8 = new Platform(Rect(7, 3, 5, 2));
	floor8->color = Colour(200, 0, 200);

	Platform* floor9 = new Platform(Rect(4, 2, 1, 1));
	floor9->color = Colour(200, 0, 200);

	Platform* floor10 = new Platform(Rect(6, 3, 1, 1));
	floor10->color = Colour(200, 0, 200);

	Platform* floor11 = new Platform(Rect(1, -3, 1, 0.1));
	floor11->color = Colour(200, 0, 200);

	Platform* floor12 = new Platform(Rect(0, -5, 1, 0.1));
	floor12->color = Colour(200, 0, 200);

	Platform* floor13 = new Platform(Rect(-2, -8, 1, 3));
	floor13->color = Colour(200, 0, 200);

	Platform* floor14 = new Platform(Rect(-4, -8, 1, 2));
	floor14->color = Colour(200, 0, 200);

	block.push_back(floor1);
	block.push_back(floor2);
	block.push_back(floor3);
	block.push_back(floor4);
	block.push_back(floor5);
	block.push_back(floor6);
	block.push_back(floor7);
	block.push_back(floor8);
	block.push_back(floor9);
	block.push_back(floor10);
	block.push_back(floor11);
	block.push_back(floor12);
	block.push_back(floor13);
	block.push_back(floor14);

	return block;
}

std::vector<Platform*> LevelManager::level3G()
{
	block.clear();

	Platform* floor1 = new Platform(Rect(-9, 2, 2, 1));
	floor1->color = Colour(200, 0, 200);

	Platform* floor2 = new Platform(Rect(-7, -1, 2, 1));
	floor2->color = Colour(200, 0, 200);

	Platform* floor3 = new Platform(Rect(-4, -1, 2, 1));
	floor3->color = Colour(200, 0, 200);

	Platform* floor4 = new Platform(Rect(1, -8, 2, 2));
	floor4->color = Colour(200, 0, 200);

	Platform* floor5 = new Platform(Rect(1, 1, 1, 1));
	floor5->color = Colour(200, 0, 200);

	Platform* floor6 = new Platform(Rect(4, -1, 1, 1));
	floor6->color = Colour(200, 0, 200);

	Platform* floor7 = new Platform(Rect(3, -8, 7, 6));
	floor7->color = Colour(200, 0, 200);

	Platform* floor8 = new Platform(Rect(7, 3, 5, 2));
	floor8->color = Colour(200, 0, 200);

	Platform* floor9 = new Platform(Rect(4, 2, 1, 1));
	floor9->color = Colour(200, 0, 200);

	Platform* floor10 = new Platform(Rect(6, 3, 1, 1));
	floor10->color = Colour(200, 0, 200);

	Platform* floor11 = new Platform(Rect(1, -3, 1, 0.1));
	floor11->color = Colour(200, 0, 200);

	Platform* floor12 = new Platform(Rect(0, -5, 1, 0.1));
	floor12->color = Colour(200, 0, 200);

	Platform* floor13 = new Platform(Rect(-2, -8, 1, 3));
	floor13->color = Colour(200, 0, 200);

	Platform* floor14 = new Platform(Rect(-4, -8, 1, 2));
	floor14->color = Colour(200, 0, 200);

	Platform* floor15 = new Platform(Rect(-10, -8, 1, 2));
	floor15->color = Colour(200, 0, 200);

	block.push_back(floor1);
	block.push_back(floor2);
	block.push_back(floor3);
	block.push_back(floor4);
	block.push_back(floor5);
	block.push_back(floor6);
	block.push_back(floor7);
	block.push_back(floor8);
	block.push_back(floor9);
	block.push_back(floor10);
	block.push_back(floor11);
	block.push_back(floor12);
	block.push_back(floor13);
	block.push_back(floor14);
	block.push_back(floor15);

	return block;
}

std::vector<Platform*> LevelManager::level4E_enemy()
{
	block.clear();

	Platform* floor1 = new Platform(Rect(-10, -2, 4, 1));
	floor1->color = Colour(200, 0, 200);

	Platform* floor2 = new Platform(Rect(-5, -2, 6, 1));
	floor2->color = Colour(200, 0, 200);

	Platform* floor3 = new Platform(Rect(2, -2, 5, 1));
	floor3->color = Colour(200, 0, 200);

	Platform* floor4 = new Platform(Rect(8, -2, 2, 1));
	floor4->color = Colour(200, 0, 200);

	block.push_back(floor1);
	block.push_back(floor2);
	block.push_back(floor3);
	block.push_back(floor4);

	return block;
}

