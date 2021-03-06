#include "InputManager.h"

InputManager::InputManager()
{
}


InputManager::~InputManager()
{
}

bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window)
{
	if( sf::Mouse::isButtonPressed( button))
	{
		sf::IntRect tempRect(	int( object.getPosition().x ), int( object.getPosition().y ),
								int(object.getGlobalBounds().width), int(object.getGlobalBounds().height ));

		if( tempRect.contains( sf::Mouse::getPosition(window)))
			return true;
	}

	return false;
}

sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow& window) const
{
	return sf::Mouse::getPosition(window);
}
