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

//Move the enemies 
//Each is given a min and max position and a speed to move between the points
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
