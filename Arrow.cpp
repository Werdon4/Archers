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
	//std::cout << "licznik x :" << mouseP.x - mouse.x << " mianownik x :" << (0.34*myWindow.getSize().x) << std::endl;
	//std::cout<< "licznik y :"<< mouseP.y - mouse.y<<" mianownik y :"<< (0.34*myWindow.getSize().y) << std::endl;
	if (X>1)
		X = 1;
	if (X<-1)
		X = -1;
	if (Y>1)
		Y = 1;
	if (Y<-1)
		Y = -1;
	cst_veloc = sf::Vector2f(20 * X, 20 * Y);
	velocityZero = cst_veloc;
}

void Arrow::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(mysprite);
}

void Arrow::update(sf::RenderWindow& myWindow, sf::View& view1, sf::Clock myClock, Wind myWind)
{
	timeOfRun = (myClock.getElapsedTime() - momentZero);
	if (!(mysprite.getPosition().y >= myWindow.getSize().y - mytexture->getSize().y) && !isHit) {
		if (-atan(cst_veloc.x / cst_veloc.y) * 180 / M_PI < 0)
			mysprite.setRotation(90 + (90 - atan(cst_veloc.x / cst_veloc.y) * 180 / M_PI));
		else
			mysprite.setRotation(-atan(cst_veloc.x / cst_veloc.y) * 180 / M_PI);
		if (cst_veloc.x < 0)
			mysprite.rotate(180);

		mysprite.move(cst_veloc);
		//view1.move(cst_veloc);
		view1.setCenter(mysprite.getPosition());
		double gravity = 9.81;

		if (myWind.myuseWind) {
			cst_veloc.y = myWind.v2iwind.y + velocityZero.y + gravity * (timeOfRun.asSeconds()); // V= wiatr + v0 - g*t
			cst_veloc.x = myWind.v2iwind.x + velocityZero.x; // Vx+ wiatr
		}										 //double gravity = 0.15;
		else {
			cst_veloc.y = velocityZero.y + gravity * (timeOfRun.asSeconds());
			//cst_veloc.x = velocityZero.x;
		}
	}
	else {
		isHit = true;

	}
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
