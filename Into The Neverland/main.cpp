#include <time.h>
#include "GameObjects.h"
#include "TheGame.h"

const int FPS = 60;
const int DELAY_TIME = 1000 / FPS;	

int main(int argc, char* argv[])
{
	srand(time(NULL));
	int startTime = SDL_GetTicks();
	theGame intoTheNeverland;
	return 0;
}