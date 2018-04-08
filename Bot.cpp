#include"Bot.h"

Bot::Bot(int playerPosition) {
	//shoot.x = 1000;
	//shoot.y = 100;
	xPosition = playerPosition;
}

void Bot::aim(float dificultyLevel) {
	if (isItFirst) {
		srand(time(NULL));
		prev.x = rand() % 652;		// tutaj tak sam jak ponizej	UWAGA chwilowo w Arrow cpp ograniczenie jest do winsize*0.3 wynosi 652.8
		prev.y = rand() % 367;		//wartosc startowa bedzie ustalana od rng UWAGA w y jest to 367.2 *z tymi parametrami komputer strzela z maksymalną sila luku
		shoot.x = prev.x;
		shoot.y = prev.y;
		isItFirst = 0;
		isItSecond = 1;
	}
	else {
		if (goodAim) {
			//shoot.x=shoot.x;
			//shoot.y=shoot.y;
		}
		else {
			if (isItSecond) {
				xPrev = xLastArrow;
				//xPrev= getArrow x to przy niszczeniu strzly
				if (xPrev < xPosition) {	//strzala jest za graczem
					next.x = prev.x - step*dificultyLevel;
					next.y = prev.y - step*dificultyLevel;
				}
				else {	//strzala jest przed graczem
					next.x = prev.x + step*dificultyLevel;
					next.y = prev.y + step*dificultyLevel;
				}
				shoot.x = next.x;
				shoot.y = next.y;
				isItSecond = 0;
			}
			else {	//tutaj powinnismy miec juz dwa oddane strzaly prev i next
				xNext = xLastArrow;
				if (xPrev < xPosition && xNext < xPosition) {	//oba sa po lewej od gracza
					step *= 1.5*dificultyLevel;
					prev.x = next.x;
					prev.y = next.y;
					xPrev = xNext;
					next.x -= step;
					next.y -= step;
					shoot.x = next.x;
					shoot.y = next.y;
				}
				else {
					if (xPrev<xPosition && xNext > xPosition) {	// sytuacja   prev Player next
						step *= 0.5*dificultyLevel;
						prev.x = next.x;
						prev.y = next.y;
						xPrev = xNext;
						next.x += step;
						next.y += step;
						shoot.x = next.x;
						shoot.y = next.y;
					}
					else {
						if (xPrev > xPosition && xNext > xPosition) {	// sytuacja Player prev next
							step *= 1.5*dificultyLevel;
							prev.x = next.x;
							prev.y = next.y;
							xPrev = xNext;
							next.x += step;
							next.y += step;
							shoot.x = next.x;
							shoot.y = next.y;
						}
						else {
							if (xPrev > xPosition && xNext < xPosition) {	// sytuacja next Player prev
								step *= 0.5*dificultyLevel;
								prev.x = next.x;
								prev.y = next.y;
								xPrev = xNext;
								next.x -= step;
								next.y -= step;
								shoot.x = next.x;
								shoot.y = next.y;
							}
							else {
								///w sumie nawet nie wiem jak mogloby sie to zdarzyc ale nalezaloby walnac exception czy cos
							}
						}
					}

				}

			}

		}

	}

}