#include <iostream>
#include "Arrow.h"
class DeadArrow : public sf::Drawable
{
public:
	DeadArrow() = delete;
	DeadArrow(Arrow x);
	~DeadArrow() = default;
	//void update( sf::View& view1);
private:
	sf::Texture myxtexture;
	sf::Sprite myxsprite;

	void draw(sf::RenderTarget& target, sf::RenderStates state) const;
};
#pragma once
