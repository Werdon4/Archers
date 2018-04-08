#pragma once
#include <SFML/Graphics.hpp>
#define _USE_MATH_DEFINES
#include <math.h>
#include "DataOfOptions.h"
#include<time.h>
#include "Player.h"

class Wind : public sf::Drawable {
public:
	friend class MultiPlayer;
	friend class SinglePlayer;
	bool myuseWind=1;
	Wind() = delete;
	Wind(sf::Vector2f position,DataOfOptions & doo);

	~Wind() = default;
	sf::Vector2i v2iwind;
	void update(int sequence,sf::Vector2f position1,sf::Vector2f position2);
	void update();
private:
	sf::Clock windClock;
	sf::Time windTime1;
	sf::Time oldTime;
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