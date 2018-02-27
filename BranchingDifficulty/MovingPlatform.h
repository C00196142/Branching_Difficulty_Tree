#pragma once

#include "GameObject.h"
#include "Renderer.h"
#include "SDL_image.h"
#include <iostream>
#include <string>

class MovingPlatform : public GameObject
{
public:
	MovingPlatform();
	~MovingPlatform();

	MovingPlatform(Rect r) : mover(r) {};
	void Render(Renderer & r);
	void Update(unsigned int deltaTime);


	Rect mover;
	Colour color;

};

