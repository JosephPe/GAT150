#include "Actor.h"
#include <Components/RenderComponent.h>

namespace anthemum
{
	void Actor::Update()
	{
		for (auto& component : m_components)
		{
			component->Update();
		}
		for (auto& child : m_children)
		{
			child->Update();
		}

		if (m_parent) m_transform.Update(m_parent->m_transform.matrix);
		else m_transform.Update();

		m_transform.Update();
	}
	void anthemum::Actor::Draw(Renderer& renderer)
	{
		for (auto& component : m_components)
		{
			auto renderComponent = dynamic_cast<RenderComponent*>(component.get());
			if (renderComponent)
			{
				renderComponent->Draw(renderer);
			}
			//component->Update();
		}
		for (auto& child : m_children)
		{
			child->Draw(renderer);
		}
		//m_model.Draw(renderer, m_transform.position, m_transform.rotation, m_transform.scale);
	}
	void Actor::AddChild(std::unique_ptr<Actor> child)
	{
		child->m_scene = m_scene;
		m_children.push_back(std::move(child));
	}
	void Actor::AddComponent(std::unique_ptr<Component> component)
	{
		component->m_owner = this;
		m_components.push_back(std::move(component));
	}

}
