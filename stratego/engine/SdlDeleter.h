//
// Created by bekor on 11/24/17.
//

#ifndef STRATEGO_SDLDELETER_H
#define STRATEGO_SDLDELETER_H


#include <SDL_video.h>
#include <SDL_render.h>

struct SdlDeleter {
    void operator()(SDL_Window *p) const { SDL_DestroyWindow(p); }
    void operator()(SDL_Renderer *p) const { SDL_DestroyRenderer(p); }
    void operator()(SDL_Texture *p) const { SDL_DestroyTexture(p); }

};


#endif //STRATEGO_SDLDELETER_H
