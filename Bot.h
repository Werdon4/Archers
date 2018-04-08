#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include<time.h>

class Bot
{
public:
	friend class SinglePlayer;
	//bot() = delete;
	Bot(int playerPosition, float dificultyLevelPlus,float difficultyLevelMinus);
	//Bot(void);
	~Bot() {
		std::cout << "Bot konczy dzialanie\n";
	};
	//void update(sf::Vector2u winSize, sf::View& view1, sf::Clock myClock, Wind myWind);
	//bool isEnabled;
	void aim();
	sf::Vector2i shoot;
	bool waiting = 1;
private:
	bool isItFirst = 1;
	bool isItSecond = 0;
	bool cheetWindOff = 0;
	bool goodAim = 0;
	int step = 100;		// tzw. NIECO
	float multPlus;
	float multMinus;
	int xPosition;	//przekazywana w konstruktorze pozycja gracza
	int xLastArrow;

	sf::Vector2i prev;			//poprzedni strzal
	bool locationPrev;			//lokalizacja strzalu      ( x  Player) 0   (Player x) 1
	int xPrev;

	sf::Vector2i next;			//kolejny strzal
								//bool locationNext;			//lokalizacja strzalu   (x Player) 0   (Player x) 1
	int xNext;
};