#include "Button.h"
#include <iostream>

Button::Button(std::vector<GameObjects*>* gameObjects)
	:GameObjects(x, y, width, height, screenWidth, screenHeight) {
	this->gameObjects = gameObjects;
	setting = false;
	resume = false;
	//Set the x, y, width, height for setting button
	settingButton.x = 850;
	settingButton.y = 10;
	settingButton.w = 40;
	settingButton.h = 40;
	
	//Set the x, y, width, height for resume button
	resumeButton.x = 525;
	resumeButton.y = 150;
	resumeButton.w = 150;
	resumeButton.h = 50;
}

void Button::renderSettingButton(SDL_Renderer* renderer, Resources* resources, Clock* clock) {
	SDL_Texture* texture;
	texture = resources->getTexture("setting_button", 0);

	SDL_RenderCopyEx(renderer, texture, NULL, &settingButton, 0,
		NULL, SDL_FLIP_NONE);
}

void Button::renderResumeButton(SDL_Renderer* renderer, Resources* resources, Clock* clock) {
	SDL_Texture* texture;
	texture = resources->getTexture("resume_button", 0);

	SDL_RenderCopyEx(renderer, texture, NULL, &resumeButton, 0,
		NULL, SDL_FLIP_NONE);
}

void Button::render(SDL_Renderer* renderer, Resources* resources, Clock* clock) {
	renderSettingButton(renderer, resources, clock);
	if (setting) {
		renderResumeButton(renderer, resources, clock);
	}
}

void Button::update(double timeBetweenFrames, Inputs* inputs) {
	//update setting button
	if (settingButton.x <= inputs->getMouseX() && inputs->getMouseX() <= settingButton.x + settingButton.w
		&& settingButton.y <= inputs->getMouseY() && inputs->getMouseY() <= settingButton.y + settingButton.h) {
		if (inputs->click() && !setting) {
			setting = true;
			//std::cout << "[Button]: clicked" << std::boolalpha << " " << clicked << std::endl;
		}
		else {

		}
	}
	//update resume button
	if (resumeButton.x <= inputs->getMouseX() && inputs->getMouseX() <= resumeButton.x + resumeButton.w
		&& resumeButton.y <= inputs->getMouseY() && inputs->getMouseY() <= resumeButton.y + resumeButton.h) {
		if (inputs->click() && setting) {
			setting = false;
			//std::cout << "[Button]: clicked" << std::boolalpha << " " << clicked << std::endl;
		}
		else {

		}
	}
}

bool Button::isAlive() {
	return true;
}
int Button::getID() {
	return 4;
}
void Button::die() {

}
