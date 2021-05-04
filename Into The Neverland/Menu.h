#ifndef BUTTON_H
#define BUTTON_H

#include <SDL.h>
#include <string>
#include "GameObjects.h"


#define CIRCLE_EPSILON 9.6f

#define PLAY_BUTTON_X_A 300
#define PLAY_BUTTON_Y_A 450
#define PLAY_BUTTON_X_B 875
#define PLAY_BUTTON_Y_B 140
#define PLAY_BUTTON_X_C 1080
#define PLAY_BUTTON_Y_C 450
#define PLAY_BUTTON_X_D 525
#define PLAY_BUTTON_Y_D 830

#define EXIT_BUTTON_X_A 1190
#define EXIT_BUTTON_Y_A 858
#define EXIT_BUTTON_X_B 1525
#define EXIT_BUTTON_Y_B 658
#define EXIT_BUTTON_X_C 1666
#define EXIT_BUTTON_Y_C 858
#define EXIT_BUTTON_X_D 1333
#define EXIT_BUTTON_Y_D 1040

#define SETTING_BUTTON_X 1600 - 40 - 80
#define SETTING_BUTTON_Y 30
#define SETTING_BUTTON_W 100
#define SETTING_BUTTON_H 100

#define PAUSE_BUTTON_X 250
#define PAUSE_BUTTON_Y 200
#define PAUSE_BUTTON_H 80

#define MUTE_BUTTON_Y 40
#define MUTE_BUTTON_W 70
#define MUTE_BUTTON_H 70

#define YES_X 
#define YES_Y 

#define NO_X 
#define NO_Y

class Menu : public GameObjects
{
private:

	std::vector<GameObjects*>* gameObjects;
	SDL_Rect settingButton = { (int)SETTING_BUTTON_X, SETTING_BUTTON_Y, SETTING_BUTTON_W, SETTING_BUTTON_H };
	SDL_Rect fullscreenRect = { 0, 0, (int)screenWidth, (int)screenHeight };
	SDL_Rect resumeRect = { PAUSE_BUTTON_X, PAUSE_BUTTON_Y, DEFAULT, PAUSE_BUTTON_H };
	SDL_Rect restartRect = { PAUSE_BUTTON_X, PAUSE_BUTTON_Y + PAUSE_BUTTON_H + 80, DEFAULT, PAUSE_BUTTON_H };
	SDL_Rect quitRect = { PAUSE_BUTTON_X, PAUSE_BUTTON_Y + PAUSE_BUTTON_H*2 + 160, DEFAULT, PAUSE_BUTTON_H };
	SDL_Rect muteRect;
	SDL_Rect yesButton;
	SDL_Rect noButton;

	double screenWidth;
	double screenHeight;

	double mouseX, mouseY;
	bool music;

	void renderButton(SDL_Renderer* renderer, Resources* resources, Clock* clock, std::string textureName, SDL_Rect* dst);


public:
	int state;
	
	Menu(std::vector<GameObjects*>* gameObjects,double screenWidth, double screenHeight);
	~Menu();
	void render(SDL_Renderer* renderer, Resources* resources, Clock* clock);
	void update(Clock* clock, Inputs* inputs, double velocity, Sound* sound);

	void renderStartScreen(SDL_Renderer* renderer, Resources* resources, int type);
	void renderTextButton(SDL_Renderer* renderer, Resources* resources, std::string buttonName, SDL_Rect* buttonRect);
	void renderTransparentBlackBG(SDL_Renderer* renderer, Resources* resources);
	bool isClicked();

	bool isAlive();
	int getID();
	void die();
};

#endif // !BUTTON_H
