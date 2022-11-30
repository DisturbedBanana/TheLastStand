#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"

struct Game
{
    sf::Vector2f position;
    sf::Vector2f size;
    sf::RectangleShape shape;
    sf::CircleShape circleShape;
    float circleSize;

    Player player;
};

void InitGame(Game& game, sf::Vector2f position, sf::Vector2f size, float circleSize);
void UpdateGame(Game& game, float deltaTime);
void RenderGame(Game& game, sf::RenderWindow& window);
void ReceivePlayerInput(Game& game, float axis);

