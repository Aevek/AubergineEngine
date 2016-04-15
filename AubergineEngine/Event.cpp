#include "stdafx.h"
#include "Event.h"

Event::Event(GameObject * sender) : Sender(sender)
{
}

Event::~Event()
{
}
