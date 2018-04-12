#pragma once
#include <SFML/Graphics.hpp>
#define _USE_MATH_DEFINES
#include <math.h>
#include "DataOfOptions.h"
#include<time.h>
#include "Player.h"

class Wind : public sf::Drawable {
public:
	Wind() = delete;
	Wind(sf::Vector2f position,DataOfOptions & doo);

	~Wind() = default;
	void update(int sequence,sf::Vector2f position1,sf::Vector2f position2);
	void update();
	sf::Sprite getwindsprite();

	bool getmyuseWind();
	void setmyuseWind(bool myuseWind);

	sf::Vector2i getv2iwind();
	void setv2iwind(sf::Vector2i v2iwind);
private:
	sf::Vector2i v2iwind;
	sf::Clock windClock;
	sf::Time windTime1;
	sf::Time oldTime;
	bool myuseWind = 1;
	int maxPlusX = 7;
	int maxNegativeX = 7;
	int maxPlusY = 4;
	int maxNegativeY = 4;
	int windX, windY;

	int moveX = 0;
	int moveY = 0;
	int moveXplus = 1;
	int moveYplus = 1;

	sf::Texture windtexture;
	sf::Sprite windsprite;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const;
};