#include "ThisGame.h"
#include "GameComponents/EnemyComponent.h"
#include "Engine.h"

void ThisGame::Initialize()
{
	REGISTER_CLASS(EnemyComponent);

	m_scene = std::make_unique<anthemum::Scene>();

	rapidjson::Document document;

	std::vector<std::string> sceneNames = { "Scenes/Prefabs.txt","Scenes/TileMap.txt","Scenes/level.txt" };
	for (auto sceneName : sceneNames)
	{
		bool success = anthemum::json::Load(sceneName, document);

		if (!success)
		{
			LOG("Could not load scene #s", sceneName.c_str());
			continue;
		}

		m_scene->Read(document);

	}

	//assert(success);
	m_scene->Initialize();

	//auto actor = anthemum::Factory::Instance().Create<anthemum::Actor>("Coin");
	//actor->m_transform.position = { 600, 100 };
	//actor->Initialize();

	

	anthemum::g_eventManager.Subscribe("EVENT_ADD_POINTS", std::bind(&ThisGame::OnAddpoints, this, std::placeholders::_1));
}

void ThisGame::Shutdown()
{
	m_scene->RemoveAll();
}

void ThisGame::Update()
{
	m_scene->Update();

	switch (m_gameState)
	{
	case ThisGame::gameState::titleScreen:
			if (anthemum::g_inputSystem.GetKeyState(anthemum::key_space) == anthemum::InputSystem::keyState::Pressed)
				{
					m_gameState = gameState::startLevel;
				}
			break;
	case ThisGame::gameState::startLevel:
			for (int i = 0; i < 10; i++)
			{
				auto actor = anthemum::Factory::Instance().Create<anthemum::Actor>("Coin");
				actor->m_transform.position = { anthemum::randomf(800), 100.0f };
				actor->Initialize();

				m_scene->Add(std::move(actor));
			}
			//for (int i = 0; i < 3; i++)
			//{
			//	auto actor = anthemum::Factory::Instance().Create<anthemum::Actor>("Ghost");
			//	actor->m_transform.position = { 600, 100 };
			//	actor->Initialize();

			//	m_scene->Add(std::move(actor));
			//}
			m_gameState = gameState::game;
			break;
	case ThisGame::gameState::game:
	{
		//auto actor = m_scene->GetActorFromName("Score");
		//auto component = actor->GetComponent<anthemum::TextComponent>();
		//component->SetText(std::to_string(m_score));

		//auto actor = m_scene->GetActorFromName("Health");
		//auto component = actor->GetComponent<anthemum::TextComponent>();

		//auto player = m_scene->GetActorFromName("Player");
		//auto playerComponent = player->GetComponent<anthemum::PlayerComponent>();
		//playerComponent->SetText(std::to_string((int)playerComponent->health));
	}


			break;
	case ThisGame::gameState::playerDead:
		m_stateTimer -= anthemum::g_time.deltaTime;
		if (m_stateTimer <= 0)
		{
			m_gameState = (m_lives > 0) ? gameState::startLevel : gameState::gameOver;
		}
			break;
	case ThisGame::gameState::gameOver:
			break;
	}
}

void ThisGame::Draw(anthemum::Renderer& renderer)
{
	m_scene->Draw(renderer);
}

void ThisGame::OnAddpoints(const anthemum::Event& event)
{
	std::cout << event.name << std::endl;
	std::cout << std::get<int>(event.data) << std::endl;
}

void ThisGame::OnPlayerDead(const anthemum::Event& event)
{
	m_gameState = gameState::playerDead;
	m_lives = 0;
}

void ThisGame::OnNotify(const anthemum::Event& event)
{
}
