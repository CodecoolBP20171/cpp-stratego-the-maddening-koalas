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

private:
	std::vector<Card> gameObjects;
};

