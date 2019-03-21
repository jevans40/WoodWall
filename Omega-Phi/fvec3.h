#pragma once

namespace OP {
	class fvec3 {
	public:
		float x;
		float y;
		float z;

		/**
		 * @fn	fvec3::fvec3(float x = 0, float y = 0, float z = 0);
		 *
		 * @brief	Constructor
		 *
		 * @param	x	(Optional) The x coordinate.
		 * @param	y	(Optional) The y coordinate.
		 * @param	z	(Optional) The z coordinate.
		 */

		fvec3(float x = 0, float y = 0, float z = 0);

		/**
		 * @fn	fvec3& fvec3::operator=(const fvec3& other);
		 *
		 * @brief	Assignment operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	A shallow copy of this object.
		 */

		fvec3& operator=(const fvec3& other);

		/**
		 * @fn	fvec3& fvec3::operator+=(const fvec3& other);
		 *
		 * @brief	Addition assignment operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	The result of the operation.
		 */

		fvec3& operator+=(const fvec3& other);

		/**
		 * @fn	fvec3& fvec3::operator-=(const fvec3& other);
		 *
		 * @brief	Subtraction assignment operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	The result of the operation.
		 */

		fvec3& operator-=(const fvec3& other);

		/**
		 * @fn	bool fvec3::operator==(const fvec3& other);
		 *
		 * @brief	Equality operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	True if the parameters are considered equivalent.
		 */

		bool operator==(const fvec3& other);

		/**
		 * @fn	bool fvec3::operator!=(const fvec3& other);
		 *
		 * @brief	Inequality operator
		 *
		 * @param	other	The other.
		 *
		 * @returns	True if the parameters are not considered equivalent.
		 */

		bool operator!=(const fvec3& other);

		/**
		 * @fn	float fvec3::dotProduct(const fvec3& other);
		 *
		 * @brief	Dot product
		 *
		 * @param	other	The other.
		 *
		 * @returns	An int.
		 */

		float dotProduct(const fvec3& other);
	};
}