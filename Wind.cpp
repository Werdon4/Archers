#include"wind.h"
#include<iostream>
Wind::Wind(sf::Vector2f position, DataOfOptions & doo) {
	v2iwind = sf::Vector2i(0, 0);
	myuseWind = doo.useWind;
	if (myuseWind) {
		if (windtexture.loadFromFile("Arrow.png"))
			std::cout << "Wind" << std::endl;
		windtexture.setSmooth(true);
		windsprite.setTexture(windtexture);
		windsprite.setPosition(sf::Vector2f(position.x, position.y ));
		if (v2iwind.y == 0) {
			windsprite.setRotation(90);
		}
		else {
			if (-atan(v2iwind.x / v2iwind.y) * 180 / M_PI < 0)
				windsprite.setRotation(90 + (90 - atan(v2iwind.x / v2iwind.y) * 180 / M_PI));
			else
				windsprite.setRotation(-atan(v2iwind.x / v2iwind.y) * 180 / M_PI);
		}
		if (v2iwind.x < 0)
			windsprite.rotate(180);
		//windsprite.setRotation(windsprite.getRotation());
		windsprite.setOrigin(8, 68);
	}

}

void Wind::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	if (myuseWind) { target.draw(this->windsprite, state); }
}

void Wind::update(sf::Vector2u winSize, sf::View& view1)
{
	///windtexture.loadFromFile("Arrow.png");
	windsprite.setTexture(windtexture);
}