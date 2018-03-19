#include "Arrow.h"

Arrow::Arrow(sf::Vector2i mouseP, sf::Vector2i mouse, sf::Vector2f poczatek, sf::Vector2u winSize)
{
	if (mytexture.loadFromFile("Arrow.png"))
		std::cout << "Udalo sie!" << std::endl;
	mytexture.setSmooth(true);
	mysprite.setTexture(mytexture);
	mysprite.setPosition(sf::Vector2f(poczatek.x, poczatek.y-120));
	//mysprite.setScale(0.67, 0.67);
	mysprite.setOrigin(8, 68);
	
	//rect.setSize(sf::Vector2f(1, 50));
	//rect.setOrigin(sf::Vector2f(0.5, 25));
	//rect.setPosition(sf::Vector2f(poczatek.x, poczatek.y));
	//rect.setFillColor(sf::Color::Red);

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
	cst_veloc = sf::Vector2f(10 * X, 8 * Y);
}

void Arrow::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->mysprite, state);
}

void Arrow::update(sf::Vector2u winSize,sf::View& view1)
{
	mytexture.loadFromFile("Arrow.png");
	mysprite.setTexture(mytexture);
	if (!(mysprite.getPosition().y >= winSize.y - mytexture.getSize().y) && !isHit) {
		if (-atan(cst_veloc.x / cst_veloc.y) * 180 / M_PI < 0)
			mysprite.setRotation(90 + (90 - atan(cst_veloc.x / cst_veloc.y) * 180 / M_PI));
		else
			mysprite.setRotation(-atan(cst_veloc.x / cst_veloc.y) * 180 / M_PI);
		if (cst_veloc.x < 0)
			mysprite.rotate(180);

		mysprite.move(cst_veloc);
		view1.move(cst_veloc);
		cst_veloc.y += 0.035;
	}
	else
		isHit = true;
}

void Arrow::hitting()
{
	isHit = true;
}

bool Arrow::isInterecting(Player& player)
{

	if (mysprite.getGlobalBounds().intersects(player.rect.getGlobalBounds()))
	{
		isHit = true;
		return true;
	}
	return false;
}
