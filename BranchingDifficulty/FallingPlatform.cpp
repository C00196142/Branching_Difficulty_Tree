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

void FallingPlatform::PlayerCollision(Rect obj)
{
	//if the 2 rectangles intersect
	if ((fallFloor.pos.x + fallFloor.size.w) > obj.pos.x && fallFloor.pos.x < (obj.pos.x + obj.size.w) && fallFloor.pos.y + 1 < (obj.pos.y + obj.size.h) && (fallFloor.pos.y + 1 + fallFloor.size.h) > obj.pos.y)
	{
		cout << fallFloor.pos.y << endl;
		//cout << count << endl;
		count++;
		if (count > 50)
		{
			color = Colour(200, 0, 0);
		}
		if (count > 100)
		{
			fallFloor.pos.y--;
		}
		if (fallFloor.pos.y <= -9)
		{
			fallFloor.pos.y = -1;
			count = 0;
			color = Colour(200, 200, 0);
		}
	}
}
