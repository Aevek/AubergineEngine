#pragma once

class GameObject;

class Event
{
public:
	Event(GameObject* sender);
	virtual ~Event();

	//Object that sent this event
	GameObject * const Sender;
};