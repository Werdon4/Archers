#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
#include "Menu.h"

const int NUMBER_OF_OPTIONS_ITEMS = 6;

class Options :public Menu
{
public:
	//Options()=delete;
	Options(sf::RenderWindow& myWindow);
	~Options() { std::cout << "OPT dectruct"; }
	Menu* Listening(sf::Event event, sf::RenderWindow& myWindow, Menu* wsk1, Menu* wsk2, Menu* wsk3,DataOfOptions & doo,Camera & myCamera) override;
	void MoveUp() override;
	void MoveDown() override;
	void Display(sf::RenderWindow& myWindow) override;
	int GetPressedItem() { return selectedItemIndex; }
private:
	int selectedItemIndex;
	sf::Font myFont;
	sf::Text optionsTexts[NUMBER_OF_OPTIONS_ITEMS];
};


