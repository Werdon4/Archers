#include "MultiPlayer.h"

MultiPlayer::MultiPlayer(sf::RenderWindow& myWindow, DataOfOptions & doo,Camera & myCamera)
{
	myTime = myClock.getElapsedTime();
	liveArrow.isDead = true;
	gracz1 = Player(45, myWindow.getSize().y - 400);
	gracz2 = Player(myWindow.getSize().x - 45, myWindow.getSize().y - 400);
	windPosition.x = gracz1.getPosition().x+150;
	windPosition.y = gracz1.getPosition().y - 150;
	players.push_back(gracz1);
	players.push_back(gracz2);
	//Wind myWind(windPosition, doo);
	myWind=new Wind(windPosition, doo);
	mySounds = new SoundandMusic(myClock,doo);
	//myBackground=Background(myWindow.getSize());
	//myCamera = new Camera;
	view1 = sf::View(sf::FloatRect(sf::Vector2f(-100, 480), sf::Vector2f(1000, 1000)));
	view1.setCenter(players[kolejnosc].getPosition());
	myWindow.setView(view1);

	if (!myFont.loadFromFile("snap.ttf"))
	{
		std::cout << "Font error" << std::endl;
	}
	hpTexts[0].setFont(myFont);
	hpTexts[0].setPosition(gracz1.getPosition().x,gracz1.getPosition().y-140);
	hpTexts[0].setCharacterSize(30);
	hpTexts[0].setOutlineColor(sf::Color::Black);
	hpTexts[0].setOutlineThickness(5);
	hpTexts[0].setFillColor(sf::Color::White);
	hpTexts[0].setString(std::to_string(gracz1.playerHP));

	hpTexts[1].setFont(myFont);
	hpTexts[1].setPosition(gracz2.getPosition().x, gracz2.getPosition().y - 140);
	hpTexts[1].setCharacterSize(30);
	hpTexts[1].setOutlineColor(sf::Color::Black);
	hpTexts[1].setOutlineThickness(5);
	hpTexts[1].setFillColor(sf::Color::White);
	hpTexts[1].setString(std::to_string(gracz2.playerHP));

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
					checker = 0;
					if (kolejnosc == 0 && letShoot == 1) {
						liveArrow = Arrow(aim1, aimNow, gracz1.getPosition(), myWindow, myClock);
						kolejnosc = 1;
						letShoot = 0;
						//firsttime = 1;//////////to zastapic tym ponizej i usunac firsttime z multiplayer
						mySounds->firstTime = 1;
					}
					else if (letShoot == 1) {
						liveArrow = Arrow(aim1, aimNow, gracz2.getPosition(), myWindow, myClock);
						kolejnosc = 0;
						letShoot = 0;
						//firsttime = 1;/////////to zastapic tym ponizej
						mySounds->firstTime = 1;
					}
				}
				break;
			case sf::Event::MouseButtonPressed:
				if (event.mouseButton.button == sf::Mouse::Left) {
					sf::Vector2i pixelPos = sf::Mouse::getPosition(myWindow);
					sf::Vector2f worldPos = myWindow.mapPixelToCoords(pixelPos);
					aim1 = sf::Vector2i(worldPos);
					checker = 1;
				}
				break;
			default:
				break;
			}
		}
		//////////////////////////////////////////////////////////////////////Window update
		if (!liveArrow.isDead) {
			//std::cout << "update" << std::endl;
			//liveArrow.isInterecting(gracz1);
			if (kolejnosc==0 && liveArrow.isInterecting(gracz1)) {
				gracz1.playerHP--;
				mySounds->painUpdate();
				hpTexts[0].setFillColor(sf::Color::Red);
				hpTexts[0].setString(std::to_string(gracz1.playerHP));
			}
			//liveArrow.isInterecting(gracz2);
			if (kolejnosc==1 && liveArrow.isInterecting(gracz2)) {
				gracz2.playerHP--; 
				mySounds->painUpdate();
				hpTexts[1].setFillColor(sf::Color::Red);
				hpTexts[1].setString(std::to_string(gracz2.playerHP));
			}
			liveArrow.update(myWindow, view1, myClock,*myWind);

			mySounds->flyingUpdate(myClock);

			if (liveArrow.isHit)
			{
				//to tez mozna zamienic na funkcje aby bardziej oczywiste bylo
				if (!liveArrow.isDead) {/////isHit ma raz zmienion? wartosc, to przebiega caly czas
					deadarrows.push_back(DeadArrow(liveArrow));
					liveArrow.isDead = true;
					letShoot = 1;///// <---- turowe wystarczy usunac tablice strzal jesli sie na to decydujemy
					mySounds->hitUpdate();
					//myBot->xLastArrow=
				}
				myCamera.start();
			}
		}

		sf::Vector2i pixelPos = sf::Mouse::getPosition(myWindow);
		sf::Vector2f worldPos = myWindow.mapPixelToCoords(pixelPos);
		aimNow = sf::Vector2i(worldPos);
		sf::VertexArray lines(sf::LinesStrip, 2);   //tworzenie i rysowanie lini
		lines[0].position = sf::Vector2f(aim1.x, aim1.y);
		lines[1].position = sf::Vector2f(aimNow.x, aimNow.y);
		myCamera.update(view1, players, kolejnosc, myWindow);

		if (myWind->myuseWind) {
			myWind->update(kolejnosc, gracz1.getPosition(), gracz2.getPosition());
			//wordOfWind.append("X= ");
			wordOfWind = "X= ";
			wordOfWind.append(std::to_string(myWind->v2iwind.x));
			wordOfWind.append(" Y= ");
			wordOfWind.append(std::to_string(myWind->v2iwind.y));
			hpTexts[2].setString(wordOfWind);
			//hpTexts[2].setPosition(windPosition.x, windPosition.y);
			hpTexts[2].setPosition(myWind->windsprite.getPosition());
		}

		///////////////////////////////////////////////////////////////////////////////////Window Render
		myWindow.clear();
		myBackground.displayGraphics(myWindow, players, liveArrow, deadarrows);
		if (checker == 1) {
			myWindow.draw(lines);
		}
		//myWindow.draw()
		//myCamera.update(view1, players, kolejnosc, myWindow);
		myWindow.setView(view1);
		myWindow.draw(*myWind);

		myWindow.draw(hpTexts[0]);
		myWindow.draw(hpTexts[1]);
		//myWindow.draw(hpTexts[3]);
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