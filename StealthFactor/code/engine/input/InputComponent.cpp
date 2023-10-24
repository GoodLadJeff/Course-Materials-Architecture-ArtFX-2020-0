#include "InputComponent.h"
#include <engine/Engine.hpp>

InputComponent::InputComponent(Actor* actor) : Component(actor)
{
}

bool InputComponent::isKeyJustPressed(sf::Keyboard::Key key) const
{
	if (!engine::Engine::getInstance().getGraphics().hasFocus())
		return false;
	
	return engine::Engine::getInstance().getInput().getJustPressedKeys()->find(key) 
		!= std::end(*engine::Engine::getInstance().getInput().getJustPressedKeys());
}
