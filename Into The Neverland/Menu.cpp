#include "Menu.h"
#include "Sound.h"
#include <iostream>
#include <math.h>

enum MENU
{
	BACKGROUND,
	SOUND_ON_BUTTON,
	SOUND_OFF_BUTTON,
	EXIT_BUTTON,
	PLAY_BUTTON,
	OVER_SOUND_ON_BUTTON,
	OVER_SOUND_OFF_BUTTON,
	OVER_EXIT_BUTTON,
	OVER_PLAY_BUTTON
};

Menu::Menu(std::vector<GameObjects*>* gameObjects, double screenWidth,double screenHeight)
	:GameObjects(x, y, width, height, screenWidth, screenHeight, hitbox)
{
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	this->gameObjects = gameObjects;
	
	state = -1;
	music = true;
	muteRect = { (int)(screenWidth - MUTE_BUTTON_W - MUTE_BUTTON_Y), MUTE_BUTTON_Y, MUTE_BUTTON_W, MUTE_BUTTON_H };
}

bool leftOfTheLine(double xS, double yS, double xM, double yM, double xN, double yN) {
	return ((xM - xN) * (yS - yM) - (yM - yN) * (xS - xM) <= 0);
}

bool insideRectButton(double xS, double yS, double xA, double yA, double xB, double yB, double xC, double yC, double xD, double yD) {
	return (leftOfTheLine(xS, yS, xA, yA, xB, yB) && !leftOfTheLine(xS, yS, xA, yA, xD, yD)
		&& leftOfTheLine(xS, yS, xB, yB, xC, yC) && leftOfTheLine(xS, yS, xC, yC, xD, yD));
}

bool insideRectButton(SDL_Rect* dst, int mouseX, int mouseY) {
	return (dst->x <= mouseX && mouseX <= dst->x + dst->w
		&& dst->y <= mouseY && mouseY <= dst->y + dst->h);
}


bool insideCircleButton(double xM, double yM, double xO, double yO, double R, double epsilon) {
	//std::cout << sqrt(pow((xM - xO), 2) + pow((yM - yO), 2)) - R << std::endl;
	return (sqrt(pow((xM - xO), 2) + pow((yM - yO), 2)) - R <= epsilon);
}



void Menu::renderButton(SDL_Renderer* renderer, Resources* resources, Clock* clock, std::string textureName, SDL_Rect* dst) {
	SDL_Texture* texture;
	
	texture = resources->getTexture(textureName, 0);
	
	SDL_RenderCopyEx(renderer, texture, NULL, dst, 0,
		NULL, SDL_FLIP_NONE);
}


void Menu::render(SDL_Renderer* renderer, Resources* resources, Clock* clock) {
	switch (clock->gameState)
	{
	case OPENING_STATE:
		break;
	case START_STATE:
	{
		renderStartScreen(renderer, resources, BACKGROUND);

		if (insideRectButton(mouseX, mouseY, PLAY_BUTTON_X_A, PLAY_BUTTON_Y_A, PLAY_BUTTON_X_B,
			PLAY_BUTTON_Y_B, PLAY_BUTTON_X_C, PLAY_BUTTON_Y_C, PLAY_BUTTON_X_D, PLAY_BUTTON_Y_D))
		{
			renderStartScreen(renderer, resources, OVER_PLAY_BUTTON);
		}
		else {
			renderStartScreen(renderer, resources, PLAY_BUTTON);
		}

		if (music) {
			if (insideCircleButton(mouseX, mouseY, 20, 158, 63, CIRCLE_EPSILON)) {
				renderStartScreen(renderer, resources, OVER_SOUND_ON_BUTTON);
			}
			else {
				renderStartScreen(renderer, resources, SOUND_ON_BUTTON);
			}
		}
		else {
			if (insideCircleButton(mouseX, mouseY, 20, 158, 63, CIRCLE_EPSILON)) {
				renderStartScreen(renderer, resources, OVER_SOUND_OFF_BUTTON);
			}
			else {
				renderStartScreen(renderer, resources, SOUND_OFF_BUTTON);
			}
		}
		if (insideRectButton(mouseX, mouseY, EXIT_BUTTON_X_A, EXIT_BUTTON_Y_A, EXIT_BUTTON_X_B,
			EXIT_BUTTON_Y_B, EXIT_BUTTON_X_C, EXIT_BUTTON_Y_C, EXIT_BUTTON_X_D, EXIT_BUTTON_Y_D))
		{
			renderStartScreen(renderer, resources, OVER_EXIT_BUTTON);
		}
		else {
			renderStartScreen(renderer, resources, EXIT_BUTTON);
		}

		break;
	}
	case PLAY_STATE:
	{
		renderButton(renderer, resources, clock, "setting_button", &settingButton);
		break;
	}
	case PAUSE_STATE:
	{
		renderTextButton(renderer, resources, "resume", &resumeRect);
		renderTextButton(renderer, resources, "restart", &restartRect);
		renderTextButton(renderer, resources, "quit", &quitRect);
		if (music) {
			if (insideRectButton(&muteRect, mouseX, mouseY))
			{
				SDL_Rect temp = muteRect;
				temp.x -= 10;
				temp.y -= 10;
				temp.w += 20;
				temp.h += 20;
				SDL_RenderCopy(renderer, resources->getTexture("unmute", DEFAULT), NULL, &temp);
			}
			else {
				SDL_RenderCopy(renderer, resources->getTexture("unmute", DEFAULT), NULL, &muteRect);
			}
		}
		else {
			if (insideRectButton(&muteRect, mouseX, mouseY))
			{
				SDL_Rect temp = muteRect;
				temp.x -= 10;
				temp.y -= 10;
				temp.w += 20;
				temp.h += 20;
				SDL_RenderCopy(renderer, resources->getTexture("mute", DEFAULT), NULL, &temp);
			}
			else {
				SDL_RenderCopy(renderer, resources->getTexture("mute", DEFAULT), NULL, &muteRect);
			}
		}
		break;
	}
	case GAME_OVER_STATE:
		int w, h;
		SDL_QueryTexture(resources->createTextTexture("wanna play again?", GAME_OVER_TEXT_SIZE),NULL, NULL, &w, &h);
		SDL_Rect temp = { (int)(screenWidth/2 - w/2), (int)(screenHeight/2 - 2*h), w, h };
		SDL_RenderCopy(renderer, resources->createTextTexture("wanna play again?", GAME_OVER_TEXT_SIZE), NULL, &temp);
		//render Yes

		SDL_QueryTexture(resources->createTextTexture("yes", GAME_OVER_BUTTON_SIZE), NULL, NULL, &w, &h);
		yesButton = { (int)(screenWidth / 3 - w), (int)(screenHeight / 4 * 3 - h), w, h };
		renderTextButton(renderer, resources, "yes", &yesButton);
		//render No
		SDL_QueryTexture(resources->createTextTexture("no", GAME_OVER_BUTTON_SIZE), NULL, NULL, &w, &h);
		noButton = { (int)(screenWidth * 2 / 3 + w/2), (int)(screenHeight / 4 * 3 - h), w, h };
		renderTextButton(renderer, resources, "no", &noButton);
		break;
	}
}

void Menu::update(Clock* clock, Inputs* inputs, double velocity, Sound* sound) {
	music = !sound->mute;
	mouseX = inputs->getMouseX();
	mouseY = inputs->getMouseY();
	switch(clock->gameState){
	case OPENING_STATE:
		
		break;
	case START_STATE:
		if (insideRectButton(mouseX, mouseY, PLAY_BUTTON_X_A, PLAY_BUTTON_Y_A, PLAY_BUTTON_X_B,
			PLAY_BUTTON_Y_B, PLAY_BUTTON_X_C, PLAY_BUTTON_Y_C, PLAY_BUTTON_X_D, PLAY_BUTTON_Y_D))
		{
			if (inputs->click()) {
				clock->gameState = PLAY_STATE;
				sound->playMusic();
			}
		}
		if ((insideCircleButton(mouseX, mouseY, 20, 158, 63, CIRCLE_EPSILON)))
		{
			if (inputs->click()) {
				sound->mute = !sound->mute;
			}
		}
		if (insideRectButton(mouseX, mouseY, EXIT_BUTTON_X_A, EXIT_BUTTON_Y_A, EXIT_BUTTON_X_B,
			EXIT_BUTTON_Y_B, EXIT_BUTTON_X_C, EXIT_BUTTON_Y_C, EXIT_BUTTON_X_D, EXIT_BUTTON_Y_D))
		{
			if (inputs->click()) {
				sound->pauseMusic();
				clock->quit = true;
			}
		}
		break;
	case PLAY_STATE:
		if (insideRectButton(&settingButton, mouseX, mouseY)) {
			if (inputs->click()) {
				clock->gameState = PAUSE_STATE;
			}
		}
		break;

	case PAUSE_STATE:
	{
		if (insideRectButton(&resumeRect, mouseX, mouseY)) {
			if (inputs->click()) {
				clock->gameState = PLAY_STATE;
			}
		}

		if (insideRectButton(&restartRect, mouseX, mouseY)) {
			if (inputs->click()) {
				clock->restart = true;
			}
		}

		if (insideRectButton(&quitRect, mouseX, mouseY)) {
			if (inputs->click()) {
				clock->quit = true;
			}
		}

		if (insideRectButton(&muteRect, mouseX, mouseY)) {
			if (inputs->click()) {
				sound->mute = !sound->mute;
			}
		}
		break;
	}
	case GAME_OVER_STATE:
	{
		if ((insideRectButton(&yesButton, mouseX, mouseY) && inputs->click()) || inputs->isKeyDown(SDL_SCANCODE_Y)) {
			clock->restart = true;
		}

		if ((insideRectButton(&noButton, mouseX, mouseY) && inputs->click()) || inputs->isKeyDown(SDL_SCANCODE_N)) {
			clock->quit = true;
		}
		break;
	}
	}
}

bool Menu::isAlive() {
	return true;
}

int Menu::getID() {
	return MENU_ID;
}

void Menu::die() {

}



void Menu::renderStartScreen(SDL_Renderer* renderer, Resources* resources, int type) {
	SDL_Texture* texture;
	texture = resources->getTexture("menu", type);
	SDL_Rect dst = {
		0,
		0,
		screenWidth,
		screenHeight
	};

	SDL_RenderCopyEx(renderer, texture, NULL, &dst, 0,
		NULL, SDL_FLIP_NONE);
}

void Menu::renderTextButton(SDL_Renderer* renderer, Resources* resources, std::string buttonName, SDL_Rect* buttonRect) {
	int w;
	SDL_QueryTexture(resources->createTextTexture(buttonName, PAUSE_BUTTON_SIZE), NULL, NULL, &w, NULL);
	buttonRect->w = w;
	SDL_Rect temp;
	if (insideRectButton(buttonRect, mouseX, mouseY)){
		temp.x = buttonRect->x - 10;
		temp.y = buttonRect->y - 10;
		temp.w = buttonRect->w + 20;
		temp.h = buttonRect->h + 20;
		SDL_RenderCopy(renderer, resources->createTextTexture(buttonName, PAUSE_BUTTON_SIZE), NULL, &temp);
	}
	else {
		temp.x = buttonRect->x;
		temp.y = buttonRect->y;
		temp.w = buttonRect->w;
		temp.h = buttonRect->h;
		SDL_RenderCopy(renderer, resources->createTextTexture(buttonName, PAUSE_BUTTON_SIZE), NULL, &temp);
	}
}

Menu::~Menu() {

}