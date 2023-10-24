#include "engine/Engine.hpp"

#include <cassert>
#include <iostream>
#include <sstream>
#include <pugixml/pugixml.hpp>
#include <SFML/System.hpp>

namespace engine
{
	Engine *Engine::instance = nullptr;

	void Engine::loadConfiguration()
	{
		pugi::xml_document doc;
		pugi::xml_parse_result result = doc.load_file("configuration.xml");

		if (result)
		{
			assert(!doc.empty());
			auto configuration = doc.first_child();
			startMap = configuration.child_value("start_map");
		}
		else
		{
			std::cerr << "Configuration parsed with errors." << std::endl;
			std::cerr << "Error description: " << result.description() << std::endl;
			std::cerr << "Error offset: " << result.offset << std::endl;
		}

		physics = std::make_unique<physics::Manager>();
		gameplay = std::make_unique<gameplay::Manager>();
		graphics = std::make_unique<graphics::Manager>();
		input = std::make_unique<input::Manager>();

	}

	void Engine::run()
	{
		running = true;

		gameplay->loadMap(startMap);

		sf::Clock clock;
		while (running)
		{
			deltaTime = clock.restart().asSeconds();

			physics->update();
			gameplay->update();
			input->update();

			graphics->clear();

			gameplay->draw();

			graphics->display();
		}
	}

	float Engine::getDeltaTime() const
	{
		return deltaTime;
	}

	void Engine::exit()
	{
		running = false;
	}

	Engine &Engine::getInstance()
	{
		if (!instance)
			instance = new Engine();

		return *instance;
	}
}
