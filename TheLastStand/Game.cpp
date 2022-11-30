#include "Game.h"

const float WALL_THICKNESS = 6.f;
const float CIRCLE_THICKNESS = 6.f;

void InitGame(Game& game, sf::Vector2f position, sf::Vector2f size, float circleSize)
{
    game.position = position;
    game.size = size;
    game.circleSize = circleSize;
    game.circleShape.setPosition(position);
    game.circleShape.setRadius(circleSize);
    game.circleShape.setOrigin(circleSize, circleSize);
    game.circleShape.setFillColor(sf::Color::Transparent);
    game.circleShape.setOutlineColor(sf::Color::Blue);
    game.circleShape.setOutlineThickness(CIRCLE_THICKNESS);
    game.shape.setPosition(position);
    game.shape.setSize(size);
    game.shape.setOrigin(size / 2.f);
    game.shape.setFillColor(sf::Color::Transparent);
    game.shape.setOutlineColor(sf::Color::White);
    game.shape.setOutlineThickness(WALL_THICKNESS);
    



}

void RenderGame(Game& game, sf::RenderWindow& window)
{
    window.draw(game.shape);
    window.draw(game.circleShape);
}
