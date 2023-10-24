#include "Entity.hpp"

namespace engine
{
	namespace gameplay
	{
		void Entity::Update()
		{
			Actor::Update();
		}

		Entity::Entity() :
			physics(Engine::getInstance().getPhysics()),
			gameplay(Engine::getInstance().getGameplay()),
			input(Engine::getInstance().getInput()),
			graphics(Engine::getInstance().getGraphics())
		{
		}

		const sf::Vector2f & Entity::getPosition() const
		{
			return _position;
		}

		void Entity::setPosition(const sf::Vector2f &newPosition)
		{
			_position = newPosition;
			updateTransform();
		}

		float Entity::getRotation() const
		{
			return _rotation;
		}

		void Entity::setRotation(float newRotation)
		{
			_rotation = newRotation;
			updateTransform();
		}

		const sf::Transform & Entity::getTransform() const
		{
			return _transform;
		}

		void Entity::updateTransform()
		{
			_transform = sf::Transform::Identity;
			_transform.translate(_position);
			_transform.rotate(_rotation);
		}
	}
}
