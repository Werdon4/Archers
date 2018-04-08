#include <SFML/Graphics.hpp>
#include <cmath>
#include "Background.h"
#include "Minimap.h"
#include "MainMenu.h"
#include "Menu.h"
#include "SinglePlayer.h"
#include "MultiPlayer.h"
#include <iostream>
#include "DataOfOptions.h"
#include "Camera.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Archers 1.0");
	window.setFramerateLimit(60);
	GameMode *ptrGameMode;//wskaznik do zmieniania trybu gry
	Background background(window);
	MainMenu myMenu(window);
	Options myOptions(window);
	Menu* wskPresent = &myMenu;//dwa wskazniki ktore sluza do przenoszenia sie miedzy menu gry a opcjami zaczynamy od menu gry wiec wskPresent = myMenu
	Menu* wskAlternative = &myOptions;
	DataOfOptions doo;
	Camera myCamera;

	while (window.isOpen())
	{
		/////////////////////////////////////////////////////////Event Handling
		sf::Event event;
		while (window.pollEvent(event))
		{//zmiany w Menu.h MainMenu cpp i h Options cpp i h
			wskPresent->Listening(event, window, wskPresent, wskAlternative,ptrGameMode, doo, myCamera);//funkcja juz nic nie zwraca bo przyjmuje referencje do wskaznikow, jezli chce sie przejsc do innego menu to wskanziki zamieniaja sie wartosciami
		}
		//////////////////////////////////////////////////////////////Update


		/////////////////////////////////////////////////////////////Window Render
		window.clear();

		background.displayBackground(window);
		wskPresent->Display(window);

		window.display();
	}
	return 0;
}