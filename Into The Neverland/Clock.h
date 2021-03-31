#pragma once
#ifndef CLOCK_H
#define CLOCK_H


class Clock {

	unsigned int lastTime;
	double timeBetweenFrames;
	

public:

	bool pause;
	bool start;
	bool animationRunning;
	double characterLifeTime;

	Clock();
	void reset();
	double getTimeBetweenFrames();
	void tick();

};

#endif // CLOCK_H
