#include"DataOfOptions.h"
bool DataOfOptions::getuseWind()
{
	return useWind;
}
void DataOfOptions::setuseWind(bool useWind)
{
	this->useWind = useWind;
}
bool DataOfOptions::getuseMusic()
{
	return useMusic;
}
void DataOfOptions::setuseMusic(bool useMusic)
{
	this->useMusic = useMusic;
}
DataOfOptions::DataOfOptions() {
	useWind = 1;
	useMusic = 1;
	dificultyLevelPlus = 1.5;
	dificultyLevelMinus = 0.5;
}

void DataOfOptions::changeWind() {
	if (useWind) {
		useWind = 0;
	}
	else {
		useWind = 1;
	}
	std::cout << "Wiatr zostal zmieniony\n";
}

void DataOfOptions::changeMusic() {
	if (useMusic) {
		useMusic = 0;
	}
	else {
		useMusic = 1;
	}
	std::cout << "Muzyka zostala zmieniona\n";
}

void DataOfOptions::changeDificultyLevel(float levelPlus, float levelMinus)
{
	dificultyLevelPlus = levelPlus;
	dificultyLevelMinus = levelMinus;
}

float DataOfOptions::getDificultyLevelPlus()
{
	return dificultyLevelPlus;
}

float DataOfOptions::getDificultyLevelMinus() {
	return dificultyLevelMinus;
}