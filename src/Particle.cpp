#include "Particle.h"

Particle::Particle(double x, double y, double vX, double vY, double scale, std::string particleName)
		:GameObjects(x, y, width, height, screenWidth, screenHeight, hitbox)
{
	opacity = 255;
	this->scale = scale;
	this->vX = vX;
	this->vY = vY;
	this->particleName = particleName;

}
void Particle::render(SDL_Renderer* renderer, Resources* resources, Clock* clock) {
	switch (clock->gameState) {
	case OPENING_STATE:
	case START_STATE:
	case GAME_OVER_STATE:
		break;
	case PAUSE_STATE:
	{
		break;
	}
	case PLAY_STATE:
		if (particleName == "pow") {
			int w, h;
			SDL_Texture* texture = resources->getTexture(particleName, DEFAULT);
			SDL_QueryTexture(texture, NULL, NULL, &w, &h);
			SDL_Rect rect = { x, y, w / scale , h / scale };
			SDL_SetTextureAlphaMod(texture, opacity);
			SDL_RenderCopy(renderer, texture, NULL, &rect);
		}
		else {
			int w, h;
			SDL_Texture* texture = resources->getTexture(particleName, DEFAULT);
			SDL_QueryTexture(texture, NULL, NULL, &w, &h);
			SDL_Rect rect = { x - w / scale, y - h / scale, w / scale , h / scale };
			SDL_SetTextureAlphaMod(texture, opacity);
			SDL_RenderCopy(renderer, texture, NULL, &rect);
		}
	}
}


void Particle::update(Clock* clock, Inputs* inputs, double veloctity, Sound* sound){
	switch (clock->gameState) {
	case OPENING_STATE:
	case START_STATE:
	case GAME_OVER_STATE:
		break;
	case PAUSE_STATE:
		break;
	case PLAY_STATE:

		if (particleName == "pow") {
			y += vY / 10 * clock->deltaT + 0.5f * ACCELERATION * clock->deltaT * clock->deltaT;
			x += vX / 10 * clock->deltaT + 0.5f * ACCELERATION * clock->deltaT * clock->deltaT;
			scale -= POW_SCALE;
		}
		else if (particleName == "danger") {
			x += vX / 10 * 1.2;
			y += vY / 10 * 1.2;
			scale -= DANGER_SCALE;
		}
		
		
		opacity -= 5;
		if (opacity < 0) {
			opacity = 0;
		}
	}
}




bool Particle::isAlive() {
	return (opacity != 0);
}
int Particle::getID() {
	return PARTICLE_ID;
}
