#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Zombie : public GameObject
{
public:
	Zombie(sf::RenderWindow* hwnd);
	~Zombie();

	void update(float dt) override;
	void handleInput(float dt);

protected:
	Animation walk;

	float scale;
	bool isJumping;

	sf::Vector2f jumpVector;
	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;
	sf::RenderWindow* window;
};

