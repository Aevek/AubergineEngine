#pragma once
#include <iostream>
#include "Component.h"

class UpdateEvent;

class HelloWorldComponent : public Component
{
public:
	HelloWorldComponent(GameObject* owner);
	~HelloWorldComponent();

	void OnUpdate(const UpdateEvent* event);
};