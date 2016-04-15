#include "stdafx.h"
#include "UpdateEvent.h"

UpdateEvent::UpdateEvent(double frameTime, double timeScale) : Event(nullptr), DeltaTime(frameTime), TimeScale(timeScale)
{
}

UpdateEvent::~UpdateEvent()
{
}
