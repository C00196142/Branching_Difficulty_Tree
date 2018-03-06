#include "Collectible.h"



Collectible::Collectible()
{
}


Collectible::~Collectible()
{
}

void Collectible::Render(Renderer & r)
{
	r.drawWorldRect(collectible, color);
}

void Collectible::Update(unsigned int deltaTime)
{

	Point2D p = collectible.pos;
	
}

void Collectible::collectibleCollision(Rect obj)
{
	//if the 2 rectangles intersect
	if ((collectible.pos.x + collectible.size.w) > obj.pos.x && collectible.pos.x < (obj.pos.x + obj.size.w) && collectible.pos.y < (obj.pos.y + obj.size.h) && (collectible.pos.y + collectible.size.h) > obj.pos.y)
	{

		CheckAlive(1000, 0);
	}
}

void Collectible::CheckAlive(int x, int y)
{
	collectible.pos.x = x;
	collectible.pos.y = y;
}

