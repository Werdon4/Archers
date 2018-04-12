#include "Camera.h"


Camera::Camera() {
	cameraStart = 0;
	cameraMoveX = 0;
	cameraXDirection = 0;
	cameraYDirection = 0;
	cameraMoveY = 0;
}

void Camera::update(sf::View & view1, std::vector<Player> & players, int & sequence, sf::RenderWindow & myWindow) {
	if (cameraStart) {
		cameraStart = 0;
		cameraMoveX = 1;
		cameraMoveY = 1;
		if (view1.getCenter().x > players[sequence].getPosition().x) {
			cameraXDirection = true;
		}
		if (view1.getCenter().x < players[sequence].getPosition().x) {
			cameraXDirection = false;
		}
		if (view1.getCenter().y > players[sequence].getPosition().y) {
			cameraYDirection = true;
		}
		if (view1.getCenter().y < players[sequence].getPosition().y) {
			cameraYDirection = false;
		}
	}
	if (cameraMoveX) {// X
		if (view1.getCenter().x > players[sequence].getPosition().x && cameraXDirection) {
			view1.move(-12, 0);
		}
		else {
			if (view1.getCenter().x < players[sequence].getPosition().x && !cameraXDirection) {
				view1.move(12, 0);
			}
			else {
				cameraMoveX = 0;
				std::cout << "Wylaczenie kamery\n";
			}
		}
	}

	if (cameraMoveY) {// Y
		if (view1.getCenter().y > players[sequence].getPosition().y && cameraYDirection) {
			view1.move(0, -3);
		}
		else {
			if (view1.getCenter().y < players[sequence].getPosition().y && !cameraYDirection) {
				view1.move(0, 3);
			}
			else {
				cameraMoveY = 0;
			}
		}
	}
	myWindow.setView(view1);
}

void Camera::start() {
	cameraStart = 1;
}