#include <iostream>
#include "engine/Engine.h"

int main() {
    Engine engine;

    // Init engine
    engine.init("Stratego", 750, 500);
    Scene scene;

    // Bomb texture
    std::shared_ptr<Sprite> texture = std::make_shared<Sprite>(engine.getRenderer(), "images/bomb.png");

    for(int y= 0; y < 3; ++y) {
        for (int x = 0; x < 3; ++x) {
            SDL_Rect rect{x * 50 + 1 ,y * 50 + 1 , 48, 48};
            std::shared_ptr<Card> card = std::make_shared<Card>(texture, rect, 11);
            scene.addObject(card);
        }
    }

    // wait a little so the animation won't start before the window appears
    SDL_Delay(100);

    bool quit = false;
    Uint32 timePassed = 0;
    Uint32 timestep = 16;

    while (!quit) {
        timePassed = SDL_GetTicks();

        SDL_Event e;
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        scene.draw(engine.getRenderer());

        while(timePassed + timestep > SDL_GetTicks()) {
            SDL_Delay(0);
        }
    }

    return 0;
}