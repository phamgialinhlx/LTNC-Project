#include <time.h>
#include "TheGame.h"
#include "Graphics.h"
#include "Inputs.h"

int main(int argc, char* argv[])
{
	srand(time(NULL));

	Inputs inputs;
	Graphics graphics;
	theGame intoTheNeverland;
	
	bool loop = true;
	SDL_Event e;
	while (loop) {

		inputs.update();
		loop = !inputs.getQuit();

		intoTheNeverland.update(&inputs);

		graphics.clearScreen();
		graphics.renderGameObjects(intoTheNeverland.getGameObjects(),intoTheNeverland.getTimeBetweenFrames());
		graphics.rendererPresent();
	}
	
	return 0;
}