#pragma once
#ifndef INPUTS_H
#define INPUTS_H

#include <SDL.h>

class Inputs {

	bool quit;
	int mouseX;
	int mouseY;
	const Uint8* keyStates;

	

public:

	Inputs();
	void update();
	bool checkForQuit(SDL_Event event);
	bool getQuit();
	bool isKeyDown(int key);

};

#endif // !INPUTS_H
