#pragma once
#include <SFML/Graphics.hpp>

class Player : public sf::Drawable
{
public:
	Player() = default;
	Player(float xp, float yp);
	~Player() = default;
	sf::RectangleShape rect;
	sf::Vector2f getPosition();
	int playerHP;
private:
	sf::Texture myplayertexture;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const;
};
