#include "WindowManager.h"


WindowManager::WindowManager()
{
	window.create(sf::VideoMode{ (unsigned int)WINDOW_WIDTH, (unsigned int)WINDOW_HEIGHT }, "Stealth Factor");
	window.setVerticalSyncEnabled(true);

	view = sf::View(sf::Vector2f{ 0.f, 0.f }, sf::Vector2f{ (float)WINDOW_WIDTH, (float)WINDOW_HEIGHT });
	window.setView(view);
}

WindowManager::~WindowManager()
{
	window.close();
}

bool WindowManager::hasFocus()
{
	return window.hasFocus();
}