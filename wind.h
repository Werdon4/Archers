#pragma once
#include <SFML/Graphics.hpp>
#define _USE_MATH_DEFINES
#include <math.h>
class wind: public sf::Drawable {
	public:
		//friend class Arrow;
		bool useWind;
		wind()=delete;
		wind(int help);

		~wind() = default;
		sf::Vector2i v2iwind;
		void update(sf::Vector2u winSize, sf::View& view1);
	private:
		sf::Texture windtexture;
		sf::Sprite windsprite;
		void draw(sf::RenderTarget& target, sf::RenderStates state) const;
};