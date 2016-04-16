#include "stdafx.h"
#include "GameObject.h"

namespace AubergineEngine
{
	unsigned long GameObject::InstanceCount = 0;

	GameObject::GameObject(std::string name) : id(InstanceCount++), Name(name)
	{
	}

	GameObject::GameObject() : GameObject("Unnamed Object")
	{
	}

	GameObject::~GameObject()
	{
	}

	GameObject * GameObject::AddChild(GameObject * child)
	{
		child->space_ = space_;
		child->owner_ = this;
		children_.push_back(child);
		return child;
	}

	void GameObject::SetParent(GameObject * newParent)
	{
		owner_->RemoveChild(this);
		newParent->AddChild(this);
		owner_ = newParent;
	}

	GameObject * GameObject::GetParent()
	{
		return owner_;
	}

	void GameObject::RemoveChild(GameObject * child)
	{
		for (auto it = children_.begin(); it < children_.end(); ++it)
		{
			if (*it == child)
			{
				std::iter_swap(it, children_.end() - 1);
				children_.pop_back();
				
				//A child is only there once, and it is gone. All done.
				//Also continuing to loop thru is probably unsafe? Since the end changed
				return;
			}
		}
	}

}