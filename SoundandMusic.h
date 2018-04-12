#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "DataOfOptions.h"
class SoundandMusic {
public:
	friend class MultiPlayer;
	friend class SinglePlayer;
	SoundandMusic() = delete;
	SoundandMusic(sf::Clock myCLock, DataOfOptions & doo);
	~SoundandMusic() = default;

	void flyingUpdate(sf::Clock myClock);
	void hitUpdate();
	void painUpdate();
	void musicPlay();
	void musicStop();
private:
	bool myuseSound;
	bool bodyHit=0;
	bool firstTime = 1;
	sf::Time myTime;
	sf::Time oldTime;
	sf::SoundBuffer sBuffer1;
	sf::SoundBuffer sBuffer2;
	sf::SoundBuffer sBufferP;
	sf::Sound mySound1;
	sf::Sound mySound2;
	sf::Sound painSound;
	sf::Music notmyMusic;
};