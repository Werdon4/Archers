#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include <iostream>

class Background : public sf::Drawable
{
public:
	Background()=delete;
	Background(sf::Vector2u myWinSize);
	~Background()=default;
private:
	sf::Texture forestTexture;
	sf::Texture skyTexture;
	sf::Texture grassTexture;
	sf::Sprite mySprite;
	//sf::Sprite skySprite;
	//sf::Sprite grassSprite;
	std::vector <sf::Sprite> tabSprite;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

