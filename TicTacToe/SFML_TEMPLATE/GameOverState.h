#pragma once
#include "Game.h"

class GameOverState : public State
{
public:
	GameOverState(GameDataRef data);
	~GameOverState();

	void Init() override;
	void HandleInput() override;

	void Update(float dt) override;
	void Draw(float dt) override;

private:
	GameDataRef _data;

	sf::Sprite _retryButton;

	sf::Sprite _homeButton;
};

