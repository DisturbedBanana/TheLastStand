#include "Ennemies.h"



bool IsEnnemyOut(Ennemies& ennemies, float circleRadius)
{
    std::list<Ennemy*>::iterator it = ennemies.all.begin();
    for (int i = 0; i < ennemies.all.size(); i++)
    {
        
        float distance = ((*it)->position.x * (*it)->position.x) + ((*it)->position.y * (*it)->position.y);
        
        if (distance - (circleRadius * circleRadius) >= 0) //sur ou à l'exterieur
            return true;
        it++;
    }

        return false;

}
void RendreEnnemies(Ennemies& ennemies, sf::RenderWindow window)
{
    std::list<Ennemy*>::iterator it = ennemies.all.begin();
    for (int i = 0; i < ennemies.all.size(); i++)
    {
        window.draw((*it)->ennemisShape);
        it++;
    }
}
void InitEnnemies(Ennemies& ennemies, sf::Vector2f pos)
{
    ennemies.circleCenter = pos;
    ennemies.all.push_back(InitEnemy(1));
}
void UpdateEnnemies(Ennemies& ennemies, float deltaTime)
{

}




void Ennemies::ennemiesTimer()
{
    sf::Clock timer;


    sf::Time time1 = timer.getElapsedTime();
    if (time1 > timeBeforeRespawn)
    {
        
        all.push_back(InitEnemy(all.size() + 1, this->circleCenter));
        time1 = timer.restart();
    }


}

Ennemy* InitEnemy(int index, sf::Vector2f circleCenter)
{
    Ennemy* ennemy = new Ennemy;
    ennemy->position = ennemy->circleCenter;
    ennemy->ennemisShape.setPosition(ennemy->position);
    ennemy->ennemisShape.setRadius(ennemy->size);
    ennemy->ennemisShape.setOrigin(ennemy->size, ennemy->size);
    ennemy->ennemisShape.setOutlineColor(sf::Color::Green);
    ennemy->ennemisShape.setFillColor(sf::Color::Green);
    ennemy->ennemisShape.setOutlineThickness(2.f);
    ennemy->index = index;

    return ennemy;
}


