#pragma once
#include<vector>
#include "Player.h"
#include "SFML\Graphics.hpp"
#include<iostream>

class Camera
{
public:
	friend class SinglePlayer;
	Camera();
	void update(sf::View & view1, std::vector<Player> & players, int & sequence, sf::RenderWindow & myWindow);
	void start();
private:
	bool cameraStart;
	bool cameraMoveX;
	bool cameraXDirection;
	bool cameraYDirection;
	bool cameraMoveY;
};