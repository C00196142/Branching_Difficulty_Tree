#include "MovingPlatform.h"



MovingPlatform::MovingPlatform()
{
}


MovingPlatform::~MovingPlatform()
{
}

void MovingPlatform::Render(Renderer & r)
{
	r.drawWorldRect(mover, color);
}

void MovingPlatform::Update(unsigned int deltaTime)
{
	Point2D p = mover.pos;
}