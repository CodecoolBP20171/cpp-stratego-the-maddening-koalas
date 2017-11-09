#pragma once

#include "../Card.h"
#include <vector>

class Scene
{
public:
	Scene();
	~Scene();

	void addObject(Card card);
	void draw(SDL_Renderer* renderer);
    std::vector<Card> getObjects() const { return  gameObjects; }
	void clean();
	void setBeckgroundAndDraw(SDL_Renderer *renderer);

private:
	std::vector<Card> gameObjects;
	void drawBackground(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect rect);

};

