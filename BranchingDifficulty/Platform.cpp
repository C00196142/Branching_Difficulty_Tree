#include "Platform.h"

Platform::Platform()
{
}


Platform::~Platform()
{
}

void Platform::Render(Renderer& r)
{
	r.drawWorldRect(floor, color);
}

void Platform::Update(unsigned int deltaTime)
{
	Point2D p = floor.pos;
}
