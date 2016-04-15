#pragma once
#include "Event.h"

class UpdateEvent : public Event
{
public:
	UpdateEvent(double frameTime, double timeScale = 1);
	~UpdateEvent();

	//CONST THINGS BECAUSE DO NOT EDIT THE EVENT DAMMIT
	const double DeltaTime;
	const double TimeScale;
};