// AubergineEngine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HelloWorldComponent.h"
#include "EventListener.h"
#include "UpdateEvent.h"

int main()
{
	GameObject steve;
	UpdateEvent update(1.0, 1.0);


	steve.AddComponent<HelloWorldComponent>();

	EventListener<UpdateEvent>::SendGlobalEvent(&update);


    return 0;
}

