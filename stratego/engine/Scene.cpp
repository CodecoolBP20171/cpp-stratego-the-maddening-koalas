#include "Scene.h"

Scene::Scene(){}

Scene::~Scene() {}


void Scene::addObject(Card card)
{
	gameObjects.emplace_back(card);
}

void Scene::draw(SDL_Renderer* renderer)
{
	SDL_RenderClear(renderer);
	for (Card object : gameObjects)
	{
		object.draw(renderer);
	}
	// Update the screen
	SDL_RenderPresent(renderer);
}
/*
void Scene::clean()
{
	for (auto object : gameObjects)
	{
		object.destroy();
	}
}
 */