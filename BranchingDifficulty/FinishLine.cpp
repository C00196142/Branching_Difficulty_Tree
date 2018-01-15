#include "FinishLine.h"



FinishLine::FinishLine()
{
}


FinishLine::~FinishLine()
{
}

void FinishLine::Render(Renderer & r)
{
	r.drawWorldRectOutline(finish, color);
}

void FinishLine::Update(unsigned int deltaTime)
{
	Point2D p = finish.pos;
}

void FinishLine::NextLevel(Rect player)
{
	if (finish.pos.x <= player.pos.x + player.size.w / 2 && finish.pos.x >= player.pos.x - player.size.w*1.5 && finish.pos.y <= player.pos.y + player.size.h * 1.5 && finish.pos.y >= player.pos.y - player.size.h / 2)
	{
		levelComplete = true;
		std::cout << "FINISH" << std::endl;

	}
}