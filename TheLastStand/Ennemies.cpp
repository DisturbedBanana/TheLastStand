#include "Ennemies.h"
#include <iostream>



bool IsEnemyOut(Enemies& ennemies, float circleRadius)
{
    std::list<Enemy*>::iterator it = ennemies.all.begin();
    for (int i = 0; i < ennemies.all.size(); i++)
    {
        
        float distance = ((*it)->position.x * (*it)->position.x) + ((*it)->position.y * (*it)->position.y);
        
        if (distance - (circleRadius * circleRadius) <= 0) //sur ou à l'exterieur
            return true;
        it++;
    }

        return false;

}
void RenderEnemies(Enemies& ennemies, sf::RenderWindow& window)
{
    std::list<Enemy*>::iterator it = ennemies.all.begin();
    for (int i = 0; i < ennemies.all.size(); i++)
    {
        window.draw((*it)->ennemisShape);
        it++;
    }
}
void InitEnemies(Enemies& ennemies, sf::Vector2f pos, float rad)
{
    ennemies.circleCenter = pos;
    ennemies.all.push_back(InitEnemy(1, pos, rad));
}
void UpdateEnemies(Enemies& ennemies, float deltaTime)
{
    std::list<Enemy*>::iterator it = ennemies.all.begin();
    for (int i = 0; i < ennemies.all.size(); i++)
    {
		float deltaX = (*it)->moveSpeed * deltaTime * (*it)->direction.x;
		float deltaY = (*it)->moveSpeed * deltaTime * (*it)->direction.y;
        (*it)->position.x += deltaX;
        (*it)->position.y += deltaY;
        (*it)->ennemisShape.setPosition((*it)->position);
        it++;
    }
}




void EnemiesTimer(float deltaTime, Enemies& enemies, float rad)
{
    enemies.elapsedTime += deltaTime;

    if (enemies.elapsedTime >= enemies.timeBeforeRespawn)
    {
        std::cout << "spawn" << std::endl;
        enemies.all.push_back(InitEnemy(enemies.all.size() + 1, enemies.circleCenter, rad));
        enemies.elapsedTime = 0;
    }
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
    float r = rad * sqrt(rand() % 1);
    float theta = rand() % 1 * 2 * 3.14159265358979323846;
    ennemy->direction.x = circleCenter.x + r * cos(theta);
    ennemy->direction.y = circleCenter.y + r * sin(theta);
    return ennemy;
}


void Enemies::deleteAll()
{
    std::list<Enemy*>::iterator it = this->all.begin();
    for (int i = 0; i < this->all.size(); i++)
    {
        it = this->all.erase(it);
    }
}


