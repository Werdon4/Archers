#pragma once
#include<iostream>
class DataOfOptions {
public:
	bool getuseWind();
	void setuseWind(bool useWind);
	bool getuseMusic();
	void setuseMusic(bool useMusic);
	DataOfOptions();
	void changeWind();
	void changeMusic();
	void changeDificultyLevel(float levelPlus, float levelMinus);
	float getDificultyLevelPlus();
	float getDificultyLevelMinus();
private:
	bool useWind;
	bool useMusic;
	float dificultyLevelPlus;
	float dificultyLevelMinus;
};