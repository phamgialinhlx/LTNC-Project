#include "Effects.h"
#include <iostream>

Effects::Effects(const int* screenWidth, const int* screenHeight) {
	xCredit = 100;
	yCredit = 75;
	opacity = 255;
	effectType = CREDIT;
	init = true;
	finish = false;
	brighter = true;

	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
}

void Effects::renderTransparentBG(SDL_Renderer* renderer, Resources* resources, double opacity, std::string bgName) {
	SDL_Texture* texture;
	texture = resources->getTexture(bgName, 0);

	SDL_Rect dst = { 0, 0, *screenWidth, *screenHeight };

	SDL_SetTextureAlphaMod(texture, opacity);

	SDL_RenderCopyEx(renderer, texture, NULL, &dst, 0,
		NULL, SDL_FLIP_NONE);
}

void Effects::render(SDL_Renderer* renderer, Resources* resources, Clock* clock) {
	switch (effectType)
	{
	case NONE:

		break;

	case CREDIT:
	{
		SDL_Texture* texture;
		texture = resources->getTexture("credit", 0);

		SDL_Rect dst = { xCredit , yCredit, *screenWidth * 1.5, *screenHeight * 1.5 };

		SDL_RenderCopyEx(renderer, texture, NULL, &dst, 0,
			NULL, SDL_FLIP_NONE);

		renderTransparentBG(renderer, resources, opacity, "black");
		break;
	}
	case FADE:
		renderTransparentBG(renderer, resources, opacity, "black");
		break;

	case FLASH:
		renderTransparentBG(renderer, resources, opacity, "white");
		break;
	}
	
}


void Effects::update(Clock* clock, Inputs* inputs, Sound* sound) {
	switch (effectType)
	{
	case NONE:

		break;

	case CREDIT:
	{
		//std::cout << opacity << std::endl;
		if (brighter) {
			opacity -= 9;
		}
		else {
			opacity += 9;
			if (opacity > 255) {
				finish = true;
				effectType = NONE;
				opacity = 255;
				init = false;
			}
		}
		xCredit -= 7;
		yCredit -= 5;
		if (opacity < 0) {
			opacity = 0;
			brighter = false;
		}
		SDL_Delay(100);
		break;
	}
	case FADE:
		//std::cout << opacity << std::endl;
		if (!init) {
			finish = false;
			opacity = 255;
			init = true;
		}
		opacity -= 15;
		if (opacity < 0) {
			opacity = 0;
			effectType = NONE;
			init = false;
			finish = true;
		}
		//SDL_Delay(50);
		break;

	case FLASH:
		
		if (!init) {
			finish = false;
			opacity = 255;
			init = true;
		}
		opacity -= 10;
		if (opacity < 0) {
			opacity = 0;
			effectType = NONE;
			init = false;
			finish = true;
		}
		break;
	}
}
