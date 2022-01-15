#include "Sound.h"
#include <iostream>

Sound::Sound() {
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
	}
	mute = false;
	Log::log("[Sound] init succesfully");
}

void Sound::changeMusic(int state) {
	Mix_FreeMusic(music);
	music = NULL;
	loadMusic(state);
	pauseMusic();
}

Sound::~Sound() {
	Mix_FreeMusic(music);
	music = NULL;
}

bool Sound::loadMusic(int state) {
	//Loading success flag
	bool success = true;
	switch (state)
	{
	case OPENING_STATE:
	case START_STATE:
		
		music = Mix_LoadMUS("res/sound/opening_music.mp3");
		if (music == NULL)
		{
			printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
			success = false;
		}
		break;
	case PLAY_STATE:
		music = Mix_LoadMUS("res/sound/play.mp3");
		if (music == NULL)
		{
			printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
			success = false;
		}
		break;
	case PAUSE_STATE:
	case GAME_OVER_STATE:
		break;
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

void Sound::update(Clock* clock) {
	switch (clock->gameState)
	{
	case OPENING_STATE:
		break;
	case START_STATE:
		if (!mute) {
			playMusic();
			resumeMusic();
		}
		else {
			pauseMusic();
		}
		break;
	case PLAY_STATE:
		if (!mute) {
			playMusic();
			resumeMusic();
		}
		else {
			pauseMusic();
		}
		break;
	case PAUSE_STATE:
		pauseMusic();
		break;
	case GAME_OVER_STATE:
		stopMusic();
		break;
	}
}