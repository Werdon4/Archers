#pragma once
#include<iostream>
class DataOfOptions {
public:
	bool useWind;
	bool useMusic;
	DataOfOptions();
	void changeWind();
	void changeMusic();
	void changeDificultyLevel(float level);
	float getDificultyLevel();
private:
	float dificultyLevel;
};