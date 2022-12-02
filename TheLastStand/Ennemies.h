#pragma once
#include <SFML/Graphics.hpp>
#include <list>



struct Enemy
{
    sf::CircleShape ennemisShape;
    sf::Vector2f position;
    sf::Vector2f circleCenter;
    float direction = 0;
    int index;
    float size = 10.f;
    float moveSpeed = 0.001f;

};

struct Enemies
{
    sf::Vector2f circleCenter;
    float timeBeforeRespawn = 2.f;
    std::list<Enemy*> all;
    void deleteAll();
    float startClock = 0;
    float elapsedTime = 0;
};





Enemy* InitEnemy(int index, sf::Vector2f circleCenter);
void RenderEnemies(Enemies& ennemies, sf::RenderWindow& window);
Enemy* InitEnemy(int index, sf::Vector2f pos);
void InitEnemies(Enemies& ennemies, sf::Vector2f pos);
void UpdateEnemies(Enemies& ennemies, float deltaTime);
bool IsEnemyOut(Enemies& ennemies, float circleRadius);
void EnemiesTimer(float deltaTime, Enemies& enemies);
