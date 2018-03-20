#include "Background.h"



Background::Background(sf::Vector2u myWinSize)
{
	if (!forestTexture.loadFromFile("forest.jpg"))
		std::cout << "Blad las!" << std::endl;
	if(!skyTexture.loadFromFile("sky.jpg"))
		std::cout << "Blad niebo!" << std::endl;
	if(!grassTexture.loadFromFile("grass.jpg"))
		std::cout << "Blad trawa!" << std::endl;
	
	for (int i = 0; i < 5; i++)
	{
		tabSprite.push_back(mySprite);
		tabSprite[i].setTexture(forestTexture);
		tabSprite[i].setPosition(-2* float(myWinSize.x) + i * float(myWinSize.x), 0);
	}
	for (int i = 5,j=0; i < 10; i++,j++)
	{
		tabSprite.push_back(mySprite);
		tabSprite[i].setTexture(skyTexture);
		tabSprite[i].setPosition(-2 * float(myWinSize.x) + j * float(myWinSize.x), -float(myWinSize.y));
	}
	for (int i = 10,j=0; i < 15; i++,j++)
	{
		tabSprite.push_back(mySprite);
		tabSprite[i].setTexture(grassTexture);
		tabSprite[i].setPosition(-2 * float(myWinSize.x) + j * float(myWinSize.x), float(myWinSize.y));
	}
}

void Background::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < 15; i++) {
		target.draw(tabSprite[i]);
	}
}