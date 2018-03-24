#include <SFML/Graphics.hpp>
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Player.h"

class Arrow : public sf::Drawable
{
public:
	Arrow() = delete;
	Arrow(sf::Vector2i mouseP, sf::Vector2i mouse, sf::Vector2f poczatek, sf::Vector2u winSize);///zmieni³em argumenty na wektroy zeby by³o ³atwiej mouseP - poczatek mouse- koniec, wektor poczatek to wektor z ktorego strzala ma wylatwyac na razie da³em ze jest to getPosition obiektu gracz
	~Arrow() = default;
	void update(sf::Vector2u winSize,sf::View& view1);
	bool isInterecting(Player& player);///funkcja przeniesiona z maina do klasy
	bool isHit;
	void hitting();
private:
	sf::Texture mytexture;
	sf::Sprite mysprite;
	//sf::RectangleShape rect;///dzieki przeniesieniu rect jest znowu prywatne
	sf::Vector2f cst_veloc;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const;
};

