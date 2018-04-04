#pragma once
#include <SFML/Graphics.hpp>
#define _USE_MATH_DEFINES
#include <math.h>
#include "DataOfOptions.h"
//#include "Camera.h"
class Wind : public sf::Drawable {
public:
	//friend class Arrow;
	bool myuseWind=1;
	Wind() = delete;
	Wind(sf::Vector2f position,DataOfOptions & doo);

	~Wind() = default;
	sf::Vector2i v2iwind;
	void update(sf::Vector2u winSize, sf::View& view1);
private:
	sf::Texture windtexture;
	sf::Sprite windsprite;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const;
};