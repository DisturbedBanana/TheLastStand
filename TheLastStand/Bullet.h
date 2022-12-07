#pragma once
#include <SFML/Graphics.hpp>

struct Bullet
{
	sf::CircleShape bulletShape;
	sf::Vector2f position;
	sf::Vector2f direction;
	float bulletSize = 9;
	float bulletSpeed = 500;

	Bullet* previous = nullptr;
	Bullet* next = nullptr;
};

void InitBullet(Bullet* bullet, float playerAngle);

