#include <iostream>
#include "Engine.h"


int main()
{	
	anthemum::InitializeMemory();

	//std::cout << "hello world";

	anthemum::SetFilePath("../Assets");

	anthemum::g_renderer.Initialize();
	anthemum::g_inputSystem.Initialize();
	anthemum::g_audioSystem.Initialize();

	// create window
	anthemum::g_renderer.CreateWindow("Neumont", 800, 600);
	anthemum::g_renderer.SetClearColor(anthemum::Color{ 50, 50, 155, 255 });

	std::shared_ptr<anthemum::Texture> texture = std::make_shared<anthemum::Texture>();
	texture->Create(anthemum::g_renderer, "sf2.bmp");

	bool quit = false;
	while (!quit)
	{
		anthemum::g_time.Tick();
		anthemum::g_inputSystem.Update();

		if (anthemum::g_inputSystem.GetKeyDown(anthemum::key_escape)) quit = true;


		//game.Update();


		anthemum::g_renderer.BeginFrame();
		anthemum::g_renderer.Draw(texture, { 400, 300 }, 0);
		//game.Draw(anthemum::g_renderer);
		anthemum::g_audioSystem.Update();

		anthemum::g_renderer.EndFrame();

		//		title.delete;
	}
	anthemum::g_inputSystem.Shutdown();
	anthemum::g_audioSystem.Shutdown();
	anthemum::g_renderer.Shutdown();

}