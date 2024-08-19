#include "listeners/listeners.hpp"
#include <iostream>
#include <iomanip>

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/* 
* Thed main screen that will always appair
* on the console.
*/
void Utils::sendMainScreen() {
    clearScreen();

    std::cout << std::string(50, '=') << std::endl;
    std::cout << std::left << std::setw(50) << "Welcome to GourClicker++" << std::endl;
    std::cout << std::string(50, '-') << std::endl;

    std::cout << "Press <del + 1> for change the bypass range\n" << std::endl;

    std::cout << "[*] Is Enabled: " << (isEnabledLeft ? "Yes" : "No") << std::endl;
    std::cout << "[*] Bypass range: " << max << std::endl;

    std::cout << std::string(50, '=') << std::endl;
}
