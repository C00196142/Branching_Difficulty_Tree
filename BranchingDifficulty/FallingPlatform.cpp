#include "FallingPlatform.h"

FallingPlatform::FallingPlatform()
{
}


FallingPlatform::~FallingPlatform()
{
}

void FallingPlatform::Render(Renderer& r)
{
	r.drawWorldRect(fallFloor, color);
}

void FallingPlatform::Update(unsigned int deltaTime)
{
	Point2D p = fallFloor.pos;
}

void FallingPlatform::PlayerCollision(Rect obj, int minTimer, int maxTimer)
{
	//if the player is on the platform for two long it will fall
	if ((fallFloor.pos.x + fallFloor.size.w) > obj.pos.x && fallFloor.pos.x < (obj.pos.x + obj.size.w) && fallFloor.pos.y + 1 < (obj.pos.y + obj.size.h) && (fallFloor.pos.y + 1 + fallFloor.size.h) > obj.pos.y)
	{
		count++;
		if (count > minTimer)
		{
			color = Colour(200, 0, 0);
		}
		if (count > maxTimer)
		{
			falling = true;
		}
	}
	if (falling == true)
	{
		fallFloor.pos.y -= 0.1;
	}
	//if the platform moves off screen it will return to its original position
	if (fallFloor.pos.y <= -9)
	{
		falling = false;
		fallFloor.pos.y = -1;
		count = 0;
		color = Colour(200, 200, 0);
	}
}
