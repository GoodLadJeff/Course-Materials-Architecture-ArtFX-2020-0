#pragma once



class Actor;
class Component
{
public:
	Component(Actor* actor);
	Component() = delete;
	Component(const Component&) = delete;
	Component& operator=(const Component&) = delete;
	void Update();

protected:
	Actor& owner;
};