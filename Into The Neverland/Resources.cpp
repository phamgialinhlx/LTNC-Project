#include "Resources.h"


Resources::Resources(SDL_Renderer* renderer) {
	this->renderer = renderer;
}

void Resources::loadTexture(SDL_Texture **texture, std::string path) {
    *texture = NULL;
    SDL_Surface* loaded_surface = NULL;
    path = "images/" + path;
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
    loadTexture(&texture["background"][0], "background.png");

    loadTexture(&texture["character"][0], "character.png");
    loadTexture(&texture["character"][1], "red.png");
    loadTexture(&texture["character"][2], "yellow.png");
    loadTexture(&texture["character"][3], "green.png");
    loadTexture(&texture["character"][4], "blue.png");
    loadTexture(&texture["character"][5], "purple.png");
    
    loadTexture(&texture["wall"][0], "wall.png");
    loadTexture(&texture["setting_button"][0], "setting_button.png");
    loadTexture(&texture["resume_button"][0], "resume.png");
    loadTexture(&texture["black"][0], "black.png");
}

SDL_Texture* Resources::getTexture(std::string path, int frame) {
    return texture[path][frame];
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