
#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
{
	col = Colour(255, 100, 0);
	rect = Rect(-9, 0, 0.5, 1);
	xVel = 0;
	yVel = 0;
	timer = 0;
	jumpTimer = 40;

	fallDeaths = 0;
	enemyDeaths = 0;
	collectibles = 0;
	maxCollectibles = 0;
}
Player::~Player()
{
}

void Player::Update()
{

}
void Player::Update(unsigned int deltaTime)
{
	CheckJumpingStatus();
	MaxSpeed();
	rect.pos.y += yVel;
	Move();

	checkFallDeath();
	falling = true;

}

void Player::Render(Renderer& r)
{
	r.drawWorldRect(rect, col);
}


void::Player::Jump()
{
	if (onPlatform == true && canJump == true)
	{
		rising = true;
		jumpTimer = 40;
		yVel = maxXVel;
	}

}

void::Player::MaxSpeed()
{
	if (xVel > maxXVel)
	{
		xVel = maxXVel;
	}
	else if (xVel < -maxXVel)
	{
		xVel = -maxXVel;
	}
}
void::Player::CheckJumpingStatus()
{
	//checkAlive();
	if (isJumpPressed)
	{
		Jump();
	}
	//if Player is rising add to the rising timer
	if (rising)
	{
		inAir = true;
		timer++;
	}
	if (inAir == true && rising == false)
	{
		Fall();
	}

	//start to fall
	if (timer >= jumpTimer) 
	{
		if (isJumpPressed && jumpTimer < 60)
		{
			jumpTimer = 60;
		}
		else
		{
			rising = false;
			timer = 0;
			yVel = 0;
		}
	}

	
}

void Player::Move()
{
	if (rect.pos.x <= 9.5 && rect.pos.x >= -10)
	{
		if (xVel < 0.0025 && xVel > -0.0025 && isMoveButton == false)
		{
			xVel = 0;
			isStopping = false;
		}
		else
		{
			rect.pos.x += xVel;
		}
		if (isStopping)
		{
			Stop();
		}

	}
	else
	{
		xVel = 0;
		if (rect.pos.x > 9.5)
		{
			rect.pos.x = 9.5;
		}
		else if (rect.pos.x < -10)
		{
			rect.pos.x = -10;
		}
	}
}

void Player::setInAir(bool airBool)
{
	inAir = airBool;
}

void Player::PlatformCollision(Rect obj)
{
	//if the 2 rectangles intersect
	if ((rect.pos.x + rect.size.w) > obj.pos.x && rect.pos.x < (obj.pos.x + obj.size.w) && rect.pos.y < (obj.pos.y + obj.size.h) && (rect.pos.y + rect.size.h) > obj.pos.y)
	{
		//if minusing the x velocity
		float lastXPos = rect.pos.x - xVel;
		float lastYPos = rect.pos.y - yVel;
		if (!((lastXPos + rect.size.w) > obj.pos.x && lastXPos < (obj.pos.x + obj.size.w)))
		{
			rect.pos.x = lastXPos;
			xVel = 0;
		
		}
		else if (!(lastYPos < (obj.pos.y + obj.size.h) && (lastYPos + rect.size.h) > obj.pos.y))
		{
			rect.pos.y = lastYPos;
			yVel = 0;

			if (rect.pos.y >= (obj.pos.y + obj.size.h))
			{
				inAir = false;
				rect.pos.y = obj.pos.y + obj.size.h;
				onPlatform = true;
			}
			else
			{
				rising = false;
				timer = 60;
			}
		}
	}
	float tempY = rect.pos.y - maxXVel;
	if ((rect.pos.x + rect.size.w) > obj.pos.x && rect.pos.x < (obj.pos.x + obj.size.w) && tempY < (obj.pos.y + obj.size.h) && (tempY + rect.size.h) > obj.pos.y)
	{
		falling = true;
	}

}

void Player::setOnPlatform(bool platBool)
{
	onPlatform = platBool;
}

void Player::setCanJump(bool jumpBool)
{
	canJump = jumpBool;
}

void Player::StartMove(bool left)
{
	//if (!rising)
	//{
		inAir = true;
		rising = false;
		if (left)
		{
			if (inAir)
			{
				//xVel -= (xAccel / 2);
				xVel -= (xAccel / 1.5);
			}
			else
			{
				xVel -= xAccel;
			}

		}
		else
		{
			if (inAir)
			{
				//xVel += (xAccel / 2);
				xVel += (xAccel / 1.5);
			}
			else
			{
				xVel += xAccel;
			}
		}
	//}
}
void Player::Fall()
{

	yVel -= 0.001;

}

void Player::Stop()
{
	if (!rising)
	{
		if (xVel < 0)
		{
			xVel += (xAccel / 3);
		}
		if (xVel > 0)
		{
			xVel -= (xAccel / 3);
		}
	}
}

void Player::onEvent(EventListener::Event evt)
{
	if (evt == EventListener::Event::LEFT)
	{
		StartMove(true);
		isMoveButton = true;
		isStopping = false;
	}
	if (evt == EventListener::Event::RIGHT)
	{
		StartMove(false);
		isMoveButton = true;
		isStopping = false;
	}
	if (evt == EventListener::Event::STOP)
	{
		isStopping = true;
		isMoveButton = false;
	}
	if (evt == EventListener::Event::JUMP)
	{
		isJumpPressed = true;
	}
	if (evt == EventListener::Event::SUPERJUMP)
	{
		isJumpPressed = false;
	}
}

void Player::checkFallDeath()
{
	if (rect.pos.y < -8)
	{
		alive = false;
		std::cout << "Fell to Death" << std::endl;

		fallDeaths++;
		cout << "Fall Deaths: " << fallDeaths << endl;
	}
}
void Player::enemyCollision(Rect obj)
{
	//if the 2 rectangles intersect
	if ((rect.pos.x + rect.size.w) > obj.pos.x && rect.pos.x < (obj.pos.x + obj.size.w) && rect.pos.y < (obj.pos.y + obj.size.h) && (rect.pos.y + rect.size.h) > obj.pos.y)
	{
		alive = false;
		std::cout << "Killed by Enemy" << std::endl;

		enemyDeaths++;
		cout << "Enemy Deaths: " << enemyDeaths << endl;
	}
}

void Player::collectibleCollision(Rect obj)
{
	//if the 2 rectangles intersect
	if ((rect.pos.x + rect.size.w) > obj.pos.x && rect.pos.x < (obj.pos.x + obj.size.w) && rect.pos.y < (obj.pos.y + obj.size.h) && (rect.pos.y + rect.size.h) > obj.pos.y)
	{
		collectibles++;
		std::cout << "Collected: " << collectibles << " of " << maxCollectibles << std::endl;

	}
}

void Player::ChangePos(int x, int y)
{
	rect.pos.x = x;
	rect.pos.y = y;
	xVel = 0;
	yVel = 0;	
}
void Player::resetPlayer(int resetX, int resetY)
{
	ChangePos(resetX, resetY);
	alive = true;
}
