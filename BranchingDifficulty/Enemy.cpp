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
}

void Enemy::Move(float xMin, float xMax, float speed)
{
	if (moveRight == true)
	{
		enemy.pos.x = enemy.pos.x + speed;
		if (enemy.pos.x >= xMax)
		{
			moveRight = false;
		}
	}
	else if (moveRight == false)
	{
		enemy.pos.x = enemy.pos.x - speed;
		if (enemy.pos.x <= xMin)
		{
			moveRight = true;
		}
	}
}
