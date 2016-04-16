#include "stdafx.h"
#include "Component.h"
namespace AubergineEngine
{
	Component::Component(GameObject * owner) : Owner(owner)
	{
	}

	Component::~Component()
	{
	}
}