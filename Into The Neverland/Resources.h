#pragma once
#ifndef RESOURCES_H
#define RESOURCES_H

#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <map>
#include <iostream>


class Resources {
private:
	SDL_Renderer* renderer;
	SDL_Texture* background;
	std::map<std::string, std::map<int, SDL_Texture*> > texture;
public:
	Resources(SDL_Renderer* renderer);
	~Resources();
	void loadResources();
	void loadTexture(SDL_Texture** texture, std::string filename);
	SDL_Texture* getTexture(std::string path, int frame);
};

#endif