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

	unsigned int lastTime;
	double timeBetweenFrames;


public:

	
	int gameState;
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	int deltaT;

	bool quit;
	bool pause;
	bool start;
	bool animationRunning;
	double characterLifeTime;

	Clock();
	void reset();
	void tick();
	void delay();

};

#endif // CLOCK_H
