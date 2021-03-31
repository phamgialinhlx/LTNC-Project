#pragma once
#ifndef RESOURCES_H
#define RESOURCES_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include <map>
#include <iostream>


class Resources {
private:
	TTF_Font* font = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Texture* background = NULL;
	std::map<std::string, std::map<int, SDL_Texture*> > texture;

	

public:
	Resources(SDL_Renderer* renderer);
	~Resources();
	void loadResources();
	void loadTexture(SDL_Texture** texture, std::string filename);
	void loadTextTexture(SDL_Texture** texture, std::string text);
	SDL_Texture* getTexture(std::string path, int frame);
	SDL_Texture* createTextTexture(std::string text);
};

#endif