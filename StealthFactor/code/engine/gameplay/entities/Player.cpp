#include "engine/gameplay/entities/Player.hpp"

#include <ode/collision.h>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/gameplay/entities/Target.hpp>
#include <engine/physics/PhysicsManager.hpp>
#include <engine/Engine.hpp>


namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			Player::Player() : Character()
			{
				shapeList.load("player");

				collisionGeomId = dCreateBox(getPhysics().getSpaceId(), gameplay::Manager::CELL_SIZE * 0.9f, gameplay::Manager::CELL_SIZE * 0.9f, 1.f);
				dGeomSetData(collisionGeomId, this);

				inputComponent = new InputComponent(this);
			}

			void Player::Update()
			{
				Character::Update();

				justMoved = false;
				auto position = getPosition();
				float rotation = getRotation();

				if (inputComponent->isKeyJustPressed(sf::Keyboard::Left))
				{
					justMoved = true;
					position.x -= gameplay::Manager::CELL_SIZE;
					rotation = 180.f;
				}

				if (inputComponent->isKeyJustPressed(sf::Keyboard::Right))
				{
					justMoved = true;
					position.x += gameplay::Manager::CELL_SIZE;
					rotation = 0.f;
				}

				if (inputComponent->isKeyJustPressed(sf::Keyboard::Up))
				{
					justMoved = true;
					position.y -= gameplay::Manager::CELL_SIZE;
					rotation = -90.f;
				}

				if (inputComponent->isKeyJustPressed(sf::Keyboard::Down))
				{
					justMoved = true;
					position.y += gameplay::Manager::CELL_SIZE;
					rotation = 90.f;
				}

				if (justMoved)
				{
					setPosition(position);
					setRotation(rotation);

					dGeomSetPosition(collisionGeomId, position.x, position.y, 0);
				}

				auto collisions = getPhysics().getCollisionsWith(collisionGeomId);
				for (auto &geomId : collisions)
				{
					auto entity = reinterpret_cast<Entity *>(dGeomGetData(geomId));
					auto targetEntity = dynamic_cast<entities::Target *>(entity);
					if (targetEntity)
					{
						getGameplay().loadNextMap();
					}
				}
			}

			bool Player::hasJustMoved() const
			{
				return justMoved;
			}
		}
	}
}
