#include "stdafx.h"
#include "HelloWorldComponent.h"
namespace AubergineEngine
{
	HelloWorldComponent::HelloWorldComponent(GameObject * owner) : Component(owner)
	{
		//Subscribe to the Update event
		//When the update event is called, call the OnUpdate function on this
		Owner->SubscribeEvent<Events::LogicUpdate>(this, &HelloWorldComponent::OnUpdate);
	}

	HelloWorldComponent::~HelloWorldComponent()
	{
	}

	void AubergineEngine::HelloWorldComponent::OnUpdate(const Events::LogicUpdate * event)
	{
		std::cout << "Hello, Aubergine. My name is " << Owner->Name << std::endl;
		std::cout << "Delta time is " << event->DeltaTime << " time scale is " << event->TimeScale << std::endl;
	}
}