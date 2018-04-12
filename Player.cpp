#include "Player.h"

Player::Player(float xp, float yp)
{
	if (myPlayerTexture->loadFromFile("Player.png"))
		std::cout << "Constructor strzaly" << std::endl;
	myPlayerTexture->setSmooth(true);
	myPlayerSprite.setTexture(*myPlayerTexture);
	myPlayerSprite.setOrigin(myPlayerTexture->getSize().x / 2, myPlayerTexture->getSize().y / 2);
	myPlayerSprite.setScale(1.0f, 1.0f);
	myPlayerSprite.setPosition(sf::Vector2f(xp, yp));

	/*rect.setSize(sf::Vector2f(25, 300));
	rect.setOrigin(sf::Vector2f(6, 40));
	rect.setPosition(sf::Vector2f(xp, yp));
	rect.setFillColor(sf::Color::Blue);
	rect.setOutlineColor(sf::Color::Red);
	rect.setOutlineThickness(3);*/

	playerHP = 10;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->myPlayerSprite, state);///////
}

sf::Vector2f Player::getPosition()//////////
{
	return myPlayerSprite.getPosition();
}

int Player::getplayerHP()
{
	return playerHP;
}

void Player::setplayerHP(int playerHP)
{
	this->playerHP = playerHP;
}

void Player::decreaseHP()
{
	playerHP--;
}

void Player::playerFlip()
{
	myPlayerSprite.setScale(-1.0f, 1.0f);
}

sf::Sprite Player::getmyPlayerSprite()
{
	return myPlayerSprite;
}


