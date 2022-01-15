#pragma once
#ifndef EFFECTS_H
#define EFFECTS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Clock.h"
#include "Inputs.h"
#include "Resources.h"
#include "Sound.h"

enum EFFECT_TYPES {
	NONE,
	CREDIT,
	FADE,
	FLASH
};


class Effects{
private:

	double xCredit, yCredit;
	double opacity;
	const int * screenWidth, * screenHeight;
	bool init;
	
	bool brighter;

public:

	bool finish;
	int effectType;
	Effects(const int * screenWidth, const int *screenHeight);
	void renderTransparentBG(SDL_Renderer* renderer, Resources* resources, double opacity, std::string bgName);
	void render(SDL_Renderer* renderer, Resources* resources, Clock* clock);
	void update(Clock* clock, Inputs* inputs, Sound* sound);
	
};
#endif // !EFFECTS_H
