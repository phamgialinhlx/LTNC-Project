#pragma once
#ifndef THE_GAME
#define THE_GAME

#include <SDL.h>
#include <string>
#include <iostream>

class theGame
{
public:
	theGame();
	~theGame();

	void clearScreen();
	void initSDL();
private:
	static const int screenWidth, screenHeight;
	static const std::string windowTitle;

	SDL_Window* screenWindow;
	SDL_Renderer* renderer;
};



#endif // !THE_GAME
