#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Gracz : public sf::Drawable
{
public:
	Gracz()=delete;
	Gracz(float x, float y);
	~Gracz()=default;

private:
	sf::RectangleShape kwd;

};

