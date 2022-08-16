#include "Engine.h"

namespace anthemum
{
	Renderer g_renderer;
	InputSystem g_inputSystem;
	Time g_time;
	AudioSystem g_audioSystem;
	ResourceManager g_resourceManager;




	void Engine::Register()
	{
		REGISTER_CLASS(Actor);
		REGISTER_CLASS(AudioComponent);
		REGISTER_CLASS(ModelComponent);
		REGISTER_CLASS(PlayerComponent);
		REGISTER_CLASS(SpriteComponent);
		REGISTER_CLASS(PhysicsComponent);
	}
}