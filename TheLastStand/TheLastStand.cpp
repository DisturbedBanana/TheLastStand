#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"

const sf::Vector2f GAME_SIZE = { 900, 650 };
const float CIRCLE_RADIUS = 275.f;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "TheLastStand");
	// Initialise everything below
	Game game;
	InitGame(game, sf::Vector2f{ window.getSize().x / 2.0f, window.getSize().y / 2.0f }, GAME_SIZE, CIRCLE_RADIUS);

	// Game loop
	sf::Clock mainClock;
	while (window.isOpen())
	{
		sf::Time time = mainClock.restart();
		float deltaTime = time.asSeconds();

		sf::Event event;
		while (window.pollEvent(event))
		{
			// Process any input event here
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			
		}

		float axis = 0;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			axis -= 1;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			axis += 1;
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		{
			AddBullet(game.bulletSpawner.pList, game.player.position, game.circleShape.getPosition());
			
		}

		ReceivePlayerInput(game, axis);

		UpdateGame(game, deltaTime);
		
		window.clear();
		// Whatever I want to draw goes here
		RenderGame(game, window);
		window.display();
	}

}

