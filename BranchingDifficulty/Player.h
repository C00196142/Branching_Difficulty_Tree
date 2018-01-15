// PURPOSE : HEADER FILE THAT DEFINES Players PROPERTIES AND FUNCTIONS (ESPECIALLY MANY BOOL PROPERTIES FOR CHECKING IF HE IS IN THE AIR OR IF HES MOVING)
#pragma once
#include "GameObject.h"
#include "BasicTypes.h"
#include "EventListener.h"
#include "Renderer.h"


class Player :public GameObject, public EventListener
{
public:
	Player();
	~Player();
	void Update();
	void Render(Renderer& r);
	void Move();
	void Update(unsigned int deltaTime);
	void setInAir(bool airBool);
	void StartMove(bool left);
	void Fall();
	void Stop();
	void Jump();
	void MaxSpeed();
	void CheckJumpingStatus();
	void onEvent(EventListener::Event);
	void ChangePos(int x, int y);
	void Obstacle(Rect obj);
	void setCanJump(bool jumpBool);
	void setOnPlatform(bool platBool);
	//void checkAlive();
	void resetPlayer();
	bool alive = true;
	Rect rect;

	int resetX;
	int resetY;

private:

	Colour col;
	float xVel;
	float yVel;
	const double maxXVel = 0.05;
	const double xAccel = 0.0025;
	bool isStopping = false;
	bool rising = false;
	bool inAir = false;
	bool isJumpPressed = false;
	bool isMoveButton = false;
	bool onPlatform = false;
	bool falling = true;

	int timer;
	int jumpTimer;
	bool canJump = true;
	bool hitCheck = false;

};