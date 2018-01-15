#pragma once

#define SDL_MAIN_HANDLED
#ifdef __APPLE__
#include "SDL2/SDL.h"
#elif defined(_WIN64) || defined(_WIN32)
#include "SDL.h"
#endif


#include<map>
#include<vector>
#include "EventListener.h"
#include <iostream>

//Convert input into logical events
class InputManager
{
	//dictionary holding a list of litener objs for each event type
	std::map<
		EventListener::Event,
		//pointer to vec of eventlisteners
		std::vector<EventListener*>*
	> listeners;
	bool keyPressed = true;

public:
	InputManager();
	~InputManager();

	void AddListener(EventListener::Event, EventListener*);
	void Dispatch(EventListener::Event);

	std::vector<EventListener::Event> events;
	std::vector<EventListener::Event> getEventList();

	void ProcessInput();

	int start = 0;
};

