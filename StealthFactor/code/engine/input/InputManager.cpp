#include "engine/input/InputManager.hpp"

#include <iterator>
#include <engine/graphics/GraphicsManager.hpp>
#include "engine/Engine.hpp"

namespace engine
{
	namespace input
	{

		bool Manager::isKeyPressed(sf::Keyboard::Key key) const
		{
			if (!Engine::getInstance().getGraphics().hasFocus())
				return false;

			return sf::Keyboard::isKeyPressed(key);
		}

		bool Manager::isKeyJustPressed(sf::Keyboard::Key key) const
		{
			if (!Engine::getInstance().getGraphics().hasFocus())
				return false;

			return justPressedKeys.find(key) != std::end(justPressedKeys);
		}

		bool Manager::isKeyJustReleased(sf::Keyboard::Key key) const
		{
			if (!Engine::getInstance().getGraphics().hasFocus())
				return false;

			return justReleasedKeys.find(key) != std::end(justReleasedKeys);
		}

		void Manager::clear()
		{
			justPressedKeys.clear();
			justReleasedKeys.clear();
		}

		void Manager::onKeyPressed(const sf::Event::KeyEvent &event)
		{
			justPressedKeys.insert(event.code);
		}

		void Manager::onKeyReleased(const sf::Event::KeyEvent &event)
		{
			justReleasedKeys.insert(event.code);
		}

		void Manager::update()
		{
			clear();

			sf::Event event;
			while (Engine::getInstance().getGraphics().getWindow().pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					Engine::getInstance().exit();
					break;

				case sf::Event::KeyPressed:
					Engine::getInstance().getInput().onKeyPressed(event.key);
					break;

				case sf::Event::KeyReleased:
					Engine::getInstance().getInput().onKeyReleased(event.key);
					break;

				default:
					break;
				}
			}
		}
	}
}
