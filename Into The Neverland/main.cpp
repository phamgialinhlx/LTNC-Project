#include <time.h>
#include "TheGame.h"
#include "Graphics.h"
#include "Inputs.h"
#include "Effects.h"


int main(int argc, char* argv[])
{
	srand(time(NULL));
	
	Sound* sound = new Sound;
	Clock* clock = new Clock;
	Inputs* inputs = new Inputs;
	Graphics* graphics = new Graphics;
	Effects* effects = new Effects(&graphics->screenWidth, &graphics->screenHeight);
	theGame* intoTheNeverland= new theGame(graphics->screenWidth, graphics->screenHeight);
	
	bool loop = true;
	while (loop) {
		
		clock->tick();
		
		inputs->update();
		loop = !inputs->getQuit();
		
		if (effects->effectType != NONE) {
			effects->update(clock, inputs, sound);
		}
		intoTheNeverland->update(inputs, clock, sound, effects);
		
		graphics->renderGameObjects(intoTheNeverland->getGameObjects(), clock, effects);

		if (clock->quit) {
			break;
		}

		clock->delay();
		
	}
	
	delete intoTheNeverland;
	delete sound;
	delete clock;
	delete graphics;
	delete effects;

	return 0;
}