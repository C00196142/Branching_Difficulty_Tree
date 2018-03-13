#include "Spikes.h"



Spikes::Spikes()
{
}


Spikes::~Spikes()
{
}

void Spikes::Render(Renderer & r)
{
	r.drawWorldRect(spikes, color);
}

void Spikes::Update(unsigned int deltaTime)
{
	Point2D p = spikes.pos;
}

void Spikes::Move(float yMin, float yMax, float speed)
{
	if (moveDown == true)
	{
		spikes.pos.y = spikes.pos.y - speed;
		if (spikes.pos.y <= yMin)
		{
			moveDown = false;
		}
	}
	else if (moveDown == false)
	{
		spikes.pos.y = spikes.pos.y + (speed/3);
		if (spikes.pos.y >= yMax)
		{
			moveDown = true;
		}
	}
}