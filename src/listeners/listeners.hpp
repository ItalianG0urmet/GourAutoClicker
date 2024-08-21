/* Mouse Listener */
#ifndef MOUSELISTENER_H
#define MOUSELISTENER_H

#include <Windows.h>
#include <thread>

extern bool isEnabled;
extern bool holdingLeft;
extern bool holdingRight;
extern bool enableAutoRightClick;
extern HHOOK hookMouse;
extern int max;

class MouseListener {

public:
	void runMouseListener();
	static void startInputSenderLeft();
	static void runMsg();
private:
	static LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam);
	static DWORD lastClickTime;
};

#endif

/* Utils */
#ifndef UTILS_H
#define UTILS_H

extern int max;

class Utils {
public:
	static void sendMainScreen();
	static void modifyMax();
	static void sendRightPermission();
	static void sendHelpMessage();
};

#endif 