#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Player.h"
#include "Wind.h"

class Arrow : public sf::Drawable
{
public:
	Arrow() = default;
	Arrow(sf::Vector2i mouseP, sf::Vector2i mouse, sf::Vector2f poczatek, sf::RenderWindow& myWindow, sf::Clock myClock);
	~Arrow() = default;
	void update(sf::RenderWindow& myWindow, sf::View& view1, sf::Clock myClock,Wind myWind);
	bool isInterecting(Player& player);//funkcja sprawdzajaca zywej strzaly z graczem podanym jako argument

	bool getisHit();
	void setisHit(bool isHit);

	bool getisDead();
	void setisDead(bool isDead);

	sf::Vector2f getarrowVelocity();
	void setarroVelocity(sf::Vector2f arrowVelocity);
	
	sf::Sprite getmysprite();
private:
	bool isHit;
	bool isDead;
	sf::Time timeOfRun;
	sf::Vector2f velocityZero;
	sf::Time momentZero;
	sf::Texture* mytexture = new sf::Texture;
	sf::Sprite mysprite;
	sf::Vector2f arrowVelocity;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const;
};

