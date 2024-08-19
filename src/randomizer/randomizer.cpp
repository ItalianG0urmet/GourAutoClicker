#include "randomizer.hpp"
#include <random>

Randomizer::Randomizer(int min) {
    this->min = min;
}

/*
* This algorytm will create a random number,
* that will be used for immitate the human click
*/
int Randomizer::getRandomDelay(){
    std::random_device rd;

    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribuzione(0, max);

    return distribuzione(gen);
}