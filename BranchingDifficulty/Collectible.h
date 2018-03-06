#pragma once

#include "GameObject.h"
#include "Renderer.h"
#include "SDL_image.h"
#include <iostream>
#include <string>

class Collectible : public GameObject
{
public:
	Collectible();
	~Collectible();

	Collectible(Rect r) : collectible(r) {};
	void Render(Renderer & r);
	void Update(unsigned int deltaTime);

	Rect collectible;
	Colour color;

	void CheckAlive(int x, int y);
	void collectibleCollision(Rect obj);

};

