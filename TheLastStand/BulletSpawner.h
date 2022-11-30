#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Bullet.h"

struct List 
{
	Bullet* pFirst;
	int count;
};

struct BulletSpawner
{
	List* pList;
};

void InitBulletSpawner(BulletSpawner& bulletSpawner);
List* CreateBulletList();
Bullet* GetBulletAt(List* pList, int index);
void AddBullet(List* pList, sf::Vector2f position, sf::Vector2f direction);
void RenderBullets(List* pList, sf::RenderWindow& window);
void RemoveBullet(List* pList, int index);
