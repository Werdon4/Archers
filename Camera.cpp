#include "Camera.h"


Camera::Camera() {
	cameraController = 0;
	cameraController2 = 0;
	cameraController3 = 0;
	cameraController4 = 0;
	cameraController5 = 0;
}

void Camera::update(sf::View & view1, std::vector<Player> & players, int & kolejnosc, sf::RenderWindow & myWindow) {
	if (cameraController) {
		cameraController = 0;
		cameraController2 = 1;
		cameraController5 = 1;
		if (view1.getCenter().x > players[kolejnosc].getPosition().x) {
			cameraController3 = true;
		}
		if (view1.getCenter().x < players[kolejnosc].getPosition().x) {
			cameraController3 = false;
		}
		if (view1.getCenter().y > players[kolejnosc].getPosition().y) {
			cameraController4 = true;
		}
		if (view1.getCenter().y < players[kolejnosc].getPosition().y) {
			cameraController4 = false;
		}
	}
	if (cameraController2) {// X
		if (view1.getCenter().x > players[kolejnosc].getPosition().x && cameraController3) {
			view1.move(-12, 0);
		}
		else {
			if (view1.getCenter().x < players[kolejnosc].getPosition().x && !cameraController3) {
				view1.move(12, 0);
			}
			else {
				cameraController2 = 0;
				std::cout << "Wylaczenie kamery\n";
			}
		}
	}

	if (cameraController5) {// Y
		if (view1.getCenter().y > players[kolejnosc].getPosition().y && cameraController4) {
			view1.move(0, -3);
		}
		else {
			if (view1.getCenter().y < players[kolejnosc].getPosition().y && !cameraController4) {
				view1.move(0, 3);
			}
			else {
				cameraController5 = 0;
			}
		}
	}
	myWindow.setView(view1);
}

void Camera::start() {
	cameraController = 1;
}