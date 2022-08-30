#pragma once

#include "Serialization/json.h"

#include "Math/Vector2.h"
#include "Math/MathUtils.h"
#include "Math/ModelComponent.h"

#include "Framework/Game.h"
#include "Framework/Scene.h"
#include "Framework/Factory.h"
#include "Framework/EventManager.h"

#include "Renderer/Font.h"
#include "Renderer/Model.h"
#include "Renderer/Text.h"

#include "Input/InputSystem.h"

#include "Audio/AudioSystem.h"

#include "Resource/ResourceManager.h"

#include "Physics/PhysicsSystem.h"


#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Timer.h"
#include "Core/SingleTon.h"
#include "Core/Logger.h"

#include "Components/SpriteComponent.h"
#include "Components/PlayerComponent.h"
#include "Components/CollisionComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/RBPhysicsComponent.h"
#include "Components/AudioComponent.h"
#include "Components/SpritesAnimComponent.h"
#include "Components/TextComponent.h"
#include "Components/TilemapComponent.h"

#include <memory>
#include <variant>

namespace anthemum
{
	extern Renderer g_renderer;
	extern InputSystem g_inputSystem;
	extern Time g_time;
	extern AudioSystem g_audioSystem;
	extern ResourceManager g_resourceManager;
	extern PhysicsSystem g_physicsSystem;
	extern EventManager g_eventManager;

	class Engine : public Singleton<Engine>
	{
	public:
		void Register();
	};
}