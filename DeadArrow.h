#include <SFML/Graphics.hpp>
#include <iostream>
//#define _USE_MATH_DEFINES
//#include <math.h>
//#include "Player.h"
#include "Arrow.h"
class DeadArrow : public sf::Drawable
{
public:
	DeadArrow() = delete;
	DeadArrow(Arrow x);
	~DeadArrow() = default;
	void update(sf::Vector2u winSize, sf::View& view1);
private:
	sf::Texture myxtexture;
	sf::Sprite myxsprite;

	void draw(sf::RenderTarget& target, sf::RenderStates state) const;
};
#pragma once
