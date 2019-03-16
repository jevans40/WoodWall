#include <iostream>

#include "Game.h"
#include "Shader.h"






//Try to keep as few lines in here as possible
int main() {
	//RUN THIS FIRST YOU SHITWARD
	OP::Game* testGame = new OP::Game("Test Game", 600,480 );

	
	OP::Shader* testShader = new OP::Shader("VertexShader.vert","FragShader.frag");




	testGame->Start();
	


	return 0;
}