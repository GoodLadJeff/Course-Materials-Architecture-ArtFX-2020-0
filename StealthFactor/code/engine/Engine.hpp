#pragma once

#include <string>
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/graphics/GraphicsManager.hpp>
#include <engine/physics/PhysicsManager.hpp>
#include <engine/input/InputManager.hpp>

namespace engine
{
	class Engine
	{
	public:
		void loadConfiguration();

		void run();
		float getDeltaTime() const;

		void exit();



		static Engine &getInstance();
		physics::Manager& getPhysics() { return *physics; }
		gameplay::Manager& getGameplay() { return *gameplay; }
		input::Manager& getInput() { return *input; }
		graphics::Manager& getGraphics() { return *graphics; }

	private:
		std::unique_ptr<physics::Manager> physics;
		std::unique_ptr<gameplay::Manager> gameplay;
		std::unique_ptr<input::Manager> input;
		std::unique_ptr<graphics::Manager> graphics;

		bool running;
		float deltaTime;

		// Configuration
		std::string startMap;

		static Engine *instance;
	};
}
