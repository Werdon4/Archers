#include "Player.h"

Player::Player(float xp, float yp)
{
	rect.setSize(sf::Vector2f(12, 50));
	rect.setOrigin(sf::Vector2f(6, 40));
	rect.setPosition(sf::Vector2f(xp, yp));
	rect.setFillColor(sf::Color::Blue);
	rect.setOutlineColor(sf::Color::Red);
	rect.setOutlineThickness(3);
	playerHP = 10;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->rect, state);
}

void Player::hitting()
{
	playerHP--;
}

sf::Vector2f Player::getPosition()
{
	return rect.getPosition();
}