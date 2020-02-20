#pragma once
#include "Framework/GameObject.h"
#include "Framework/Vector.h"

class Ball : public GameObject
{
public:
	Ball();
	~Ball();

	void update(float dt) override;

protected:
	float speed;
	float scale;
	sf::Vector2f pointA;
	sf::Vector2f pointB;
	sf::Vector2f direction;
};