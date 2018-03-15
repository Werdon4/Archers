#include <SFML/Graphics.hpp>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Player.h"

class Arrow : public sf::Drawable
{
public:
	Arrow() = delete;
	Arrow(sf::Vector2i mouseP, sf::Vector2i mouse, sf::Vector2f poczatek, sf::Vector2i winSize);///zmieni³em argumenty na wektroy zeby by³o ³atwiej mouseP - poczatek mouse- koniec, wektor poczatek to wektor z ktorego strzala ma wylatwyac na razie da³em ze jest to getPosition obiektu gracz
	~Arrow() = default;
	void update(sf::Vector2i winSize);
	bool isInterecting(Arrow& arrow, Player& player);///funkcja przeniesiona z maina do klasy

	bool isHit;
	void hitting();
private:
	sf::RectangleShape rect;///dzieki przeniesieniu rect jest znowu prywatne
	sf::Vector2f cst_veloc;
	void draw(sf::RenderTarget& target, sf::RenderStates state) const;
};

