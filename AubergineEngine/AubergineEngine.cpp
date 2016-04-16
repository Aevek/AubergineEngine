// AubergineEngine.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "HelloWorldComponent.h"
#include "EventListener.h"

using namespace AubergineEngine;


int main()
{
	GameObject space("Space");

	GameObject steve("Steve");
	GameObject dave("Dave");

	GameObject greg("Greg");
	GameObject albert("Albert");
	
	GameObject georgia("Georgia");

	Events::LogicUpdate update(0.5, 1.5);


	steve.AddComponent<HelloWorldComponent>();
	dave.AddComponent<HelloWorldComponent>();
	greg.AddComponent<HelloWorldComponent>();
	albert.AddComponent<HelloWorldComponent>();
	georgia.AddComponent<HelloWorldComponent>();

	space.AddChild(&steve);
	space.AddChild(&dave);

	steve.AddChild(&greg);
	
	greg.AddChild(&albert);

	albert.AddChild(&georgia);

	space.SendEventDown(&update);

	while (true);

	return 0;
}

