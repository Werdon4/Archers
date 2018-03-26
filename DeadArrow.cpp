#include "DeadArrow.h"
DeadArrow::DeadArrow(Arrow x)
{
	if (myxtexture.loadFromFile("Arrow.png"))
		//std::cout << "DEADARROW" << std::endl;
	myxtexture.setSmooth(true);
	myxsprite.setTexture(myxtexture);
	myxsprite.setPosition(sf::Vector2f(x.mysprite.getPosition().x, x.mysprite.getPosition().y));
	myxsprite.setRotation(x.mysprite.getRotation());
	myxsprite.setOrigin(8, 68);
}

void DeadArrow::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->myxsprite, state);
}

void DeadArrow::update(sf::Vector2u winSize, sf::View& view1)
{
	///myxtexture.loadFromFile("Arrow.png");	///to powodowalo sciny
	myxsprite.setTexture(myxtexture);	//rozkmina czy to daloby rade jakos omin¹c
}

