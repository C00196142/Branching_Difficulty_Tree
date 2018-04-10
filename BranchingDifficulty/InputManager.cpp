#include "InputManager.h"


InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

void InputManager::AddListener(EventListener::Event evt, EventListener *listener)
{
	//event not in map add it.
	if (listeners.find(evt) == listeners.end()) {
		listeners[evt] = new std::vector<EventListener*>();
	}

	listeners[evt]->push_back(listener);

}

//Send the events to interested objects
void InputManager::Dispatch(EventListener::Event evt)
{

	if (listeners.find(evt) != listeners.end()) {

		//go through all listeners for this event
		for (auto const &listener : *listeners[evt]) {
			//Call on event for the listener
			listener->onEvent(evt);
			events.push_back(evt);
		}
	}

}


//Generate events
void InputManager::ProcessInput(bool menu)
{
	events.clear();
	SDL_Event e;
	const Uint8 *state = SDL_GetKeyboardState(NULL);

	while (SDL_PollEvent(&e) != 0)
	{
		if (start == 0 && menu == true)
		{
			switch (e.type) {
				//Keyboard event
			case SDL_KEYDOWN:
				start = 1;
				Dispatch(EventListener::Event::START);
				break;
			}

		}
		if (start == 1) {
			switch (e.type) {
				// Keyboard event
				//KEYDOWN means if you press a key
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym) {
				case SDLK_SPACE:
					Dispatch(EventListener::Event::JUMP);
					break;
				case SDLK_r:
					Dispatch(EventListener::Event::REVERSE);
					break;
				case SDLK_ESCAPE:
					Dispatch(EventListener::Event::QUIT);
					break;
				case SDLK_a:
					Dispatch(EventListener::Event::LEFT);
					break;
				case SDLK_d:
					Dispatch(EventListener::Event::RIGHT);
					break;
				case SDLK_i:
					Dispatch(EventListener::Event::RECORD);
					break;
				}
				break;

				//KEYUP means if you release a key
			case SDL_KEYUP:
				switch (e.key.keysym.sym) {
				case SDLK_a:
					Dispatch(EventListener::Event::STOP);
					break;
				case SDLK_d:
					Dispatch(EventListener::Event::STOP);
					break;
				case SDLK_SPACE:
					Dispatch(EventListener::Event::SUPERJUMP);
					break;
				}

				break;
				// SDL_QUIT event (window close)
			case SDL_QUIT:
				Dispatch(EventListener::Event::QUIT);
				break;
			default:
				break;
			}

		}
		if (start == 2)
		{
			if (e.type == SDL_KEYUP)
			{
				keyPressed = false;
			}
			if (keyPressed == false)
			{
				switch (e.type) {
					/* Keyboard event */
				case SDL_KEYDOWN:
					if (e.key.keysym.sym == SDLK_q) {
						Dispatch(EventListener::Event::QUIT);
						break;
					}
				}
			}
		}
	}
}
std::vector<EventListener::Event> InputManager::getEventList()
{
	return events;
}