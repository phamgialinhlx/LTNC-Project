#pragma once
#ifndef SOUND_H
#define SOUND_H


#include <SDL_mixer.h>

class Sound {
private:
	Mix_Music* music;

	bool loadMedia();
public:
	Sound();
	~Sound();
	void playMusic();
	void pauseMusic();
	void resumeMusic();
	void stopMusic();
};

#endif // !SOUND_H
