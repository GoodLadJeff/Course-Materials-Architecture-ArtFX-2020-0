#include "Target.hpp"

#include "engine/Engine.hpp"
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/graphics/GraphicsManager.hpp>
#include <engine/physics/PhysicsManager.hpp>

namespace engine
{
	namespace gameplay
	{
		namespace entities
		{
			Target::Target() :
				Entity()
			{
				shapeList.load("target");

				collisionGeomId = dCreateBox(getPhysics().getSpaceId(), gameplay::Manager::CELL_SIZE * 0.9f, gameplay::Manager::CELL_SIZE * 0.9f, 1.f);
				dGeomSetData(collisionGeomId, this);
			}

			Target::~Target()
			{
				dGeomDestroy(collisionGeomId);
			}

			void Target::Update()
			{
				Entity::Update();
				auto &position = getPosition();
				dGeomSetPosition(collisionGeomId, position.x, position.y, 0);
			}

			void Target::draw()
			{
			Engine::getInstance().getGraphics().draw(shapeList, getTransform());
			}
		}
	}
}
