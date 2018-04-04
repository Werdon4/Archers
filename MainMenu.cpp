#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow& myWindow)
{
	selectedItemIndex = 0;
	if (!myFont.loadFromFile("snap.ttf"))
	{
		std::cout << "Font error" << std::endl;
	}
	for (int i = 0; i < NUMBER_OF_MENU_ITEMS; i++)
	{
		menuTexts[i].setFont(myFont);
		menuTexts[i].setPosition(sf::Vector2f(myWindow.getSize().x*0.4, myWindow.getSize().y / (NUMBER_OF_MENU_ITEMS + 1)*(i + 0.5)));
		menuTexts[i].setCharacterSize(50);
		menuTexts[i].setOutlineColor(sf::Color::Black);
		menuTexts[i].setOutlineThickness(5);
	}
	menuTexts[0].setFillColor(sf::Color::Red);
	menuTexts[0].setString(" Jeden gracz");

	menuTexts[1].setFillColor(sf::Color::White);
	menuTexts[1].setString("Dwóch graczy");

	menuTexts[2].setFillColor(sf::Color::White);
	menuTexts[2].setString("Ustawienia");

	menuTexts[3].setFillColor(sf::Color::White);
	menuTexts[3].setString("  Wyjscie");
}

void MainMenu::Display(sf::RenderWindow& myWindow)
{
	for (int i = 0; i < NUMBER_OF_MENU_ITEMS; i++)
	{
		myWindow.draw(menuTexts[i]);
	}
}

void MainMenu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menuTexts[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menuTexts[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void MainMenu::MoveDown()
{
	if (selectedItemIndex + 1 < NUMBER_OF_MENU_ITEMS)
	{
		menuTexts[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menuTexts[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

Menu* MainMenu::Listening(sf::Event event, sf::RenderWindow& myWindow, Menu* wsk1, Menu* wsk2, Menu* wsk3, DataOfOptions & doo,Camera & myCamera)
{
	switch (event.type)
	{
	case sf::Event::Closed:
		myWindow.close();
		break;
	case sf::Event::KeyPressed:
		switch (event.key.code)
		{
		case sf::Keyboard::Up:
			this->MoveUp();
			break;
		case sf::Keyboard::Down:
			this->MoveDown();
			break;
		case sf::Keyboard::Return:
			switch (GetPressedItem())
			{
			case 0:
			{
				std::cout << "Jeden gracz" << std::endl;

				SinglePlayer* SP = new SinglePlayer(myWindow, doo, myCamera);
				SP->Run(myWindow, doo, myCamera);
				delete SP;
				break;
			}
			case 1:
			{
				std::cout << "Dwoch graczy" << std::endl;

				//Camera myCamera;
				MultiPlayer* MP = new MultiPlayer(myWindow,doo,myCamera);
				//Camera*  myCamera= new Camera();
				MP->Run(myWindow,doo,myCamera);
				delete MP;
				break;
			}
			case 2:
			{
				std::cout << "Ustawienia" << std::endl;
				//return wsk2;
				std::cout << wsk3 << std::endl;
				wsk3 = wsk2;
				std::cout << wsk3 << std::endl;
				break;
			}
			case 3:
				myWindow.close();
				break;
			}
			break;
		}
		break;
	default:
		break;
	}
	return wsk3;
}
