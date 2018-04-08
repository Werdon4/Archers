#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include<time.h>

class Bot
{
public:
	friend class SinglePlayer;
	Bot(int playerPosition, float dificultyLevelPlus, float difficultyLevelMinus);
	~Bot() = default;
	void aim();
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