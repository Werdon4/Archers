#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Player : public sf::Drawable
{
public:
	Player() = default;
	Player(float xp, float yp);
	~Player() = default;
	sf::RectangleShape rect;
	sf::Vector2f getPosition();
	int getplayerHP();
	void setplayerHP(int playerHP);
	void decreaseHP();
	void playerFlip();
	sf::Sprite getmyPlayerSprite();
private:
	int playerHP;
	sf::Texture* myPlayerTexture=new sf::Texture;
	sf::Sprite myPlayerSprite;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const;
};
