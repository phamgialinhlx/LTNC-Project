#pragma once
#ifndef INPUTS_H
#define INPUTS_H

#include <SDL.h>

class Inputs {

	bool quit;
	int mouseX;
	int mouseY;
	const Uint8* keyStates;

	bool isClicked;

public:

	Inputs();
	void update();
	bool checkForQuit(SDL_Event event);
	bool getQuit();
	int getMouseX();
	int getMouseY();
	bool isKeyDown(int key);
	bool click();
};

#endif // !INPUTS_H
