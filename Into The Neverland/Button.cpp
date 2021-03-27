#include "Button.h"
#include <iostream>

Button::Button(std::vector<GameObjects*>* gameObjects)
	:GameObjects(x, y, width, height, screenWidth, screenHeight) {
	this->gameObjects = gameObjects;
	setting = false;
	retry = false;
	quit = false;
	//Set the x, y, width, height for setting button
	settingButton.x = 850;
	settingButton.y = 10;
	settingButton.w = 40;
	settingButton.h = 40;
	
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
}

void Button::renderTransparentBlackBG(SDL_Renderer* renderer, Resources* resources) {
	SDL_Texture* texture;
	texture = resources->getTexture("black", 0);


	SDL_Rect dst = { 0, 0, 900, 400 };

	SDL_SetTextureAlphaMod(texture, 100);

	SDL_RenderCopyEx(renderer, texture, NULL, &dst, 0,
		NULL, SDL_FLIP_NONE);
}



void Button::renderButton(SDL_Renderer* renderer, Resources* resources, Clock* clock, std::string textureName, const SDL_Rect* dst) {
	SDL_Texture* texture;
	texture = resources->getTexture(textureName, 0);

	SDL_RenderCopyEx(renderer, texture, NULL, dst, 0,
		NULL, SDL_FLIP_NONE);
}


void Button::render(SDL_Renderer* renderer, Resources* resources, Clock* clock) {
	renderButton(renderer, resources, clock, "setting_button", &settingButton);
	if (setting) {
		renderTransparentBlackBG(renderer, resources);
		renderButton(renderer, resources, clock, "retry_button", &retryButton);
		renderButton(renderer, resources, clock, "resume_button", &resumeButton);
		renderButton(renderer, resources, clock, "quit_button", &quitButton);

	}
}

bool insideButton(SDL_Rect* dst, Inputs* inputs) {
	return (dst->x <= inputs->getMouseX() && inputs->getMouseX() <= dst->x + dst->w
		&& dst->y <= inputs->getMouseY() && inputs->getMouseY() <= dst->y + dst->h);
}

void Button::update(Clock* clock, Inputs* inputs) {
	//update setting button
	if (insideButton(&settingButton, inputs)){
		if (inputs->click() && !setting) {
			setting = true;
			//std::cout << "[Button]: clicked" << std::boolalpha << " " << clicked << std::endl;
		}
		else {

		}
	}
	//update resume button
	if (insideButton(&resumeButton, inputs)) {
		if (inputs->click() && setting) {
			setting = false;
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
}

bool Button::isAlive() {
	return true;
}

int Button::getID() {
	return 4;
}

void Button::die() {

}
