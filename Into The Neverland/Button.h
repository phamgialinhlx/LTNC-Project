#pragma once

#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include "GameObjects.h"



class Button : public GameObjects
{
private:
	std::vector<GameObjects*>* gameObjects;
	SDL_Rect settingButton, resumeButton;

	void renderSettingButton(SDL_Renderer* renderer, Resources* resources, Clock* clock);
	void renderResumeButton(SDL_Renderer* renderer, Resources* resources, Clock* clock);

public:

	bool setting;
	bool resume;

	Button(std::vector<GameObjects*>* gameObjects);
	void render(SDL_Renderer* renderer, Resources* resources, Clock* clock);
	void update(double timeBetweenFrames, Inputs* inputs);

	bool isClicked();

	bool isAlive();
	int getID();
	void die();
};

#endif // !BUTTON_H
