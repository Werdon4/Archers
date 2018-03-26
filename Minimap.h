#pragma once
#include <SFML\Graphics.hpp>
#include "Background.h"

class Minimap : public sf::Drawable
{
public:
	Minimap(sf::RenderWindow& myWindow, sf::View gameView);
	Minimap() = delete;
	~Minimap() = default;

private:
	sf::RectangleShape miniMapSurround;
	sf::View miniMapView;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};