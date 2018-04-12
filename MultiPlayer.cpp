#include "MultiPlayer.h"

MultiPlayer::MultiPlayer(sf::RenderWindow& myWindow, DataOfOptions & doo,Camera & myCamera)
{
	endMessageTab[0].setString("Wygral gracz pierwszy");
	endMessageTab[1].setString("Wygral gracz drugi");

	myTime = myClock.getElapsedTime();
	liveArrow.isDead = true;
	player1 = Player(45, myWindow.getSize().y - 400);
	player2 = Player(myWindow.getSize().x - 45, myWindow.getSize().y - 400);
	windPosition.x = player1.getPosition().x+150;
	windPosition.y = player1.getPosition().y - 150;
	players.push_back(player1);
	players.push_back(player2);
	myWind=new Wind(windPosition, doo);
	mySounds = new SoundandMusic(myClock,doo);
	view1 = sf::View(sf::FloatRect(sf::Vector2f(-100, 480), sf::Vector2f(1000, 1000)));
	view1.setCenter(players[sequence].getPosition());
	myWindow.setView(view1);

	if (!myFont.loadFromFile("snap.ttf"))
	{
		std::cout << "Font error" << std::endl;
	}
	hpTexts[0].setFont(myFont);
	hpTexts[0].setPosition(player1.getPosition().x,player1.getPosition().y-140);
	hpTexts[0].setCharacterSize(30);
	hpTexts[0].setOutlineColor(sf::Color::Black);
	hpTexts[0].setOutlineThickness(5);
	hpTexts[0].setFillColor(sf::Color::White);
	hpTexts[0].setString(std::to_string(player1.playerHP));

	hpTexts[1].setFont(myFont);
	hpTexts[1].setPosition(player2.getPosition().x, player2.getPosition().y - 140);
	hpTexts[1].setCharacterSize(30);
	hpTexts[1].setOutlineColor(sf::Color::Black);
	hpTexts[1].setOutlineThickness(5);
	hpTexts[1].setFillColor(sf::Color::White);
	hpTexts[1].setString(std::to_string(player2.playerHP));

	hpTexts[2].setFont(myFont);
	hpTexts[2].setPosition(windPosition.x,windPosition.y);
	hpTexts[2].setCharacterSize(30);
	hpTexts[2].setOutlineColor(sf::Color::Black);
	hpTexts[2].setOutlineThickness(5);
	hpTexts[2].setFillColor(sf::Color::White);
	wordOfWind.append("X= ");
	wordOfWind.append(std::to_string(myWind->v2iwind.x));
	wordOfWind.append(" Y= ");
	wordOfWind.append(std::to_string(myWind->v2iwind.y));
	hpTexts[2].setString(wordOfWind);

}

void MultiPlayer::Run(sf::RenderWindow& myWindow,DataOfOptions & doo, Camera & myCamera)
{
	mySounds->musicPlay();
	Background myBackground(myWindow);
	while (myWindow.isOpen())
	{
		//////////////////////////////////////////////////////////////////////Event handling
		sf::Event event;
		while (myWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				myWindow.close();
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					return;
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Left) {
					aimLineChecker = 0;
					if (sequence == 0 && letShoot == 1) {
						liveArrow = Arrow(aimLineBegin, aimLineEnd, player1.getPosition(), myWindow, myClock);
						sequence = 1;
						letShoot = 0;
						mySounds->firstTime = 1;
					}
					else if (letShoot == 1) {
						liveArrow = Arrow(aimLineBegin, aimLineEnd, player2.getPosition(), myWindow, myClock);
						sequence = 0;
						letShoot = 0;
						mySounds->firstTime = 1;
					}
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) {
					sf::Vector2i pixelPos = sf::Mouse::getPosition(myWindow);
					sf::Vector2f worldPos = myWindow.mapPixelToCoords(pixelPos);
					aimLineBegin = sf::Vector2i(worldPos);
					aimLineChecker = 1;
				}
				break;
			default:
				break;
			}
		}
		//////////////////////////////////////////////////////////////////////Window update
		if (!liveArrow.isDead) {
			//std::cout << "update" << std::endl;
			if (sequence==0 && liveArrow.isInterecting(player1)) {
				player1.playerHP--;
				if (player1.playerHP < 1) {
					gameOver(myWindow, myBackground, false);
					return;
				}
				mySounds->painUpdate();
				hpTexts[0].setFillColor(sf::Color::Red);
				hpTexts[0].setString(std::to_string(player1.playerHP));
			}
			if (sequence==1 && liveArrow.isInterecting(player2)) {
				player2.playerHP--; 
				if (player2.playerHP < 1) {
					gameOver(myWindow, myBackground, true);
					return;
				}
				mySounds->painUpdate();
				hpTexts[1].setFillColor(sf::Color::Red);
				hpTexts[1].setString(std::to_string(player2.playerHP));
			}
			liveArrow.update(myWindow, view1, myClock,*myWind);

			mySounds->flyingUpdate(myClock);

			if (liveArrow.isHit)
			{
				if (!liveArrow.isDead) {
					deadarrows.push_back(DeadArrow(liveArrow));
					liveArrow.isDead = true;
					letShoot = 1;
					mySounds->hitUpdate();
				}
				myCamera.start();
			}
		}

		sf::Vector2i pixelPos = sf::Mouse::getPosition(myWindow);
		sf::Vector2f worldPos = myWindow.mapPixelToCoords(pixelPos);
		aimLineEnd = sf::Vector2i(worldPos);
		sf::VertexArray lines(sf::LinesStrip, 2);   //tworzenie i rysowanie lini
		lines[0].position = sf::Vector2f(aimLineBegin.x, aimLineBegin.y);
		lines[1].position = sf::Vector2f(aimLineEnd.x, aimLineEnd.y);
		myCamera.update(view1, players, sequence, myWindow);

		if (myWind->myuseWind) {
			myWind->update(sequence, player1.getPosition(), player2.getPosition());
			wordOfWind = "X= ";
			wordOfWind.append(std::to_string(myWind->v2iwind.x));
			wordOfWind.append(" Y= ");
			wordOfWind.append(std::to_string(myWind->v2iwind.y));
			hpTexts[2].setString(wordOfWind);
			hpTexts[2].setPosition(myWind->windsprite.getPosition());
		}

		///////////////////////////////////////////////////////////////////////////////////Window Render
		myWindow.clear();
		myBackground.displayGraphics(myWindow, players, liveArrow, deadarrows);
		if (aimLineChecker) {
			myWindow.draw(lines);
		}
		myWindow.setView(view1);
		myWindow.draw(*myWind);
		myWindow.draw(hpTexts[0]);
		myWindow.draw(hpTexts[1]);
		if (myWind->myuseWind) {
			myWindow.draw(hpTexts[2]);
		}
		myWindow.display();
	}
	return;
}
MultiPlayer::~MultiPlayer() {
	mySounds->musicStop();
}