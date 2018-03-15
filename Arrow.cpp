#include "Arrow.h"

Arrow::Arrow(sf::Vector2i mouseP,sf::Vector2i mouse, sf::Vector2f poczatek, sf::Vector2i winSize)
{
	rect.setSize(sf::Vector2f(1, 50));
	rect.setOrigin(sf::Vector2f(0.5, 25));
	rect.setPosition(sf::Vector2f(poczatek.x, poczatek.y));
	rect.setFillColor(sf::Color::Red);
	isHit = false;
	float X = (mouseP.x - mouse.x) / (0.34*winSize.x);
	float Y = (mouseP.y - mouse.y) / (0.34*winSize.y);
	if (X>1)
		X = 1;
	if (X<-1)
		X = -1;
	if (Y>1)
		Y = 1;
	if (Y<-1)
		Y = -1;
	cst_veloc = sf::Vector2f(8 * X, 8 * Y);
}

void Arrow::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->rect, state);
}

void Arrow::update(sf::Vector2i winSize)
{
	if (!(rect.getPosition().y + rect.getSize().y/2 >= winSize.y) && !isHit) {
		rect.setRotation(-atan(cst_veloc.x / cst_veloc.y) * 180 / M_PI);
		rect.move(cst_veloc);
		cst_veloc.y += 0.035;
	}
}

void Arrow::hitting()
{
	isHit = true;
}

bool Arrow::isInterecting(Arrow& arrow, Player& player)
{
	if (arrow.rect.getGlobalBounds().intersects(player.rect.getGlobalBounds()))
	{
		if (arrow.isHit == false)
		{
			arrow.isHit = true;
			player.playerHP -= 1;
		}
		return true;
	}
	return false;
}