#pragma once
#include<vector>
#include "Player.h"
#include "SFML\Graphics.hpp"
#include<iostream>
class Camera
{
public:
	friend class SinglePlayer;
	//Camera() = delete;
	Camera();
	void update(sf::View & view1, std::vector<Player> & players, int & kolejnosc, sf::RenderWindow & myWindow);
	void start();
private:
	bool cameraController;
	bool cameraController2;
	bool cameraController3;
	bool cameraController4;
	bool cameraController5;
};