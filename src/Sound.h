#pragma once
#ifndef SOUND_H
#define SOUND_H

#include <SDL2/SDL_mixer.h>
#include "Clock.h"
#include "Log.h"

class Sound {
private:
	Mix_Music* music;
	
public:

	bool mute;

	Sound();
	~Sound();
	void changeMusic(int state);
	void update(Clock *clock);
	bool loadMusic(int state);
	void playMusic();
	void pauseMusic();
	void resumeMusic();
	void stopMusic();
};

#endif // !SOUND_H
