#pragma once
#include "Component.h"
#include <utility>
#include <vector>
#include <functional>
namespace AubergineEngine
{
	namespace Events
	{
		template <typename T>
		class EventListener : public Component
		{
		public:
			EventListener(GameObject* owner);
			~EventListener();

			void OnEvent(const T *event);

			template<typename S>
			void SubscribeEvent(S* comp, void(S::* onEvent)(const T *));

			static void SendGlobalEvent(const T* event);

		private:
			std::vector<std::function<void(const T*)>> toCall_;
			std::vector<std::function<void(const T*)>> toCallChildren_;
			static std::vector<std::function<void(const T*)>> toCallGlobal_;
		};

		template<typename T>
		inline EventListener<T>::EventListener(GameObject * owner) : Component(owner)
		{
		}

		template<typename T>
		inline EventListener<T>::~EventListener()
		{
		}

		template<typename T>
		inline void EventListener<T>::OnEvent(const T * event)
		{
			for (auto call : toCall_)
			{
				call(event);
			}
		}

		template<typename T>
		template<typename S>
		inline void EventListener<T>::SubscribeEvent(S* comp, void(S::* onEvent)(const T *))
		{
			using std::placeholders::_1;
			std::function<void(const T*)> bound = std::bind(onEvent, comp, _1);
			toCall_.push_back(bound);
			toCallGlobal_.push_back(bound);

			GameObject* parentObject = Owner->GetParent();
			while (parentObject != nullptr)
			{
				EventListener<T>* parentListener = parentObject->AddComponent<EventListener<T>>();
				parentListener->toCallChildren_.push_back(bound);
				parentObject = parentObject->GetParent();
			}
		}

		template<typename T>
		inline void EventListener<T>::SendGlobalEvent(const T * event)
		{
			for (auto call : toCallGlobal_)
			{
				call(event);
			}
		}

		template <typename T>
		std::vector<std::function<void(const T*)>> EventListener<T>::toCallGlobal_;
	}
}