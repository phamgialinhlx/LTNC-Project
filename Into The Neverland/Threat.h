#pragma once
#ifndef THREAT_H
#define THREAT_H

#include <vector>
#include "GameObjects.h"
#include"Wolf.h"
class GameObjects;

class Threat {
private:
	std::vector<GameObjects*> *gameObjects;
	int screenWidth, screenHeight;

public:
	Threat(int screenWidth, int screenHeight, std::vector<GameObjects*> *gameObjects);
	void createThreats(double* threatCoolDown);
};


#endif // !THREAT_H
