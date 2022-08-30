#pragma once
#include "PhysicsComponent.h"
#include "Physics/PhysicsSystem.h"

namespace anthemum
{
	class RBPHysicsComponent : public PhysicsComponent
	{
	public:
		RBPHysicsComponent() = default;
		~RBPHysicsComponent();

		CLASS_DECLARATION(RBPHysicsComponent)

		void Initialize() override;

		void Update() override;
		virtual void ApplyForce(const Vector2 force);

		// Inherited via ISerializable
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		friend class CollisionComponent;

	private:
		PhysicsSystem::RigidBodyData data;
		b2Body* m_body = nullptr;
	};
}