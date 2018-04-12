#pragma once
#include "Bot.h"
#include "GameMode.h"

class SinglePlayer : public GameMode
{
public:
	SinglePlayer(sf::RenderWindow& myWindow, DataOfOptions & doo, Camera & myCamera);
	~SinglePlayer();
	void Run(sf::RenderWindow& myWindow, DataOfOptions & doo, Camera & myCamera) override;
private:
	Bot *myBot;
	sf::Time botWaits;
};

