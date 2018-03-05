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

