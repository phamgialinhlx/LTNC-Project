#pragma once

#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include "GameObjects.h"



class Button : public GameObjects
{
private:
	std::vector<GameObjects*>* gameObjects;
	SDL_Rect settingButton, resumeButton, retryButton, quitButton;

	void renderButton(SDL_Renderer* renderer, Resources* resources, Clock* clock, std::string textureName, const SDL_Rect* dst);

public:

	bool setting;
	bool retry;
	bool quit;

	Button(std::vector<GameObjects*>* gameObjects);
	void render(SDL_Renderer* renderer, Resources* resources, Clock* clock);
	void update(Clock* clock, Inputs* inputs);

	void renderTransparentBlackBG(SDL_Renderer* renderer, Resources* resources);
	bool isClicked();

	bool isAlive();
	int getID();
	void die();
};

#endif // !BUTTON_H
