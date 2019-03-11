#include <iostream>

#include "Game.h"







//Try to keep as few lines in here as possible
int main() {

	OP::Game* testGame = new OP::Game("Test Game", 600,480 );



	testGame->Start();
	


	return 0;
}