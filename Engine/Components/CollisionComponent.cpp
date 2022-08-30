#include "CollisionComponent.h"
#include "Engine.h"

namespace anthemum
{


    bool CollisionComponent::Write(const rapidjson::Value& value) const
    {
        return false;
    }

    bool CollisionComponent::Read(const rapidjson::Value& value)
    {
        Vector2 size;
        float density = 1;
        float friction = 1;
        float restitution = 0.3f;
        bool is_trigger = false;

        READ_DATA(value, data.size);
        READ_DATA(value, data.density);
        READ_DATA(value, data.friction);
        READ_DATA(value, data.restitution);
        READ_DATA(value, data.is_trigger);

        return false;
    }

    void CollisionComponent::Initialize()
    {
        auto component = m_owner->GetComponent<RBPHysicsComponent>();
        if (component)
        {
            if (data.size.x == 0 || data.size.y == 0)
            {
                auto renderComponent = m_owner->GetComponent<RenderComponent>();
                if (renderComponent)
                {
                    data.size = Vector2{ renderComponent->GetSource().w, renderComponent->GetSource().h };
                }
            }
            g_physicsSystem.SetCollisionBox(component->m_body, data, m_owner);
        }
    }

    void CollisionComponent::Update()
    {
    }

    void CollisionComponent::OnCollisionEnter(Actor* other)
    {
        if(m_enterFunction) m_enterFunction(other);
    }

    void CollisionComponent::OnCollisionExit(Actor* other)
    {
        if(m_exitFunction) m_exitFunction(other);

    }

}