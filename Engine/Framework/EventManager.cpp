#include "EventManager.h"

void anthemum::EventManager::Initialize()
{
}

void anthemum::EventManager::Shutdown()
{
}

void anthemum::EventManager::Update()
{
}

void anthemum::EventManager::Subscribe(const std::string& name, Event::functionPtr function, GameObject* receiver)
{
	Observer observer;
	observer.receiver = receiver;
	observer.function = function;

	m_events[name].push_back(observer);
}

void anthemum::EventManager::Unsubscribe(const std::string& name, GameObject* receiver)
{
}

void anthemum::EventManager::Notify(const Event& event)
{
	auto observers = m_events[event.name];
	for (auto& observer : observers)
	{
		if (event.receiver == nullptr || event.receiver == observer.receiver)
		{
			observer.function(event);
		}
	}
}
