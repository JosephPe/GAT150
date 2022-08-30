#pragma once
#include "Framework/Component.h"
#include "Physics/Collision.h"


namespace anthemum
{
	class PlayerComponent : public Component, public ICollision
	{
	public:
		PlayerComponent() = default;

		void Initialize() override;
		void Update() override;

		CLASS_DECLARATION(PlayerComponent)

		// Inherited via ISerializable
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		virtual void OnCollisionEnter(Actor* other) override;
		virtual void OnCollisionExit(Actor* other) override;
	public:
	float speed = 0 ;
	};
}