//
// Created by alex on 2017.11.21..
//

#include "SpriteCardsResource.h"
#include <memory>

void SpriteCardsResource::generateSprites(const std::string& color, SDL_Renderer* renderer) const {
    std::shared_ptr<Sprite> bombTexture = std::make_shared<Sprite>(renderer, "images/" + color + "_cards/bomb.png");
    //TODO push back sprites into vector
    //TODO Rename images-directories to blue and red

}

std::weak_ptr<Sprite> SpriteCardsResource::getSprite(SpriteName name) {
    return strategoSprites[name];
}
