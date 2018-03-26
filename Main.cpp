#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "Player.h"
#include "Arrow.h"
#include "DeadArrow.h"
#include "wind.h"
#include "Background.h"
#include "Minimap.h"
#include <vector>


int main()
{
	sf::Clock myClock;
	sf::Clock my2Clock;
	sf::Time myTime = myClock.getElapsedTime();
	sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	sf::Vector2u winSize = sf::Vector2u(desktop.width, desktop.height);
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Archers 1.0");
	window.setFramerateLimit(60);
	std::vector<Player> players;
	Arrow liveArrow;
	liveArrow.isDead = true;
	std::vector<DeadArrow> deadarrows;
	Player gracz1(45, window.getSize().y - 400);
	Player gracz2(window.getSize().x - 45, window.getSize().y - 400);
	players.push_back(gracz1);
	players.push_back(gracz2);
	int kolejnosc = 0;
	int checker = 0;
	static sf::Vector2i aim1, aimNow;
	bool firsttime = 0;

	sf::SoundBuffer sbuffer;
	if (!sbuffer.loadFromFile("sound3.wav"))
		std::cout << "cos poszlo nie tak\n";
	sf::Sound mySound;
	mySound.setBuffer(sbuffer);

	sf::SoundBuffer s2buffer;
	if (!s2buffer.loadFromFile("sound2.wav"))
		std::cout << "cos sie popsulo\n";
	sf::Sound my2Sound;
	my2Sound.setBuffer(s2buffer);
	my2Sound.setPitch(2.0);

	bool letShoot = 1;
	int help = window.getSize().y - 400;//pozycja kompasu

	Background myBackground(window.getSize());

	sf::View view1(sf::FloatRect(sf::Vector2f(-100, 480), sf::Vector2f(1000, 1000)));
	view1.setCenter(players[kolejnosc].getPosition());
	//window.setView(view1);

	wind myWind(help);//tutaj nowe z dnia 24.03
	sf::Vector2f windZero = sf::Vector2f(0, 0);

	Minimap myMinimap(window, view1);

	while (window.isOpen())
	{
		window.setView(view1);
		//////////////////////////////////////////////////////////////////////////////////event handling
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
					checker = 0;
					if (kolejnosc == 0 && letShoot == 1) {
						liveArrow = Arrow(aim1, aimNow, gracz1.getPosition(), winSize, myClock);
						kolejnosc = 1;
						letShoot = 0;
						firsttime = 1;
					}
					else if (letShoot == 1) {
						liveArrow = Arrow(aim1, aimNow, gracz2.getPosition(), winSize, myClock);
						kolejnosc = 0;
						letShoot = 0;
						firsttime = 1;
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
		if (!liveArrow.isDead) {
			std::cout << "update" << std::endl;
			liveArrow.isInterecting(players[0]);
			liveArrow.isInterecting(players[1]);
			liveArrow.update(winSize, view1, myClock);

			liveArrow.cst_veloc -= windZero;
			windZero = sf::Vector2f(myWind.v2iwind);
			liveArrow.cst_veloc += windZero;///////to zmienic

			myTime = my2Clock.getElapsedTime();	//przyklad dzialania clocka
			if (myTime.asSeconds() >= 2 || firsttime) {
				mySound.play();
				my2Clock.restart();
				firsttime = 0;
			}
			if (liveArrow.isHit)
			{
				my2Sound.play();
				//to tez mozna zamienic na funkcje aby bardziej oczywiste bylo
				if (!liveArrow.isDead) {/////isHit ma raz zmienion¹ wartosc, to przebiega caly czas
														//tu usunac strzelke
					mySound.stop();
					deadarrows.push_back(DeadArrow(liveArrow));
					liveArrow.isDead = true;
					letShoot = 1;///// <---- turowe wystarczy usunac tablice strzal jesli sie na to decydujemy
				}

				float kierunek = view1.getCenter().x - players[kolejnosc].getPosition().x;
				if (kierunek <= 0)
				{
					view1.move(6, 0);
				}
				else
					view1.move(-6, 0);
				if (fabs(kierunek<2))
					view1.setCenter(players[kolejnosc].getPosition());
				window.setView(view1);// do tego momentu

			}
		}
		for (int j = 0; j < deadarrows.size(); j++) {////nie zapomniec o tym
			deadarrows[j].update(winSize, view1);
		}


		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
		sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
		aimNow = sf::Vector2i(worldPos);
		sf::VertexArray lines(sf::LinesStrip, 2);   //tworzenie i rysowanie lini
		lines[0].position = sf::Vector2f(aim1.x, aim1.y);
		lines[1].position = sf::Vector2f(aimNow.x, aimNow.y);
		////////////////////////////////////////////////////////////////////////////////////////////////////////window render
		window.clear();
		//window.draw(myBackground);
		myBackground.displayGraphics(window,players,liveArrow,deadarrows);
		window.draw(myWind);
		if (checker == 1) {
			window.draw(lines);
		}

		window.draw(myMinimap);
		myBackground.displayGraphics(window, players, liveArrow, deadarrows);
		window.draw(myWind);
		window.display();
	}

	return 0;
}