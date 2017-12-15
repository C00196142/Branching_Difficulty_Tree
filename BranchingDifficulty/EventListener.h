// PURPOSE : HEADER FILE FOR DEFINING ALL THE POSSIBLE EVENTS THAT CAN HAPPEN.
#pragma once

//Used as an interface for the event dispatcher
//Objects wanting to receive events must inherit from this

class EventListener
{
public:

	//list of possible events
	enum Event {
		REVERSE,
		LEFT,
		RIGHT,
		STOP,
		START,
		JUMP,
		SUPERJUMP,
		QUIT
	};


	virtual void onEvent(Event) = 0;
};
