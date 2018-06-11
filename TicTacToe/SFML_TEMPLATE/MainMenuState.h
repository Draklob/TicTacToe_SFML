#pragma once

#include <SFML/Graphics.hpp>

#include "State.h"
#include "Game.h"

class MainMenuState : public State
{
public:
	MainMenuState( GameDataRef data);
	~MainMenuState();

	void Init() override;
	void HandleInput() override;

	void Update(float dt) override;
	void Draw(float dt) override;

private:
	GameDataRef _data;

	sf::Sprite _background;
	sf::Sprite _title;
	sf::Sprite _playButton;
	sf::Sprite _playButtonOuter;
};

