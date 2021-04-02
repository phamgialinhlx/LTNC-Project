#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include "GameObjects.h"



class Menu : public GameObjects
{
private:
	std::vector<GameObjects*>* gameObjects;
	SDL_Rect settingButton, resumeButton, retryButton, quitButton, startButton;

	void renderButton(SDL_Renderer* renderer, Resources* resources, Clock* clock, std::string textureName, SDL_Rect* dst);

public:

	bool setting;
	bool retry;
	bool quit;
	int menuType;

	Menu(std::vector<GameObjects*>* gameObjects);
	void render(SDL_Renderer* renderer, Resources* resources, Clock* clock);
	void update(Clock* clock, Inputs* inputs, double velocity);

	void resetButton();
	void renderStartScreen(SDL_Renderer* renderer, Resources* resources);
	void renderTransparentBlackBG(SDL_Renderer* renderer, Resources* resources);
	bool isClicked();

	bool isAlive();
	int getID();
	void die();
};

#endif // !BUTTON_H
