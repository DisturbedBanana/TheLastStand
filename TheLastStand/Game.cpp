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
    
	InitPlayer(game.player, sf::Vector2f{ position.x, position.y - circleSize });
    InitBulletSpawner(game.bulletSpawner);
    InitEnnemies(game.ennemies, game.circleShape.getPosition());
}

void UpdateGame(Game& game, float deltaTime)
{
    UpdatePlayer(game.player, deltaTime, game.circleSize, game.circleShape.getPosition());
    UpdateEnnemies(game.ennemies, deltaTime);
    if (IsEnnemyOut(game.ennemies, game.circleShape.getRadius()))
    {
        printf("game over");
        //game over

    }
    game.ennemies.ennemiesTimer(deltaTime);

}


void RenderGame(Game& game, sf::RenderWindow& window)
{
    window.draw(game.shape);
    window.draw(game.circleShape);
    RenderPlayer(game.player, window);
    RenderBullets(game.bulletSpawner.pList, window);
    RenderEnnemies(game.ennemies, window);
}

void ReceivePlayerInput(Game& game, float axis)
{
    SetPlayerDirection(game.player, axis);
}

void Shoot(Game& game)
{
    AddBullet(game.bulletSpawner.pList, sf::Vector2f{ 100,100 }, game.circleShape.getPosition());
}
