#include "SoundandMusic.h"

SoundandMusic::SoundandMusic(sf::Clock myClock, DataOfOptions & doo) {
	myuseSound = doo.useMusic;
	if (myuseSound) {
		//if (!musicBuffer.loadFromFile("title.wav"))
		//	std::cout << "cos poszlo nie tak\n";
		if (!notmyMusic.openFromFile("title.wav"))
		{
			// error...
		}
		if (!sBuffer1.loadFromFile("sound4.wav"))
			std::cout << "cos poszlo nie tak\n";
		if (!sBuffer2.loadFromFile("sound2.wav"))
			std::cout << "cos poszlo nie tak\n";
		if (!sBufferP.loadFromFile("pain.wav"))
			std::cout << "cos poszlo nie tak\n";

		notmyMusic.setVolume(10);         // reduce the volume <0-100>
		notmyMusic.setLoop(true);         // make it loop

		mySound1.setBuffer(sBuffer1);
		//mySound1.setPitch(1.0);			//playing speed

		mySound2.setBuffer(sBuffer2);
		//mySound2.setPitch(1.0);

		painSound.setBuffer(sBufferP);
		//painSound.setPitch(1.0);

		oldTime = sf::seconds(0);
	}
}

void SoundandMusic::flyingUpdate(sf::Clock myClock) {
	if (myuseSound) {
		myTime = myClock.getElapsedTime();
		if (myTime.asSeconds() >= 1.5 + oldTime.asSeconds() || firstTime) {
			mySound1.play();
			oldTime = myTime;
			firstTime = 0;
		}
	}
}

void SoundandMusic::hitUpdate() {
	if (myuseSound) {
		if (!bodyHit) {
			mySound2.play();
		}
		else {
			bodyHit = 0;
		}
	}
}

void SoundandMusic::painUpdate() {
	if (myuseSound) {
		painSound.play();
		bodyHit = 1;
	}
}

void SoundandMusic::musicPlay() {
	if (myuseSound) {
		notmyMusic.play();
	}
}

void SoundandMusic::musicStop() {	
		notmyMusic.stop();
}