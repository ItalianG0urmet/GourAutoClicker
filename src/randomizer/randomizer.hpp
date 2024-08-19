#ifndef RANDOMIZER_H
#define RANDOMIZER_H

extern int max;

class Randomizer {
public:
	Randomizer(int min);
	int getRandomDelay();
private:
	int min;

};

#endif
