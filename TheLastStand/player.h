#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include <list>
#include <iostream>
# define M_PI           3.14159265358979323846  /* pi */

struct Player
{
    sf::CircleShape playerShape;
    sf::Vector2f position;

    float playerSize = 8.f;
    float moveSpeed = 100.f;
    float direction = 0;
    float angle = 0;
};

void RenderPlayer(Player& player, sf::RenderWindow& window);
void InitPlayer(Player& player, sf::Vector2f position);
void UpdatePlayer(Player& player, float deltaTime, float circleRadius, sf::Vector2f circlePosition);
void SetPlayerDirection(Player& player, float axis);

