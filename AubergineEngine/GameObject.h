#pragma once
#include <vector>
#include "EventListener.h"

class Component;

class GameObject
{
public:
	GameObject();
	~GameObject();

	//Get a component on this object of a given type, returns nullptr if not found
	template <typename T>
	T* GetComponent() const;

	//Add a component of type T to the object
	//If one exists already returns a pointer to that
	//Otherwise adds one, then returns a pointer to it
	template <typename T>
	T* AddComponent();

	//Links a specific function to 
	template <typename T, typename S>
	void SubscribeEvent(S * comp, void(S::*onEvent)(const T *));

private:
	static unsigned long InstanceCount;
	unsigned long id;

	std::vector<Component*> components_;
};

template<typename T>
inline T * GameObject::GetComponent() const
{
	for (Component* component : components_)
	{
		if (T* match = dynamic_cast<T*>(component))
			return match;
	}
	return NULL;
}

template<typename T>
inline T * GameObject::AddComponent()
{
	if (T* found = GetComponent<T>())
	{
		return found;
	}
	else
	{
		T* newComp = new T(this);
		components_.push_back(newComp);
		return newComp;
	}
}

template<typename T, typename S>
inline void GameObject::SubscribeEvent(S * comp, void(S::*onEvent)(const T *))
{
	EventListener<T>* evls = AddComponent<EventListener<T>>();
	evls->SubscribeEvent(comp, onEvent);
}
