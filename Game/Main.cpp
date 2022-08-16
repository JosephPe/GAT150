#include <iostream>
#include "Engine.h"
#include <Components/AudioComponent.h>
#include <Components/PhysicsComponent.h>

class SingleTon
{
public:
	//constructor, deconstructor, copy constructure, assignment etor

	~SingleTon() { std::cout << "dtor\n"; }

	SingleTon(const SingleTon& other) = delete;

	SingleTon& operator = (const SingleTon& other) = delete;

	void Say() { std::cout << "hey hey"; }

	static SingleTon& Instance()
	{

	}
};

void f()
{
	static int c = 0;
	c++;
	std::cout << c << std::endl;
}



int main()
{
	anthemum::InitializeMemory();

	//std::cout << "hello world";

	anthemum::SetFilePath("../Assets");

	anthemum::g_renderer.Initialize();
	anthemum::g_inputSystem.Initialize();
	anthemum::g_audioSystem.Initialize();
	anthemum::g_resourceManager.Initialize();
	
	anthemum::Engine::Instance().Register();

	// create window
	anthemum::g_renderer.CreateWindow("Neumont", 800, 600);
	anthemum::g_renderer.SetClearColor(anthemum::Color{ 255, 255, 255, 255 });

	// load assets
	//std::shared_ptr<anthemum::Model> model = std::make_shared<anthemum::Model>();
	//model->Create("Textures/sf2.bmp");

	//std::shared_ptr<anthemum::Texture> texture = std::make_shared<anthemum::Texture>();
	//texture->Create(anthemum::g_renderer, "Textures/sf2.bmp");
	std::shared_ptr<anthemum::Texture> texture = anthemum::g_resourceManager.Get< anthemum::Texture>("Textures/sf2.bmp", &anthemum::g_renderer);
	 
	std::shared_ptr<anthemum::Model> model = anthemum::g_resourceManager.Get<anthemum::Model>("Model.txt", &anthemum::g_renderer);
	std::shared_ptr<anthemum::Model> model2 = anthemum::g_resourceManager.Get<anthemum::Model>("Model.txt", &anthemum::g_renderer);

	anthemum::g_audioSystem.AddAudio("gunshot", "gunShot.wav");

	//create actors
	anthemum::Scene scene;
	anthemum::Transform transform{ { 400, 300 }, 90, { 1, 1 } };

	//std::unique_ptr<anthemum::Actor> actor = std::make_unique<anthemum::Actor>(transform);
	std::unique_ptr<anthemum::Actor> actor = anthemum::Factory::Instance().Create<anthemum::Actor>("Actor");
	actor->m_transform = transform;

	std::unique_ptr<anthemum::PlayerComponent> pcomponent = anthemum::Factory::Instance().Create<anthemum::PlayerComponent>("PlayerComponent");
	actor->AddComponent(std::move(pcomponent));

	std::unique_ptr<anthemum::ModelComponent> mcomponent = std::make_unique<anthemum::ModelComponent>();
	mcomponent->m_model = model;
	actor->AddComponent(std::move(mcomponent));

	//std::unique_ptr<anthemum::SpriteComponent> scomponent = std::make_unique<anthemum::SpriteComponent>();
	//scomponent->m_texture = texture;
	//actor->AddComponent(std::move(scomponent));

	std::unique_ptr<anthemum::AudioComponent> acomponent = std::make_unique<anthemum::AudioComponent>();
	acomponent->m_soundName = "gunShot";
	actor->AddComponent(std::move(acomponent));

	std::unique_ptr<anthemum::PhysicsComponent> phcomponent = anthemum::Factory::Instance().Create<anthemum::PhysicsComponent>("PhysicsComponent");
	actor->AddComponent(std::move(phcomponent));

	anthemum::Transform transformC{ anthemum::Vector2{ 10, 10 }, 0, { 1, 1 } };
	std::unique_ptr<anthemum::Actor> child = std::make_unique<anthemum::Actor>(transform);

	std::unique_ptr<anthemum::ModelComponent> mcomponentc = std::make_unique<anthemum::ModelComponent>();
	mcomponentc->m_model = model;
	child->AddComponent(std::move(mcomponentc));

	actor->AddChild(std::move(child));

	scene.Add(std::move(actor));

	float angle = 0;

	bool quit = false;
	while (!quit)
	{
		// update
		anthemum::g_time.Tick();
		anthemum::g_inputSystem.Update();
		anthemum::g_audioSystem.Update();

		if (anthemum::g_inputSystem.GetKeyDown(anthemum::key_escape)) quit = true;

		angle += 360.0f * anthemum::g_time.deltaTime;
		scene.Update();

		// draw
		anthemum::g_renderer.BeginFrame();
		scene.Draw(anthemum::g_renderer);
		anthemum::g_renderer.EndFrame();

		//		title.delete;
	}
	anthemum::g_inputSystem.Shutdown();
	anthemum::g_audioSystem.Shutdown();
	anthemum::g_renderer.Shutdown();

}