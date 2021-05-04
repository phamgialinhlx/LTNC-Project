#include "Resources.h"


Resources::Resources(SDL_Renderer* renderer) {
	this->renderer = renderer;
    if (TTF_Init() == -1)
    {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
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
    loadTexture(&texture["background"][DEFAULT], "background/background.png");
    loadTexture(&texture["ground"][DEFAULT], "background/ground.png");
    loadTexture(&texture["mushroom"][0], "background/mushroom.png");
    loadTexture(&texture["mushroom"][1], "background/bigMushroom.png");


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

    loadTexture(&texture["wolfRun"][0], "wolf/run/run0.png");
    loadTexture(&texture["wolfRun"][1], "wolf/run/run1.png");
    loadTexture(&texture["wolfRun"][2], "wolf/run/run2.png");
    loadTexture(&texture["wolfRun"][3], "wolf/run/run3.png");
    loadTexture(&texture["wolfRun"][4], "wolf/run/run4.png");
    loadTexture(&texture["wolfRun"][5], "wolf/run/run5.png");
    loadTexture(&texture["wolfRun"][6], "wolf/run/run6.png");
    loadTexture(&texture["wolfRun"][7], "wolf/run/run7.png");
    loadTexture(&texture["wolfRun"][8], "wolf/run/run8.png");
    loadTexture(&texture["wolfRun"][9], "wolf/run/run9.png");
    loadTexture(&texture["wolfRun"][10], "wolf/run/run10.png");
    loadTexture(&texture["wolfRun"][11], "wolf/run/run11.png");

    loadTexture(&texture["wolfJump"][0], "wolf/jump/jump1.png");
    loadTexture(&texture["wolfJump"][1], "wolf/jump/jump2.png");
    loadTexture(&texture["wolfJump"][2], "wolf/jump/jump3.png");
    loadTexture(&texture["wolfJump"][3], "wolf/jump/jump4.png");
    loadTexture(&texture["wolfJump"][4], "wolf/jump/jump5.png");

    loadTexture(&texture["danger"][DEFAULT], "danger.png");
    loadTexture(&texture["pow"][DEFAULT], "pow.png");

    loadTexture(&texture["menu"][0], "menu/menu.png");
    loadTexture(&texture["menu"][1], "menu/soundOnButton.png");
    loadTexture(&texture["menu"][2], "menu/soundOffButton.png");
    loadTexture(&texture["menu"][3], "menu/exitButton.png");
    loadTexture(&texture["menu"][4], "menu/playButton.png");
    loadTexture(&texture["menu"][5], "menu/overSoundOnButton.png");
    loadTexture(&texture["menu"][6], "menu/overSoundOffButton.png");
    loadTexture(&texture["menu"][7], "menu/overExitButton.png");
    loadTexture(&texture["menu"][8], "menu/overPlayButton.png");

    loadTexture(&texture["credit"][DEFAULT], "credit.png");

    loadTexture(&texture["setting_button"][0], "menu/setting_button.png");

    loadTexture(&texture["pause"][DEFAULT], "menu/pauseMenu.png");
    loadTexture(&texture["unmute"][DEFAULT], "menu/unmute.png");
    loadTexture(&texture["mute"][DEFAULT], "menu/mute.png");

    loadTexture(&texture["black"][DEFAULT], "TransBG/black.png");
    loadTexture(&texture["white"][DEFAULT], "TransBG/white.png");

    font[SCORE_SIZE] = TTF_OpenFont("font/arcade.ttf", SCORE_SIZE);
    font[BEST_SCORE_SIZE] = TTF_OpenFont("font/arcade.ttf", BEST_SCORE_SIZE);
    font[PAUSE_BUTTON_SIZE] = TTF_OpenFont("font/arcade.ttf", PAUSE_BUTTON_SIZE);
    font[GAME_OVER_TEXT_SIZE] = TTF_OpenFont("font/arcade.ttf", GAME_OVER_TEXT_SIZE);
    font[GAME_OVER_BUTTON_SIZE] = TTF_OpenFont("font/arcade.ttf", GAME_OVER_BUTTON_SIZE);


    texture["resume"][DEFAULT] = createTextTexture("resume", PAUSE_BUTTON_SIZE);
}

SDL_Texture* Resources::getTexture(std::string path, int frame) {
    return texture[path][frame];
}
    
SDL_Texture* Resources::createTextTexture(std::string text, int size) {
    SDL_Texture* texture;
    SDL_Color textColor = { 255, 255, 255 };
    SDL_Surface* textSurface = TTF_RenderText_Solid(font[size], text.c_str(), textColor);
    texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);

    return texture;
}

Resources::~Resources() {
    std::map<std::string, std::map<int, SDL_Texture*>> ::iterator index;
    for (index = texture.begin(); index != texture.end(); index++) {
        std::map<int, SDL_Texture*>::iterator frame;
        for (frame = index->second.begin(); frame != index->second.end(); frame++) {
            SDL_DestroyTexture(frame->second);
        }
    }

    std::map<int, TTF_Font*>::iterator ttf_index;
    for (ttf_index = font.begin(); ttf_index != font.end(); ttf_index++) {
        TTF_CloseFont(ttf_index->second);
        ttf_index->second = NULL;
    }
}