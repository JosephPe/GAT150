#pragma once

#include "Math/Vector2.h"
#include "Input/InputSystem.h"
#include "Core/Timer.h"
#include "Framework/Scene.h"
#include "Audio\AudioSystem.h"
#include "Framework/Game.h"
#include "../Engine/Renderer/Font.h"
#include "../Engine/Renderer/Random.h"
#include "../Engine/Text.h"
#include "..\Engine\Framework\Scene.h"
#include "Math/MathUtils.h"
#include <memory>
#include "Core/Memory.h"
#include "Core/File.h"

namespace anthemum
{
	extern Renderer g_renderer;
	extern InputSystem g_inputSystem;
	extern Time g_time;
	extern AudioSystem g_audioSystem;
}