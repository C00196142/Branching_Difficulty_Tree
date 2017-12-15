#include <iostream>
using namespace std;
#include "Game.h"
//"Thomas is NOT Alone (Except for the first 2 levels in which he is in fact Alone)"

//Create and initialises an instance of game, and clean up when the game is closed

int main()
{
	Game game;

	cout << "Initialising Game" << endl;

	if (!game.init()) {
		cout << "Failed to init game" << '\n';
	}

	//run the game loop
	game.loop();

	game.destroy();

	return 0;
}