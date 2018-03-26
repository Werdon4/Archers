#include "Minimap.h"



Minimap::Minimap(sf::RenderWindow& myWindow, sf::View gameView)
{
	miniMapView.reset(sf::FloatRect(0, 0, 1920, 1080));
	miniMapView.setViewport(sf::FloatRect(0.60f, 0.0f, 0.3f, 0.3f));
	miniMapView.zoom(1);
	//miniMapView = gameView;

	miniMapSurround.setSize(sf::Vector2f(miniMapView.getViewport().width * myWindow.getSize().x, miniMapView.getViewport().height * myWindow.getSize().y));
	miniMapSurround.setFillColor(sf::Color::Transparent);
	miniMapSurround.setOutlineColor(sf::Color::Black);
	miniMapSurround.setOutlineThickness(10);
	//miniMapSurround.setPosition(miniMapView.getViewport().left*myWindow.getSize().x, miniMapView.getViewport().top*myWindow.getSize().y);
	miniMapSurround.setPosition(100, 100);
}



void Minimap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//target.draw(miniMapSurround);
	target.setView(miniMapView);
	target.draw(miniMapSurround);
}
