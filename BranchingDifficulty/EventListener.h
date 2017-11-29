// PURPOSE : HEADER FILE FOR DEFINING ALL THE POSSIBLE EVENTS THAT CAN HAPPEN.
#pragma once

//Used as an interface for the event dispatcher
//Objects wanting to receive events must inherit from this

class EventListener
{
public:

	//list of possible events
	enum Event {
		//REVERSE,
		//PAUSE,
		//QUIT,
		//LEFT,
		//RIGHT,
		//STOP,
		//START,
		//JUMP,
		//RESTART
	};


	virtual void onEvent(Event) = 0;
};
