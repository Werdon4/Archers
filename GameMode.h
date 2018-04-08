#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <iostream>
#include "Player.h"
#include "Arrow.h"
#include "DeadArrow.h"
#include "Background.h"
#include "Camera.h"
//#include "Wind.h"
#include <string>
#include "SoundandMusic.h"
//#include <sstream>
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
	sf::Text hpTexts[3];
	//std::ostringstream windStream;
	std::string wordOfWind;

	Wind* myWind;
	SoundandMusic* mySounds;
	///bot
	sf::View view1;
	Player gracz1;
	Player gracz2;
	sf::Clock myClock;
	sf::Time myTime;
	///botwaits
	std::vector<Player> players;
	Arrow liveArrow;
	std::vector<DeadArrow> deadarrows;
	int kolejnosc = 0;
	int checker = 0;
	sf::Vector2f windPosition;
	sf::Vector2i aim1, aimNow;
	//bool firsttime = 0;
	bool letShoot = 1;
};

