#include <time.h>
#include "GameObjects.h"
#include "TheGame.h"
#include "Graphics.h"

int main(int argc, char* argv[])
{
	srand(time(NULL));
	int startTime = SDL_GetTicks();

	theGame intoTheNeverland;
	Graphics graphics;
	bool loop = true;
	SDL_Event e;
	while (loop) {

		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				loop = false;
			}
		}

		graphics.clearScreen();
		graphics.renderGameObjects(intoTheNeverland.getGameObjects());
		graphics.rendererPresent();
	}
	
	return 0;
}