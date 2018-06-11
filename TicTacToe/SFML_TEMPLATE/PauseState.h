#pragma once
#include "Game.h"

class PauseState : public State
{
public:
	PauseState(GameDataRef data);
	~PauseState();

	void Init() override;
	void HandleInput() override;

	void Update(float dt) override;
	void Draw(float dt) override;

private:
	GameDataRef _data;

	sf::Sprite _background;

	sf::Sprite _homeButton;
	sf::Sprite _resumeButton;
};

