#include "Bullet.h"

void InitBullet(Bullet* pBullet)
{
	pBullet->bulletShape.setRadius(pBullet->bulletSize);
	pBullet->bulletShape.setFillColor(sf::Color::Magenta);
	pBullet->bulletShape.setOrigin(pBullet->bulletSize, pBullet->bulletSize);
	pBullet->bulletShape.setPosition({ 100,100 });
}
