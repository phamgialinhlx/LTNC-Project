#pragma once
#ifndef RESOURCES_H
#define RESOURCES_H


#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <map>
#include <iostream>

#define SCORE_SIZE 40
#define BEST_SCORE_SIZE 20
#define PAUSE_BUTTON_SIZE 100
#define GAME_OVER_TEXT_SIZE 100
#define GAME_OVER_BUTTON_SIZE 90

#define DEFAULT 0

class Resources {
private:
	SDL_Renderer* renderer = NULL;
	SDL_Texture* background = NULL;
	std::map<std::string, std::map<int, SDL_Texture*> > texture;
	std::map<int, TTF_Font*> font;
	

public:
	Resources(SDL_Renderer* renderer);
	~Resources();
	void loadResources();
	void loadTexture(SDL_Texture** texture, std::string filename);
	void loadTextTexture(SDL_Texture** texture, std::string text);
	SDL_Texture* getTexture(std::string path, int frame);
	SDL_Texture* createTextTexture(std::string text, int size);
};

#endif