#pragma once
#include "Framework/Game.h"
#include "Framework/Event.h"

class ThisGame : public anthemum::Game, public anthemum::INotify
{
public:
	enum class gameState
	{
		titleScreen,
		startLevel,
		game,
		playerDead,
		gameOver
	};

	virtual void Initialize() override;
	virtual void Shutdown() override;
	virtual void Update() override;
	virtual void Draw(anthemum::Renderer& renderer) override;

	void OnAddpoints(const anthemum::Event& event);
	void OnPlayerDead(const anthemum::Event& event);

private:
	gameState m_gameState = gameState::titleScreen;
	float m_stateTimer = 3;
	int m_lives = 3;

	// Inherited via INotify
	virtual void OnNotify(const anthemum::Event& event) override;
};