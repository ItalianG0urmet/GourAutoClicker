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


bool Randomizer::shouldPause() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribuzione(0, 100);
    return distribuzione(gen) < 7; // 5% di probabilità di pausa
}

int Randomizer::getRandomPauseDuration() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribuzione(30, 120); // Durata della pausa in millisecondi
    return distribuzione(gen);
}

int Randomizer::getRandomHoldDuration() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distribuzione(10, 30); // Simula un tempo di pressione variabile
    return distribuzione(gen);
}