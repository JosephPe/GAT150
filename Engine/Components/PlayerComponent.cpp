#include "PlayerComponent.h"
#include <Components/PhysicsComponent.h>
#include <Engine.h>
#include <Components/AudioComponent.h>
#include <iostream>

anthemum::PlayerComponent::PlayerComponent()
{
}

void anthemum::PlayerComponent::Update()
{
	

	if (g_inputSystem.GetKeyState(key_a) == InputSystem::keyState::held)
	{
		m_owner->m_transform.rotation -= 180 * g_time.deltaTime;
	}	
	if (g_inputSystem.GetKeyState(key_d) == InputSystem::keyState::held)
	{
		m_owner->m_transform.rotation += 180 * g_time.deltaTime;
	}	

	float thrust = 0;
	if (g_inputSystem.GetKeyState(key_w) == InputSystem::keyState::held)
	{
		thrust = 500;
	}
	//m_owner->m_transform.position += direction * 300 * g_time.deltaTime;

	auto component = m_owner->GetComponent<PhysicsComponent>();
	if (component)
	{
		Vector2 force = Vector2::Rotate( { 1, 0 }, math::DegToRad(m_owner->m_transform.rotation)) * thrust;
		component->ApplyForce(force);

		force = (Vector2{ 400, 300 } - m_owner->m_transform.position).Normalized() * 60.0f;
		component->ApplyForce(force);
	}





	if (g_inputSystem.GetKeyState(key_space) == InputSystem::keyState::Pressed)
	{
		auto component = m_owner->GetComponent<AudioComponent>();
		if (component)
		{
			component->Play();
		}
	}

}
