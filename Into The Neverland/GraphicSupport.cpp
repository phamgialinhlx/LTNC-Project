#include "GraphicSupport.h"
#include <iostream>

GraphicSupport::GraphicSupport(Resources* resources, SDL_Renderer* renderer) {
	this->resources = resources;
	this->renderer = renderer;

    typeOfAnimation = 0;
    finish = false;
    opacity = 90;
}
void GraphicSupport::renderTransparentBlackBG() {
    SDL_Texture* texture;
    texture = resources->getTexture("black", 0);

    SDL_Rect dst = { 0, 0, 900, 400 };

    SDL_SetTextureAlphaMod(texture, opacity);

    SDL_RenderCopyEx(renderer, texture, NULL, &dst, 0,
        NULL, SDL_FLIP_NONE);
}

void GraphicSupport::update(int typeOfAnimation) {
    this->typeOfAnimation = typeOfAnimation;
    switch (this->typeOfAnimation)
    {
        // Brighten the black background
    case 1:
        opacity -= 5;
        
        if (opacity == 0) {
            opacity = 90;
            finish = true;
        }

        //std::cout << "[GraphicSupport] opacity: " << opacity << std::endl;
        //std::cout << "                 finish: " << std::boolalpha << finish << std::endl;
        break;

    default:
        break;
    }
}

void GraphicSupport::render() {
    switch (typeOfAnimation)
    {
    case 1:
        renderTransparentBlackBG();
        break;
    default:
        break;
    }
}

void GraphicSupport::renderNote(){
    SDL_Texture* texture = NULL;

    std::string text = "PRESS SPACE TO START THE GAME";

    texture = resources->createTextTexture(text);

    int textWidth, textHeight;
    SDL_QueryTexture(texture, NULL, NULL, &textWidth, &textHeight);

    SDL_Rect dst = {
        300,
        350,
        textWidth,
        textHeight
    };

    SDL_RenderCopyEx(renderer, texture, NULL, &dst, 0,
        NULL, SDL_FLIP_NONE);
    SDL_DestroyTexture(texture);
}