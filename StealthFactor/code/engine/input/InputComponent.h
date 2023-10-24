#pragma once
#include "engine/Component.h"
#include <SFML/Window/Keyboard.hpp>

class InputComponent : public Component
{
public:
	InputComponent(Actor* actor);
	bool isKeyJustPressed(sf::Keyboard::Key key) const;
};

