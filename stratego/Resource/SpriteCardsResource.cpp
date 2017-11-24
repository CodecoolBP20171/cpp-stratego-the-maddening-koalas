//
// Created by alex on 2017.11.21..
//

#include "SpriteCardsResource.h"

void SpriteCardsResource::generateSprites(const Color& color, std::unique_ptr<SDL_Renderer, SdlDeleter>&  renderer) {
    std::string playerColor = "";

    if(color == Color::red){
        playerColor = "red";
        genearetPlayerCards(renderer, playerColor);
    } else if(color == Color::blue ) {
        playerColor = "blue";
        genearetPlayerCards(renderer, playerColor);
    } else if(color == Color::neutral ) {
        generateNeutralSprites(renderer);
    }
}

void SpriteCardsResource::genearetPlayerCards(std::unique_ptr<SDL_Renderer, SdlDeleter>& renderer, const std::string &playerColor){
    std::shared_ptr<Sprite> flagTexture = std::make_shared<Sprite>(renderer, "images/" + playerColor + "_cards2/flag.png");
    std::shared_ptr<Sprite> spyTexture = std::make_shared<Sprite>(renderer, "images/" + playerColor + "_cards2/spy.png");
    std::shared_ptr<Sprite> scoutTexture = std::make_shared<Sprite>(renderer, "images/" + playerColor + "_cards2/scout.png");
    std::shared_ptr<Sprite> minerTexture = std::make_shared<Sprite>(renderer, "images/" + playerColor + "_cards2/miner.png");
    std::shared_ptr<Sprite> sergeantTexture = std::make_shared<Sprite>(renderer, "images/" + playerColor + "_cards2/sergeant.png");
    std::shared_ptr<Sprite> lieutenantTexture = std::make_shared<Sprite>(renderer, "images/" + playerColor + "_cards2/lieutenant.png");
    std::shared_ptr<Sprite> captainTexture = std::make_shared<Sprite>(renderer, "images/" + playerColor + "_cards2/captain.png");
    std::shared_ptr<Sprite> majorTexture = std::make_shared<Sprite>(renderer, "images/" + playerColor + "_cards2/major.png");
    std::shared_ptr<Sprite> colonelTexture = std::make_shared<Sprite>(renderer, "images/" + playerColor + "_cards2/colonel.png");
    std::shared_ptr<Sprite> generalTexture = std::make_shared<Sprite>(renderer, "images/" + playerColor + "_cards2/general.png");
    std::shared_ptr<Sprite> marshallTexture = std::make_shared<Sprite>(renderer, "images/" + playerColor + "_cards2/marshall.png");
    std::shared_ptr<Sprite> bombTexture = std::make_shared<Sprite>(renderer, "images/" + playerColor + "_cards2/bomb.png");

    std::shared_ptr<Sprite> cardBack = std::make_shared<Sprite>(renderer, "images/" + playerColor + "_cards2/back.png");


    strategoSprites.push_back(move(flagTexture));
    strategoSprites.push_back(move(spyTexture));
    strategoSprites.push_back(move(scoutTexture));
    strategoSprites.push_back(move(minerTexture));
    strategoSprites.push_back(move(sergeantTexture));
    strategoSprites.push_back(move(lieutenantTexture));
    strategoSprites.push_back(move(captainTexture));
    strategoSprites.push_back(move(majorTexture));
    strategoSprites.push_back(move(colonelTexture));
    strategoSprites.push_back(move(generalTexture));
    strategoSprites.push_back(move(marshallTexture));
    strategoSprites.push_back(move(bombTexture));
    strategoSprites.push_back(move(cardBack));
}

std::shared_ptr<Sprite> SpriteCardsResource::getSprite(SpriteName& name) {
    return strategoSprites[name];
}

void SpriteCardsResource::generateNeutralSprites(std::unique_ptr<SDL_Renderer, SdlDeleter>&  renderer) {
    std::shared_ptr<Sprite> cardField = std::make_shared<Sprite>(renderer, "images/mark_field2.png");
    std::shared_ptr<Sprite> emptyField = std::make_shared<Sprite>(renderer, "images/empty.png");
    std::shared_ptr<Sprite> waterField = std::make_shared<Sprite>(renderer, "images/empty.png");

    strategoSprites.push_back(std::move(cardField));
    strategoSprites.push_back(std::move(emptyField));
    strategoSprites.push_back(std::move(waterField));
}

std::shared_ptr<Sprite> SpriteCardsResource::getSprite(NeutralName& name) {
    return strategoSprites[name];
}
