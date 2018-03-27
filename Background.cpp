#include "Background.h"



Background::Background(sf::Vector2u myWinSize)
{
	licznik = 0;
	if (!forestTexture.loadFromFile("forest.jpg"))
		std::cout << "Blad las!" << std::endl;
	if (!skyTexture.loadFromFile("sky.jpg"))
		std::cout << "Blad niebo!" << std::endl;
	if (!grassTexture.loadFromFile("grass.jpg"))
		std::cout << "Blad trawa!" << std::endl;

	for (int i = 0; i < 13; i++,licznik++)
	{
		tabSprite.push_back(mySprite);
		tabSprite[licznik].setTexture(forestTexture);
		tabSprite[licznik].setPosition(-6 * float(myWinSize.x) + i * float(myWinSize.x), 0);
	}
	for (int i = 0; i < 13; i++, licznik++)
	{
		tabSprite.push_back(mySprite);
		tabSprite[licznik].setTexture(skyTexture);
		tabSprite[licznik].setPosition(-6 * float(myWinSize.x) + i * float(myWinSize.x), -float(myWinSize.y));
	}
	for (int i = 0; i < 13; i++, licznik++)
	{
		tabSprite.push_back(mySprite);
		tabSprite[licznik].setTexture(skyTexture);
		tabSprite[licznik].setPosition(-6 * float(myWinSize.x) + i * float(myWinSize.x), -2*float(myWinSize.y));
	}
	for (int i = 0; i < 13; i++, licznik++)
	{
		tabSprite.push_back(mySprite);
		tabSprite[licznik].setTexture(grassTexture);
		tabSprite[licznik].setPosition(-6 * float(myWinSize.x) + i * float(myWinSize.x), float(myWinSize.y));
	}
}

/*void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < 15; i++) {
		target.draw(tabSprite[i]);
	}
}*/

void Background::displayGraphics(sf::RenderWindow& myWindow, std::vector<Player> players, Arrow liveArrow, std::vector<DeadArrow> deadarrows)
{
	for (int i = 0; i < 52; i++) {
		myWindow.draw(tabSprite[i]);
	}
	for (int i = 0; i<players.size(); i++)
	{
		myWindow.draw(players[i]);
	}
	if (!liveArrow.isDead) {
		myWindow.draw(liveArrow);
	}
	for (int i = 0; i < deadarrows.size(); i++) {
		myWindow.draw(deadarrows[i]);
	}
}

void Background::displayBackground(sf::RenderWindow& myWindow)
{
	for (int i = 0; i < 52; i++)
	{
		myWindow.draw(tabSprite[i]);
	}
}