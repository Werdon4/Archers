#pragma once
#include "GameMode.h"

class MultiPlayer : public GameMode
{
public:
	MultiPlayer(sf::RenderWindow& myWindow,DataOfOptions & doo,Camera & myCamera);
	~MultiPlayer();
	void Run(sf::RenderWindow& myWindow,DataOfOptions & doo,Camera & myCamera);
};

