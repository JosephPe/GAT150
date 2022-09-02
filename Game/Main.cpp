#include "Engine.h"
#include "ThisGame.h"
#include <iostream>



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


	//auto texture = anthemum::g_resourceManager.Get<anthemum::Texture>("textures/blue_01.png", anthemum::g_renderer);
		//auto font = anthemum::g_resourceManager.Get<anthemum::Font>("fonts/arcadeclassic.ttf", 10);
		//component->m_model = anthemum::g_resourceManager.Get<anthemum::Model>("models/player.txt");


	anthemum::g_renderer.Initialize();
	anthemum::g_inputSystem.Initialize();
	anthemum::g_audioSystem.Initialize();
	anthemum::g_resourceManager.Initialize();
	anthemum::g_physicsSystem.Initialize();
	anthemum::g_eventManager.Initialize();
	
	anthemum::Engine::Instance().Register();

	// create window
	anthemum::g_renderer.CreateWindow("Neumont", 800, 600);
	anthemum::g_renderer.SetClearColor(anthemum::Color{ 0, 0, 0, 255 });

	std::unique_ptr<ThisGame> game = std::make_unique<ThisGame>();
	game->Initialize();

	//create actors
	//anthemum::Scene scene;

	//scene.Add(std::move(actor));

	bool quit = false;
	while (!quit)
	{
		// update
		anthemum::g_time.Tick();
		anthemum::g_inputSystem.Update();
		anthemum::g_audioSystem.Update();
		anthemum::g_physicsSystem.Update();
		anthemum::g_eventManager.Update();

		if (anthemum::g_inputSystem.GetKeyDown(anthemum::key_escape)) quit = true;

		//angle += 360.0f * anthemum::g_time.deltaTime;
		game->Update();

		// draw
		anthemum::g_renderer.BeginFrame();
		game->Draw(anthemum::g_renderer);
		anthemum::g_renderer.EndFrame();

		//		title.delete;
	}
	game->Shutdown();
	game.reset();

	anthemum::Factory::Instance().Shutdown();
	anthemum::g_physicsSystem.Shutdown();
	anthemum::g_resourceManager.Shutdown();
	anthemum::g_inputSystem.Shutdown();
	anthemum::g_audioSystem.Shutdown();
	anthemum::g_renderer.Shutdown();
	anthemum::g_eventManager.Shutdown();

}