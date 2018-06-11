#pragma once

#include "Game.h"
#include "State.h"
#include "AI.h"



class GameState : public State
{
public:
	GameState( GameDataRef data);
	~GameState();

	void Init() override;
	void HandleInput() override;

	void Update(float dt) override;
	void Draw(float dt) override;

private:
	GameDataRef _data;

	sf::Sprite _background;
	sf::Sprite _pauseButton;
	sf::Sprite _gridSprite;
	sf::Sprite _gridPieces[3][3];
	int _gridArray[3][3];


	int turn;
	int gameState;

	AI *ai;

	void InitGridPieces();
	void CheckAndPlacePiece();
	void CheckPlayerHasWon( int turn );
	void Check3PiecesForMatch( int x1, int y1, int x2, int y2, int x3, int y3, int pieceToCheck);

	sf::Clock _clock;
};

