#include "engine/graphics/GraphicsManager.hpp"

#include <cassert>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Window/Event.hpp>
#include <engine/graphics/ShapeList.hpp>
#include <engine/gameplay/GameplayManager.hpp>

namespace engine
{
	namespace graphics
	{


		Manager::Manager() :
			windowManager(new WindowManager())
		{
		}

		Manager::~Manager()
		{
			delete windowManager;
		}

		void Manager::clear()
		{
			sf::RenderWindow& window = windowManager->getWindow();
			window.clear(sf::Color::Black);
			window.setView(windowManager->getView());
		}

		void Manager::draw(const ShapeList& shapeList, const sf::Transform& transform)
		{
			sf::RenderStates renderStates{ transform };
			for (auto shape : shapeList.getShapes())
			{
				windowManager->getWindow().draw(*shape, renderStates);
			}
		}

		void Manager::display()
		{
			windowManager->getWindow().display();
		}

		bool Manager::hasFocus() const
		{
			return windowManager->hasFocus();
		}

		void Manager::setView(const sf::View& viewToSet)
		{
			windowManager->setView(viewToSet);
		}

	}
}
