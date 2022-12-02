#pragma once
#include <SFML/Graphics.hpp>
#include <list>



struct Ennemy
{
    sf::CircleShape ennemisShape;
    sf::Vector2f position;
    sf::Vector2f circleCenter;
    float direction = 0;
    int index;
    float size = 10.f;
    float moveSpeed = 0.001f;

};

struct Ennemies
{
    sf::Vector2f circleCenter;
    sf::Time timeBeforeRespawn = sf::seconds(2);
    std::list<Ennemy*> all;
    void ennemiesTimer(sf::Clock timer);
    void deleteAll();
};





Ennemy* InitEnemy(int index, sf::Vector2f circleCenter);
void RenderEnnemies(Ennemies& ennemies, sf::RenderWindow& window);
Ennemy* InitEnemy(int index, sf::Vector2f pos);
void InitEnnemies(Ennemies& ennemies, sf::Vector2f pos);
void UpdateEnnemies(Ennemies& ennemies, float deltaTime);
bool IsEnnemyOut(Ennemies& ennemies, float circleRadius);
