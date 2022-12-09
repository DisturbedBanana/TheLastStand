#include "BulletSpawner.h"

void InitBulletSpawner(BulletSpawner& bulletSpawner)
{
	bulletSpawner.pList = CreateBulletList();
}

List* CreateBulletList()
{
	List* pList = new List;
	pList->pFirst = nullptr;
	pList->count = 0;
	return pList;
}

Bullet* GetBulletAt(List* pList, int index)
{
	Bullet* pBullet = pList->pFirst;
	for (int i = 0; i < index; i++)
	{
		pBullet = pBullet->next;
	}
	return pBullet;
}

void AddBullet(List* pList, sf::Vector2f position, float playerAngle)
{
	Bullet* pBullet = new Bullet;
	pBullet->position = position;
	pBullet->bulletShape.setPosition(pBullet->position);
	InitBullet(pBullet, playerAngle);
	
	if (pList->pFirst == nullptr)
	{
		pList->pFirst = pBullet;
	}
	else
	{
		Bullet* pLast = GetBulletAt(pList, pList->count - 1);
		pLast->next = pBullet;
		pBullet->previous = pLast;
	}
	pList->count++;
}

void RenderBullets(List* pList, sf::RenderWindow& window)
{
	Bullet* pBullet = pList->pFirst;
	for (int i = 0; i <= (pList->count - 1); i++)
	{
		window.draw(pBullet->bulletShape);
		pBullet = pBullet->next;
	}
}

void RemoveBullet(List* pList, int index)
{
	Bullet* pBullet = GetBulletAt(pList, index);
	if (pBullet->previous != nullptr)
	{
		pBullet->previous->next = pBullet->next;
	}
	else
	{
		pList->pFirst = pBullet->next;
	}
	
	if (pBullet->next != nullptr)
	{
		pBullet->next->previous = pBullet->previous;
	}
	delete pBullet;
	pList->count--;
}

void UpdateBullets(List* pList, float deltaTime)
{
	if (pList->pFirst != nullptr)
	{
		Bullet* pBullet = pList->pFirst;

		for (int i = 0; i <= (pList->count - 1); i++)
		{
			pBullet->position += pBullet->direction * deltaTime * pBullet->bulletSpeed;
			pBullet->bulletShape.setPosition(pBullet->position);
			pBullet = pBullet->next;
		}
	}
}

void IsBulletOut(List* bulletList, float circleRadius, sf::Vector2f center)
{
	for (int i = 0; i <= bulletList->count - 1; i++)
	{
		Bullet* pBullet = GetBulletAt(bulletList, i);
		sf::Vector2f centerToEnemy = pBullet->position - center;
		float sqDistance = (centerToEnemy.x * centerToEnemy.x) + (centerToEnemy.y * centerToEnemy.y);

		if (sqDistance - (circleRadius * circleRadius) >= 0) //sur ou à l'exterieur
			RemoveBullet(bulletList, i);
	}
}

void RemoveAllBullets(List* bulletList)
{
	for (int i = 0; i < bulletList->count; i++)
	{
		RemoveBullet(bulletList, i);
	}
}
