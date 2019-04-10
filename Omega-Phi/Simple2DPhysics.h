#pragma once
#include "SimpleBoundingBox.h"
#include "CollisionGrid.h"
#include <vector>
#include <chrono>


namespace OP {

	class Simple2DPhysics : public SimpleBoundingBox {

		private:
			static CollisionGrid CollisionDetector;
			static std::vector<SimpleBoundingBox *> possibleCollisions;

			std::vector<SimpleBoundingBox *> Collisions;

			OP::fvec2  Velocity;
			OP::fvec2 Size;
			OP::fvec2 SubPixel;

			std::string l_Name;
			std::chrono::milliseconds::rep lastTime;
			
			

			bool incorpreal;

		public:
			bool Collision;

			~Simple2DPhysics() {
				CollisionDetector.RemoveBox(this);
				std::cout << "Simple2DPhysicsDestroyed" << std::endl;
			};

			Simple2DPhysics(fvec2 Pos, ivec2 size, std::string name = "") : SimpleBoundingBox(ivec2{ int(Pos.x), int(Pos.y) }, ivec2{ int(Pos.x) + int(size.x),int(Pos.y) + int(size.y) }, 1) {
				Velocity = { 0,0 };
				l_Name = name;
				SubPixel = { Pos.x,Pos.y };
				Size = { float(size.x),float(size.y) };
				CollisionDetector.InsertBox(this);


				bool Collision;

				bool incorporeal;

			}

			void setVelocity(fvec2 newVelocity);

			fvec2 getVelocity();

			void removeCollision(Simple2DPhysics * collision);

			void addCollision(Simple2DPhysics * collision);

			bool isIncorpreal();

			void setIncorpreal(bool);

			ivec2 getMovement(std::chrono::milliseconds Time);


			bool CollidesWith(Simple2DPhysics * collision);

			Simple2DPhysics * getFirstCollision();

			fvec2 getSubPixel();

			void setSubPixel(ivec2 newPosition);

			virtual void onCollision(Simple2DPhysics * left) = 0;

			std::string getBoxes() {
				return CollisionDetector.getBoxes(this);
			}
			
			// Access the Name
			const std::string GetName(void) const	{ return l_Name;	}
			void SetName(const std::string name)	{ l_Name = name;	}
	};



}