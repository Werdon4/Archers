#include "Minimap.h"



Minimap::Minimap(sf::RenderWindow& myWindow)
{
	miniMapView.reset(sf::FloatRect(0, 0, 1920, 1080));
	miniMapView.setViewport(sf::FloatRect(0.80f, 0.10f, 0.15f, 0.15f));
	miniMapView.zoom(1);

	miniMapSurround.setSize(sf::Vector2f(miniMapView.getViewport().width * myWindow.getSize().x, miniMapView.getViewport().height * myWindow.getSize().y));
	miniMapSurround.setFillColor(sf::Color::Transparent);
	miniMapSurround.setOutlineColor(sf::Color::Black);
	miniMapSurround.setOutlineThickness(10);
	miniMapSurround.setPosition(miniMapView.getViewport().left*myWindow.getSize().x, miniMapView.getViewport().top*myWindow.getSize().y);
}



void Minimap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//target.draw(miniMapSurround);
	target.setView(miniMapView);
}

