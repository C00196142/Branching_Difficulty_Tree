
#include "Player.h"
#include <iostream>

//Constructor of Thomas with his general attributes
//his colour
//he is a rectangle
//he has no start-speed in x and y direction
//no falling timer
//setting his start jumpTimer to 40
Player::Player()
{
	col = Colour(255, 0, 0);
	rect = Rect(0, 0, 0.5, 1);
	xVel = 0;
	yVel = 0;
	timer = 0;
}

//Destructor of Thomas
Player::~Player()
{
}

//empty Thomas Update-function
void Player::Update()
{

}

//Rendering function
//Rendering function for drawing the Thomas-Object
// \param[in] the Renderer which actually should draw the Thomas-Object
void Player::Render(Renderer& r)
{
	r.drawWorldRect(rect, col);
}


//Jumping function
//Function which causes the Thomas-Object to jump up
void::Player::Jump()
{
	//if (onPlatform == true)
	//{
		rising = true;
		jumpTimer = 40;
		yVel = maxXVel;
	//}

}

//Maximum Speed function
//Function checks if the velocity is greater than max speed.
//If velocity is greater than max speed it sets speed to be equal to max speed
//If velocity is less than minus max speed it sets speed to be equal to minus max speed
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

//Checks the status of various jumping related variables
//Checks if the jump button is pressed
//checks if Player is jumping up
//checks if he is falling and calls Fall() if he is 
//checks if he reaches the apex of the jump by seeing if the timer reaches the maxTimer value
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
		//while decending
		Fall();
	}

	//start to fall
	//set rising to false, reset variables
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

//Moves Player horizontally
//Checks if thomas is within the bounds of the screen, if they are the player can move left and right
//sets the speed of Player to be 0 if he is moving too slowly
//calls the slowdown function called Stop() if the player isn't moving
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

//Update Player loop
//Calls the CheckJumpingStatus, Move and MaxSpeed functions
//adds yVelocity to position
//sets falling to true
// \param[in] deltaTime is used to know how long has passed since the last frame
void Player::Update(unsigned int deltaTime)
{
	CheckJumpingStatus();
	MaxSpeed();
	rect.pos.y += yVel;
	Move();

	//falling is set to true at the end of update
	//when collisions are called if Player collides with the top of any object falling is set to false
	//falling is set to true every update so he will fall of platforms if he walks off them
	falling = true;
}

//Sets the inAir bool
// \param[in] airBool is the value to be set
void Player::setInAir(bool airBool)
{
	inAir = airBool;
}

void Player::setOnPlatform(bool platBool)
{
	onPlatform = platBool;
}

//Horizontal movement function
//Function which causes the Player-Object to move left or right if the he is on the ground
//if he is in the air and falling he can move left or right but at a slower pace
// \param[in] left is the bool to say if the player is moving left or right
void Player::StartMove(bool left)
{
	if (!rising)
	{
		inAir = true;
		rising = false;
		if (left)
		{
			if (inAir)
			{
				xVel -= (xAccel / 2);
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
				xVel += (xAccel / 2);
			}
			else
			{
				xVel += xAccel;
			}
		}
	}
}

//Falling Function
//decrements Player' yVelovity
void Player::Fall()
{

	yVel -= 0.001;

}

//Stopping Function
//decrements Thomas' xVelovity if he isnt rising
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

//Event handler
//Sets variables when it recieves input
//sets move left if left is pressed, move right if right is pressed
//starts jump if jump is pressed
//sets stop if left or right is released
//sets superjump if jump button is held
// \param[in] evt is the event called
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

//Chenges Player's position and resets speed
// \param[in] x is the X position to move Player to
// \param[in] y is the Y position to move Player to
void Player::ChangePos(int x, int y)
{
	rect.pos.x = x;
	rect.pos.y = y;
	xVel = 0;
	yVel = 0;
}

void Player::resetPlayer()
{
	ChangePos(resetX, resetY);
	alive = true;
	std::cout << "DEAD" << std::endl;
}



