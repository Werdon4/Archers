#include "Background.h"



Background::Background(sf::RenderWindow& myWindow)
{
	spriteTabIterator = 0;
	if (!forestTexture.loadFromFile("forest.jpg"))
		std::cout << "Blad las!" << std::endl;
	if (!skyTexture.loadFromFile("sky.jpg"))
		std::cout << "Blad niebo!" << std::endl;
	if (!grassTexture.loadFromFile("grass.jpg"))
		std::cout << "Blad trawa!" << std::endl;

	for (int i = 0; i < 13; i++, spriteTabIterator++)
	{
		tabSprite.push_back(mySprite);
		tabSprite[spriteTabIterator].setTexture(forestTexture);
		tabSprite[spriteTabIterator].setPosition(-6 * float(myWindow.getSize().x) + i * float(myWindow.getSize().x), 0);
	}
	for (int i = 0; i < 13; i++, spriteTabIterator++)
	{
		tabSprite.push_back(mySprite);
		tabSprite[spriteTabIterator].setTexture(skyTexture);
		tabSprite[spriteTabIterator].setPosition(-6 * float(myWindow.getSize().x) + i * float(myWindow.getSize().x), -float(myWindow.getSize().y));
	}
	for (int i = 0; i < 13; i++, spriteTabIterator++)
	{
		tabSprite.push_back(mySprite);
		tabSprite[spriteTabIterator].setTexture(skyTexture);
		tabSprite[spriteTabIterator].setPosition(-6 * float(myWindow.getSize().x) + i * float(myWindow.getSize().x), -2 * float(myWindow.getSize().y));
	}
	for (int i = 0; i < 13; i++, spriteTabIterator++)
	{
		tabSprite.push_back(mySprite);
		tabSprite[spriteTabIterator].setTexture(grassTexture);
		tabSprite[spriteTabIterator].setPosition(-6 * float(myWindow.getSize().x) + i * float(myWindow.getSize().x), float(myWindow.getSize().y));
	}
}

/*void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
for (int i = 0; i < 15; i++) {
target.draw(tabSprite[i]);
}
}*/

void Background::displayGraphics(sf::RenderWindow& myWindow, std::vector<Player> players, Arrow& liveArrow, std::vector<DeadArrow> deadarrows)
{
	for (int i = 0; i < 52; i++) {
		myWindow.draw(tabSprite[i]);
	}
	for (int i = 0; i<players.size(); i++)
	{
		myWindow.draw(players[i]);
	}
	if (!liveArrow.getisDead()) {
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