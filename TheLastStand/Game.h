#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"
#include "BulletSpawner.h"
#include "Ennemies.h"

# define CIRCLE_POS sf::Vector2f circlePos = { window.getSize().x / 2.0f, window.getSize().y / 2.0f }

struct Game
{
    sf::Vector2f position;
    sf::Vector2f size;
    sf::RectangleShape shape;
    sf::CircleShape circleShape;
    float circleSize;
    sf::Font font;
    sf::Text score;
    bool isLose = false;
    bool firstTime = true;
    int gameScore = 0;
    void reset();
    
    Player player;
    BulletSpawner bulletSpawner;
    Enemies ennemies;
};

void InitGame(Game& game, sf::Vector2f position, sf::Vector2f size, float circleSize);
void UpdateGame(Game& game, float deltaTime);
void RenderGame(Game& game, sf::RenderWindow& window);
void ReceivePlayerInput(Game& game, float axis);
void TeleportPlayer(Game& game);
void InitScore(sf::Text& score, sf::Font& font);


