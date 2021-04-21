#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include <string>
#include "GameObjects.h"



class Menu : public GameObjects
{
private:
	std::vector<GameObjects*>* gameObjects;
	SDL_Rect settingButton, resumeButton, retryButton, quitButton, startButton;

	double screenWidth;
	double screenHeight;

	double mouseX, mouseY;

	void renderButton(SDL_Renderer* renderer, Resources* resources, Clock* clock, std::string textureName, SDL_Rect* dst);

public:

	bool music;
	bool setting;
	bool retry;
	bool quit;
	int menuType;
	int state;
	double opacity;

	Menu(std::vector<GameObjects*>* gameObjects,double screenWidth, double screenHeight);
	void render(SDL_Renderer* renderer, Resources* resources, Clock* clock);
	void update(Clock* clock, Inputs* inputs, double velocity, Sound* sound);

	void renderStartScreen(SDL_Renderer* renderer, Resources* resources, int type);
	void renderStartScreen(SDL_Renderer* renderer, Resources* resources);
	void renderTransparentBlackBG(SDL_Renderer* renderer, Resources* resources);
	bool isClicked();

	bool isAlive();
	int getID();
	void die();
};

#endif // !BUTTON_H
