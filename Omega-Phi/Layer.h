#pragma once
#include "Window.h"

/**
 * @namespace	OP
 *
 * @brief	The Engine Namespace
 */

namespace OP {

	/**
	 * @class	Layer
	 *
	 * @brief	A layer.
	 */

	class Layer {
	private:
		const char* l_name;
		Window* l_Window;
		short l_Priority;
		//TODO: Add Shaders
		//TODO: Add Renderable Vector

	public:

		/**
		 * @fn	Layer::Layer(Window* window,const char* name = "Default Name", int priority = 0);
		 *
		 * @brief	Constructor
		 *
		 * @param [in,out]	window  	The window this layer will be on.
		 * @param 		  	name		(Optional) The name.
		 * @param 		  	priority	(Optional) The priority.
		 */

		Layer(Window* window, const char* name, int priority);

		/**
		 * @fn	void Layer::update(int time);
		 *
		 * @brief	Update all sprites associated with this layer
		 *
		 * @param	time	The time in ms.
		 */

		void Update(int time);

		/**
		 * @fn	void Layer::Render();
		 *
		 * @brief	Renders the sprites in this layer
		 */

		void Render();

		/**
		 * @fn	void Layer::AddRenderable();
		 *
		 * @brief	Adds a renderable
		 */

		void AddRenderable();


	};

}