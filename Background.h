#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <iostream>
#include "Player.h"
#include "Arrow.h"
#include "DeadArrow.h"

class Background //: public sf::Drawable
{
public:
	Background() = delete;
	Background(sf::Vector2u myWinSize);
	~Background() = default;
	void displayGraphics(sf::RenderWindow& myWindow, std::vector<Player> players, Arrow liveArrow, std::vector<DeadArrow> deadarrows);
private:
	sf::Texture forestTexture;
	sf::Texture skyTexture;
	sf::Texture grassTexture;
	sf::Sprite mySprite;
	std::vector <sf::Sprite> tabSprite;
	//void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

