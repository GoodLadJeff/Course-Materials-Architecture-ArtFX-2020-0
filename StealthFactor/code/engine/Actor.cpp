#include "Actor.h"

Actor::Actor()
{

}

void Actor::AddComponent(Component* componentToAdd)
{
	components.push_back(componentToAdd);
}

void Actor::RemoveComponent(Component* componentToRemove)
{
	auto iter = std::find(begin(components), end(components), componentToRemove);
	if (iter != end(components))
	{
		components.erase(iter);
	}
}

void Actor::Update()
{
	std::cout << "ceci est l'update de l'actor" << std::endl;
}

void Actor::UpdateComponents()
{
	for (auto var : components)
	{
		var->Update();
	}
}