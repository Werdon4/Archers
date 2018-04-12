#pragma once
#include<vector>
#include "Player.h"
#include "SFML\Graphics.hpp"
#include<iostream>

class Camera
{
public:
	Camera();
	void update(sf::View & view1, std::vector<Player> & players, int & sequence, sf::RenderWindow & myWindow);
	void start();
	bool getcameraMoveX();
	bool getcameraMoveY();
private:
	bool cameraStart;
	bool cameraMoveX;
	bool cameraMoveY;
	bool cameraXDirection;
	bool cameraYDirection;
};