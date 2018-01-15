#pragma once

#include "GameObject.h"
#include "Renderer.h"
#include "SDL_image.h"
#include <iostream>
#include <string>

class FinishLine : public GameObject
{
public:
	FinishLine();
	~FinishLine();

	FinishLine(Rect r) : finish(r) {};
	void Render(Renderer & r);
	void Update(unsigned int deltaTime);
	void NextLevel(Rect player);

	Rect finish;
	Colour color;
	bool levelComplete;

};

