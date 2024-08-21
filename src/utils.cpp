#include "listeners/listeners.hpp"
#include <iostream>
#include <iomanip>
#include <thread>

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

/*
* The main screen that will always appear
* on the console.
*/
void Utils::sendMainScreen() {
    std::thread inputThread([&]() {
        std::string command;
        clearScreen();
        std::cout << R"(
         $$$$$$\  $$\ $$\           $$\                           
        $$  __$$\ $$ |\__|          $$ |                          
        $$ /  \__|$$ |$$\  $$$$$$$\ $$ |  $$\  $$$$$$\   $$$$$$\  
        $$ |      $$ |$$ |$$  _____|$$ | $$  |$$  __$$\ $$  __$$\ 
        $$ |      $$ |$$ |$$ /      $$$$$$  / $$$$$$$$ |$$ |  \__|
        $$ |  $$\ $$ |$$ |$$ |      $$  _$$<  $$   ____|$$ |      
        \$$$$$$  |$$ |$$ |\$$$$$$$\ $$ | \$$\ \$$$$$$$\ $$ |      
         \______/ \__|\__| \_______|\__|  \__| \_______|\__|      
                                                                                  
        )" << std::endl;
        std::cout << std::string(80, '=') << std::endl;
        std::cout << "Press <DEL + 1> to change the bypass range" << std::endl;
        std::cout << "Type 'help' to display the help menu." << std::endl;
        std::cout << std::string(80, '-') << std::endl;
        std::cout << "[*] Is Enabled: " << (isEnabled ? "Yes" : "No") << std::endl;
        std::cout << "[*] Right Click: " << (enableAutoRightClick ? "Yes" : "No") << std::endl;
        std::cout << "[*] Bypass Range: " << max << std::endl;
        std::cout << std::string(80, '-') << std::endl;
        std::cout << "> ";
        std::cin >> command;

        if (command == "max"){
            modifyMax();
        } 
        else if (command == "help") {
            sendHelpMessage();
        }
        else if (command == "right") {
            sendRightPermission();
        }
        else {
            sendMainScreen();
        }

        });
    inputThread.detach();
}

void Utils::modifyMax() {
    clearScreen(); 
    std::cout << std::string(80, '-') << std::endl;
    std::cout << "The number you will now enter will determine the power of the autoclicker.\n";
    std::cout << "The higher the number, the less powerful the autoclicker will be, resulting in fewer clicks per second.\n";
    std::cout << "So, a higher number means slower clicks.\n";
    std::cout << std::string(80, '-') << std::endl;
    std::cout << "[*] New max: ";
    std::cin >> max;
    clearScreen();  
    sendMainScreen();  
}

void Utils::sendHelpMessage() {

    clearScreen();
    std::cout << std::string(80, '-') << std::endl;
    std::cout << "Available Commands:\n";
    std::cout << "  [max]  - Modify the Bypass range\n";
    std::cout << "  [right] - Enable right click\n";
    std::cout << "  [help] - Display this help message\n";
    std::cout << std::string(80, '-') << std::endl;
    std::cout << "[*] Press Enter to return to the main screen.";
    std::cin.ignore(10000, '\n');
    clearScreen();
    sendMainScreen();


}

void Utils::sendRightPermission() {
    clearScreen();
    enableAutoRightClick = !enableAutoRightClick;
    sendMainScreen();
}
