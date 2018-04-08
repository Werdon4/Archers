#pragma once
#include "SFML\Graphics.hpp"
#include "DataOfOptions.h"
#include "Camera.h"
#include "GameMode.h"

class Menu
{
public:
	~Menu() = default;
	virtual void MoveUp() = 0;
	virtual void MoveDown() = 0;
	virtual void Display(sf::RenderWindow& myWindow) = 0;
	virtual void Listening(sf::Event event, sf::RenderWindow& myWindow, Menu*& ptrPresent, Menu*&ptrAlternative,GameMode*&ptrGameMode, DataOfOptions & doo,Camera & myCamera)=0 ;//dzieki dodaniu referencji mozna zmieniac ich wartosci oraz nie trzeba wysylac wskaznika do wskaznika tylko sam wskaznik
	int GetPressedItem() { return selectedItemIndex; }
protected:
	int selectedItemIndex;
	sf::Font myFont;
	sf::Text endMessage[2];
};


