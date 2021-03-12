#pragma once
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
#include <string>
#include <vector>
#include "Resources.h"
#include "GameObjects.h"



class Graphics {
private:
	static const int screenWidth, screenHeight;
	static const std::string windowTitle;
	Resources* resources;
	SDL_Window* screenWindow;
	SDL_Renderer* renderer;


public:
	Graphics();
	~Graphics();

	bool initSDL();

	void clearScreen();
	void renderGameObjects(std::vector<GameObjects*>* gameObjects, double timeBetweenFrames);
	void rendererPresent();
	int getScreenWidth();
	int getScreenHeight();
};


#endif // !GRAPHICS_H
