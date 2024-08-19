#include <iostream>
#include <thread>
#include "listeners/listeners.hpp"

HHOOK hookMouse;
HHOOK hookKeyboard;
bool isEnabledLeft = false;
int max = 3;
bool holdingLeft = false;
MouseListener mouseListener;
KeyBoardListener keyBoardListener;

int main()
{
    mouseListener = MouseListener();
    std::thread inputSenderMouse(&MouseListener::runMouseListener, &mouseListener);
    Sleep(800);
    keyBoardListener = KeyBoardListener();
    std::thread inputSenderKeyboard(&KeyBoardListener::runKeyboardListener, &keyBoardListener);

    inputSenderMouse.join();
    inputSenderKeyboard.join();

    return EXIT_SUCCESS;
}
