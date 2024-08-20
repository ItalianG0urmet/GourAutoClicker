#include "listeners.hpp"
#include "../randomizer/randomizer.hpp"
#include <Windows.h>
#include <iostream>
#include <string>
#include <thread>
#include <random>
#include <functional>


std::thread inputSenderLeft;
std::thread inputSenderRight;
DWORD MouseListener::lastClickTime = 0;

/*
* This is the costructor. Here the hook
* will be created and the loop for the message will
* start
*/
void MouseListener::runMouseListener(){
	
	inputSenderLeft = std::thread(startInputSenderLeft);
	hookMouse = SetWindowsHookEx(WH_MOUSE_LL, MouseProc, NULL, 0);
	if (hookMouse == NULL) {
		std::cout << "[-] Failed to set a hook. Error code: " << GetLastError() << std::endl;
		return;
	}
	std::cout << "[+] Mouse hook created\n";
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		Sleep(500);
	}

	inputSenderLeft.join();
	inputSenderRight.join();
	UnhookWindowsHookEx(hookMouse);
}

/*
* This will be the function that will be
* executed in the thread defined in the costructor
*/
void MouseListener::startInputSenderLeft() {

	INPUT ip = { 0 };
	ip.type = INPUT_MOUSE;
	Randomizer randomizer(0);

	while (true) {
		if (isEnabledLeft && holdingLeft) {
			
			if (randomizer.shouldPause()) Sleep(randomizer.getRandomPauseDuration());
			
			Sleep(randomizer.getRandomDelay());
			ip.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
			SendInput(1, &ip, sizeof(INPUT));

			Sleep(randomizer.getRandomHoldDuration());
			ip.mi.dwFlags = MOUSEEVENTF_LEFTUP;
			SendInput(1, &ip, sizeof(INPUT));

			Sleep(17 + randomizer.getRandomDelay());
			
		}
	}
}


/*
* Here all the mouse input will be processed.
* With the mouse weel button you can disable and
* activate the clicker
*/
LRESULT CALLBACK MouseListener::MouseProc(int nCode, WPARAM wParam, LPARAM lParam) {


	if (nCode == HC_ACTION) {
		PMSLLHOOKSTRUCT pMouseStruct = (PMSLLHOOKSTRUCT)lParam;

		if (!(pMouseStruct->flags & LLMHF_INJECTED)) {
			if (wParam == WM_LBUTTONDOWN) {
				holdingLeft = true;
			}
			else if (wParam == WM_LBUTTONUP) {
				holdingLeft = false;

			}
			else if (wParam == WM_MBUTTONUP) {
				DWORD currentTime = GetTickCount();
				if (currentTime - lastClickTime > 50) {
					isEnabledLeft = !isEnabledLeft;
					Utils::sendMainScreen(); //Main Message
					lastClickTime = currentTime;  // Update the last click time
				}

			}

		}
	}

	return CallNextHookEx(hookMouse, nCode, wParam, lParam);
}
