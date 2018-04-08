#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "DataOfOptions.h"
class SoundandMusic {
public:
	friend class MultiPlayer;
	friend class SinglePlayer;
	friend class GameMode;
	SoundandMusic() = delete;
	SoundandMusic(sf::Clock myCLock, DataOfOptions & doo);
	~SoundandMusic() = default;

	//sf::Time myTime = myClock.getElapsedTime();
	//sf::Time windTime = sf::seconds(0);
	//std::cout <<myTime.asSeconds()<<"time\n";

	void flyingUpdate(sf::Clock myClock);
	void hitUpdate();
	void painUpdate();
	void musicPlay();
	void musicStop();
private:
	bool myuseSound;
	bool bodyHit=0;
	bool firstTime = 1;
	sf::Time myTime;// = myClock.getElapsedTime();
	sf::Time oldTime;
	//sf::SoundBuffer sbuffer;
	//if (!sbuffer.loadFromFile("sound4.wav"))
	//	std::cout << "cos poszlo nie tak\n";
	//sf::Sound mySound;
	//mySound.setBuffer(sbuffer);
	sf::SoundBuffer sBuffer1;
	sf::SoundBuffer sBuffer2;
	sf::SoundBuffer sBufferP;
	sf::Sound mySound1;
	sf::Sound mySound2;
	sf::Sound painSound;
	sf::Music notmyMusic;
};