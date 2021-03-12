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
    loadTexture(&texture["background"], "background.png");
    loadTexture(&texture["character"], "character.png");
    loadTexture(&texture["wall"], "wall.png");
}

SDL_Texture* Resources::getTexture(std::string path) {
    return texture[path];
}

Resources::~Resources() {
    std::map<std::string, SDL_Texture*> ::iterator index;
    for (index = texture.begin(); index != texture.end(); index++) {
        SDL_DestroyTexture(index->second);
    }
}