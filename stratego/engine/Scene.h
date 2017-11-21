#ifndef STRATEGO_SCENE_H
#define STRATEGO_SCENE_H

#include "../Card.h"
#include <vector>

class Scene
{
public:
	Scene();
	~Scene();

	void addObject(std::shared_ptr<GameObject> gameObject);
	void draw(SDL_Renderer* renderer);
    std::vector<std::shared_ptr<GameObject>> getObjects() const { return gameObjects; }

private:
	std::vector<std::shared_ptr<GameObject>> gameObjects;
};

#endif // STRATEGO_SCENE_H