#pragma once
#ifndef CLOCK_H
#define CLOCK_H


class Clock {

	unsigned int lastTime;
	double timeBetweenFrames;


public:

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	int deltaT;

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
