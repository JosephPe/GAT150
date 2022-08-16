#pragma once

#include "Math/Vector2.h"
#include "Math/MathUtils.h"
#include "Math/ModelComponent.h"

#include "Framework/Game.h"
#include "Framework/Scene.h"
#include "Framework/Factory.h"

#include "Renderer/Font.h"
#include "Renderer/Model.h"

#include "Input/InputSystem.h"

#include "Audio/AudioSystem.h"

#include "Resource/ResourceManager.h"

#include "Text.h"

#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Timer.h"
#include "Core/SingleTon.h"

#include "Components/SpriteComponent.h"
#include "Components/PlayerComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/AudioComponent.h"

#include <memory>

namespace anthemum
{
	extern Renderer g_renderer;
	extern InputSystem g_inputSystem;
	extern Time g_time;
	extern AudioSystem g_audioSystem;
	extern ResourceManager g_resourceManager;

	class Engine : public Singleton<Engine>
	{
	public:
		void Register();
	};
}