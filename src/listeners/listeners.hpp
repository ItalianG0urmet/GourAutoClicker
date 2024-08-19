/* Mouse Listener */
#ifndef MOUSELISTENER_H
#define MOUSELISTENER_H

#include <Windows.h>
#include <thread>

extern bool isEnabledLeft;
extern bool holdingLeft;
extern HHOOK hookMouse;
extern int max;

class MouseListener {

public:
	void runMouseListener();
	static void startInputSenderLeft();
	std::thread inputSender;
private:
	static LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam);
	static DWORD lastClickTime;
};

#endif

/* Keyboard Listener */
#ifndef KEYBOARDLISTENER_H
#define KEYBOARDLISTENER_H

#include <Windows.h>
#include <thread>

extern HHOOK hookKeyboard;
extern int max;

class KeyBoardListener {
public:
	void runKeyboardListener();
	static LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
private:
	static int number;
	static bool delPressed;
};

#endif

/* Utils */
#ifndef UTILS_H
#define UTILS_H

class Utils {
public:
	static void sendMainScreen();
};

#endif 