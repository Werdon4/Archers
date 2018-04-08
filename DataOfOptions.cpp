#include"DataOfOptions.h"
DataOfOptions::DataOfOptions() {
	useWind = 1;
	useMusic = 1;
	dificultyLevel = 1;
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

void DataOfOptions::changeDificultyLevel(float level)
{
	dificultyLevel = level;
}

float DataOfOptions::getDificultyLevel()
{
	return dificultyLevel;
}
