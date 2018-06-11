#include "Game.h"

#include "SplashState.h"

Game::Game(int width, int height, std::string title)
{
	_data->window.create( sf::VideoMode( width, height), title, sf::Style::Close | sf::Style::Titlebar );
	_data->machine.AddState(( StateRef ( new SplashState ( this->_data))));
	
	this->Run();
}

Game::~Game()
{
}

void Game::Run()
{
	float newTime, frameTime, interpolation;

	float currenTime = this->clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	while ( this->_data->window.isOpen())
	{
		this->_data->machine.ProcessStateChanges();

		newTime = this->clock.getElapsedTime().asSeconds();

		frameTime = newTime - currenTime;

		if( frameTime > 0.25f )
			frameTime = 0.25f;

		currenTime = newTime;
		accumulator += frameTime;

		while ( accumulator >= dt )
		{
			this->_data->machine.GetActiveState()->HandleInput();
			this->_data->machine.GetActiveState()->Update( dt );

			accumulator -= dt;
		}

		interpolation = accumulator / dt;
		this->_data->machine.GetActiveState()->Draw( interpolation );
	}
}