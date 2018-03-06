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

	Platform* floor3D3 = new Platform(Rect(-4, -1, 2, 1));
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

	Platform* floor3E3 = new Platform(Rect(-4, -1, 2, 1));
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

	Platform* floor4EF2 = new Platform(Rect(-8, -4, 1, 3));
	floor4EF2->color = Colour(200, 0, 200);

	Platform* floor4EF3 = new Platform(Rect(-6, -4, 1, 3));
	floor4EF3->color = Colour(200, 0, 200);

	Platform* floor4EF4 = new Platform(Rect(-3, -3.5, 1, 0.5));
	floor4EF4->color = Colour(200, 0, 200);

	Platform* floor4EF5 = new Platform(Rect(0, -4, 1, 3));
	floor4EF5->color = Colour(200, 0, 200);

	Platform* floor4EF6 = new Platform(Rect(2, -4, 1, 3));
	floor4EF6->color = Colour(200, 0, 200);

	Platform* floor4EF7 = new Platform(Rect(4, -4, 1, 4));
	floor4EF7->color = Colour(200, 0, 200);

	Platform* floor4EF8 = new Platform(Rect(6, -4, 1, 5));
	floor4EF8->color = Colour(200, 0, 200);

	Platform* floor4EF9 = new Platform(Rect(9, 1, 1, 1));
	floor4EF9->color = Colour(200, 0, 200);

	block.push_back(floor4EF1);
	block.push_back(floor4EF2);
	block.push_back(floor4EF3);
	block.push_back(floor4EF4);
	block.push_back(floor4EF5);
	block.push_back(floor4EF6);
	block.push_back(floor4EF7);
	block.push_back(floor4EF8);
	block.push_back(floor4EF9);

	return block;
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

	Platform* floor4HF2 = new Platform(Rect(-8, -4, 0.5, 3));
	floor4HF2->color = Colour(200, 0, 200);

	Platform* floor4HF3 = new Platform(Rect(-6, -4, 0.5, 3));
	floor4HF3->color = Colour(200, 0, 200);

	Platform* floor4HF4 = new Platform(Rect(-3, -3.5, 1, 0.5));
	floor4HF4->color = Colour(200, 0, 200);

	Platform* floor4HF5 = new Platform(Rect(0, -4, 0.5, 3));
	floor4HF5->color = Colour(200, 0, 200);

	Platform* floor4HF6 = new Platform(Rect(2, -4, 0.5, 3));
	floor4HF6->color = Colour(200, 0, 200);

	Platform* floor4HF7 = new Platform(Rect(4, -4, 0.5, 4));
	floor4HF7->color = Colour(200, 0, 200);

	Platform* floor4HF8 = new Platform(Rect(6, -4, 0.5, 5));
	floor4HF8->color = Colour(200, 0, 200);

	Platform* floor4HF9 = new Platform(Rect(9, 1, 1, 1));
	floor4HF9->color = Colour(200, 0, 200);

	block.push_back(floor4HF1);
	block.push_back(floor4HF2);
	block.push_back(floor4HF3);
	block.push_back(floor4HF4);
	block.push_back(floor4HF5);
	block.push_back(floor4HF6);
	block.push_back(floor4HF7);
	block.push_back(floor4HF8);
	block.push_back(floor4HF9);

	return block;
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

	Platform* floor4HT5 = new Platform(Rect(-3, -2, 10, 1));
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

	Platform* floor4HT11 = new Platform(Rect(7, -4, 3, 0.5));
	floor4HT11->color = Colour(200, 0, 200);

	Platform* floor4HT12 = new Platform(Rect(8, -3, 2, 0.5));
	floor4HT12->color = Colour(200, 0, 200);

	Platform* floor4HT13 = new Platform(Rect(9, -2, 1, 0.5));
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

