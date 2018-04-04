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

	Background background(window);
	MainMenu myMenu(window);
	Options myOptions(window);
	Menu* wsk;
	wsk = &myMenu;
	//	wsk = &myOptions;
	//MultiPlayer MP(window);
	DataOfOptions doo;
	Camera myCamera;

	while (window.isOpen())
	{
		/////////////////////////////////////////////////////////Event Handling
		sf::Event event;
		while (window.pollEvent(event))
		{
			wsk = wsk->Listening(event, window, &myMenu, &myOptions, wsk, doo,myCamera);
		}
		//////////////////////////////////////////////////////////////Update


		/////////////////////////////////////////////////////////////Window Render
		window.clear();

		background.displayBackground(window);
		wsk->Display(window);

		window.display();
	}
	return 0;
}