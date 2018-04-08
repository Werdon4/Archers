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
	Arrow(sf::Vector2i mouseP, sf::Vector2i mouse, sf::Vector2f poczatek, sf::RenderWindow& myWindow, sf::Clock myClock);///zmieni³em argumenty na wektroy zeby by³o ³atwiej mouseP - poczatek mouse- koniec, wektor poczatek to wektor z ktorego strzala ma wylatwyac na razie da³em ze jest to getPosition obiektu gracz
																														 //~Arrow() = default;
	~Arrow() {
		std::cout << "Strzala zostala zniszczona\n";
	};
	void update(sf::RenderWindow& myWindow, sf::View& view1, sf::Clock myClock,Wind myWind);
	bool isInterecting(Player& player);///funkcja przeniesiona z maina do klasy
	bool isHit;
	bool isDead;
	sf::Vector2f cst_veloc;
private:
	sf::Time timeOfRun;
	sf::Vector2f velocityZero;
	sf::Time momentZero;
	sf::Texture* mytexture = new sf::Texture;
	sf::Sprite mysprite;
	//sf::Vector2f cst_veloc;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const;
};

