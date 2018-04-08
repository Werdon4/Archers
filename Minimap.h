#pragma once
#include <SFML\Graphics.hpp>

class Minimap : public sf::Drawable
{
public:
	Minimap(sf::RenderWindow& myWindow);
	Minimap() = delete;
	~Minimap() = default;
	sf::View getMiniMapView();
private:
	sf::RectangleShape miniMapSurround;
	sf::View miniMapView;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

