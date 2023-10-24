#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "WindowManager.h"

namespace engine
{
	namespace graphics
	{
		class ShapeList;

		class Manager
		{
		public:
			Manager();
			~Manager();

			void clear();
			void draw(const ShapeList& shapeList, const sf::Transform& transform);
			void display();

			bool hasFocus() const;

			sf::RenderWindow& getWindow() { return windowManager->getWindow(); }
			sf::View* getView() { return &view; }
			void setView(const sf::View& viewToSet);

			sf::Vector2f getWindowEdges() { return windowManager->getEdges(); }


		private:
			sf::View view;
			WindowManager* windowManager;
		};
	}
}