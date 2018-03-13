#pragma once

#include "GameObject.h"
#include "Renderer.h"
#include "SDL_image.h"
#include <iostream>
#include <string>

class Spikes : public GameObject
{
public:
	Spikes();
	~Spikes();

	Spikes(Rect r) : spikes(r) {};
	void Render(Renderer & r);
	void Update(unsigned int deltaTime);
	void Move(float yMin, float yMax, float speed);

	Rect spikes;
	Colour color;

private:
	bool moveDown = true;

};