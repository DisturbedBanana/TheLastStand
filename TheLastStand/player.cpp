#include "player.h"
const sf::Vector2f M_GAME_SIZE = { 900, 650 };


void player::mouvement(float circleRad, float deltaTime)
{
	
	angle += moveSpeed * deltaTime;
	pos = sf::Vector2f((cos((angle / 360) * M_PI * 2) * circleRad), sin((angle / 360) * M_PI * 2) * circleRad);
	playerShape.setPosition(pos);


	
}


//void player::UpdatePlayer(player& player, float deltaTime)
//{
//	float deltaX = player.moveSpeed * player.direction * deltaTime;
//	player.position.x += deltaX;
//	player.playerShape.setPosition(player.position);
//}

void RenderPlayer(player& player, sf::RenderWindow& window)
{
	window.draw(player.playerShape);
}

void InitPlayer(player& player, sf::Vector2f position)
{
	player.playerShape.setPosition(position);
	player.playerShape.setRadius(player.playerSize);
	player.playerShape.setOrigin(player.playerSize, player.playerSize);
	player.playerShape.setOutlineColor(sf::Color::Red);
	player.playerShape.setFillColor(sf::Color::Red);
	player.playerShape.setOutlineThickness(2.f);
	player.pos = player.playerShape.getPosition();

}



