#include "Ball.h"

Ball::Ball() {
	speed = 0;
	scale = 100;
}

Ball::~Ball() {

}

void Ball::update(float dt) {
	pointA = sf::Vector2f(getPosition().x, getPosition().y);
	pointB = sf::Vector2f(input->getMouseX(), input->getMouseY());

	speed += 3 * dt;
	direction = pointB - pointA;
	direction = Vector::normalise(direction);
	velocity = (direction * speed) * scale;
	setPosition(getPosition() + (velocity * dt));

	if (Vector::magnitude(pointB - getPosition()) <= 5.f) {
		setPosition(pointB);
		speed = 0;
	}
}