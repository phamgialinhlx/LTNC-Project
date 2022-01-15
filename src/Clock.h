#pragma once
#ifndef CLOCK_H
#define CLOCK_H

enum GAME_STATE
{
	OPENING_STATE,
	START_STATE,
	PLAY_STATE,
	PAUSE_STATE,
	GAME_OVER_STATE
};

class Clock {
private:

	unsigned int lastTime;

public:

	int gameState;
	static const int FPS = 75;
	static const int frameDelay = 1000 / FPS;

	int deltaT;

	bool quit;
	bool pause;
	bool restart;
	double characterLifeTime;

	Clock();
	void reset();
	void tick();
	void delay();

};

#endif // CLOCK_H
