//
// Created by alex on 2017.11.21..
//

#include "SpriteCardsResource.h"

void SpriteCardsResource::generateSprites(const std::string& color, SDL_Renderer* renderer) const {
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

    this->strategoSprites.push_back(std::move(flagTexture));
    this->strategoSprites.push_back(std::move(spyTexture));
    this->strategoSprites.push_back(std::move(scoutTexture));
    this->strategoSprites.push_back(std::move(minerTexture));
    this->strategoSprites.push_back(std::move(sergeantTexture));
    this->strategoSprites.push_back(std::move(lieutenantTexture));
    this->strategoSprites.push_back(std::move(captainTexture));
    this->strategoSprites.push_back(std::move(majorTexture));
    this->strategoSprites.push_back(std::move(colonelTexture));
    this->strategoSprites.push_back(std::move(generalTexture));
    this->strategoSprites.push_back(std::move(marshallTexture));
    this->strategoSprites.push_back(std::move(bombTexture));

    //TODO push back sprites into vector
    //TODO Rename images-directories to blue and red
}

std::weak_ptr<Sprite> SpriteCardsResource::getSprite(SpriteName name) {
    return strategoSprites[name];
}
