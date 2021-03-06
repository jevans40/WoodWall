#pragma once
#include "Layer.h"
#include "Window.h"
#include "Renderer.h"
#include "EventListener.h"
namespace OP{

	class Game : public EventListner {
	protected:
		std::vector<Layer*> l_Layers;
		Window* l_Window;
		Renderer l_Renderer;
		std::vector<ImageAtlas*> l_SpriteAtlas;//(ImageAtlas*) malloc(GL_MAX_TEXTURE_UNITS * sizeof(ImageAtlas));
		
		std::chrono::milliseconds::rep timeSinceLastTick;
		std::chrono::milliseconds::rep timeSinceLastFrame;

		std::chrono::milliseconds::rep targetTickRate;
		std::chrono::milliseconds::rep targetFrameRate;



		OP::ivec2 l_size;

	public:

		/**
		 * @fn	Game::Game(const char* gameName = "GameName", int x = 0, int y = 0);
		 *
		 * @brief	Default constructor
		 *
		 * @param	gameName	(Optional) Name of the game.
		 * @param	x			(Optional) The x coordinate.
		 * @param	y			(Optional) The y coordinate.
		 */

		Game( const char* gameName = "GameName", int x = 0, int y = 0, const char* gamedir = "./../");

		/**
		 * @fn	Game::~Game();
		 *
		 * 
		 * @brief	Destructor
		 */

		~Game();

		/**
		 * @fn	void Game::Start();
		 *
		 * @brief	Starts The Game
		 * 			
		 */

		void Start();

		/**
		 * @fn	void Game::Init();
		 *
		 * @brief	Initializes the Window and other Game related things
		 */

		virtual void Init();

		/**
		 * @fn	void Game::AddLayer(Layer newLayer);
		 * 		
		 *
		 * @brief	Adds a layer
		 *
		 * @param	newLayer	The new layer.
		 */

		void AddLayer(Layer &newLayer);

		/**
		 * @fn	void Game::UpdateAtlas();
		 *
		 * @brief	Updates the SpriteImages and Layer Textures from the Atlas
		 */

		void UpdateAtlas();

		/**
		/* DEPRICATED
		 * @fn	void Game::getSprite(const char* spriteName);
		 *
		 * @brief	Gets a sprite
		 *
		 * @param	spriteName	Name of the sprite.
		 * DEPRICATED
		 */

		void getSprite(const char* spriteName);

		/**
		 * @fn	void Game::RemoveLayer(char* layerName);
		 *
		 * @brief	Removes the first layer described by layerName
		 *
		 * @param [in,out]	layerName	If non-null, name of the layer.
		 */

		void RemoveLayer(char* layerName);

		/**
		 * @fn	void Game::Render();
		 *
		 * @brief	Renders the layers
		 */

		void Render();

		/**
		 * @fn	void Game::Update(int time);
		 *
		 * @brief	Updates with a given time
		 *
		 * @param	time	The time in ms.
		 */

		void Update(std::chrono::milliseconds time);
			

		bool getKey(char key);

		OP::ivec2 getSize();

		int getHeight();
		
		int getWidth();


		virtual void gameTick() = 0;

		virtual void gameUpdate() = 0;

		virtual void gameRender() = 0;

		virtual void* OP::EventListner::HandleEvent(OP::OPEvent * event); \

		fvec2 getWindowSize();
	
	};





}