#include "stdafx.h"
#include "HelloWorldComponent.h"

HelloWorldComponent::HelloWorldComponent(GameObject * owner) : Component(owner)
{
	//Subscribe to the Update event
	//When the update event is called, call the OnUpdate function on this
	Owner->SubscribeEvent<UpdateEvent>(this, &HelloWorldComponent::OnUpdate);
}

HelloWorldComponent::~HelloWorldComponent()
{
}

void HelloWorldComponent::OnUpdate(const UpdateEvent * event)
{
	std::cout << "Hello, Aubergine" << std::endl;
}
