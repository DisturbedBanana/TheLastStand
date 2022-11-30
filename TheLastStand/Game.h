#pragma once
#include <SFML/Graphics.hpp>


struct Game
{
    sf::Vector2f position;
    sf::Vector2f size;
    sf::RectangleShape shape;
    sf::CircleShape circleShape;
    float circleSize;

};

void InitGame(Game& game, sf::Vector2f position, sf::Vector2f size, float circleSize);

void RenderGame(Game& game, sf::RenderWindow& window);

