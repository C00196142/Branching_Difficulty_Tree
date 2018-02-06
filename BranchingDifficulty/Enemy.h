#pragma once

#include "GameObject.h"
#include "Renderer.h"
#include "SDL_image.h"
#include <iostream>
#include <string>

class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();

	Enemy(Rect r) : enemy(r) {};
	void Render(Renderer & r);
	void Update(unsigned int deltaTime);
	void Move(float xMin, float xMax, float speed);

	Rect enemy;
	Colour color;

private:
	bool moveRight = false;

};

