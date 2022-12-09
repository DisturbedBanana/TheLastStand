#pragma once
#include <SFML/Graphics.hpp>
#include <list>



struct Enemy
{
    sf::CircleShape ennemisShape;
    sf::Vector2f position;
    sf::Vector2f circleCenter;
    sf::Vector2f direction;
    int index;
    float size = 10.f;
    float moveSpeed = 100.f;
    bool isDead = false;
    bool isInvincible = true;
    float invincibilityTime = 0.7f;
    float timeSinceInvicibilityFade = 0;
};

struct Enemies
{
    sf::Vector2f circleCenter;
    float timeBeforeRespawn = 2.f;
    float difficulty = 1;
    std::list<Enemy*> enemiesList;
    void deleteAll();
    float startClock = 0;
    float elapsedTime = 0;
    float ratio = 0.05f;
    int points = 10;
};





Enemy* InitEnemy(int index, sf::Vector2f circleCenter, float rad);
void RenderEnemies(Enemies& ennemies, sf::RenderWindow& window);
void InitEnemies(Enemies& ennemies, sf::Vector2f pos, float rad);
void UpdateEnemies(Enemies& ennemies, float deltaTime);
bool IsEnemyOut(Enemies& ennemies, float circleRadius);
void EnemiesTimer(float deltaTime, Enemies& enemies, float rad);
