#pragma once
#include <SFML/Graphics.hpp>

struct Bullet
{
	sf::CircleShape bulletShape;
	sf::Vector2f position;
	sf::Vector2f direction;
	float bulletSize = 4.f;
	float moveSpeed = 200.f;

	Bullet* previous = nullptr;
	Bullet* next = nullptr;
};

void InitBullet(Bullet* bullet);

