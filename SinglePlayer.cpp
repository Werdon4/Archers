#include "SinglePlayer.h"

SinglePlayer::SinglePlayer(sf::RenderWindow& myWindow, DataOfOptions & doo, Camera & myCamera)
{
	endMessageTab[0].setString("Wygrales !!!");
	endMessageTab[1].setString("Przegrales");
	liveArrow.setisDead(true);
	player1 = Player(45, myWindow.getSize().y - 300);
	player2 = Player(myWindow.getSize().x - 45, myWindow.getSize().y - 300);
	player2.playerFlip();
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
	hpTexts[0].setPosition(player1.getPosition().x, player1.getPosition().y - 200);///140
	hpTexts[0].setCharacterSize(30);
	hpTexts[0].setOutlineColor(sf::Color::Black);
	hpTexts[0].setOutlineThickness(5);
	hpTexts[0].setFillColor(sf::Color::White);
	hpTexts[0].setString(std::to_string(player1.getplayerHP()));

	hpTexts[1].setFont(myFont);
	hpTexts[1].setPosition(player2.getPosition().x, player2.getPosition().y - 200);
	hpTexts[1].setCharacterSize(30);
	hpTexts[1].setOutlineColor(sf::Color::Black);
	hpTexts[1].setOutlineThickness(5);
	hpTexts[1].setFillColor(sf::Color::White);
	hpTexts[1].setString(std::to_string(player2.getplayerHP()));

	hpTexts[2].setFont(myFont);
	hpTexts[2].setPosition(windPosition.x, windPosition.y);
	hpTexts[2].setCharacterSize(30);
	hpTexts[2].setOutlineColor(sf::Color::Black);
	hpTexts[2].setOutlineThickness(5);
	hpTexts[2].setFillColor(sf::Color::White);
	wordOfWind.append("X= ");
	wordOfWind.append(std::to_string(myWind->getv2iwind().x));
	wordOfWind.append(" Y= ");
	wordOfWind.append(std::to_string(myWind->getv2iwind().y));
	hpTexts[2].setString(wordOfWind);
}

void SinglePlayer::Run(sf::RenderWindow& myWindow, DataOfOptions & doo, Camera & myCamera)
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
						mySounds->setfirstTime(true);
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
		if (sequence == 1 && letShoot == 1 && !myCamera.getcameraMoveY() && !myCamera.getcameraMoveX()) {
			myTime = myClock.getElapsedTime();
			if (myBot->getwaiting()) {
				botWaits = myTime;
				botWaits = botWaits + sf::seconds(2);
				myBot->setwaiting(false);
				std::cout << "Wszedlem!\n";
			}
			if (myTime.asSeconds() >= botWaits.asSeconds()) {
				myBot->setwaiting(true);
				aimLineBegin = sf::Vector2i(0, 0);
				if (myBot->getcheetWindOff()) {	//mozna wylaczyc dzialanie waitru na strzaly bota
					myWind->setmyuseWind(false);
				}
				myBot->aim();
				aimLineEnd = myBot->getshoot();
				liveArrow = Arrow(aimLineBegin, aimLineEnd, player2.getPosition(), myWindow, myClock);
				sequence = 0;
				letShoot = 0;
				mySounds->setfirstTime(true);
			}
		}
		//////////////////////////////////////////////////////////////////////Window update
		if (!liveArrow.getisDead()) {
			if (sequence == 0 && liveArrow.isInterecting(player1)) {
				player1.decreaseHP();
				if (player1.getplayerHP() < 1) {
					gameOver(myWindow, myBackground, false);
					return;
				}
				myBot->setgoodAim(true);
				mySounds->painUpdate();
				hpTexts[0].setFillColor(sf::Color::Red);
				hpTexts[0].setString(std::to_string(player1.getplayerHP()));
			}
			if (sequence == 1 && liveArrow.isInterecting(player2)) {
				player2.decreaseHP();
				if (player2.getplayerHP() < 1) {
					gameOver(myWindow, myBackground, true);
					return;
				}
				mySounds->painUpdate();
				hpTexts[1].setFillColor(sf::Color::Red);
				hpTexts[1].setString(std::to_string(player2.getplayerHP()));
			}
			liveArrow.update(myWindow, view1, myClock, *myWind);

			mySounds->flyingUpdate(myClock);

			if (liveArrow.getisHit())
			{
				if (!liveArrow.getisDead()) {
					deadarrows.push_back(DeadArrow(liveArrow));
					liveArrow.setisDead(true);
					if (sequence == 0) {
						myBot->setxLastArrow(liveArrow.getmysprite().getPosition().x);
						if (!liveArrow.isInterecting(player1)) {	//to ma zapewnic ze bot sobie poradzi po trafieniu a potem nietrafieniu
							myBot->setgoodAim(false);
						}
					}
					letShoot = 1;
					mySounds->hitUpdate();
				}
				if (myBot->getcheetWindOff()) {	//wlaczam wiatr kiedy tylko chce
					myWind->setmyuseWind(true);
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
		wordOfWind.append(std::to_string(myWind->getv2iwind().x));
		wordOfWind.append(" Y= ");
		wordOfWind.append(std::to_string(myWind->getv2iwind().y));
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
		if (myWind->getmyuseWind()) {
			myWindow.draw(hpTexts[2]);
		}
		myWindow.display();
	}
	return;
}
SinglePlayer::~SinglePlayer() {
	mySounds->musicStop();
}