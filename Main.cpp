#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Arrow.h"
#include "Background.h"
#include "AimLine.h"
#include <vector>


int main()
{
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::Vector2u winSize = sf::Vector2u(desktop.width, desktop.height);
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Archers 1.0");
	window.setFramerateLimit(60);
	std::vector<Player> players;
	std::vector<Arrow> arrows;
	Player gracz1(45, window.getSize().y-400);
	Player gracz2(window.getSize().x-45, window.getSize().y - 400);
	players.push_back(gracz1);
	players.push_back(gracz2);
	int kolejnosc = 0;
	int checker = 0;

	//Background tlo(desktop.width, desktop.height);

	sf::Texture mytexture;
	mytexture.loadFromFile("forest.jpg");
	sf::Sprite mybackground[5];
	for (int i = 0; i < 5; i++) {
		mybackground[i].setTexture(mytexture);
		mybackground[i].setPosition(-3840 + i * 1920, 0);
	}

	sf::Texture mytexture_sky;
	mytexture_sky.loadFromFile("sky.jpg");
	sf::Sprite sky[5];
	for (int i = 0; i < 5; i++) {
		sky[i].setTexture(mytexture_sky);
		sky[i].setPosition(-3840 + i * 1920, -1080);
	}
	
	sf::Texture mytexture_grass;
	mytexture_grass.loadFromFile("grass.jpg");
	sf::Sprite grass[5];
	for (int i = 0; i < 5; i++) {
		grass[i].setTexture(mytexture_grass);
		grass[i].setPosition(-3840 + i * 1920, 1080);
	}

	sf::View view1(sf::FloatRect(sf::Vector2f(-100,480 ), sf::Vector2f(1000, 1000)));
	view1.setCenter(players[kolejnosc].getPosition());
	window.setView(view1);

	while (window.isOpen())
	{
		//////////////////////////////////////////////////////////////////////////////////event handling
		static sf::Vector2i aim1, aimNow;
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Resized:
				// window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
				//  window.create(sf::VideoMode(event.size.width, event.size.height, 32), "Archers 1.0");
				break;
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Left) {
					checker = 0;
					if (kolejnosc == 0) {
						arrows.push_back(Arrow(aim1, aimNow, gracz1.getPosition(), winSize));///daje od razu wektory aim1,2 zamiast ich wspolrzednych oraz pobieram pozycje obiektu zeby wiedziec skad wylatuje strzala
						kolejnosc=1;//dodalem strzaly na zmiane ten int wyzancza czyja jest teraz kolejnosc gry zawsze zaczyna ten po lewej
					}
					else {
						std::cout << gracz2.getPosition().x << " " << gracz2.getPosition().y << std::endl;
						arrows.push_back(Arrow(aim1, aimNow, gracz2.getPosition(), winSize));
						kolejnosc=0;
					}
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) {
					sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
					sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
					aim1 = sf::Vector2i(worldPos);
					checker = 1;
				}
				break;
			default:
				break;
			}
		}
		/////////////////////////////////////////////////////////////////////////////////////////////////window update
		for (int i = 0; i<arrows.size(); i++)
		{
			arrows[i].isInterecting(players[0]);
			arrows[i].isInterecting(players[1]);
			arrows[i].update(winSize, view1);
			if (arrows[arrows.size()-1].isHit)
			{
				//sf::sleep(sf::seconds(3));
				view1.setCenter(players[kolejnosc].getPosition());
				window.setView(view1);
			}
		}
		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
		sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
		aimNow = sf::Vector2i(worldPos);
		sf::VertexArray lines(sf::LinesStrip, 2);   //tworzenie i rysowanie lini
		lines[0].position = sf::Vector2f(aim1.x, aim1.y);
		lines[1].position = sf::Vector2f(aimNow.x, aimNow.y);
		//AimLine lines(aim1, aimNow);
		////////////////////////////////////////////////////////////////////////////////////////////window render
		window.clear();
		window.setView(view1);
		for (int i = 0; i < 5; i++) {
			window.draw(mybackground[i]);
		}

		for (int i = 0; i < 5; i++) {
			window.draw(sky[i]);
		}

		for (int i = 0; i < 5; i++) {
			window.draw(grass[i]);
		}
		//window.draw(tlo);
		for (int i = 0; i<players.size(); i++)
		{
			window.draw(players[i]);
		}
		for (int i = 0; i<arrows.size(); i++)
		{
			window.draw(arrows[i]);
		}
		if (checker == 1) {
			window.draw(lines);
		}
		window.display();
	}

	return 0;
}
