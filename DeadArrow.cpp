#include "DeadArrow.h"
DeadArrow::DeadArrow(Arrow x)
{
	if (myxtexture.loadFromFile("Arrow.png"))
		//std::cout << "DEADARROW" << std::endl;
		myxtexture.setSmooth(true);
	myxsprite.setTexture(myxtexture);
	myxsprite.setPosition(sf::Vector2f(x.getmysprite().getPosition().x, x.getmysprite().getPosition().y));
	myxsprite.setRotation(x.getmysprite().getRotation());
	myxsprite.setOrigin(8, 68);
}

void DeadArrow::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	target.draw(this->myxsprite, state);
}

