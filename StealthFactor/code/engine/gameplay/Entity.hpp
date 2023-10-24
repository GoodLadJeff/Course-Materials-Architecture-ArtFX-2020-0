#pragma once

#include <SFML/Graphics/Transform.hpp>
#include "engine/Engine.hpp"
#include "engine/Actor.h"

namespace engine
{
	namespace gameplay
	{
		class Entity : public Actor
		{
		public:

			virtual ~Entity() = default;

			void Update() override;
			virtual void draw() = 0;


			Entity();

			const sf::Vector2f &getPosition() const;
			void setPosition(const sf::Vector2f &newPosition);

			float getRotation() const;
			void setRotation(float newRotation);

			const sf::Transform &getTransform() const;

		private:

			physics::Manager& physics;
			gameplay::Manager& gameplay;
			input::Manager& input;
			graphics::Manager& graphics;
			
			sf::Vector2f _position{};
			float _rotation{ 0.f };
			sf::Transform _transform;

			void updateTransform();

		protected:

			physics::Manager& getPhysics() { return physics; }
			gameplay::Manager& getGameplay() { return gameplay; }
			input::Manager& getInput() { return input; }
			graphics::Manager& getGraphics() { return graphics; }


		};
	}
}
