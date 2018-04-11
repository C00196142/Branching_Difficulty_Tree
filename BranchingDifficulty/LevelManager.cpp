#include "LevelManager.h"


LevelManager::LevelManager()
{
}


LevelManager::~LevelManager()
{
}

//PLATFORMS
//Draw and give positions
std::vector<Platform*> LevelManager::tutorial()
{
	block.clear();

	Platform* floorT1 = new Platform(Rect(-10, -8, 5, 5));
	floorT1->color = Colour(200, 0, 0);

	Platform* floorT2 = new Platform(Rect(-4, -8, 7, 5));
	floorT2->color = Colour(200, 0, 0);

	Platform* floorT3 = new Platform(Rect(5, -8, 5, 5));
	floorT3->color = Colour(200, 0, 0);

	block.push_back(floorT1);
	block.push_back(floorT2);
	block.push_back(floorT3);

	return block;
}

std::vector<Platform*> LevelManager::level1() //Complete
{
	block.clear();

	Platform* floor11 = new Platform(Rect(-10, -8, 2.5, 5));
	floor11->color = Colour(200, 0, 0);

	Platform* floor12 = new Platform(Rect(-7, -8, 2, 5));
	floor12->color = Colour(200, 0, 0);

	Platform* floor13 = new Platform(Rect(-4, -8, 3, 5));
	floor13->color = Colour(200, 0, 0);

	Platform* floor14 = new Platform(Rect(0, -8, 2, 6));
	floor14->color = Colour(200, 0, 0);

	Platform* floor15 = new Platform(Rect(3, -8, 2, 7.5));
	floor15->color = Colour(200, 0, 0);

	Platform* floor16 = new Platform(Rect(5.5, -8, 1, 2));
	floor16->color = Colour(200, 0, 0);

	Platform* floor17 = new Platform(Rect(8, -8, 2, 2));
	floor17->color = Colour(200, 0, 0);

	block.push_back(floor11);
	block.push_back(floor12);
	block.push_back(floor13);
	block.push_back(floor14);
	block.push_back(floor15);
	block.push_back(floor16);
	block.push_back(floor17);

	return block;
}

std::vector<Platform*> LevelManager::level2A()
{
	block.clear();

	Platform* floor2A1 = new Platform(Rect(-10, -8, 1, 5));
	floor2A1->color = Colour(200, 0, 200);

	Platform* floor2A2 = new Platform(Rect(-8, -8, 1.5, 6));
	floor2A2->color = Colour(200, 0, 200);

	Platform* floor2A3 = new Platform(Rect(-5.5, -1, 2, 1));
	floor2A3->color = Colour(200, 0, 200);

	Platform* floor2A4 = new Platform(Rect(-3.5, 1, 2, 1));
	floor2A4->color = Colour(200, 0, 200);

	Platform* floor2A5 = new Platform(Rect(-1.5, 3, 2.5, 1));
	floor2A5->color = Colour(200, 0, 200);

	Platform* floor2A6 = new Platform(Rect(2, 4, 2, 1));
	floor2A6->color = Colour(200, 0, 200);

	Platform* floor2A7 = new Platform(Rect(4, 2, 2, 1));
	floor2A7->color = Colour(200, 0, 200);

	Platform* floor2A8 = new Platform(Rect(6, 4, 2, 1));
	floor2A8->color = Colour(200, 0, 200);

	Platform* floor2A9 = new Platform(Rect(8, -8, 2, 6.5));
	floor2A9->color = Colour(200, 0, 200);

	Platform* floor2A10 = new Platform(Rect(-10, 1, 2, 1));
	floor2A10->color = Colour(200, 0, 200);

	block.push_back(floor2A1);
	block.push_back(floor2A2);
	block.push_back(floor2A3);
	block.push_back(floor2A4);
	block.push_back(floor2A5);
	block.push_back(floor2A6);
	block.push_back(floor2A7);
	block.push_back(floor2A8);
	block.push_back(floor2A9);
	block.push_back(floor2A10);

	return block;
}

std::vector<Platform*> LevelManager::level2B()
{
	block.clear();

	Platform* floor2B1 = new Platform(Rect(-10, -8, 1, 5));
	floor2B1->color = Colour(200, 0, 200);

	Platform* floor2B2 = new Platform(Rect(-8, -8, 1.5, 6));
	floor2B2->color = Colour(200, 0, 200);

	Platform* floor2B3 = new Platform(Rect(-5.5, -1, 2, 1));
	floor2B3->color = Colour(200, 0, 200);

	Platform* floor2B4 = new Platform(Rect(-3.5, 1, 6, 1));
	floor2B4->color = Colour(200, 0, 200);

	Platform* floor2B5 = new Platform(Rect(-1.5, 3, 3, 1));
	floor2B5->color = Colour(200, 0, 200);

	Platform* floor2B6 = new Platform(Rect(2, 4, 2, 1));
	floor2B6->color = Colour(200, 0, 200);

	Platform* floor2B7 = new Platform(Rect(4, -1, 2, 1));
	floor2B7->color = Colour(200, 0, 200);

	Platform* floor2B8 = new Platform(Rect(6, 4, 2, 1));
	floor2B8->color = Colour(200, 0, 200);

	Platform* floor2B9 = new Platform(Rect(8, -8, 2, 6.5));
	floor2B9->color = Colour(200, 0, 200);

	Platform* floor2B10 = new Platform(Rect(-10, 1, 2, 1));
	floor2B10->color = Colour(200, 0, 200);

	block.push_back(floor2B1);
	block.push_back(floor2B2);
	block.push_back(floor2B3);
	block.push_back(floor2B4);
	block.push_back(floor2B5);
	block.push_back(floor2B6);
	block.push_back(floor2B7);
	block.push_back(floor2B8);
	block.push_back(floor2B9);
	block.push_back(floor2B10);

	return block;
}

std::vector<Platform*> LevelManager::level3A()
{
	block.clear();

	Platform* floor3A1 = new Platform(Rect(-9, 2, 2, 1));
	floor3A1->color = Colour(200, 0, 200);

	Platform* floor3A2 = new Platform(Rect(-6, 1, 2, 1));
	floor3A2->color = Colour(200, 0, 200);

	Platform* floor3A3 = new Platform(Rect(-4, -1, 2, 1));
	floor3A3->color = Colour(200, 0, 200);

	Platform* floor3A4 = new Platform(Rect(-2, 1, 2, 1));
	floor3A4->color = Colour(200, 0, 200);

	Platform* floor3A5 = new Platform(Rect(0, 2, 1, 1));
	floor3A5->color = Colour(200, 0, 200);

	Platform* floor3A6 = new Platform(Rect(1, 1, 1, 1));
	floor3A6->color = Colour(200, 0, 200);

	Platform* floor3A7 = new Platform(Rect(3, -1, 1, 1));
	floor3A7->color = Colour(200, 0, 200);

	Platform* floor3A8 = new Platform(Rect(3, -8, 5, 6));
	floor3A8->color = Colour(200, 0, 200);

	Platform* floor3A9 = new Platform(Rect(7, 3, 5, 2));
	floor3A9->color = Colour(200, 0, 200);

	Platform* floor3A10 = new Platform(Rect(4, 2, 1, 1));
	floor3A10->color = Colour(200, 0, 200);

	Platform* floor3A11 = new Platform(Rect(6, 3, 1, 1));
	floor3A11->color = Colour(200, 0, 200);

	block.push_back(floor3A1);
	block.push_back(floor3A2);
	block.push_back(floor3A3);
	block.push_back(floor3A4);
	block.push_back(floor3A5);
	block.push_back(floor3A6);
	block.push_back(floor3A7);
	block.push_back(floor3A8);
	block.push_back(floor3A9);
	block.push_back(floor3A10);
	block.push_back(floor3A11);

	return block;
}

std::vector<Platform*> LevelManager::level3B()
{
	block.clear();

	Platform* floor3B1 = new Platform(Rect(-9, 2, 2, 1));
	floor3B1->color = Colour(200, 0, 200);

	Platform* floor3B2 = new Platform(Rect(-6, 1, 2, 1));
	floor3B2->color = Colour(200, 0, 200);

	Platform* floor3B3 = new Platform(Rect(-4, -1, 2, 1));
	floor3B3->color = Colour(200, 0, 200);

	Platform* floor3B4 = new Platform(Rect(-2, 1, 2, 1));
	floor3B4->color = Colour(200, 0, 200);

	Platform* floor3B5 = new Platform(Rect(1, 1, 1, 1));
	floor3B5->color = Colour(200, 0, 200);

	Platform* floor3B6 = new Platform(Rect(3, -1, 1, 1));
	floor3B6->color = Colour(200, 0, 200);

	Platform* floor3B7 = new Platform(Rect(3, -8, 5, 6));
	floor3B7->color = Colour(200, 0, 200);

	Platform* floor3B8 = new Platform(Rect(7, 3, 5, 2));
	floor3B8->color = Colour(200, 0, 200);

	Platform* floor3B9 = new Platform(Rect(4, 2, 1, 1));
	floor3B9->color = Colour(200, 0, 200);

	Platform* floor3B10 = new Platform(Rect(6, 3, 1, 1));
	floor3B10->color = Colour(200, 0, 200);

	block.push_back(floor3B1);
	block.push_back(floor3B2);
	block.push_back(floor3B3);
	block.push_back(floor3B4);
	block.push_back(floor3B5);
	block.push_back(floor3B6);
	block.push_back(floor3B7);
	block.push_back(floor3B8);
	block.push_back(floor3B9);
	block.push_back(floor3B10);

	return block;
}

std::vector<Platform*> LevelManager::level3C()
{
	block.clear();

	Platform* floor3C1 = new Platform(Rect(-9, 2, 2, 1));
	floor3C1->color = Colour(200, 0, 200);

	Platform* floor3C2 = new Platform(Rect(-6, 1, 3, 1));
	floor3C2->color = Colour(200, 0, 200);

	Platform* floor3C3 = new Platform(Rect(-5, -1, 6, 1));
	floor3C3->color = Colour(200, 0, 200);

	Platform* floor3C4 = new Platform(Rect(-2, 1, 2, 1));
	floor3C4->color = Colour(200, 0, 200);

	Platform* floor3C5 = new Platform(Rect(1, 1, 1, 1));
	floor3C5->color = Colour(200, 0, 200);

	Platform* floor3C6 = new Platform(Rect(3, -1, 1, 1));
	floor3C6->color = Colour(200, 0, 200);

	Platform* floor3C7 = new Platform(Rect(3, -8, 5, 6));
	floor3C7->color = Colour(200, 0, 200);

	Platform* floor3C8 = new Platform(Rect(7, 3, 5, 2));
	floor3C8->color = Colour(200, 0, 200);

	Platform* floor3C9 = new Platform(Rect(4, 2, 1, 1));
	floor3C9->color = Colour(200, 0, 200);

	Platform* floor3C10 = new Platform(Rect(6, 3, 1, 1));
	floor3C10->color = Colour(200, 0, 200);

	block.push_back(floor3C1);
	block.push_back(floor3C2);
	block.push_back(floor3C3);
	block.push_back(floor3C4);
	block.push_back(floor3C5);
	block.push_back(floor3C6);
	block.push_back(floor3C7);
	block.push_back(floor3C8);
	block.push_back(floor3C9);
	block.push_back(floor3C10);

	return block;
}

std::vector<Platform*> LevelManager::level3D()
{
	block.clear();

	Platform* floor3D1 = new Platform(Rect(-9, 2, 2, 1));
	floor3D1->color = Colour(200, 0, 200);

	Platform* floor3D2 = new Platform(Rect(-7, -1, 2, 1));
	floor3D2->color = Colour(200, 0, 200);

	Platform* floor3D3 = new Platform(Rect(-4, -1, 4, 1));
	floor3D3->color = Colour(200, 0, 200);

	Platform* floor3D4 = new Platform(Rect(1, -8, 2, 2));
	floor3D4->color = Colour(200, 0, 200);

	Platform* floor3D5 = new Platform(Rect(1, 1, 1, 1));
	floor3D5->color = Colour(200, 0, 200);

	Platform* floor3D6 = new Platform(Rect(4, -1, 1, 1));
	floor3D6->color = Colour(200, 0, 200);

	Platform* floor3D7 = new Platform(Rect(3, -8, 7, 6));
	floor3D7->color = Colour(200, 0, 200);

	Platform* floor3D8 = new Platform(Rect(7, 3, 5, 2));
	floor3D8->color = Colour(200, 0, 200);

	Platform* floor3D9 = new Platform(Rect(4, 2, 1, 1));
	floor3D9->color = Colour(200, 0, 200);

	Platform* floor3D10 = new Platform(Rect(6, 3, 1, 1));
	floor3D10->color = Colour(200, 0, 200);

	Platform* floor3D11 = new Platform(Rect(1, -3, 1, 0.1));
	floor3D11->color = Colour(200, 0, 200);

	Platform* floor3D12 = new Platform(Rect(0, -5, 1, 0.1));
	floor3D12->color = Colour(200, 0, 200);

	Platform* floor3D13 = new Platform(Rect(-2, -8, 1, 3));
	floor3D13->color = Colour(200, 0, 200);

	Platform* floor3D14 = new Platform(Rect(-4, -8, 1, 2));
	floor3D14->color = Colour(200, 0, 200);

	Platform* floor3D15 = new Platform(Rect(-10, -1, 1.5, 1));
	floor3D15->color = Colour(200, 0, 200);

	block.push_back(floor3D1);
	block.push_back(floor3D2);
	block.push_back(floor3D3);
	block.push_back(floor3D4);
	block.push_back(floor3D5);
	block.push_back(floor3D6);
	block.push_back(floor3D7);
	block.push_back(floor3D8);
	block.push_back(floor3D9);
	block.push_back(floor3D10);
	block.push_back(floor3D11);
	block.push_back(floor3D12);
	block.push_back(floor3D13);
	block.push_back(floor3D14);
	block.push_back(floor3D15);

	return block;
}

std::vector<Platform*> LevelManager::level3E() 											
{
	block.clear();

	Platform* floor3E1 = new Platform(Rect(-9, 2, 2, 1));
	floor3E1->color = Colour(200, 0, 200);

	Platform* floor3E2 = new Platform(Rect(-7, -1, 2, 1));
	floor3E2->color = Colour(200, 0, 200);

	Platform* floor3E3 = new Platform(Rect(-4, -1, 4, 1));
	floor3E3->color = Colour(200, 0, 200);

	Platform* floor3E4 = new Platform(Rect(1, -8, 2, 2));
	floor3E4->color = Colour(200, 0, 200);

	Platform* floor3E5 = new Platform(Rect(1, 1, 1, 1));
	floor3E5->color = Colour(200, 0, 200);

	Platform* floor3E6 = new Platform(Rect(4, -1, 1, 1));
	floor3E6->color = Colour(200, 0, 200);

	Platform* floor3E7 = new Platform(Rect(3, -8, 5, 6));
	floor3E7->color = Colour(200, 0, 200);

	Platform* floor3E8 = new Platform(Rect(7, 3, 5, 2));
	floor3E8->color = Colour(200, 0, 200);

	Platform* floor3E9 = new Platform(Rect(4, 2, 1, 1));
	floor3E9->color = Colour(200, 0, 200);

	Platform* floor3E10 = new Platform(Rect(6, 3, 1, 1));
	floor3E10->color = Colour(200, 0, 200);

	Platform* floor3E11 = new Platform(Rect(1, -3, 1, 0.1));
	floor3E11->color = Colour(200, 0, 200);

	Platform* floor3E12 = new Platform(Rect(0, -5, 1, 0.1));
	floor3E12->color = Colour(200, 0, 200);

	Platform* floor3E13 = new Platform(Rect(-2, -8, 1, 3));
	floor3E13->color = Colour(200, 0, 200);

	Platform* floor3E14 = new Platform(Rect(-4, -8, 1, 2));
	floor3E14->color = Colour(200, 0, 200);

	Platform* floor3E15 = new Platform(Rect(-7, -8, 2, 3));
	floor3E15->color = Colour(200, 0, 200);

	Platform* floor3E16 = new Platform(Rect(-10, -8, 1, 3));
	floor3E16->color = Colour(200, 0, 200);

	block.push_back(floor3E1);
	block.push_back(floor3E2);
	block.push_back(floor3E3);
	block.push_back(floor3E4);
	block.push_back(floor3E5);
	block.push_back(floor3E6);
	block.push_back(floor3E7);
	block.push_back(floor3E8);
	block.push_back(floor3E9);
	block.push_back(floor3E10);
	block.push_back(floor3E11);
	block.push_back(floor3E12);
	block.push_back(floor3E13);
	block.push_back(floor3E14);
	block.push_back(floor3E15);
	block.push_back(floor3E16);

	return block;
}

std::vector<Platform*> LevelManager::level3F()
{
	block.clear();

	Platform* floor3F1 = new Platform(Rect(-9, 2, 2, 1));
	floor3F1->color = Colour(200, 0, 200);

	Platform* floor3F2 = new Platform(Rect(-8, -1, 8, 1));
	floor3F2->color = Colour(200, 0, 200);

	Platform* floor3F3 = new Platform(Rect(1, -8, 2, 2));
	floor3F3->color = Colour(200, 0, 200);

	Platform* floor3F4 = new Platform(Rect(1, 1, 1, 1));
	floor3F4->color = Colour(200, 0, 200);

	Platform* floor3F5 = new Platform(Rect(4, -1, 1, 1));
	floor3F5->color = Colour(200, 0, 200);

	Platform* floor3F6 = new Platform(Rect(3, -8, 7, 6));
	floor3F6->color = Colour(200, 0, 200);

	Platform* floor3F7 = new Platform(Rect(7, 3, 5, 2));
	floor3F7->color = Colour(200, 0, 200);

	Platform* floor3F8 = new Platform(Rect(4, 2, 1, 1));
	floor3F8->color = Colour(200, 0, 200);

	Platform* floor3F9 = new Platform(Rect(6, 3, 1, 1));
	floor3F9->color = Colour(200, 0, 200);

	Platform* floor3F10 = new Platform(Rect(1, -3, 1, 0.1));
	floor3F10->color = Colour(200, 0, 200);

	Platform* floor3F11 = new Platform(Rect(0, -5, 1, 0.1));
	floor3F11->color = Colour(200, 0, 200);

	Platform* floor3F12 = new Platform(Rect(-2, -8, 1, 3));
	floor3F12->color = Colour(200, 0, 200);

	Platform* floor3F13 = new Platform(Rect(-4, -8, 1, 2));
	floor3F13->color = Colour(200, 0, 200);

	block.push_back(floor3F1);
	block.push_back(floor3F2);
	block.push_back(floor3F3);
	block.push_back(floor3F4);
	block.push_back(floor3F5);
	block.push_back(floor3F6);
	block.push_back(floor3F7);
	block.push_back(floor3F8);
	block.push_back(floor3F9);
	block.push_back(floor3F10);
	block.push_back(floor3F11);
	block.push_back(floor3F12);
	block.push_back(floor3F13);

	return block;
}

std::vector<Platform*> LevelManager::level3G()
{
	block.clear();

	Platform* floor3G1 = new Platform(Rect(-9, 2, 2, 1));
	floor3G1->color = Colour(200, 0, 200);

	Platform* floor3G2 = new Platform(Rect(-8, -1, 8, 1));
	floor3G2->color = Colour(200, 0, 200);

	Platform* floor3G3 = new Platform(Rect(1, -8, 2, 2));
	floor3G3->color = Colour(200, 0, 200);

	Platform* floor3G4 = new Platform(Rect(1, 1, 1, 1));
	floor3G4->color = Colour(200, 0, 200);

	Platform* floor3G5 = new Platform(Rect(4, -1, 1, 1));
	floor3G5->color = Colour(200, 0, 200);

	Platform* floor3G6 = new Platform(Rect(3, -8, 7, 6));
	floor3G6->color = Colour(200, 0, 200);

	Platform* floor3G7 = new Platform(Rect(7, 3, 5, 2));
	floor3G7->color = Colour(200, 0, 200);

	Platform* floor3G8 = new Platform(Rect(4, 2, 1, 1));
	floor3G8->color = Colour(200, 0, 200);

	Platform* floor3G9 = new Platform(Rect(6, 3, 1, 1));
	floor3G9->color = Colour(200, 0, 200);

	Platform* floor3G10 = new Platform(Rect(1, -3, 1, 0.1));
	floor3G10->color = Colour(200, 0, 200);

	Platform* floor3G11 = new Platform(Rect(0, -5, 1, 0.1));
	floor3G11->color = Colour(200, 0, 200);

	Platform* floor3G12 = new Platform(Rect(-2, -8, 1, 3));
	floor3G12->color = Colour(200, 0, 200);

	Platform* floor3G13 = new Platform(Rect(-4, -8, 1, 2));
	floor3G13->color = Colour(200, 0, 200);

	Platform* floor3G14 = new Platform(Rect(-10, -8, 1, 2));
	floor3G14->color = Colour(200, 0, 200);

	Platform* floor3G15 = new Platform(Rect(-8, -5, 1, 1));
	floor3G15->color = Colour(200, 0, 200);

	Platform* floor3G16 = new Platform(Rect(-10, -3, 1, 1));
	floor3G16->color = Colour(200, 0, 200);

	block.push_back(floor3G1);
	block.push_back(floor3G2);
	block.push_back(floor3G3);
	block.push_back(floor3G4);
	block.push_back(floor3G5);
	block.push_back(floor3G6);
	block.push_back(floor3G7);
	block.push_back(floor3G8);
	block.push_back(floor3G9);
	block.push_back(floor3G10);
	block.push_back(floor3G11);
	block.push_back(floor3G12);
	block.push_back(floor3G13);
	block.push_back(floor3G14);
	block.push_back(floor3G15);
	block.push_back(floor3G16);

	return block;
}

std::vector<Platform*> LevelManager::level4E_enemy()
{
	block.clear();

	Platform* floor4EE1 = new Platform(Rect(-10, -2, 4, 1));
	floor4EE1->color = Colour(200, 0, 200);

	Platform* floor4EE2 = new Platform(Rect(-5, -2, 6, 1));
	floor4EE2->color = Colour(200, 0, 200);

	Platform* floor4EE3 = new Platform(Rect(2, -2, 5, 1));
	floor4EE3->color = Colour(200, 0, 200);

	Platform* floor4EE4 = new Platform(Rect(8, -2, 2, 1));
	floor4EE4->color = Colour(200, 0, 200);


	block.push_back(floor4EE1);
	block.push_back(floor4EE2);
	block.push_back(floor4EE3);
	block.push_back(floor4EE4);

	return block;
}

std::vector<Platform*> LevelManager::level4E_fall()
{
	block.clear();

	Platform* floor4EF1 = new Platform(Rect(-10, -4, 1, 3));
	floor4EF1->color = Colour(200, 0, 200);

	Platform* floor4EF2 = new Platform(Rect(-3, -3.5, 1, 3));
	floor4EF2->color = Colour(200, 0, 200);

	Platform* floor4EF3 = new Platform(Rect(4, -4, 1, 4));
	floor4EF3->color = Colour(200, 0, 200);

	Platform* floor4EF4 = new Platform(Rect(9, 1, 1, 1));
	floor4EF4->color = Colour(200, 0, 200);

	block.push_back(floor4EF1);
	block.push_back(floor4EF2);
	block.push_back(floor4EF3);
	block.push_back(floor4EF4);

	return block;
}

std::vector<FallingPlatform*> LevelManager::level4E_fallBlock()
{
	fallBlock.clear();

	FallingPlatform* floor4EFB1 = new FallingPlatform(Rect(-7, -1, 1, 0.5));
	floor4EFB1->color = Colour(200, 200, 0);

	FallingPlatform* floor4EFB2 = new FallingPlatform(Rect(0, -1, 1, 0.5));
	floor4EFB2->color = Colour(200, 200, 0);

	FallingPlatform* floor4EFB3 = new FallingPlatform(Rect(7, 0, 1, 0.5));
	floor4EFB3->color = Colour(200, 200, 0);

	fallBlock.push_back(floor4EFB1);
	fallBlock.push_back(floor4EFB2);
	fallBlock.push_back(floor4EFB3);

	return fallBlock;
}

std::vector<Platform*> LevelManager::level4E_time()
{
	block.clear();

	Platform* wall = new Platform(Rect(-7, -4, 0.5, 12));
	wall->color = Colour(200, 0, 200);

	Platform* ground = new Platform(Rect(-10, -8, 20, 1));
	ground->color = Colour(200, 0, 200);

	Platform* floor4ET1 = new Platform(Rect(-10, 3, 1.5, 2));
	floor4ET1->color = Colour(200, 0, 200);

	Platform* floor4ET2 = new Platform(Rect(-8.5, -0.5, 1.5, 2));
	floor4ET2->color = Colour(200, 0, 200);

	Platform* floor4ET3 = new Platform(Rect(-10, -4, 1.5, 2));
	floor4ET3->color = Colour(200, 0, 200);

	Platform* floor4ET4 = new Platform(Rect(-10, -8, 3, 2));
	floor4ET4->color = Colour(200, 0, 200);

	Platform* floor4ET5 = new Platform(Rect(-3, -3, 10, 1));
	floor4ET5->color = Colour(200, 0, 200);

	Platform* floor4ET6 = new Platform(Rect(-2, -7, 1, 1.5));
	floor4ET6->color = Colour(200, 0, 200);

	Platform* floor4ET7 = new Platform(Rect(-1, -1, 2, 1));
	floor4ET7->color = Colour(200, 0, 200);

	Platform* floor4ET8 = new Platform(Rect(2, 0, 2, 1));
	floor4ET8->color = Colour(200, 0, 200);

	Platform* floor4ET9 = new Platform(Rect(6, 1, 2, 1));
	floor4ET9->color = Colour(200, 0, 200);

	Platform* floor4ET10 = new Platform(Rect(9, 3, 2, 1));
	floor4ET10->color = Colour(200, 0, 200);

	Platform* floor4ET11 = new Platform(Rect(9, -5.5, 2, 1));
	floor4ET11->color = Colour(200, 0, 200);


	block.push_back(wall);
	block.push_back(ground);
	block.push_back(floor4ET1);
	block.push_back(floor4ET2);
	block.push_back(floor4ET3);
	block.push_back(floor4ET4);
	block.push_back(floor4ET5);
	block.push_back(floor4ET6);
	block.push_back(floor4ET7);
	block.push_back(floor4ET8);
	block.push_back(floor4ET9);
	block.push_back(floor4ET10);
	block.push_back(floor4ET11);

	return block;
}

std::vector<Platform*> LevelManager::level4H_enemy()
{
	block.clear();

	Platform* floor4HE1 = new Platform(Rect(-10, -2, 4, 1));
	floor4HE1->color = Colour(200, 0, 200);

	Platform* floor4HE2 = new Platform(Rect(-5, -2, 6, 1));
	floor4HE2->color = Colour(200, 0, 200);

	Platform* floor4HE3 = new Platform(Rect(2, -2, 5, 1));
	floor4HE3->color = Colour(200, 0, 200);

	Platform* floor4HE4 = new Platform(Rect(8, -2, 2, 1));
	floor4HE4->color = Colour(200, 0, 200);

	block.push_back(floor4HE1);
	block.push_back(floor4HE2);
	block.push_back(floor4HE3);
	block.push_back(floor4HE4);

	return block;
}

std::vector<Platform*> LevelManager::level4H_fall()
{
	block.clear();

	Platform* floor4HF1 = new Platform(Rect(-10, -4, 1, 3));
	floor4HF1->color = Colour(200, 0, 200);

	Platform* floor4HF2 = new Platform(Rect(0, -4, 0.5, 3));
	floor4HF2->color = Colour(200, 0, 200);

	Platform* floor4HF3 = new Platform(Rect(6, -4, 0.5, 5));
	floor4HF3->color = Colour(200, 0, 200);

	Platform* floor4HF4 = new Platform(Rect(9, 1, 1, 1));
	floor4HF4->color = Colour(200, 0, 200);

	block.push_back(floor4HF1);
	block.push_back(floor4HF2);
	block.push_back(floor4HF3);
	block.push_back(floor4HF4);

	return block;
}

std::vector<FallingPlatform*> LevelManager::level4H_fallBlock()
{
	fallBlock.clear();

	FallingPlatform* floor4HFB1 = new FallingPlatform(Rect(-8, -1, 1, 0.5));
	floor4HFB1->color = Colour(200, 200, 0);

	FallingPlatform* floor4HFB2 = new FallingPlatform(Rect(-5, -1, 1, 0.5));
	floor4HFB2->color = Colour(200, 200, 0);

	FallingPlatform* floor4HFB3 = new FallingPlatform(Rect(-2, -1, 1, 0.5));
	floor4HFB3->color = Colour(200, 200, 0);

	FallingPlatform* floor4HFB4 = new FallingPlatform(Rect(3, -1, 1, 0.5));
	floor4HFB4->color = Colour(200, 200, 0);

	fallBlock.push_back(floor4HFB1);
	fallBlock.push_back(floor4HFB2);
	fallBlock.push_back(floor4HFB3);
	fallBlock.push_back(floor4HFB4);

	return fallBlock;
}

std::vector<Platform*> LevelManager::level4H_time()
{
	block.clear();

	Platform* wall = new Platform(Rect(-7, -4, 0.5, 12));
	wall->color = Colour(200, 0, 200);

	Platform* ground = new Platform(Rect(-10, -8, 20, 1));
	ground->color = Colour(200, 0, 200);

	Platform* floor4HT1 = new Platform(Rect(-10, 3, 1.5, 2));
	floor4HT1->color = Colour(200, 0, 200);

	Platform* floor4HT2 = new Platform(Rect(-8.5, -0.5, 1.5, 2));
	floor4HT2->color = Colour(200, 0, 200);

	Platform* floor4HT3 = new Platform(Rect(-10, -4, 1.5, 2));
	floor4HT3->color = Colour(200, 0, 200);

	Platform* floor4HT4 = new Platform(Rect(-10, -8, 3, 2));
	floor4HT4->color = Colour(200, 0, 200);

	Platform* floor4HT5 = new Platform(Rect(-2, -2, 8, 1));
	floor4HT5->color = Colour(200, 0, 200);

	Platform* floor4HT6 = new Platform(Rect(-2, -7, 1, 1.5));
	floor4HT6->color = Colour(200, 0, 200);

	Platform* floor4HT7 = new Platform(Rect(-1, 0, 2, 1));
	floor4HT7->color = Colour(200, 0, 200);

	Platform* floor4HT8 = new Platform(Rect(2, 1, 2, 1));
	floor4HT8->color = Colour(200, 0, 200);

	Platform* floor4HT9 = new Platform(Rect(6, 2, 2, 1));
	floor4HT9->color = Colour(200, 0, 200);

	Platform* floor4HT10 = new Platform(Rect(9, 4, 2, 1));
	floor4HT10->color = Colour(200, 0, 200);

	Platform* floor4HT11 = new Platform(Rect(7, -6, 3, 0.5));
	floor4HT11->color = Colour(200, 0, 200);

	Platform* floor4HT12 = new Platform(Rect(8, -4.5, 2, 0.5));
	floor4HT12->color = Colour(200, 0, 200);

	Platform* floor4HT13 = new Platform(Rect(9, -3, 1, 0.5));
	floor4HT13->color = Colour(200, 0, 200);

	Platform* moving = new Platform(Rect(1, 0, 1, 0.5));
	moving->color = Colour(200, 0, 200);

	block.push_back(wall);
	block.push_back(ground);
	block.push_back(floor4HT1);
	block.push_back(floor4HT2);
	block.push_back(floor4HT3);
	block.push_back(floor4HT4);
	block.push_back(floor4HT5);
	block.push_back(floor4HT6);
	block.push_back(floor4HT7);
	block.push_back(floor4HT8);
	block.push_back(floor4HT9);
	block.push_back(floor4HT10);
	block.push_back(floor4HT11);
	block.push_back(floor4HT12);
	block.push_back(floor4HT13);
	block.push_back(moving);

	return block;
}

//COLLECTIBLES
//Draw and give positions
std::vector<Collectible*> LevelManager::c2A()
{
	collectible.clear();

	Collectible* c2A1 = new Collectible(Rect(-4.75, 0.5, 0.5, 0.5));
	c2A1->color = Colour(0, 0, 0);

	Collectible* c2A2 = new Collectible(Rect(-9.25, 2.5, 0.5, 0.5));
	c2A2->color = Colour(0, 0, 0);

	Collectible* c2A3 = new Collectible(Rect(4.75, 3.5, 0.5, 0.5));
	c2A3->color = Colour(0, 0, 0);

	Collectible* c2A4 = new Collectible(Rect(8.75, 5.5, 0.5, 0.5));
	c2A4->color = Colour(0, 0, 0);

	collectible.push_back(c2A1);
	collectible.push_back(c2A2);
	collectible.push_back(c2A3);
	collectible.push_back(c2A4);

	return collectible;
}

std::vector<Collectible*> LevelManager::c2B()
{
	collectible.clear();

	Collectible* c2B1 = new Collectible(Rect(-4.75, 0.5, 0.5, 0.5));
	c2B1->color = Colour(0, 0, 0);

	Collectible* c2B2 = new Collectible(Rect(-9.25, 2.5, 0.5, 0.5));
	c2B2->color = Colour(0, 0, 0);

	Collectible* c2B3 = new Collectible(Rect(1.75, 2.25, 0.5, 0.5));
	c2B3->color = Colour(0, 0, 0);

	Collectible* c2B4 = new Collectible(Rect(8.75, 5.5, 0.5, 0.5));
	c2B4->color = Colour(0, 0, 0);

	Collectible* c2B5 = new Collectible(Rect(4.75, 5.5, 0.5, 0.5));
	c2B5->color = Colour(0, 0, 0);

	Collectible* c2B6 = new Collectible(Rect(4.75, 0.5, 0.5, 0.5));
	c2B6->color = Colour(0, 0, 0);

	collectible.push_back(c2B1);
	collectible.push_back(c2B2);
	collectible.push_back(c2B3);
	collectible.push_back(c2B4);
	collectible.push_back(c2B5);
	collectible.push_back(c2B6);

	return collectible;
}

std::vector<Collectible*> LevelManager::c3A()
{
	collectible.clear();

	Collectible* c3A1 = new Collectible(Rect(-3.25, 0.5, 0.5, 0.5));
	c3A1->color = Colour(0, 0, 0);

	Collectible* c3A2 = new Collectible(Rect(3.25, -1.75, 0.5, 0.5));
	c3A2->color = Colour(0, 0, 0);

	collectible.push_back(c3A1);
	collectible.push_back(c3A2);

	return collectible;
}

std::vector<Collectible*> LevelManager::c3B()
{
	collectible.clear();

	Collectible* c3B1 = new Collectible(Rect(-3.25, 0.5, 0.5, 0.5));
	c3B1->color = Colour(0, 0, 0);

	Collectible* c3B2 = new Collectible(Rect(3.25, -1.75, 0.5, 0.5));
	c3B2->color = Colour(0, 0, 0);

	collectible.push_back(c3B1);
	collectible.push_back(c3B2);

	return collectible;
}

std::vector<Collectible*> LevelManager::c3C()
{
	collectible.clear();

	Collectible* c3C1 = new Collectible(Rect(-3.25, 0.5, 0.5, 0.5));
	c3C1->color = Colour(0, 0, 0);

	Collectible* c3C2 = new Collectible(Rect(3.25, -1.75, 0.5, 0.5));
	c3C2->color = Colour(0, 0, 0);

	collectible.push_back(c3C1);
	collectible.push_back(c3C2);

	return collectible;
}

std::vector<Collectible*> LevelManager::c3D()
{
	collectible.clear();

	Collectible* c3D1 = new Collectible(Rect(-9.5, 0.5, 0.5, 0.5));
	c3D1->color = Colour(0, 0, 0);

	Collectible* c3D2 = new Collectible(Rect(-3.5, 0.5, 0.5, 0.5));
	c3D2->color = Colour(0, 0, 0);

	Collectible* c3D3 = new Collectible(Rect(-3.75, -5.5, 0.5, 0.5));
	c3D3->color = Colour(0, 0, 0);

	Collectible* c3D4 = new Collectible(Rect(2, -5.5, 0.5, 0.5));
	c3D4->color = Colour(0, 0, 0);

	Collectible* c3D5 = new Collectible(Rect(3.25, -1.5, 0.5, 0.5));
	c3D5->color = Colour(0, 0, 0);

	Collectible* c3D6 = new Collectible(Rect(9, -1.5, 0.5, 0.5));
	c3D6->color = Colour(0, 0, 0);

	collectible.push_back(c3D1);
	collectible.push_back(c3D2);
	collectible.push_back(c3D3);
	collectible.push_back(c3D4);
	collectible.push_back(c3D5);
	collectible.push_back(c3D6);

	return collectible;
}

std::vector<Collectible*> LevelManager::c3E()
{
	collectible.clear();

	Collectible* c3E1 = new Collectible(Rect(-9.75, -4.5, 0.5, 0.5));
	c3E1->color = Colour(0, 0, 0);

	Collectible* c3E2 = new Collectible(Rect(-3.5, 0.5, 0.5, 0.5));
	c3E2->color = Colour(0, 0, 0);

	Collectible* c3E3 = new Collectible(Rect(-3.75, -5.5, 0.5, 0.5));
	c3E3->color = Colour(0, 0, 0);

	Collectible* c3E4 = new Collectible(Rect(2, -5.5, 0.5, 0.5));
	c3E4->color = Colour(0, 0, 0);

	Collectible* c3E5 = new Collectible(Rect(3.25, -1.5, 0.5, 0.5));
	c3E5->color = Colour(0, 0, 0);

	collectible.push_back(c3E1);
	collectible.push_back(c3E2);
	collectible.push_back(c3E3);
	collectible.push_back(c3E4);
	collectible.push_back(c3E5);

	return collectible;
}

std::vector<Collectible*> LevelManager::c3F()
{
	collectible.clear();

	Collectible* c3F1 = new Collectible(Rect(-4, 0.5, 0.5, 0.5));
	c3F1->color = Colour(0, 0, 0);

	Collectible* c3F2 = new Collectible(Rect(-3.75, -5.75, 0.5, 0.5));
	c3F2->color = Colour(0, 0, 0);

	Collectible* c3F3 = new Collectible(Rect(1.5, -5.75, 0.5, 0.5));
	c3F3->color = Colour(0, 0, 0);

	Collectible* c3F4 = new Collectible(Rect(3, -1.5, 0.5, 0.5));
	c3F4->color = Colour(0, 0, 0);

	Collectible* c3F5 = new Collectible(Rect(9, -1.5, 0.5, 0.5));
	c3F5->color = Colour(0, 0, 0);

	collectible.push_back(c3F1);
	collectible.push_back(c3F2);
	collectible.push_back(c3F3);
	collectible.push_back(c3F4);
	collectible.push_back(c3F5);

	return collectible;
}

std::vector<Collectible*> LevelManager::c3G()
{
	collectible.clear();

	Collectible* c3G1 = new Collectible(Rect(-4, 0.5, 0.5, 0.5));
	c3G1->color = Colour(0, 0, 0);

	Collectible* c3G2 = new Collectible(Rect(-3.75, -5.75, 0.5, 0.5));
	c3G2->color = Colour(0, 0, 0);

	Collectible* c3G3 = new Collectible(Rect(1.5, -5.75, 0.5, 0.5));
	c3G3->color = Colour(0, 0, 0);

	Collectible* c3G4 = new Collectible(Rect(3, -1.5, 0.5, 0.5));
	c3G4->color = Colour(0, 0, 0);

	Collectible* c3G5 = new Collectible(Rect(9, -1.5, 0.5, 0.5));
	c3G5->color = Colour(0, 0, 0);

	Collectible* c3G6 = new Collectible(Rect(-9.75, -5.75, 0.5, 0.5));
	c3G6->color = Colour(0, 0, 0);

	collectible.push_back(c3G1);
	collectible.push_back(c3G2);
	collectible.push_back(c3G3);
	collectible.push_back(c3G4);
	collectible.push_back(c3G5);
	collectible.push_back(c3G6);

	return collectible;
}

//ENEMIES
//Draw and give positions
std::vector<Enemy*> LevelManager::enemy3A()
{
	enemy.clear();

	Enemy* e3A1 = new Enemy(Rect(6, -2, 1, 1));
	e3A1->color = Colour(244, 66, 66);

	enemy.push_back(e3A1);

	return enemy;
}

std::vector<Enemy*> LevelManager::enemy3B()
{
	enemy.clear();

	Enemy* e3B1 = new Enemy(Rect(6, -2, 1, 1));
	e3B1->color = Colour(244, 66, 66);

	Enemy* e3B2 = new Enemy(Rect(-2, 2, 1, 1));
	e3B2->color = Colour(244, 66, 66);

	enemy.push_back(e3B1);
	enemy.push_back(e3B2);

	return enemy;
}

std::vector<Enemy*> LevelManager::enemy3C()
{
	enemy.clear();

	Enemy* e3C1 = new Enemy(Rect(6, -2, 1, 1));
	e3C1->color = Colour(244, 66, 66);

	Enemy* e3C2 = new Enemy(Rect(-2, 2, 1, 1));
	e3C2->color = Colour(244, 66, 66);

	Enemy* e3C3 = new Enemy(Rect(-3, 0, 1, 1));
	e3C3->color = Colour(244, 66, 66);

	Enemy* e3C4 = new Enemy(Rect(-5, 2, 1, 1));
	e3C4->color = Colour(244, 66, 66);

	enemy.push_back(e3C1);
	enemy.push_back(e3C2);
	enemy.push_back(e3C3);
	enemy.push_back(e3C4);

	return enemy;
}

std::vector<Enemy*> LevelManager::enemy3D()
{
	enemy.clear();

	Enemy* e3D1 = new Enemy(Rect(6, -2, 1, 1));
	e3D1->color = Colour(244, 66, 66);

	Enemy* e3D2 = new Enemy(Rect(-3, 0, 1, 1));
	e3D2->color = Colour(244, 66, 66);

	enemy.push_back(e3D1);
	enemy.push_back(e3D2);

	return enemy;
}

std::vector<Enemy*> LevelManager::enemy3E()
{
	enemy.clear();

	Enemy* e3E1 = new Enemy(Rect(6, -2, 1, 1));
	e3E1->color = Colour(244, 66, 66);

	Enemy* e3E2 = new Enemy(Rect(-3, 0, 1, 1));
	e3E2->color = Colour(244, 66, 66);

	enemy.push_back(e3E1);
	enemy.push_back(e3E2);

	return enemy;
}

std::vector<Enemy*> LevelManager::enemy3F()
{
	enemy.clear();

	Enemy* e3F1 = new Enemy(Rect(6, -2, 1, 1));
	e3F1->color = Colour(244, 66, 66);

	Enemy* e3F2 = new Enemy(Rect(-3, 0, 1, 1));
	e3F2->color = Colour(244, 66, 66);

	Enemy* e3F3 = new Enemy(Rect(-6, 0, 1, 1));
	e3F3->color = Colour(244, 66, 66);

	enemy.push_back(e3F1);
	enemy.push_back(e3F2);
	enemy.push_back(e3F3);

	return enemy;
}

std::vector<Enemy*> LevelManager::enemy3G()
{
	enemy.clear();

	Enemy* e3G1 = new Enemy(Rect(6, -2, 1, 1));
	e3G1->color = Colour(244, 66, 66);

	Enemy* e3G2 = new Enemy(Rect(-3, 0, 1, 1));
	e3G2->color = Colour(244, 66, 66);

	Enemy* e3G3 = new Enemy(Rect(-6, 0, 1, 1));
	e3G3->color = Colour(244, 66, 66);

	enemy.push_back(e3G1);
	enemy.push_back(e3G2);
	enemy.push_back(e3G3);

	return enemy;
}

std::vector<Enemy*> LevelManager::enemy4E_enemy()
{
	enemy.clear();

	Enemy* e4Ee1 = new Enemy(Rect(-7, -1, 1, 1));
	e4Ee1->color = Colour(244, 66, 66);

	Enemy* e4Ee2 = new Enemy(Rect(-5, -1, 1, 1));
	e4Ee2->color = Colour(244, 66, 66);

	Enemy* e4Ee3 = new Enemy(Rect(0, -1, 1, 1));
	e4Ee3->color = Colour(244, 66, 66);

	Enemy* e4Ee4 = new Enemy(Rect(5, -1, 1, 1));
	e4Ee4->color = Colour(244, 66, 66);

	enemy.push_back(e4Ee1);
	enemy.push_back(e4Ee2);
	enemy.push_back(e4Ee3);
	enemy.push_back(e4Ee4);

	return enemy;
}

std::vector<Spikes*> LevelManager::spikes4E()
{
	spikes.clear();

	Spikes* spike4E1 = new Spikes(Rect(-6, 10, 1, 20));
	spike4E1->color = Colour(244, 66, 66);

	Spikes* spike4E2 = new Spikes(Rect(1, 10, 1, 20));
	spike4E2->color = Colour(244, 66, 66);

	spikes.push_back(spike4E1);
	spikes.push_back(spike4E2);

	return spikes;

}

std::vector<Enemy*> LevelManager::enemy4H_enemy()
{
	enemy.clear();

	Enemy* e4He1 = new Enemy(Rect(-7, -1, 1, 1));
	e4He1->color = Colour(244, 66, 66);

	Enemy* e4He2 = new Enemy(Rect(-5, -1, 1, 1));
	e4He2->color = Colour(244, 66, 66);

	Enemy* e4He3 = new Enemy(Rect(0, -1, 1, 1));
	e4He3->color = Colour(244, 66, 66);

	Enemy* e4He4 = new Enemy(Rect(3, -1, 1, 1));
	e4He4->color = Colour(244, 66, 66);

	Enemy* e4He5 = new Enemy(Rect(6, -1, 1, 1));
	e4He5->color = Colour(244, 66, 66);

	enemy.push_back(e4He1);
	enemy.push_back(e4He2);
	enemy.push_back(e4He3);
	enemy.push_back(e4He4);
	enemy.push_back(e4He5);

	return enemy;
}

std::vector<Spikes*> LevelManager::spikes4H()
{
	spikes.clear();

	Spikes* spike4H1 = new Spikes(Rect(-6, 10, 1, 20));
	spike4H1->color = Colour(244, 66, 66);

	Spikes* spike4H2 = new Spikes(Rect(1, 10, 1, 20));
	spike4H2->color = Colour(244, 66, 66);

	spikes.push_back(spike4H1);
	spikes.push_back(spike4H2);

	return spikes;

}