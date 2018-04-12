#include "Arrow.h"

Arrow::Arrow(sf::Vector2i mouseP, sf::Vector2i mouse, sf::Vector2f poczatek, sf::RenderWindow& myWindow, sf::Clock myClock)
{
	if (mytexture->loadFromFile("Arrow.png"))
		std::cout << "Constructor strzaly" << std::endl;
	momentZero = myClock.getElapsedTime();
	mytexture->setSmooth(true);
	mysprite.setTexture(*mytexture);
	mysprite.setPosition(sf::Vector2f(poczatek.x, poczatek.y - 120));
	//mysprite.setScale(0.67, 0.67);
	mysprite.setOrigin(8, 68);

	isHit = false;
	isDead = false;
	float X = (mouseP.x - mouse.x) / (0.34*myWindow.getSize().x);
	float Y = (mouseP.y - mouse.y) / (0.34*myWindow.getSize().y);
	if (X>1)
		X = 1;
	if (X<-1)
		X = -1;
	if (Y>1)
		Y = 1;
	if (Y<-1)
		Y = -1;
	arrowVelocity = sf::Vector2f(20 * X, 20 * Y);
	velocityZero = arrowVelocity;
}

void Arrow::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(mysprite);
}

void Arrow::update(sf::RenderWindow& myWindow, sf::View& view1, sf::Clock myClock, Wind myWind)
{
	timeOfRun = (myClock.getElapsedTime() - momentZero);
	if (!(mysprite.getPosition().y >= myWindow.getSize().y - mytexture->getSize().y) && !isHit) {
		if (-atan(arrowVelocity.x / arrowVelocity.y) * 180 / M_PI < 0)
			mysprite.setRotation(90 + (90 - atan(arrowVelocity.x / arrowVelocity.y) * 180 / M_PI));
		else
			mysprite.setRotation(-atan(arrowVelocity.x / arrowVelocity.y) * 180 / M_PI);
		if (arrowVelocity.x < 0)
			mysprite.rotate(180);

		mysprite.move(arrowVelocity);
		view1.setCenter(mysprite.getPosition());
		double gravity = 9.81;

		if (myWind.getmyuseWind()) {
			arrowVelocity.y = myWind.getv2iwind().y + velocityZero.y + gravity * (timeOfRun.asSeconds()); // V= wiatr + v0 - g*t
			arrowVelocity.x = myWind.getv2iwind().x + velocityZero.x; // Vx+ wiatr
		}										 //double gravity = 0.15;
		else {
			arrowVelocity.y = velocityZero.y + gravity * (timeOfRun.asSeconds());
		}
	}
	else {
		isHit = true;

	}
}

bool Arrow::isInterecting(Player& player)
{

	if (mysprite.getGlobalBounds().intersects(player.getmyPlayerSprite().getGlobalBounds()))
	{
		isHit = true;
		return true;
	}
	return false;
}

bool Arrow::getisHit()
{
	return isHit;
}

void Arrow::setisHit(bool isHit)
{
	this->isHit = isHit;
}

bool Arrow::getisDead()
{
	return isDead;
}

void Arrow::setisDead(bool isDead)
{
	this->isDead = isDead;
}

sf::Vector2f Arrow::getarrowVelocity()
{
	return arrowVelocity;
}

void Arrow::setarroVelocity(sf::Vector2f arrowVelocity)
{
	this->arrowVelocity = arrowVelocity;
}

sf::Sprite Arrow::getmysprite()
{
	return mysprite;
}
