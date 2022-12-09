#include "Ennemies.h"
#include <iostream>



bool IsEnemyOut(Enemies& ennemies, float circleRadius)
{
    std::list<Enemy*>::iterator it = ennemies.enemiesList.begin();
    for (int i = 0; i < ennemies.enemiesList.size(); i++)
    {
		sf::Vector2f centerToEnemy = (*it)->position - ennemies.circleCenter;
        float sqDistance = (centerToEnemy.x * centerToEnemy.x) + (centerToEnemy.y * centerToEnemy.y);
        
        if (sqDistance - (circleRadius * circleRadius) >= 0) //sur ou à l'exterieur
            return true;
        it++;
    }

    return false;

}

void RenderEnemies(Enemies& ennemies, sf::RenderWindow& window)
{
    std::list<Enemy*>::iterator it = ennemies.enemiesList.begin();
    for (int i = 0; i < ennemies.enemiesList.size(); i++)
    {
        window.draw((*it)->ennemisShape);
        it++;
    }
}

void InitEnemies(Enemies& ennemies, sf::Vector2f pos, float rad)
{
    bool shouldRandomizeSeed = true;

    if (shouldRandomizeSeed)
    {
        srand(time(0));
        shouldRandomizeSeed = false;
    }
    ennemies.circleCenter = pos;
    ennemies.enemiesList.push_back(InitEnemy(1, pos, rad));
}

Enemy* InitEnemy(int index, sf::Vector2f circleCenter, float rad)
{
    Enemy* ennemy = new Enemy;
    ennemy->position = circleCenter;
    ennemy->ennemisShape.setPosition(ennemy->position);
    ennemy->ennemisShape.setRadius(ennemy->size);
    ennemy->ennemisShape.setOrigin(ennemy->size, ennemy->size);
    ennemy->ennemisShape.setOutlineColor(sf::Color::Green);
    ennemy->ennemisShape.setFillColor(sf::Color::Green);
    ennemy->ennemisShape.setOutlineThickness(2.f);
    ennemy->index = index;
    float theta = (rand() / float(RAND_MAX)) * 2 * 3.14159265358979323846;
    ennemy->direction.x = cos(theta);
    ennemy->direction.y = sin(theta);
    return ennemy;
}

void UpdateEnemies(Enemies& enemies, float deltaTime)
{
    std::list<Enemy*>::iterator it = enemies.enemiesList.begin();
    for (int i = 0; i < enemies.enemiesList.size(); i++)
    {
        if (!(*it)->isDead)
        {
            float deltaX = (*it)->moveSpeed * deltaTime * (*it)->direction.x;
            float deltaY = (*it)->moveSpeed * deltaTime * (*it)->direction.y;
            (*it)->position.x += deltaX;
            (*it)->position.y += deltaY;
            (*it)->ennemisShape.setPosition((*it)->position);
            (*it)->timeSinceInvicibilityFade += deltaTime;
            if ((*it)->timeSinceInvicibilityFade >= (*it)->invincibilityTime && (*it)->isInvincible)
            {
                (*it)->isInvincible = false;
                (*it)->ennemisShape.setFillColor(sf::Color::Red);
                (*it)->ennemisShape.setOutlineColor(sf::Color::Red);
            }
            it++;
        }
        else
        {
            if ((*it)->size >= 0.1f)
            {
                (*it)->size -= 25.f * deltaTime;
                (*it)->ennemisShape.setRadius((*it)->size);
                (*it)->ennemisShape.setOrigin((*it)->size, (*it)->size);
                it++;

            }
            else
                it = enemies.enemiesList.erase(it);
        }
    }
}




void EnemiesTimer(float deltaTime, Enemies& enemies, float rad)
{
    enemies.elapsedTime += deltaTime;

    if (enemies.elapsedTime * enemies.difficulty >= enemies.timeBeforeRespawn)
    {
        enemies.enemiesList.push_back(InitEnemy(enemies.enemiesList.size() + 1, enemies.circleCenter, rad));
        enemies.elapsedTime = 0;
    }
}

void Enemies::deleteAll()
{
    std::list<Enemy*>::iterator it = this->enemiesList.begin();
    for (int i = 0; i < this->enemiesList.size(); i++)
    {
        it = this->enemiesList.erase(it);
    }
}