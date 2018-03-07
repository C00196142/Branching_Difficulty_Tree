#include "Boss.h"



Boss::Boss()
{
}


Boss::~Boss()
{
}

void Boss::Render(Renderer & r)
{
	r.drawWorldRect(boss, color);
}

void Boss::Update(unsigned int deltaTime)
{
	Point2D p = boss.pos;
}

void Boss::Move(float xMin, float xMax, float speed)
{
	if (moveRight == true)
	{
		boss.pos.x = boss.pos.x + speed;
		if (boss.pos.x >= xMax)
		{
			moveRight = false;
		}
	}
	else if (moveRight == false)
	{
		boss.pos.x = boss.pos.x - speed;
		if (boss.pos.x <= xMin)
		{
			moveRight = true;
		}
	}
}
