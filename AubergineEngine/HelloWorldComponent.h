#pragma once
#include <iostream>
#include "Component.h"
#include "Event.h"
namespace AubergineEngine
{
	class HelloWorldComponent : public Component
	{
	public:
		HelloWorldComponent(GameObject* owner);
		~HelloWorldComponent();

		void OnUpdate(const Events::LogicUpdate* event);
	};
}