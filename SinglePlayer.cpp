#include "SinglePlayer.h"

SinglePlayer::SinglePlayer(sf::RenderWindow& myWindow, DataOfOptions & doo, Camera & myCamera)
{
	endMessageTab[0].setString("Wygrales !!!");
	endMessageTab[1].setString("Przegrales");
	liveArrow.isDead = true;
	player1 = Player(45, myWindow.getSize().y - 400);
	player2 = Player(myWindow.getSize().x - 45, myWindow.getSize().y - 400);
	windPosition.x = player1.getPosition().x + 150;
	windPosition.y = player1.getPosition().y - 150;
	players.push_back(player1);
	players.push_back(player2);
	myWind = new Wind(windPosition, doo);
	mySounds = new SoundandMusic(myClock, doo);

	myBot = new Bot(player1.getPosition().x, doo.getDificultyLevelPlus(), doo.getDificultyLevelMinus());

	view1 = sf::View(sf::FloatRect(sf::Vector2f(-100, 480), sf::Vector2f(1000, 1000)));
	view1.setCenter(players[sequence].getPosition());
	myWindow.setView(view1);

	if (!myFont.loadFromFile("snap.ttf"))
	{
		std::cout << "Font error" << std::endl;
	}
	hpTexts[0].setFont(myFont);
	hpTexts[0].setPosition(player1.getPosition().x, player1.getPosition().y - 140);
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
	hpTexts[2].setPosition(windPosition.x, windPosition.y);
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

void SinglePlayer::Run(sf::RenderWindow& myWindow, DataOfOptions & doo, Camera & myCamera)
{
	//Camera myCamera;
	//mySounds->notmyMusic.play(); to zmienilem na to ponizej
	mySounds->musicPlay();
	Background myBackground(myWindow);
	while (myWindow.isOpen())
	{
		//////////////////////////////////////////////////////////////////////Event handling
		sf::Event event;
		while (myWindow.pollEvent(event))
		{
			//myWindow.setView(view1);
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
						//firsttime = 1;//////////to zastapic tym ponizej i usunac firsttime z multiplayer
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
		////////////////////////////////////////////////bot
		if (sequence == 1 && letShoot == 1 && !myCamera.cameraMoveY && !myCamera.cameraMoveX) {
			myTime = myClock.getElapsedTime();
			if (myBot->waiting) {
				botWaits = myTime;
				botWaits = botWaits + sf::seconds(2);
				myBot->waiting = 0;
				std::cout << "Wszedlem!\n";
			}
			if (myTime.asSeconds() >= botWaits.asSeconds()) {
				myBot->waiting = 1;
				aimLineBegin = sf::Vector2i(0, 0);
				if (myBot->cheetWindOff) {	//mozna wylaczyc dzialanie waitru na strzaly bota
					myWind->myuseWind = 0;
				}
				myBot->aim();
				aimLineEnd = myBot->shoot;
				liveArrow = Arrow(aimLineBegin, aimLineEnd, player2.getPosition(), myWindow, myClock);
				sequence = 0;
				letShoot = 0;
				mySounds->firstTime = 1;
			}
		}
		//////////////////////////////////////////////////////////////////////Window update
		if (!liveArrow.isDead) {
			if (sequence == 0 && liveArrow.isInterecting(player1)) {
				player1.playerHP--;
				if (player1.playerHP < 10) {
					gameOver(myWindow, myBackground, false);
					return;
				}
				myBot->goodAim = 1;
				mySounds->painUpdate();
				hpTexts[0].setFillColor(sf::Color::Red);
				hpTexts[0].setString(std::to_string(player1.playerHP));
			}
			//liveArrow.isInterecting(player2);
			if (sequence == 1 && liveArrow.isInterecting(player2)) {
				player2.playerHP--;
				if (player2.playerHP < 10) {//wywolanie konca gry po 1 hicie bo nie bede tyle czekal :P
					gameOver(myWindow, myBackground, true);
					return;
				}
				mySounds->painUpdate();
				hpTexts[1].setFillColor(sf::Color::Red);
				hpTexts[1].setString(std::to_string(player2.playerHP));
			}
			liveArrow.update(myWindow, view1, myClock, *myWind);

			mySounds->flyingUpdate(myClock);

			if (liveArrow.isHit)
			{
				//to tez mozna zamienic na funkcje aby bardziej oczywiste bylo
				if (!liveArrow.isDead) {/////isHit ma raz zmienion? wartosc, to przebiega caly czas
					deadarrows.push_back(DeadArrow(liveArrow));
					liveArrow.isDead = true;
					if (sequence == 0) {
						myBot->xLastArrow = liveArrow.mysprite.getPosition().x;	// tego w code blocksie bym nie ogarnal
						if (!liveArrow.isInterecting(player1)) {	//to ma zapewnic ze bot sobie poradzi po trafieniu a potem nietrafieniu
							myBot->goodAim = 0;	//jeszcze nie wiem czy to w ogoole dziala :D
						}
					}
					letShoot = 1;///// <---- turowe wystarczy usunac tablice strzal jesli sie na to decydujemy
					mySounds->hitUpdate();
					//myBot->xLastArrow = liveArrow.mysprite.getPosition().x;
				}
				if (myBot->cheetWindOff) {	//wlaczam wiatr kiedy tylko chce
					myWind->myuseWind = 1;
				}
				myCamera.start();
			}
		}
		//tworzenie i rysowanie lini
		sf::Vector2i pixelPos = sf::Mouse::getPosition(myWindow);
		sf::Vector2f worldPos = myWindow.mapPixelToCoords(pixelPos);
		aimLineEnd = sf::Vector2i(worldPos);
		sf::VertexArray lines(sf::LinesStrip, 2);
		lines[0].position = sf::Vector2f(aimLineBegin.x, aimLineBegin.y);
		lines[1].position = sf::Vector2f(aimLineEnd.x, aimLineEnd.y);
		myCamera.update(view1, players, sequence, myWindow);
		//////////////////////////////////////////////////wind update
		myWind->update();
		wordOfWind = "X= ";
		wordOfWind.append(std::to_string(myWind->v2iwind.x));
		wordOfWind.append(" Y= ");
		wordOfWind.append(std::to_string(myWind->v2iwind.y));
		hpTexts[2].setString(wordOfWind);
		///////////////////////////////////////////////////////////////////////////////////Window Render
		myWindow.clear();
		myBackground.displayGraphics(myWindow, players, liveArrow, deadarrows);
		if (aimLineChecker == 1) {
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
SinglePlayer::~SinglePlayer() {
	mySounds->musicStop();
}