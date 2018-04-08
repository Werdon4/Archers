#pragma once
#include<iostream>
class DataOfOptions {
public:
	bool useWind;
	bool useMusic;
	DataOfOptions();
	void changeWind();
	void changeMusic();
	void changeDificultyLevel(float levelPlus, float levelMinus);
	float getDificultyLevelPlus();
	float getDificultyLevelMinus();
private:
	float dificultyLevelPlus;
	float dificultyLevelMinus;
};