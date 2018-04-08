#pragma once
#include <iostream>
#include "Arrow.h"
class DeadArrow : public sf::Drawable
{
public:
	DeadArrow() = delete;
	DeadArrow(Arrow x);
	~DeadArrow() = default;
private:
	sf::Texture myxtexture;
	sf::Sprite myxsprite;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const;
};