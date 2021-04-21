#include <time.h>
#include "TheGame.h"
#include "Graphics.h"
#include "Inputs.h"
#include "Effects.h"


int main(int argc, char* argv[])
{
	//std::cout << "here" << std::endl;
	srand(time(NULL));
	
	Sound sound;
	Clock clock;
	Inputs inputs;
	Graphics graphics;
	Effects effects(&graphics.screenWidth, &graphics.screenHeight);
	theGame intoTheNeverland(graphics.screenWidth, graphics.screenHeight);
	
	bool loop = true;
	SDL_Event e;
	while (loop) {
		
		clock.tick();
		
		inputs.update();
		loop = !inputs.getQuit();
		
		if (effects.effectType != NONE) {
			effects.update(&clock, &inputs, &sound);
		}
		intoTheNeverland.update(&inputs, &clock, &sound, &effects);
		

		graphics.clearScreen();
		graphics.renderGameObjects(intoTheNeverland.getGameObjects(), &clock, &effects);
		graphics.rendererPresent();

		if (intoTheNeverland.returnQuit()) {
			break;
		}

		clock.delay();
		
	}
	
	return 0;
}