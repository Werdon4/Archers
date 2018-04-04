#pragma once
#include "SFML\Graphics.hpp"
#include "DataOfOptions.h"
#include "Camera.h"

class Menu
{
public:
	//Menu(sf::RenderWindow myWindow)=0;
	//Menu()=delete;
	~Menu() = default;
	virtual void MoveUp() = 0;
	virtual void MoveDown() = 0;
	virtual void Display(sf::RenderWindow& myWindow) = 0;
	virtual Menu* Listening(sf::Event event, sf::RenderWindow& myWindow, Menu* wsk1, Menu*wsk2, Menu* wsk3,DataOfOptions & doo,Camera & myCamera) = 0;
	int GetPressedItem() { return selectedItemIndex; }
protected:
	int selectedItemIndex;
	sf::Font myFont;
};


