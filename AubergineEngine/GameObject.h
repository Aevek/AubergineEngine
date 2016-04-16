#pragma once
#include <vector>
#include <string>
#include "EventListener.h"
#include "Event.h"

namespace AubergineEngine
{
	class Component;

	using namespace Events;

	class GameObject
	{
	public:
		GameObject(std::string name);
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

		//Links a specific function to a specific event
		template <typename T, typename S>
		void SubscribeEvent(S * comp, void(S::*onEvent)(const T *));

		//Sends an event of a given type to a single game object
		template <typename T>
		void SendEvent(const T * event);

		//Sends an event of a given type to a single game object AND all of its children
		template <typename T>
		void SendEventDown(const T * event);

		//Sends an event of a given type to a single game objects children but NOT the object itself
		template <typename T>
		void SendEventDownOnly(const T * event);

		//Add a GameObject as a child of this one
		//This will bring it into the space correctly if that has not already happened
		GameObject* AddChild(GameObject* newChild);

		//Change the parent of a gameobject
		//This will tell both involved parental parties
		void SetParent(GameObject *newParent);

		//Accessor for the parent of a gameObject
		GameObject* GetParent();
		
		//Name of this game object
		std::string Name;
		

	private:
		void RemoveChild(GameObject* child);

		static unsigned long InstanceCount;
		unsigned long id;

		GameObject* owner_;
		GameObject* space_;

		std::vector<Component*> components_;
		std::vector<GameObject*> children_;
	};

	template<typename T>
	inline T * GameObject::GetComponent() const
	{
		if (components_.size() > 0)
		{
			for (Component* component : components_)
			{
				if (T* match = dynamic_cast<T*>(component))
					return match;
			}
		}
		return nullptr;
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
		
		if (owner_ != nullptr)
		{
			EventListener<T>* parentEvls = owner_->AddComponent<EventListener<T>>();
			parentEvls->SubscribeEvent(comp, onEvent);
		}
	}

	template<typename T>
	inline void GameObject::SendEvent(const T * event)
	{
		if (EventListener<T>* listener = GetComponent<EventListener<T>>())
		{
			listener->OnEvent(event);
		}
	}
	template<typename T>
	inline void GameObject::SendEventDown(const T * event)
	{
		SendEvent(event);
		SendEventDownOnly(event);
	}
	template<typename T>
	inline void GameObject::SendEventDownOnly(const T * event)
	{
		for (GameObject* go : children_)
		{
			go->SendEventDown(event);
		}
	}
}