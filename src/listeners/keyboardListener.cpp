#include "listeners.hpp"
#include <iostream>

int KeyBoardListener::number = 1;
bool KeyBoardListener::delPressed = false;

/*
* This is the costructor. Here the hook
* will be created and the loop for the message will
* start
*/
void KeyBoardListener::runKeyboardListener() {
	hookKeyboard = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
	if (hookKeyboard == NULL) {
		std::cout << "[-] Failed to set a hook. Error code: " << GetLastError() << std::endl;
		return;
	}
	std::cout << "[+] Keyboard hook created\n";
	Sleep(1000);
	Utils::sendMainScreen();
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		Sleep(500);
	}

	UnhookWindowsHookEx(hookKeyboard);
}

/*
* Listener of the Keyboard,
* manage all the entris
*/
LRESULT CALLBACK KeyBoardListener::KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) { //Mettere del al posto di alt

	if (nCode == HC_ACTION) {
		KBDLLHOOKSTRUCT* pKeyboard = (KBDLLHOOKSTRUCT*)lParam;

		if (wParam == WM_KEYUP && pKeyboard->vkCode == '1' && delPressed) {
			system("cls");
			std::cout << "[*] Set max: ";
			std::cin >> number;
			max = number;
			Utils::sendMainScreen();
		}
		else if (!delPressed && wParam == WM_KEYDOWN && pKeyboard->vkCode == VK_BACK) {
			delPressed = true;
			std::cout << "true";
		}
		else if (delPressed && wParam == WM_KEYUP && pKeyboard->vkCode == VK_BACK) {
			delPressed = false;
			std::cout << "false";
		}


	}

	return CallNextHookEx(hookKeyboard, nCode, wParam, lParam);
}

