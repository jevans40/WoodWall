#pragma once

namespace OP {
	class ivec3 {
	public:
		int x;
		int y;
		int z;


		/**
		 * @fn	ivec3::ivec3(int x = 0, int y = 0, int z = 0);
		 *
		 * @brief	Constructor
		 *
		 * @param	x	(Optional) The x coordinate.
		 * @param	y	(Optional) The y coordinate.
		 * @param	z	(Optional) The z coordinate.
		 */

		ivec3(int x = 0, int y = 0, int z = 0);

		/**
		 * @fn	ivec3& ivec3::operator=(const ivec3& other);
		 *
		 * @brief	Assignment operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	A shallow copy of this object.
		 */

		ivec3& operator=(const ivec3& other);

		/**
		 * @fn	ivec3& ivec3::operator+=(const ivec3& other);
		 *
		 * @brief	Addition assignment operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	The result of the operation.
		 */

		ivec3& operator+=(const ivec3& other);

		/**
		 * @fn	ivec3& ivec3::operator-=(const ivec3& other);
		 *
		 * @brief	Subtraction assignment operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	The result of the operation.
		 */

		ivec3& operator-=(const ivec3& other);

		/**
		 * @fn	bool ivec3::operator==(const ivec3& other);
		 *
		 * @brief	Equality operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	True if the parameters are considered equivalent.
		 */

		bool operator==(const ivec3& other);

		/**
		 * @fn	bool ivec3::operator!=(const ivec3& other);
		 *
		 * @brief	Inequality operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	True if the parameters are not considered equivalent.
		 */

		bool operator!=(const ivec3& other);

		/**
		 * @fn	int ivec3::dotProduct(const ivec3& other);
		 *
		 * @brief	Dot product
		 *
		 * @param	other	The other.
		 *
		 * @returns	An int.
		 */

		int dotProduct(const ivec3& other);
	};
}