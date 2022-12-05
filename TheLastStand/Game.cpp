#include "Game.h"
#include <windows.h>

const float WALL_THICKNESS = 6.f;
const float CIRCLE_THICKNESS = 6.f;

void InitScore(sf::Text& score, sf::Font& font);
std::string GetAppPath();

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
    UpdatePlayer(game.player, deltaTime, game.circleSize, game.circleShape.getPosition());
    UpdateEnemies(game.ennemies, deltaTime);
    if (IsEnemyOut(game.ennemies, game.circleShape.getRadius()))
    {
        printf("game over");
        //game over

    }

    //game.ennemies.ennemiesTimer(deltaTime);
    EnemiesTimer(deltaTime, game.ennemies, game.circleSize);

}

void RenderGame(Game& game, sf::RenderWindow& window)
{
    window.draw(game.shape);
    window.draw(game.circleShape);
    RenderPlayer(game.player, window);
    RenderBullets(game.bulletSpawner.pList, window);
    RenderEnemies(game.ennemies, window);
	window.draw(game.score);
}

void ReceivePlayerInput(Game& game, float axis)
{
    SetPlayerDirection(game.player, axis);
}

void Shoot(Game& game)
{
    AddBullet(game.bulletSpawner.pList, sf::Vector2f{ 100,100 }, game.circleShape.getPosition());
}
