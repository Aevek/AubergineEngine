#include "stdafx.h"
#include "Component.h"

Component::Component(GameObject * owner) : Owner(owner)
{
}

Component::~Component()
{
}
