//
// Created by bekor on 11/23/17.
//

#include "NeutralPlayer.h"

NeutralPlayer::NeutralPlayer(const Color &color, SDL_Renderer *renderer) {
    this->color = color;
    spriteCards.reset(new SpriteCardsResource(this->color, renderer));
    this->generateCards();
}

void NeutralPlayer::generateCards() {
    unsigned offset = 1;
    for (unsigned colY = 0; colY < 10; ++colY) {
        for (unsigned colX = 0; colX < 10; ++colX) {
            SDL_Rect rect = {BoardInfo::GameBoardStartX + colX * (BoardInfo::cardHeigth + offset),
                             BoardInfo::GameBoardStartY + colY * (BoardInfo::cardWidth + offset),
                             BoardInfo::cardWidth,
                             BoardInfo::cardHeigth};
            if(( (1 < colX && 4 > colX) || (5 < colX && 8 > colX) )
               && (3 < colY && 6 > colY))
            {
                cards.push_back(std::make_shared<Card>(spriteCards->getSprite(NeutralName::WAT),
                                         spriteCards->getSprite(NeutralName::WAT),
                                         rect,
                                         SpriteName::WATER));
            }
            else {
                cards.push_back(std::make_shared<Card>(spriteCards->getSprite(NeutralName::EMP),
                                         spriteCards->getSprite(NeutralName::PHOLDER),
                                         rect,
                                         SpriteName::EMPTY));
            }
        }
    }
}
