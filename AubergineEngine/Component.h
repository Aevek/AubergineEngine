#pragma once
namespace AubergineEngine
{
	class GameObject;

	class Component
	{
	public:
		Component(GameObject* owner);
		virtual ~Component();

		GameObject *const Owner;
	};
}