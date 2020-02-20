#include "Zombie.h"
#include "Framework/Animation.h"

Zombie::Zombie(sf::RenderWindow* hwnd) {
	// Setup walk animation
	walk.addFrame(sf::IntRect(0, 0, 55, 108));
	walk.addFrame(sf::IntRect(55, 0, 55, 108));
	walk.addFrame(sf::IntRect(110, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108));
	walk.addFrame(sf::IntRect(220, 0, 55, 108));
	walk.addFrame(sf::IntRect(275, 0, 55, 108));
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108));
	walk.setFrameSpeed(1.f / 13.f);

	// Gravity
	scale = 100.0f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	jumpVector = sf::Vector2f(0, -4.0f) * scale;

	window = hwnd;
	isJumping = true;
}

Zombie::~Zombie() {

}

void Zombie::update(float dt) {
	walk.animate(dt);
	setTextureRect(walk.getCurrentFrame());

	// Gravity stuff
	
	if(getPosition().y >= window->getSize().y - 100){
		setPosition(getPosition().x, window->getSize().y - 101);
		stepVelocity= sf::Vector2f(0, 0);
		isJumping = false;
	}
	else {
		sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt; //ut+ 1/2at^2
		stepVelocity += gravity * dt; // v = u + at  note the += is not =
		setPosition(getPosition() + pos);// Check for collision with bottom of window
	}
}

void Zombie::handleInput(float dt) {
	if (input->isKeyDown(sf::Keyboard::D)) {
		move(75 * dt, 0);
		walk.setFlipped(false);
	}
	else if (input->isKeyDown(sf::Keyboard::A)) {
		move(-75 * dt, 0);
		walk.setFlipped(true);
	}

	if (input->isKeyDown(sf::Keyboard::W)) {
		if (!isJumping) {
			stepVelocity = jumpVector;
			isJumping = true;
		}
	}

	if (input->isMouseLDown())
	{
		stepVelocity = sf::Vector2f(0, 0);
		setPosition(input->getMouseX(), input->getMouseY());
	}
}