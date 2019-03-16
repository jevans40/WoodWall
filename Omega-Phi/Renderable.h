#pragma once
#include "OPMath.h"
namespace OP {
#pragma pack(push, 0)

	struct Vertex {
		fvec3 pos = fvec3(0,0,0);
		fvec2 texPos = fvec2(0,0);
		unsigned int color = 0;
		int texMap = 0;

		Vertex() {};
	};

#pragma pack(pop)

	class Renderable {
	private:
		
		Vertex VertData[4];
		fvec2 Size;
		fvec3 Pos;
		fvec2 TexPos;
		unsigned int Color;
		int TexMap;


	protected:
		/**
		 * @fn	void Renderable::setTexx(float Texx);
		 *
		 * @brief	Sets a texx
		 *
		 * @param	Texx	The x texture.
		 */

		void setTexx(float Texx);

		/**
		 * @fn	void Renderable::setTexy(float Texy);
		 *
		 * @brief	Sets a texy
		 *
		 * @param	Texy	The y texture.
		 */

		void setTexy(float Texy);

		/**
		 * @fn	void Renderable::setTexMap(int TexMap);
		 *
		 * @brief	Sets tex map
		 *
		 * @param	TexMap	The tex map.
		 */

		void setTexMap(int TexMap);

		/**
		 * @fn	Renderable::Renderable();
		 *
		 * @brief	Default constructor
		 */
	private:

		Renderable();

		/**
		 * @fn	Renderable::Renderable(float x = 0, float y = 0, float z = 0, unsigned int Color = 0xffffffff, float Texx = 0, float Texy = 0, int TexMap = -1);
		 *
		 * @brief	Constructor
		 *
		 * @param	x	  	(Optional) The x coordinate based off of top left.
		 * @param	y	  	(Optional) The y coordinate based off of top left.
		 * @param	z	  	(Optional) The z coordinate based off of top left.
		 * @param	Color 	(Optional) The color.
		 * @param	Texx  	(Optional) The texture x coordinate.
		 * @param	Texy  	(Optional) The texture y coordinate.
		 * @param	TexMap	(Optional) The texture map.
		 */

		Renderable(fvec3 pos = fvec3(0, 0, 0), fvec2 size = fvec2(1,1), unsigned int Color = 0xffffffff, fvec2 TexPos = fvec2(0,0), int TexMap = -1);

		/**
		 * @fn	void Renderable::setXPos(float x);
		 *
		 * @brief	Sets x coordinate position based off of top left
		 *
		 * @param	x	The x coordinate.
		 * 				
		 */

		void setXPos(float x);

		/**
		 * @fn	void Renderable::setYPos(float y);
		 *
		 * @brief	Sets y coordinate position
		 *
		 * @param	y	The y coordinate.
		 */

		void setYPos(float y);

		/**
		 * @fn	void Renderable::setZPos(float z);
		 *
		 * @brief	Sets z coordinate position
		 *
		 * @param	z	The z coordinate.
		 */

		void setZPos(float z);

		/**
		 * @fn	void Renderable::setColor(unsigned int Color);
		 *
		 * @brief	Sets a color
		 *
		 * @param	Color	The color.
		 */

		void setColor(unsigned int Color);

		/**
		 * @fn	void Renderable::setSize();
		 *
		 * @brief	Sets the size
		 */

		void setSize(fvec2 size = fvec2(1,1));


		float getXPos();
		float getYPos();
		float getZPos();

	};
}