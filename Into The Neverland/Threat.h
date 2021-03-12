#pragma once
#ifndef THREAT_H
#define THREAT_H

#include <vector>
#include "GameObjects.h"
#include "Wall.h"

class GameObjects;

class Threat {
private:
	std::vector<GameObjects*> *gameObjects;

public:
	Threat(std::vector<GameObjects*> *gameObjects);
	void createThreats(double* threatCoolDown);
};


#endif // !THREAT_H
