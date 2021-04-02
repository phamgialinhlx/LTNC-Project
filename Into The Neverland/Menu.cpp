#include "Menu.h"
#include <iostream>

#define DEFAULT 0
#define START_SCREEN 1
#define SETTING_SCREEN 2
#define GAMEOVER_SCREEN 3

Menu::Menu(std::vector<GameObjects*>* gameObjects)
	:GameObjects(x, y, width, height, screenWidth, screenHeight, hitbox) {
	this->gameObjects = gameObjects;
	setting = false;
	retry = false;
	quit = false;
	menuType = START_SCREEN;
}

void Menu::renderTransparentBlackBG(SDL_Renderer* renderer, Resources* resources) {
	SDL_Texture* texture;
	texture = resources->getTexture("black", 0);


	SDL_Rect dst = { 0, 0, 900, 400 };

	SDL_SetTextureAlphaMod(texture, 100);

	SDL_RenderCopyEx(renderer, texture, NULL, &dst, 0,
		NULL, SDL_FLIP_NONE);
}

void Menu::renderStartScreen(SDL_Renderer* renderer, Resources* resources) {
	SDL_Texture* texture;
	texture = resources->getTexture("menu", 0);

	SDL_Rect dst = { 0, 0, 900, 400 };

	SDL_RenderCopyEx(renderer, texture, NULL, &dst, 0,
		NULL, SDL_FLIP_NONE);
}


void Menu::renderButton(SDL_Renderer* renderer, Resources* resources, Clock* clock, std::string textureName, SDL_Rect* dst) {
	SDL_Texture* texture;
	
	texture = resources->getTexture(textureName, 0);
	
	SDL_RenderCopyEx(renderer, texture, NULL, dst, 0,
		NULL, SDL_FLIP_NONE);
}


void Menu::render(SDL_Renderer* renderer, Resources* resources, Clock* clock) {
	switch (menuType)
	{
	case DEFAULT:
		renderButton(renderer, resources, clock, "setting_button", &settingButton);
		
		break;
	// render start screen
	case START_SCREEN:
		renderStartScreen(renderer, resources);
		renderButton(renderer, resources, clock, "start_button", &startButton);
		break;
	// render setting screen
	case SETTING_SCREEN:

		renderTransparentBlackBG(renderer, resources);
		renderButton(renderer, resources, clock, "retry_button", &retryButton);
		renderButton(renderer, resources, clock, "resume_button", &resumeButton);
		renderButton(renderer, resources, clock, "quit_button", &quitButton);
		break;
	}
	
}

bool insideButton(SDL_Rect* dst, Inputs* inputs) {
	return (dst->x <= inputs->getMouseX() && inputs->getMouseX() <= dst->x + dst->w
		&& dst->y <= inputs->getMouseY() && inputs->getMouseY() <= dst->y + dst->h);
}

void Menu::update(Clock* clock, Inputs* inputs, double velocity) {
	switch(menuType){
	case DEFAULT:
		//update setting button
		resetButton();
		if (insideButton(&settingButton, inputs)) {
			if (inputs->click() && !setting) {
				setting = true;
				clock->pause = true;
				//std::cout << "[Button]: clicked" << std::boolalpha << " " << clicked << std::endl;
			}
			else {

			}
		}
		break;
	case START_SCREEN:
		resetButton();
		if (insideButton(&startButton, inputs)) {
			if (inputs->click()) {
				clock->start = true;
				clock->pause = false;
				menuType = DEFAULT;
			}
		}
		//
		break;
	case SETTING_SCREEN:
		resetButton();
		//update resume button
		if (insideButton(&resumeButton, inputs)) {
			if (inputs->click() && setting) {
				setting = false;
				clock->pause = false;
				menuType = DEFAULT;
				//std::cout << "[Button]: clicked" << std::boolalpha << " " << clicked << std::endl;
			}
			else {

			}
		}

		//update retry button
		if (insideButton(&retryButton, inputs)) {
			if (inputs->click() && setting) {
				setting = false;
				retry = true;
				clock->pause = false;
				clock->characterLifeTime = 0;
			}
			else {

			}
		}

		//update quit button
		if (insideButton(&quitButton, inputs)) {
			if (inputs->click() && setting) {
				setting = false;
				quit = true;
			}
			else {

			}
		}
		break;
	case GAMEOVER_SCREEN:
		resetButton();
		// 
		break;
	}
}

bool Menu::isAlive() {
	return true;
}

int Menu::getID() {
	return 4;
}

void Menu::die() {

}

void Menu::resetButton() {
	switch (menuType) {
	case DEFAULT:
		//Set the x, y, width, height for setting button
		settingButton.x = 850;
		settingButton.y = 10;
		settingButton.w = 40;
		settingButton.h = 40;
		break;
	case START_SCREEN:
		////Set the x, y, width, height for start button
		startButton.x = 335;
		startButton.y = 239;
		startButton.w = 210;
		startButton.h = 90;
		break;
	case SETTING_SCREEN:
		//Set the x, y, width, height for resume button
		resumeButton.x = 625;
		resumeButton.y = 150;
		resumeButton.w = 150;
		resumeButton.h = 50;

		//Set the x, y, width, height for retry button
		retryButton.x = 425;
		retryButton.y = 150;
		retryButton.w = 150;
		retryButton.h = 50;

		//Set the x, y, width, height for quit button
		quitButton.x = 225;
		quitButton.y = 150;
		quitButton.w = 150;
		quitButton.h = 50;
		break;
	case GAMEOVER_SCREEN:
		// 
		break;
	}
}