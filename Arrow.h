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
	friend class DeadArrow;
	friend class Wind;
	friend class SinglePlayer;
	Arrow() = default;
	//Arrow() = delete;
	Arrow(sf::Vector2i mouseP, sf::Vector2i mouse, sf::Vector2f poczatek, sf::RenderWindow& myWindow, sf::Clock myClock);
	~Arrow() = default;
	void update(sf::RenderWindow& myWindow, sf::View& view1, sf::Clock myClock,Wind myWind);
	bool isInterecting(Player& player);//funkcja sprawdzajaca zywej strzaly z graczem podanym jako argument
	bool isHit;
	bool isDead;
	sf::Vector2f arrowVelocity;
private:
	sf::Time timeOfRun;
	sf::Vector2f velocityZero;
	sf::Time momentZero;
	sf::Texture* mytexture = new sf::Texture;
	sf::Sprite mysprite;
	//sf::Vector2f arrowVelocity;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const;
};

