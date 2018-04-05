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
#include "Bot.h"


class SinglePlayer
{
public:
	//friend class SoundandMusic;
	SinglePlayer() = delete;
	SinglePlayer(sf::RenderWindow& myWindow, DataOfOptions & doo, Camera & myCamera);
	//~SinglePlayer() = default;
	~SinglePlayer();
	void Run(sf::RenderWindow& myWindow, DataOfOptions & doo, Camera & myCamera);
private:

	sf::Font myFont;
	sf::Text hpTexts[3];
	//std::ostringstream windStream;
	std::string wordOfWind;

	Wind *myWind;
	SoundandMusic *mySounds;
	Bot *myBot;
	sf::View view1;
	Player gracz1;
	Player gracz2;
	sf::Clock myClock;
	sf::Time myTime;
	sf::Time botWaits;
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

