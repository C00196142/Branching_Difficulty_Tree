#pragma once

#include "GameObject.h"
#include "Renderer.h"
#include "SDL_image.h"
#include <vector>
#include <string>

class Platform:public GameObject
{
public:
	Platform();
	~Platform();

	Platform(Rect r) :floor(r) { angVel = .0f; };
	void Render(Renderer & r);
	void Update(unsigned int deltaTime);

	Rect floor;
	Colour color;

	//control rate of spin
	float angVel;
};

