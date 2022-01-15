#include "Score.h"
#include "Resources.h"
#include <fstream>;
#include <sstream>

Score::Score(int x, int y, std::vector<GameObjects*>* gameObjects) :GameObjects(x, y, width, height, screenWidth, screenHeight, hitbox)
{
    this->gameObjects = gameObjects;
    std::fstream file;
    file.open("res/best_score.txt", std::ios::in);
    std::string data;
    std::getline(file, data);
    std::stringstream temp(data);
    temp >> bestScore;
    file.close();

}

void Score::render(SDL_Renderer* renderer, Resources* resources, Clock* clock) {
    switch (clock->gameState)
    {
    case OPENING_STATE:
    case START_STATE:
    case GAME_OVER_STATE:
        break;
    case PAUSE_STATE:
        
        break;
    case PLAY_STATE:
        std::string score = "";
        std::string best = "BEST: ";

        if (characterLifeTime > bestScore) {
            bestScore = lround(characterLifeTime);
        }

        if (lround(characterLifeTime) < 10) {
            score = "000";
        }
        else if (lround(characterLifeTime) < 100) {
            score = "00";
        }
        else if (lround(characterLifeTime) < 1000) {
            score = "0";
        }

        if (bestScore < 10) {
            best += "000";
        }
        else if (bestScore < 100) {
            best += "00";
        }
        else if (bestScore < 1000) {
            best += "0";
        }

        score += std::to_string(lround(characterLifeTime)) + "m";
        best += std::to_string(bestScore);
        SDL_Texture* scoreTexture = resources->createTextTexture(score, SCORE_SIZE);
        SDL_Texture* bestScoreTexture = resources->createTextTexture(best, BEST_SCORE_SIZE);


        int scoreWidth, scoreHeight;
        SDL_QueryTexture(scoreTexture, NULL, NULL, &scoreWidth, &scoreHeight);
        int bestScoreWidth, bestScoreHeight;
        SDL_QueryTexture(bestScoreTexture, NULL, NULL, &bestScoreWidth, &bestScoreHeight);

        SDL_Rect scoreShape = { x, y, scoreWidth, scoreHeight };

        SDL_Rect bestScoreShape = { x, y + scoreHeight, bestScoreWidth, bestScoreHeight };

        SDL_RenderCopyEx(renderer, scoreTexture, NULL, &scoreShape, 0, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(renderer, bestScoreTexture, NULL, &bestScoreShape, 0, NULL, SDL_FLIP_NONE);
        SDL_DestroyTexture(scoreTexture);
        SDL_DestroyTexture(bestScoreTexture);
        break;
    }
}

void Score::update(Clock* clock, Inputs* inputs, double velocity, Sound* sound) {
    switch (clock->gameState) {
    case OPENING_STATE:
    case START_STATE:
    case GAME_OVER_STATE:
        break;
    case PAUSE_STATE:
        break;
    case PLAY_STATE:
        characterLifeTime += clock->deltaT / 10.0f;
        break;
    }
}


bool Score::isAlive() {
    return true;
}
int Score::getID() {
    return SCORE_ID;
}
void Score::die() {

}

Score::~Score() {
    std::fstream file;
    file.open("res/best_score.txt", std::ios::out);
    file << bestScore;
    file.close();   
}
