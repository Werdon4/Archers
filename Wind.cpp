#include"wind.h"
#include<iostream>
Wind::Wind(sf::Vector2f position, DataOfOptions & doo) {
	v2iwind = sf::Vector2i(20, 0);
	myuseWind = doo.useWind;
	if (myuseWind) {
		/////////////////////////////////////// Blok Rng
		srand(time(NULL));
		windY = rand() % 2;
		windX = rand() % 2;
		if (windY == 1) {
			windY = -(rand() % maxNegativeY);
		}
		else{ //windY ==0
			windY = rand() % maxPlusY;
		}
		if (windX % 2 == 0) {
			windX = rand() % maxPlusX;
		}
		else {//windX ==1
			windX = -(rand() % maxNegativeX);
		}
		v2iwind.x = windX;
		v2iwind.y = windY;
		///////////////////////////////////////
		if (windtexture.loadFromFile("Arrow.png"))
			std::cout << "Wind" << std::endl;
		windtexture.setSmooth(true);
		windsprite.setTexture(windtexture);
		windsprite.setPosition(sf::Vector2f(position.x, position.y ));
		if (v2iwind.y == 0) {
			windsprite.setRotation(90);
		}
		else {
			if (-atan(v2iwind.x / v2iwind.y) * 180 / M_PI < 0)
				windsprite.setRotation(90 + (90 - atan(v2iwind.x / v2iwind.y) * 180 / M_PI));
			else
				windsprite.setRotation(-atan(v2iwind.x / v2iwind.y) * 180 / M_PI);
		}
		if (v2iwind.x < 0)
			windsprite.rotate(180);
		windsprite.setOrigin(8, 68);
	}
}

void Wind::draw(sf::RenderTarget& target, sf::RenderStates state) const
{
	if (myuseWind) { target.draw(this->windsprite, state); }
}

void Wind::update(int sequence, sf::Vector2f position1,sf::Vector2f position2)
{
	if (myuseWind) {
		if (sequence==0) {
			position1.x += 150;
			position1.y -= 150;
			windsprite.setPosition(position1);
		}
		if (sequence == 1) {
			position2.x += 150;
			position2.y -= 150;
			windsprite.setPosition(position2);
		}
		windTime1 = windClock.getElapsedTime();
		if (windTime1.asSeconds() >= 2 + oldTime.asSeconds()) {	//co ile ma sie odswiezac wiatr
			///////////////////////////////
			if (1/*rand() % 2*/) {// zmien wiatr lub niezmien
				if (moveX == 0) {
					moveX = 7; //rand() % 5;
					moveXplus = (moveXplus+1) % 2;
				}
				if (moveY == 0) {
					moveY = rand() % 4;
					moveYplus = (moveYplus+1) % 2;
				}
				else {
					if (moveX > 0 && moveXplus == 1) {
						windX += 1;
						moveX--;
					}
					if (moveX > 0 && moveXplus == 0) {
						windX -= 1;
						moveX--;
					}
					if (moveY > 0 && moveYplus == 1) {
						windY += 1;
						moveY--;
					}
					if (moveY > 0 && moveYplus == 0) {
						windY -= 1;
						moveY--;
					}
				}

				if (windX >= maxPlusX) {	////////// blok na max'ach
					windX = 0;// maxPlusX - 1;
				}
				if (windX <= -maxNegativeX) {
					windX = 0;// maxNegativeX - 1;
				}
				if (windY >= maxPlusY) {
					windY = 0;// maxPlusY - 1;
				}
				if (windY <= -maxNegativeY) {///////////
					windY = 0;// maxNegativeY - 1;
				}

				v2iwind.x = windX;
				v2iwind.y = windY;
			}
			///////////////////////////////
			oldTime = windTime1;
		}

		if (v2iwind.y == 0) {
			windsprite.setRotation(90);
		}
		else {
			if (-atan(v2iwind.x / v2iwind.y) * 180 / M_PI < 0)
				windsprite.setRotation(90 + (90 - atan(v2iwind.x / v2iwind.y) * 180 / M_PI));
			else
				windsprite.setRotation(-atan(v2iwind.x / v2iwind.y) * 180 / M_PI);
		}
		if (v2iwind.x < 0)
			windsprite.rotate(180);

		windsprite.setTexture(windtexture);
	}
}

void Wind::update()
{
	if (myuseWind) {
		windTime1 = windClock.getElapsedTime();
		if (windTime1.asSeconds() >= 2 + oldTime.asSeconds()) {	//co ile ma sie odswiezac wiatr
																///////////////////////////////

			if (1/*rand() % 2*/) {// zmien wiatr lub niezmien
				if (moveX == 0) {
					moveX = 7; //rand() % 5;
					moveXplus = (moveXplus + 1) % 2;
				}
				if (moveY == 0) {
					moveY = rand() % 4;
					moveYplus = (moveYplus + 1) % 2;
				}
				else {
					if (moveX > 0 && moveXplus == 1) {
						windX += 1;
						moveX--;
					}
					if (moveX > 0 && moveXplus == 0) {
						windX -= 1;
						moveX--;
					}
					if (moveY > 0 && moveYplus == 1) {
						windY += 1;
						moveY--;
					}
					if (moveY > 0 && moveYplus == 0) {
						windY -= 1;
						moveY--;
					}
				}

				if (windX >= maxPlusX) {	////////// blok na max'ach
					windX = 0;// maxPlusX - 1;
				}
				if (windX <= -maxNegativeX) {
					windX = 0;// maxNegativeX - 1;
				}
				if (windY >= maxPlusY) {
					windY = 0;// maxPlusY - 1;
				}
				if (windY <= -maxNegativeY) {///////////
					windY = 0;// maxNegativeY - 1;
				}

				v2iwind.x = windX;
				v2iwind.y = windY;
			}

			///////////////////////////////
			oldTime = windTime1;
		}

		if (v2iwind.y == 0) {
			windsprite.setRotation(90);
		}
		else {
			if (-atan(v2iwind.x / v2iwind.y) * 180 / M_PI < 0)
				windsprite.setRotation(90 + (90 - atan(v2iwind.x / v2iwind.y) * 180 / M_PI));
			else
				windsprite.setRotation(-atan(v2iwind.x / v2iwind.y) * 180 / M_PI);
		}
		if (v2iwind.x < 0)
			windsprite.rotate(180);

		windsprite.setTexture(windtexture);
	}
}