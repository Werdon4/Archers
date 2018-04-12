#include "GameMode.h"



GameMode::GameMode()
{
}


GameMode::~GameMode()
{
	mySounds->musicStop();
}

void GameMode::gameOver(sf::RenderWindow & myWindow, Background myBackground, bool playerOneWins)
{
	sf::Font myFont;
	myFont.loadFromFile("snap.ttf");
	myWindow.setView(sf::View(sf::Vector2f(960, 540), sf::Vector2f(1920, 1080)));
	sf::Text endMessage;
	sf::Text endButton;
	endMessage.setFont(myFont);
	endButton.setFont(myFont);
	sf::Event event;

	endMessage.setFillColor(sf::Color::White);
	endMessage.setCharacterSize(80);
	endMessage.setOutlineThickness(8);
	endMessage.setPosition(sf::Vector2f(myWindow.getSize().x*0.3, myWindow.getSize().y*0.1));

	endButton.setFillColor(sf::Color::Red);
	endButton.setCharacterSize(40);
	endButton.setOutlineThickness(5);
	endButton.setPosition(sf::Vector2f(myWindow.getSize().x*0.4, myWindow.getSize().y*0.8));
	endButton.setString("Powrot");

	if (playerOneWins) {
		endMessage.setString(endMessageTab[0].getString());
	}
	else {
		endMessage.setString(endMessageTab[1].getString());
	}

	while (true) {
		//////////////////Event handling
		while (myWindow.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Return:
				{
					return;
				}
				}
			}

		}
		//////////Window Render
		myWindow.clear();
		myBackground.displayBackground(myWindow);
		myWindow.draw(endMessage);
		myWindow.draw(endButton);
		myWindow.display();
	}
}
