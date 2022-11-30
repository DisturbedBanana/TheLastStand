#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
# define M_PI           3.14159265358979323846  /* pi */

struct player
{
    sf::CircleShape playerShape;
    sf::Vector2f position;

    float playerSize = 3.f;
    float moveSpeed = 10.f;
    float angle = 0;
    sf::Vector2f pos;

    void mouvement(float cicleRad, float deltaTime);
    //void UpdatePlayer(player& player, float deltaTime);
};
void RenderPlayer(player& player, sf::RenderWindow& window);
void InitPlayer(player& player, sf::Vector2f position);
