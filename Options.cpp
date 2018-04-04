#include "Options.h"



Options::Options(sf::RenderWindow& myWindow)
{
	std::cout << "OPT const" << std::endl;
	selectedItemIndex = 0;
	if (!myFont.loadFromFile("snap.ttf"))
	{
		std::cout << "Font error" << std::endl;
	}
	for (int i = 0; i < NUMBER_OF_OPTIONS_ITEMS; i++)
	{
		optionsTexts[i].setFont(myFont);
		optionsTexts[i].setPosition(sf::Vector2f(myWindow.getSize().x*0.2, myWindow.getSize().y / (NUMBER_OF_OPTIONS_ITEMS + 1)*(i + 1)));
		optionsTexts[i].setCharacterSize(50);
		optionsTexts[i].setOutlineColor(sf::Color::Black);
		optionsTexts[i].setOutlineThickness(5);
	}

	optionsTexts[0].setFillColor(sf::Color::Red);
	optionsTexts[0].setString("Muzyka");

	optionsTexts[1].setFillColor(sf::Color::White);
	optionsTexts[1].setString("Wiatr");

	optionsTexts[2].setFillColor(sf::Color::White);
	optionsTexts[2].setString("Poziom trudnosci");

	optionsTexts[3].setFillColor(sf::Color::White);
	optionsTexts[3].setString("Powrot");

	optionsTexts[4].setFillColor(sf::Color::White);
	optionsTexts[4].setString("ON");
	optionsTexts[4].setPosition(sf::Vector2f(myWindow.getSize().x*0.6, myWindow.getSize().y / (NUMBER_OF_OPTIONS_ITEMS + 1)*(0 + 1)));

	optionsTexts[5].setFillColor(sf::Color::White);
	optionsTexts[5].setString("ON");
	optionsTexts[5].setPosition(sf::Vector2f(myWindow.getSize().x*0.6, myWindow.getSize().y / (NUMBER_OF_OPTIONS_ITEMS + 1)*(1 + 1)));
}

void Options::Display(sf::RenderWindow& myWindow)
{
	for (int i = 0; i < NUMBER_OF_OPTIONS_ITEMS; i++)
	{
		myWindow.draw(optionsTexts[i]);
	}
}

void Options::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		optionsTexts[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		optionsTexts[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Options::MoveDown()
{
	if (selectedItemIndex + 1 < NUMBER_OF_OPTIONS_ITEMS)
	{
		optionsTexts[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		optionsTexts[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

Menu* Options::Listening(sf::Event event, sf::RenderWindow& myWindow, Menu* wsk1, Menu* wsk2, Menu* wsk3,DataOfOptions & doo,Camera & myCamera)
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
				std::cout << "Muzyka" << std::endl;
				if (optionsTexts[4].getString() == "ON") {
					optionsTexts[4].setString("OFF");
					doo.changeMusic();
				}				
				else {
					optionsTexts[4].setString("ON");
					doo.changeMusic();
				}
				break;
			case 1:
			{
				std::cout << "Wiatr" << std::endl;
				if (optionsTexts[5].getString() == "ON") {
					optionsTexts[5].setString("OFF");
					doo.changeWind();
				}
				else {
					optionsTexts[5].setString("ON");
					doo.changeWind();
				}
				break;
			}
			case 2:
				std::cout << "Poziom trudnosci" << std::endl;
				break;
			case 3:
			{
				std::cout << "Powrot" << std::endl;
				wsk3 = wsk1;
				break;
			}
			}
			break;
		}
		break;
	default:
		break;
	}
	return wsk3;
}
