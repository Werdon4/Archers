#pragma once
#include "SFML\Graphics.hpp"
#include <iostream>
#include "Menu.h"

const int NUMBER_OF_OPTIONS_ITEMS = 9;

class Options :public Menu
{
public:
	Options(sf::RenderWindow& myWindow);
	~Options() = default;
	void Listening(sf::Event event, sf::RenderWindow& myWindow, Menu*& ptrPresent, Menu*&ptrAlternative, GameMode*&ptrGameMode, DataOfOptions & doo, Camera & myCamera) override;
	void MoveUp() override;
	void MoveDown() override;
	void Display(sf::RenderWindow& myWindow) override;
	int GetPressedItem() { return selectedItemIndex; }
private:
	int selectedItemIndex;
	int dificultyLevelIndex;//okresla jaki jest wybrany poziom trudnosci
	sf::Font myFont;
	sf::Text optionsTexts[NUMBER_OF_OPTIONS_ITEMS];
};


