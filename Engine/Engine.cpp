#include "Engine.h"

namespace anthemum
{
	Renderer g_renderer;
	InputSystem g_inputSystem;
	Time g_time;
	AudioSystem g_audioSystem;
	ResourceManager g_resourceManager;
	PhysicsSystem g_physicsSystem;
	EventManager g_eventManager;

	void Engine::Register()
	{
		REGISTER_CLASS(Actor);
		REGISTER_CLASS(AudioComponent);
		REGISTER_CLASS(ModelComponent);
		REGISTER_CLASS(PlayerComponent);
		REGISTER_CLASS(SpriteComponent);
		REGISTER_CLASS(SpriteAnimComponent);
		REGISTER_CLASS(CollisionComponent);
		REGISTER_CLASS(PhysicsComponent);
		REGISTER_CLASS(TextComponent);
		REGISTER_CLASS(TilemapComponent);
	}
}