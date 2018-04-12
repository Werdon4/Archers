#pragma once
#include "SFML\Graphics.hpp"
#include "SinglePlayer.h"
#include "MultiPlayer.h"
#include "Options.h"
#include "Menu.h"
#include <iostream>

const int NUMBER_OF_MENU_ITEMS = 4;

class MainMenu : public Menu
{
public:
	MainMenu() = delete;
	MainMenu(sf::RenderWindow& myWindow);
	~MainMenu() = default;
	void Listening(sf::Event event, sf::RenderWindow& myWindow, Menu*& ptrPresent, Menu*&ptrAlternative, GameMode*&ptrGameMode, DataOfOptions & doo, Camera & myCamera) override;
	void MoveUp();
	void MoveDown();
	void Display(sf::RenderWindow& myWindow);
	int GetPressedItem() { return selectedItemIndex; }
private:
	int selectedItemIndex;
	sf::Font myFont;
	sf::Text menuTexts[NUMBER_OF_MENU_ITEMS];
};

