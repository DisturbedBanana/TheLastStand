#include "Game.h"
#include <windows.h>

const float WALL_THICKNESS = 6.f;
const float CIRCLE_THICKNESS = 6.f;

void InitScore(sf::Text& score, sf::Font& font);
std::string GetAppPath();
void BulletsCollisions(Game& game, List* pBulletList, std::list<Enemy*> enemyList);

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
    
    InitScore(game.score, game.font); 
	InitPlayer(game.player, sf::Vector2f{ position.x, position.y - circleSize });
    InitBulletSpawner(game.bulletSpawner);
    InitEnemies(game.ennemies, game.circleShape.getPosition(), circleSize);
}

void InitScore(sf::Text& score, sf::Font& font) {

    font.loadFromFile(GetAppPath() + "arial.ttf");
    score.setString("example");
    score.setPosition(100, 100);
    score.setCharacterSize(30);
    score.setFillColor(sf::Color::Green);
    score.setFont(font);
}

std::string GetAppPath() {
    char cExeFilePath[256];
    GetModuleFileNameA(NULL, cExeFilePath, 256);
    std::string exeFilePath = cExeFilePath;
    int exeNamePos = exeFilePath.find_last_of("\\/");
    std::string appPath = exeFilePath.substr(0, exeNamePos + 1);
    return appPath;
}

void UpdateGame(Game& game, float deltaTime)
{
    if (!game.isLose)
    {
        UpdatePlayer(game.player, deltaTime, game.circleSize, game.circleShape.getPosition());
        UpdateEnemies(game.ennemies, deltaTime);
        EnemiesTimer(deltaTime, game.ennemies, game.circleSize);
        
        //game.isLose = IsEnemyOut(game.ennemies, game.circleShape.getRadius());
        
        //game.ennemies.ennemiesTimer(deltaTime);
    }
   
    UpdateBullets(game.bulletSpawner.pList, deltaTime);
	BulletsCollisions(game, game.bulletSpawner.pList, game.ennemies.all);

}

void RenderGame(Game& game, sf::RenderWindow& window)
{
    if (!game.isLose)
    {
        window.draw(game.shape);
        window.draw(game.circleShape);
        RenderPlayer(game.player, window);
        RenderBullets(game.bulletSpawner.pList, window);
        RenderEnemies(game.ennemies, window);
        window.draw(game.score);
    }
    else 
    {
        if (game.firstTime)
        {
            std::string temp = game.score.getString();
            temp = "15498552";
            game.score.setPosition(window.getSize().x / 2.0f - 400, window.getSize().y / 2.0f - 60);
            game.score.setCharacterSize(50);
            game.score.setString("Vous avez perdu,votre score : \n" + temp + " points"); //rajouter le nombre de score
            game.ennemies.deleteAll();
            game.firstTime = false;
        }
        window.draw(game.score);

        
        
    }
}

void ReceivePlayerInput(Game& game, float axis)
{
    SetPlayerDirection(game.player, axis);
}

void BulletsCollisions(Game& game, List* pBulletList, std::list<Enemy*> enemyList) 
{
    float bulletRadius = 9;
    for (int i = 0; i <= pBulletList->count - 1; i++) 
	{
		Bullet* pBullet = GetBulletAt(pBulletList, i);
		for (std::list<Enemy*>::iterator it = enemyList.begin(); it != enemyList.end(); it++)
		{
			float xMin = (*it)->position.x - (*it)->size / 2 - bulletRadius;
			float xMax = (*it)->position.x + (*it)->size / 2 + bulletRadius;
			float yMin = (*it)->position.y - (*it)->size / 2 - bulletRadius;
			float yMax = (*it)->position.y + (*it)->size / 2 + bulletRadius;
			
            if (((pBullet->position.x > xMin && pBullet->position.x < xMax) && (pBullet->position.y < yMin && pBullet->position.y < yMax)) /*|| pBullet->position == game.circleShape.getPosition()*/)
            {
                std::cout << "collision" << std::endl;
            }
		}
	}
}
