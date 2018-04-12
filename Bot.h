#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include<time.h>

class Bot
{
public:
	Bot(int playerPosition, float dificultyLevelPlus, float difficultyLevelMinus);
	~Bot() = default;
	void aim();

	bool getwaiting();
	void setwaiting(bool waiting);

	bool getgoodAim();
	void setgoodAim(bool goodAim);

	bool getcheetWindOff();
	void setcheetWindOff(bool cheetWindOff);

	sf::Vector2i getshoot();
	void setshoot(sf::Vector2i shoot);

	int getxLastArrow();
	void setxLastArrow(int xLastArrow);
private:
	sf::Vector2i shoot;
	bool waiting = 1;
	bool isItFirst = 1;
	bool isItSecond = 0;
	bool cheetWindOff = 0; //czy wiatr dziala na strzaly bota
	bool goodAim = 0;   // informuje bota czy trafil
	int step = 100;		// domyslna wartosc zmieniania sily strzalu bota po nietrafionym strzale
	//mnozniki dla poziomow trudnosci
	float multPlus;     //1.1 dla latwego, 1.5 dla normalnego, 2.0 dla trudnego
	float multMinus;    // 0.9 dla latwego, 0.5 dla normalnego, 0.4 dla trudnego

	int xPosition;	    //przekazywana w konstruktorze pozycja gracza
	int xLastArrow;     // pozycja ostatniej strzaly

	sf::Vector2i prev;  //poprzedni strzal-sila
	int xPrev;          //lokalizacja poprzedniego strzalu
	sf::Vector2i next;  //kolejny strzal-sila
	int xNext;			//lokalizacja aktualnego strzalu
};