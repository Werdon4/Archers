#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <iostream>
#include "Player.h"
#include "Arrow.h"
#include "DeadArrow.h"
#include "Background.h"
#include "Camera.h"
#include <string>
#include "SoundandMusic.h"
#include<iostream>

class GameMode
{
public:
	GameMode();
	//GameMode(sf::RenderWindow& myWindow, DataOfOptions & doo, Camera & myCamera);
	~GameMode();
	virtual void Run(sf::RenderWindow& myWindow, DataOfOptions & doo, Camera & myCamera)=0;
	void gameOver(sf::RenderWindow& myWindow, Background myBackground, bool playerOneWins);
protected:
	sf::Text endMessageTab[2];
	sf::Font myFont;
	sf::Text hpTexts[3];//HP 1 i 2 gracza + wartosci waitru w formie tekstu
	std::string wordOfWind;//tekst ktory przekazujemy tablicy do wyswietlenia
	Wind* myWind;
	SoundandMusic* mySounds;
	sf::View view1;
	Player player1;
	Player player2;
	sf::Clock myClock;
	sf::Time myTime;
	std::vector<Player> players;
	Arrow liveArrow;
	std::vector<DeadArrow> deadarrows;
	int sequence = 0;
	bool aimLineChecker = 0;
	sf::Vector2f windPosition;
	sf::Vector2i aimLineBegin, aimLineEnd;
	bool letShoot = 1;
};

