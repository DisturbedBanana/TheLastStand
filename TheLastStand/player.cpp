#include "Player.h"
const sf::Vector2f M_GAME_SIZE = { 900, 650 };

void InitPlayer(Player& player, sf::Vector2f position)
{
	player.position = position;
	player.playerShape.setPosition(player.position);
	player.playerShape.setRadius(player.playerSize);
	player.playerShape.setOrigin(player.playerSize, player.playerSize);
	player.playerShape.setOutlineColor(sf::Color::Red);
	player.playerShape.setFillColor(sf::Color::Red);
	player.playerShape.setOutlineThickness(2.f);
}

void RenderPlayer(Player& player, sf::RenderWindow& window)
{
	window.draw(player.playerShape);
}

void UpdatePlayer(Player& player, float deltaTime, float circleRadius)
{
	//float deltaX = player.moveSpeed * player.direction * deltaTime;
	//player.position.x += deltaX;
	//player.playerShape.setPosition(player.position);
	
	player.angle += player.direction* deltaTime;
	player.position.x += cos((player.angle / 360) * circleRadius) - 1;
	player.position.y += sin((player.angle / 360) * circleRadius);
	player.playerShape.setPosition(player.position);
}

void SetPlayerDirection(Player& player, float axis)
{
	player.direction = axis;
}
