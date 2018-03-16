#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Arrow.h"
#include <vector>

//stara funkcja w mainie przniesiona do Arrow
/*bool isInterecting(Arrow& arrow, Player& player)
{
	if (arrow.rect.getGlobalBounds().intersects(player.rect.getGlobalBounds()))
	{
		if (arrow.isHit == false)
		{
			arrow.isHit = true;
			player.playerHP -= 1;
		}
		return true;
	}
	return false;
}*/

int main()
{
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::Vector2i winSize = sf::Vector2i(desktop.width*0.8, desktop.height / 2);
	sf::RenderWindow window(sf::VideoMode(winSize.x, winSize.y), "Archers 1.0");
	window.setFramerateLimit(60);

	std::vector<Player> players;
	std::vector<Arrow> arrows;
	Player gracz1(45, desktop.height / 2 - 60);
	Player gracz2(desktop.width*0.8 - 45, desktop.height / 2 - 60);
	players.push_back(gracz1);
	players.push_back(gracz2);
	int kolejnosc = 0;
	int checker =0;

	while (window.isOpen())
	{
		/////event handling
		static sf::Vector2i aim1, aim2, aimNow;
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Left) {
					aim2 = sf::Mouse::getPosition(window);
					checker=0;
					if (kolejnosc % 2 == 0) {
						arrows.push_back(Arrow(aim1, aim2, gracz1.getPosition(), winSize));///daje od razu wektory aim1,2 zamiast ich wspolrzednych oraz pobieram pozycje obiektu zeby wiedziec skad wylatuje strzala
						kolejnosc++;///dodalem strzaly na zmiane ten int wyzancza czyja jest teraz kolejnosc gry zawsze zaczyna ten po lewej
					}
					else {
						std::cout << gracz2.getPosition().x<<" "<< gracz2.getPosition().y << std::endl;
						arrows.push_back(Arrow(aim1, aim2, gracz2.getPosition(), winSize));
						kolejnosc++;
					}
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) {
					aim1 = sf::Mouse::getPosition(window);
					checker=1;
				}
				break;
			default:
				break;
			}
		}
		///////window update
		for (int i = 0; i<arrows.size(); i++)
		{
			if (!arrows[i].isInterecting(arrows[i], players[kolejnosc%2]))///kolejnosc%2 wyznacza ktoremu graczowi teraz sprawdzac kolizje 0 czy 1, brak friendly fire
				arrows[i].update(winSize);
			//std::cout << players[1].playerHP << std::endl;
		}
		//////window render
		window.clear();
		for (int i = 0; i<players.size(); i++)
		{
			window.draw(players[i]);
		}
		for (int i = 0; i<arrows.size(); i++)
		{
			window.draw(arrows[i]);
		}

		aimNow = sf::Mouse::getPosition(window);
		sf::VertexArray lines(sf::LinesStrip, 2);   ///tworzenie i rysowanie lini
        lines[0].position = sf::Vector2f(aim1.x, aim1.y);
        lines[1].position = sf::Vector2f(aimNow.x, aimNow.y);
        if(checker==1){
                window.draw(lines);
        }
		window.display();
	}

	return 0;
}
