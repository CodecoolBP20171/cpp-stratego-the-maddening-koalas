//
// Created by alex on 2017.11.21..
//

#include "SpriteCardsResource.h"

void SpriteCardsResource::generateSprites(const std::string& color, SDL_Renderer* renderer) {
    std::shared_ptr<Sprite> flagTexture = std::make_shared<Sprite>(renderer, "images/" + color + "_cards/flag.png");
    std::shared_ptr<Sprite> spyTexture = std::make_shared<Sprite>(renderer, "images/" + color + "_cards/spy.png");
    std::shared_ptr<Sprite> scoutTexture = std::make_shared<Sprite>(renderer, "images/" + color + "_cards/scout.png");
    std::shared_ptr<Sprite> minerTexture = std::make_shared<Sprite>(renderer, "images/" + color + "_cards/miner.png");
    std::shared_ptr<Sprite> sergeantTexture = std::make_shared<Sprite>(renderer, "images/" + color + "_cards/sergeant.png");
    std::shared_ptr<Sprite> lieutenantTexture = std::make_shared<Sprite>(renderer, "images/" + color + "_cards/lieutenant.png");
    std::shared_ptr<Sprite> captainTexture = std::make_shared<Sprite>(renderer, "images/" + color + "_cards/captain.png");
    std::shared_ptr<Sprite> majorTexture = std::make_shared<Sprite>(renderer, "images/" + color + "_cards/major.png");
    std::shared_ptr<Sprite> colonelTexture = std::make_shared<Sprite>(renderer, "images/" + color + "_cards/colonel.png");
    std::shared_ptr<Sprite> generalTexture = std::make_shared<Sprite>(renderer, "images/" + color + "_cards/general.png");
    std::shared_ptr<Sprite> marshallTexture = std::make_shared<Sprite>(renderer, "images/" + color + "_cards/marshall.png");
    std::shared_ptr<Sprite> bombTexture = std::make_shared<Sprite>(renderer, "images/" + color + "_cards/bomb.png");

    std::shared_ptr<Sprite> cardBack = std::make_shared<Sprite>(renderer, "images/" + color + "_cards/back.png");

    strategoSprites.push_back(std::move(flagTexture));
    strategoSprites.push_back(std::move(spyTexture));
    strategoSprites.push_back(std::move(scoutTexture));
    strategoSprites.push_back(std::move(minerTexture));
    strategoSprites.push_back(std::move(sergeantTexture));
    strategoSprites.push_back(std::move(lieutenantTexture));
    strategoSprites.push_back(std::move(captainTexture));
    strategoSprites.push_back(std::move(majorTexture));
    strategoSprites.push_back(std::move(colonelTexture));
    strategoSprites.push_back(std::move(generalTexture));
    strategoSprites.push_back(std::move(marshallTexture));
    strategoSprites.push_back(std::move(bombTexture));
    strategoSprites.push_back(std::move(cardBack));
}

std::shared_ptr<Sprite> SpriteCardsResource::getSprite(SpriteName name) {
    return strategoSprites[name];
}
