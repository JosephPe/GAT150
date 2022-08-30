#include "PlayerComponent.h"
#include <Engine.h>
#include <iostream>
#include <functional>

namespace anthemum
{
	void PlayerComponent::Initialize()
	{
		auto component = m_owner->GetComponent<CollisionComponent>();
		if (component)
		{
			component->SetCollisionEnter(std::bind(&PlayerComponent::OnCollisionEnter, this, std::placeholders::_1));
			component->SetCollisionExit(std::bind(&PlayerComponent::OnCollisionExit, this, std::placeholders::_1));
		}
	}

	void PlayerComponent::Update()
	{
	
		Vector2 direction = Vector2::zero;
		if (g_inputSystem.GetKeyState(key_a) == InputSystem::keyState::held)
		{
			//m_owner->m_transform.rotation -= 180 * g_time.deltaTime;
			direction = Vector2::left;
		}	
		if (g_inputSystem.GetKeyState(key_d) == InputSystem::keyState::held)
		{
			//m_owner->m_transform.rotation += 180 * g_time.deltaTime;
			direction = Vector2::right;

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
			//Vector2 force = Vector2::Rotate( { 1, 0 }, math::DegToRad(m_owner->m_transform.rotation)) * thrust;
			//component->ApplyForce(force);
			component->ApplyForce(direction * speed);

			//force = (Vector2{ 400, 300 } - m_owner->m_transform.position).Normalized() * 60.0f;
			//component->ApplyForce(force);
		}





		if (g_inputSystem.GetKeyState(key_space) == InputSystem::keyState::Pressed)
		{
			//auto component = m_owner->GetComponent<AudioComponent>();
			//if (component)
			//{
				//component->Play();
			//}

			auto component = m_owner->GetComponent<PhysicsComponent>();
			if (component)
			{
				component->ApplyForce(Vector2::up * 30);
			}
		}

	}

	bool PlayerComponent::Write(const rapidjson::Value& value) const
	{
		return false;
	}

	bool PlayerComponent::Read(const rapidjson::Value& value)
	{

		READ_DATA(value, speed);
		return false;
	}

	void PlayerComponent::OnCollisionEnter(Actor* other)
	{
		if (other->GetName() == "Coin")
		{
			Event event;
			event.name = "EVENT_ADD_POINTS";
			event.data = 100;

			g_eventManager.Notify(event);

			other->SetDestroy();
		}


		std::cout << "player enter";
	}

	void PlayerComponent::OnCollisionExit(Actor* other)
	{
		std::cout << "Player exit";
	}

}