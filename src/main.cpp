#include <iostream>
#include <thread>
#include "listeners/listeners.hpp"

HHOOK hookMouse;
HHOOK hookKeyboard;
bool isEnabled = false;
bool holdingLeft = false;
bool holdingRight = false;
bool enableAutoRightClick = false;
int max = 3;
MouseListener mouseListener;

int main()
{
    mouseListener = MouseListener();
    std::thread inputSenderMouse(&MouseListener::runMouseListener, &mouseListener);
    inputSenderMouse.join();

    return EXIT_SUCCESS;
}
