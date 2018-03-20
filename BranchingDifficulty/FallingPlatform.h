#pragma once

#include "GameObject.h"
#include "Renderer.h"
#include "SDL_image.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class FallingPlatform :public GameObject
{
public:
	FallingPlatform();
	~FallingPlatform();

	FallingPlatform(Rect r) :fallFloor(r) { angVel = .0f; };
	void Render(Renderer & r);
	void Update(unsigned int deltaTime);
	void PlayerCollision(Rect obj);

	Rect fallFloor;
	Colour color;
	int count = 0;
	bool falling = false;

	//control rate of spin
	float angVel;
};
