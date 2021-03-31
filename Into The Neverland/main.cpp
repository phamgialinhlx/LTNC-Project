#include <time.h>
#include "TheGame.h"
#include "Graphics.h"
#include "Inputs.h"

int main(int argc, char* argv[])
{
	//std::cout << "here" << std::endl;
	srand(time(NULL));
	
	Sound sound;
	Clock clock;
	Inputs inputs;
	Graphics graphics;
	theGame intoTheNeverland(graphics.getGraphicSupport());
	
	bool loop = true;
	SDL_Event e;
	while (loop) {
		
		clock.tick();
		
		inputs.update();
		loop = !inputs.getQuit();
		
		intoTheNeverland.update(&inputs, &clock, &sound);

		graphics.clearScreen();
		graphics.renderGameObjects(intoTheNeverland.getGameObjects(),&clock);
		graphics.renderAnimation();
		graphics.rendererPresent();

		if (intoTheNeverland.returnQuit()) {
			break;
		}
		
	}
	
	return 0;
}