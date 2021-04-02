#include "Resources.h"


Resources::Resources(SDL_Renderer* renderer) {
	this->renderer = renderer;
    if (TTF_Init() == -1)
    {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
    }
    font = TTF_OpenFont("font/Jetpackia.ttf", 28);
    if (font == NULL)
    {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
    }
    
}

void Resources::loadTexture(SDL_Texture **texture, std::string path) {
    *texture = NULL;
    SDL_Surface* loaded_surface = NULL;
    path = "assets/" + path;
    loaded_surface = IMG_Load(path.c_str());
    if (loaded_surface == NULL) {
        printf("Error loading image: %s\n", SDL_GetError());
    }
    *texture = SDL_CreateTextureFromSurface(renderer, loaded_surface);
    if (texture == NULL) {
        printf("Unable to create texture from surface: %s\n", SDL_GetError());
    }
    SDL_SetTextureBlendMode(*texture, SDL_BLENDMODE_BLEND);
    SDL_FreeSurface(loaded_surface);
}   



void Resources::loadResources() {
    loadTexture(&texture["background"][0], "background/background.png");

    loadTexture(&texture["characterRun"][0], "character/run/run1.png");
    loadTexture(&texture["characterRun"][1], "character/run/run2.png");
    loadTexture(&texture["characterRun"][2], "character/run/run3.png");
    loadTexture(&texture["characterRun"][3], "character/run/run4.png");
    loadTexture(&texture["characterRun"][4], "character/run/run5.png");
    loadTexture(&texture["characterRun"][5], "character/run/run6.png");
    loadTexture(&texture["characterRun"][6], "character/run/run7.png");
    loadTexture(&texture["characterRun"][7], "character/run/run8.png");
    loadTexture(&texture["characterRun"][8], "character/run/run9.png");
    loadTexture(&texture["characterRun"][9], "character/run/run10.png");

    loadTexture(&texture["characterJump"][0], "character/jump/jump1.png");
    loadTexture(&texture["characterJump"][1], "character/jump/jump2.png");
    loadTexture(&texture["characterJump"][2], "character/jump/jump3.png");
    loadTexture(&texture["characterJump"][3], "character/jump/jump4.png");
    loadTexture(&texture["characterJump"][4], "character/jump/jump5.png");
    loadTexture(&texture["characterJump"][5], "character/jump/jump6.png");
    loadTexture(&texture["characterJump"][6], "character/jump/jump7.png");
    loadTexture(&texture["characterJump"][7], "character/jump/jump8.png");
    loadTexture(&texture["characterJump"][8], "character/jump/jump9.png");
    loadTexture(&texture["characterJump"][9], "character/jump/jump10.png");
    loadTexture(&texture["characterJump"][10], "character/jump/jump11.png");
    loadTexture(&texture["characterJump"][11], "character/jump/jump12.png");
    loadTexture(&texture["characterJump"][12], "character/jump/jump13.png");
    loadTexture(&texture["characterJump"][13], "character/jump/jump14.png");
    loadTexture(&texture["characterJump"][14], "character/jump/jump15.png");

    loadTexture(&texture["wall"][0], "wall.png");
    
    loadTexture(&texture["menu"][0], "start_screen.png");
    loadTexture(&texture["start_button"][0], "start_button.png");
    loadTexture(&texture["setting_button"][0], "setting_button.png");
    loadTexture(&texture["resume_button"][0], "resume.png");
    loadTexture(&texture["quit_button"][0], "quit.png");
    loadTexture(&texture["retry_button"][0], "retry.png");


    loadTexture(&texture["black"][0], "black.png");
}

SDL_Texture* Resources::getTexture(std::string path, int frame) {
    return texture[path][frame];
}

SDL_Texture* Resources::createTextTexture(std::string text) {
    SDL_Texture* texture;

    //std::string score = std::to_string(std::lround(characterLifeTime));

    SDL_Color textColor = { 255, 255, 0 };
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);
    texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);

    return texture;
}

Resources::~Resources() {
    std::map<std::string, std::map<int, SDL_Texture*>> ::iterator index;
    for (index = texture.begin(); index != texture.end(); index++) {
        std::map<int, SDL_Texture*>::iterator frame;
        for (frame = index->second.begin(); frame != index->second.end(); frame++) {
            //SDL_DestroyTexture(frame->second);
            SDL_DestroyTexture(frame->second);
        }
    }
        
}