#include "Menu.h"
#include "Sound.h"
#include <iostream>
#include <math.h>

#define CIRCLE_EPSILON 9.6f
#define PLAY_EPSILON 20000
#define EXIT_EPSILON 2000

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
	setting = false;
	retry = false;
	quit = false;

	opacity = 255;
	state = -1;
	music = true;
}

bool insideRotatedRectButton(double xS, double yS, double xA, double yA, double xB, double yB, double xC, double yC, double xD, double yD, double epsilon) {
	double Sabcd = sqrt(pow((xA - xB),2) + pow((yA - yB),2)) * sqrt(pow((xA - xD), 2) + pow((yA - yD), 2));
	double Ssab = abs((xA - xS) * (yB - yS) - (xB - xS) * (yA - yS)) / 2;
	double Sscd = abs((xC - xS) * (yD - yS) - (xD - xS) * (yC - yS)) / 2;
	double Ssad = abs((xA - xS) * (yD - yS) - (xD - xS) * (yA - yS)) / 2;
	double Ssbc = abs((xC - xS) * (yB - yS) - (xB - xS) * (yC - yS)) / 2;
	//std::cout << Sabcd << "_" << Ssab + Ssad + Ssbc + Sscd << std::endl;
	return (abs(Sabcd - (Ssab + Ssad + Ssbc + Sscd)) < epsilon);
}

bool insideCircleButton(double xM, double yM, double xO, double yO, double R, double epsilon) {
	//std::cout << sqrt(pow((xM - xO), 2) + pow((yM - yO), 2)) - R << std::endl;
	return (sqrt(pow((xM - xO), 2) + pow((yM - yO), 2)) - R <= epsilon);
}



void Menu::renderStartScreen(SDL_Renderer* renderer, Resources* resources) {
	SDL_Texture* texture;
	texture = resources->getTexture("menu", 0);

	SDL_Rect dst = { 0, 0, screenWidth, screenHeight };

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
	switch (clock->gameState)
	{
	case OPENING_STATE:
		break;
	case START_STATE:
		renderStartScreen(renderer, resources, BACKGROUND);

		if (insideRotatedRectButton(mouseX, mouseY, 300, 450, 875, 140, 1080, 450, 525, 830, PLAY_EPSILON)) {
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
		//std::cout << "EXIT: ";
		if (insideRotatedRectButton(mouseX, mouseY, 1190, 858, 1525, 658, 1666, 858, 1333, 1040, EXIT_EPSILON)) {
			
			renderStartScreen(renderer, resources, OVER_EXIT_BUTTON);
		}
		else {
			renderStartScreen(renderer, resources, EXIT_BUTTON);
		}
		
		break;

	// render start screen
	case PLAY_STATE:
		settingButton.x = 850;
		settingButton.y = 10;
		settingButton.w = 40;
		settingButton.h = 40;
		renderButton(renderer, resources, clock, "setting_button", &settingButton);
		break;

	// render setting screen
	case PAUSE_STATE:
		//renderTransparentBlackBG(renderer, resources);
		renderButton(renderer, resources, clock, "retry_button", &retryButton);
		renderButton(renderer, resources, clock, "resume_button", &resumeButton);
		renderButton(renderer, resources, clock, "quit_button", &quitButton);
		break;

	case GAME_OVER_STATE:
		//renderTransparentBlackBG(renderer, resources);
		renderButton(renderer, resources, clock, "retry_button", &retryButton);
		renderButton(renderer, resources, clock, "quit_button", &quitButton);
		break;
	}
}

bool insideButton(SDL_Rect* dst, Inputs* inputs) {
	return (dst->x <= inputs->getMouseX() && inputs->getMouseX() <= dst->x + dst->w
		&& dst->y <= inputs->getMouseY() && inputs->getMouseY() <= dst->y + dst->h);
}

void Menu::update(Clock* clock, Inputs* inputs, double velocity, Sound* sound) {
	mouseX = inputs->getMouseX();
	mouseY = inputs->getMouseY();
	switch(clock->gameState){
	case OPENING_STATE:
		
		break;
	case START_STATE:
		//std::cout << "HI" << std::endl;
		if (insideRotatedRectButton(mouseX, mouseY, 300, 450, 875, 140, 1080, 450, 525, 830, PLAY_EPSILON)) {
			if (inputs->click()) {
				clock->gameState = PLAY_STATE;
				sound->playMusic();
			}
		}
		if (insideRotatedRectButton(mouseX, mouseY, 1190, 858, 1525, 658, 1666, 858, 1333, 1040, EXIT_EPSILON)) {
			if (inputs->click()) {
				sound->pauseMusic();
				clock->quit = true;
			}
		}
		break;
	case PLAY_STATE:
		
		break;

	case PAUSE_STATE:
		
		break;

	case GAME_OVER_STATE:
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