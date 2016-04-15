#include "stdafx.h"
#include "GameObject.h"

unsigned long GameObject::InstanceCount = 0;

GameObject::GameObject() : id(InstanceCount++)
{
}

GameObject::~GameObject()
{
}
