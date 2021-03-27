#include <time.h>
#include "TheGame.h"
#include "Graphics.h"
#include "Inputs.h"

int main(int argc, char* argv[])
{
	srand(time(NULL));
	
	Clock clock;
	Inputs inputs;
	Graphics graphics;
	theGame intoTheNeverland;
	
	bool loop = true;
	SDL_Event e;
	while (loop) {
		
		clock.tick();
		
		inputs.update();
		loop = !inputs.getQuit();
		
		intoTheNeverland.update(&inputs, &clock);

		graphics.clearScreen();
		graphics.renderGameObjects(intoTheNeverland.getGameObjects(),&clock);
		graphics.rendererPresent();

		if (intoTheNeverland.returnQuit()) {
			break;
		}
		
	}
	
	return 0;
}