#ifndef RANDOMIZER_H
#define RANDOMIZER_H

extern int max;

class Randomizer {
public:
	Randomizer(int min);
	bool shouldPause();
	int getRandomDelay();
	int getRandomPauseDuration();
	int getRandomHoldDuration();
private:
	int min;

};

#endif
