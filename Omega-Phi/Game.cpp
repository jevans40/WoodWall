#include "Game.h"
#include "ImageLoader.h"
#include "SimpleSprite.h"
#include <chrono>
#include <cstdint>
#include <cassert>




OP::Game::Game(const char* gameName, int x, int y, const char * gameDir) : l_Window(new Window(gameName, x, y)), l_Renderer(l_Window)
{

	l_SpriteAtlas.push_back(new ImageAtlas((std::string(gameDir) + "res/Images").c_str(), 0, this));
	glfwSwapInterval(0);

}

OP::Game::~Game()
{
	l_Layers.clear();
	l_Layers.shrink_to_fit();
	l_Window->~Window();
	glfwTerminate();
}

void OP::Game::Start()
{
	float targetFPS = 6000;
	int time = 1;
	float timeSinceLastFrame = 0;
	float timeSinceLastUpdate = 0;
	long long last = 0;
	int num = 0;
	while (l_Window->isRunning()) {

		auto duration = std::chrono::system_clock::now();
		auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration.time_since_epoch()).count();
		timeSinceLastFrame = (millis - last);
		timeSinceLastUpdate = (millis - last);
		if (timeSinceLastFrame/1000 > (1 / targetFPS)) {
			Render();
			std::cout << "FPS = " << 1 / (timeSinceLastFrame/1000) << std::endl;
			//std::cout << "Sprites = " << num << std::endl;
			last = millis;
			//l_Layers[0]->AddRenderable(*new OP::SimpleSprite(this, { float(num) / 100000 * 1280 ,(1 / float(timeSinceLastFrame / 1000)) / (300) * 720,1 }, { 10,10 }, 0xffffffff));
			timeSinceLastFrame = 0;
			num++;
		}
		Update(time);
		//Tick
		time++;

	}
}

void OP::Game::Init()
{
	//~~~To be implemented by child class
}

void OP::Game::AddLayer(Layer &newLayer)
{
	l_Renderer.addLayer(&newLayer);
	l_Layers.push_back(&newLayer);
	//Add multiple layers later
	UpdateAtlas();
}

void OP::Game::UpdateAtlas()
{
	for (int i = 0; i < l_SpriteAtlas.size(); i++) {
		SimpleSprite::addSprite(l_SpriteAtlas[i]->getSpriteMap());
		for (int k = 0; k < l_Layers.size(); k++) {
			l_Layers[k]->AddTexture(l_SpriteAtlas[i]->getImage(), l_SpriteAtlas[i]->getImageMap());
			
		}
	}
}

void OP::Game::getSprite(const char* spriteName)
{
	SpriteLoc * sprite;
	for (int i = 0;i < l_SpriteAtlas.size(); i++ ) {
		sprite = l_SpriteAtlas[i]->getSprite(spriteName);
	}
}


void OP::Game::Render()
{
	//Ready the layers for Rendering
	for (int i = 0; i < l_Layers.size(); i++) {
		l_Layers[i]->Render();
	}

	//Render the layers	
	l_Renderer.commitRender();

	/* Swap front and back buffers */
	glfwSwapBuffers(l_Window->getWindow());



}

void OP::Game::Update(int time)
{
	glfwPollEvents();


}


void* OP::Game::HandleEvent(OP::OPEvent * event) {
	if (event->getName() == "updateAtlas") {
		UpdateAtlas();
		return nullptr;
	}
	if (event->getName() == "outOfAtlasSpace") {
		std::cout << "ERROR OUT OF ATLAS SPACE!" << std::endl;
	}
	if (event->getName() == "getSprite") {
		//return getSprite(event->getMessage());
	}
}