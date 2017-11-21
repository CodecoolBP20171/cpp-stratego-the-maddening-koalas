#include "Scene.h"

Scene::Scene(){}

Scene::~Scene() {}


void Scene::addObject(std::shared_ptr<GameObject> gameObject)
{
	gameObjects.push_back(gameObject);
}

void Scene::draw(SDL_Renderer* renderer)
{
	SDL_RenderClear(renderer);
	for (auto object : gameObjects)
	{
		object->draw(renderer);
	}
	// Update the screen
	SDL_RenderPresent(renderer);
}

/*
 SDL_SetRenderDrawColor(renderer, 177, 193, 216, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(renderer, 499, 0, 499, 500);
	SDL_RenderDrawLine(renderer, 500, 0, 500, 500);
	SDL_RenderDrawLine(renderer, 501, 0, 501, 500);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
 */