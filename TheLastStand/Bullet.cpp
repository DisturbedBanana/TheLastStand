#include "Bullet.h"

void InitBullet(Bullet* pBullet, float playerAngle)
{
	pBullet->bulletShape.setRadius(pBullet->bulletSize);
	pBullet->bulletShape.setFillColor(sf::Color::Magenta);
	pBullet->bulletShape.setOrigin(pBullet->bulletSize, pBullet->bulletSize);
	pBullet->bulletShape.setPosition({ 100,100 });

	sf::Vector2f deltaVector;
	float bulletAngle = playerAngle + 180;
	deltaVector.x = cos(bulletAngle / 360 * 2 * 3.1415);
	deltaVector.y = sin(bulletAngle / 360 * 2 * 3.1415);
	pBullet->direction = deltaVector;
}
