#pragma once

#include "GameObject.h"
#include "Renderer.h"
#include "SDL_image.h"
#include <iostream>
#include <string>

class Boss : public GameObject
{
public:
	Boss();
	~Boss();

	Boss(Rect r) : boss(r) {};
	void Render(Renderer & r);
	void Update(unsigned int deltaTime);
	void Move(float xMin, float xMax, float speed);

	Rect boss;
	Colour color;

private:
	bool moveRight = false;

};
