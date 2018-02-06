#include "Enemy.h"



Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

void Enemy::Render(Renderer & r)
{
	r.drawWorldRect(enemy, color);
}

void Enemy::Update(unsigned int deltaTime)
{
	Point2D p = enemy.pos;

	if (moveRight == true)
	{
		enemy.pos.x = enemy.pos.x + 0.015;
		if (enemy.pos.x >= 7)
		{
			moveRight = false;
		}
	}
	else if (moveRight == false)
	{
		enemy.pos.x = enemy.pos.x - 0.015;
		if (enemy.pos.x <= 4)
		{
			moveRight = true;
		}
	}
}
