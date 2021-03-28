#include "Sound.h"
#include <iostream>

Sound::Sound() {
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
	}
	loadMedia();
}

Sound::~Sound() {
	Mix_FreeMusic(music);
	music = NULL;
}

bool Sound::loadMedia() {
	//Loading success flag
	bool success = true;

	//Load music
	music = Mix_LoadMUS("sound/music.wav");
	if (music == NULL)
	{
	printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	return success;
}

void Sound::playMusic() {
	//If there is no music playing
	if (Mix_PlayingMusic() == 0)
	{
		//Play the music
		Mix_PlayMusic(music, -1);
	}
}

void Sound::pauseMusic() {
	//If the music is playing
	if (Mix_PausedMusic() != 1)
	{
		//Pause the music
		Mix_PauseMusic();
	}
	
	
}

void Sound::resumeMusic() {
	if (Mix_PausedMusic() == 1)
	{
		//Resume the music
		Mix_ResumeMusic();
	}
}

void Sound::stopMusic() {
	//Stop the music
	Mix_HaltMusic();
}