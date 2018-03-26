#include "Arrow.h"

Arrow::Arrow(sf::Vector2i mouseP, sf::Vector2i mouse, sf::Vector2f poczatek, sf::Vector2u winSize, sf::Clock myClock)
{
	if (mytexture->loadFromFile("Arrow.png"))
		std::cout << "Constructor strzaly" << std::endl;
	momentZero = myClock.getElapsedTime();
	mytexture->setSmooth(true);
	mysprite.setTexture(*mytexture);
	mysprite.setPosition(sf::Vector2f(poczatek.x, poczatek.y-120));
	//mysprite.setScale(0.67, 0.67);
	mysprite.setOrigin(8, 68);	

	isHit = false;
	isDead = false;
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
	cst_veloc = sf::Vector2f(20 * X, 20 * Y);
	velocityZero = cst_veloc.y;
}

void Arrow::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(mysprite);
}

void Arrow::update(sf::Vector2u winSize, sf::View& view1, sf::Clock myClock)
{
	timeOfRun = (myClock.getElapsedTime() - momentZero);
	///mytexture.loadFromFile("Arrow.png");	///to powodowalo sciny
	//mysprite.setTexture(mytexture);	//deklaracja textury jako wskaŸnik rozwi¹za³a problem
	if (!(mysprite.getPosition().y >= winSize.y - mytexture->getSize().y) && !isHit) {
		if (-atan(cst_veloc.x / cst_veloc.y) * 180 / M_PI < 0)
			mysprite.setRotation(90 + (90 - atan(cst_veloc.x / cst_veloc.y) * 180 / M_PI));
		else
			mysprite.setRotation(-atan(cst_veloc.x / cst_veloc.y) * 180 / M_PI);
		if (cst_veloc.x < 0)
			mysprite.rotate(180);

		mysprite.move(cst_veloc);
		///	view1.move(cst_veloc);
		view1.setCenter(mysprite.getPosition());
		double gravity = 9.81;
		cst_veloc.y = velocityZero + gravity * (timeOfRun.asSeconds()); // V= v0 - g*t
		//double gravity = 0.15;
		//cst_veloc.y +=gravity;
	}
	else {
		isHit = true;

	}
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
