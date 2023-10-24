#pragma once
#include "Component.h"
#include <vector>
#include <iostream>

using namespace std;

class Actor
{
protected:
	vector<Component*> components;

	void AddComponent(Component* componentToAdd);
	void RemoveComponent(Component* componentToRemove);

public:
	Actor();
	virtual void Update();
	void UpdateComponents();
};