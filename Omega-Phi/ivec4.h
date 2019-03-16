#pragma once

namespace OP {
	class ivec4 {
	public:
		int x;
		int y;
		int z;
		int w;



		/**
		 * @fn	ivec4::ivec4(int x = 0, int y = 0, int z = 0, int w = 0);
		 *
		 * @brief	Constructor
		 *
		 * @param	x	(Optional) The x coordinate.
		 * @param	y	(Optional) The y coordinate.
		 * @param	z	(Optional) The z coordinate.
		 * @param	w	(Optional) The w coordinate.
		 */

		ivec4(int x = 0, int y = 0, int z = 0, int w = 0);

		/**
		 * @fn	ivec4& ivec4::operator=(const ivec4& other);
		 *
		 * @brief	Assignment operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	A shallow copy of this object.
		 */

		ivec4& operator=(const ivec4& other);

		/**
		 * @fn	ivec4& ivec4::operator+=(const ivec4& other);
		 *
		 * @brief	Addition assignment operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	The result of the operation.
		 */

		ivec4& operator+=(const ivec4& other);

		/**
		 * @fn	ivec4& ivec4::operator-=(const ivec4& other);
		 *
		 * @brief	Subtraction assignment operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	The result of the operation.
		 */

		ivec4& operator-=(const ivec4& other);

		/**
		 * @fn	bool ivec4::operator==(const ivec4& other);
		 *
		 * @brief	Equality operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	True if the parameters are considered equivalent.
		 */

		bool operator==(const ivec4& other);

		/**
		 * @fn	bool ivec4::operator!=(const ivec4& other);
		 *
		 * @brief	Inequality operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	True if the parameters are not considered equivalent.
		 */

		bool operator!=(const ivec4& other);

		/**
		 * @fn	int ivec4::dotProduct(const ivec4& other);
		 *
		 * @brief	Dot product
		 *
		 * @param	other	The other.
		 *
		 * @returns	An int.
		 */

		int dotProduct(const ivec4& other);
	};
}