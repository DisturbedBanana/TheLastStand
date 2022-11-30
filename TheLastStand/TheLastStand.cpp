#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "player.h"

const sf::Vector2f GAME_SIZE = { 900, 650 };
const float CIRCLE_RADIUS = 275.f;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "TheLastStand");
	// Initialise everything below
	player player;
	Game game;
	InitGame(game,
		sf::Vector2f{ window.getSize().x / 2.0f, window.getSize().y / 2.0f },
		GAME_SIZE, CIRCLE_RADIUS);

	InitPlayer(player, sf::Vector2f((game.circleShape.getPosition().x + game.circleSize), game.circleShape.getPosition().y));

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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				player.mouvement(game.circleSize, deltaTime);
			}
			
		}
		window.clear();
		// Whatever I want to draw goes here
		RenderGame(game, window);
		RenderPlayer(player, window);
		window.display();
	}

}

