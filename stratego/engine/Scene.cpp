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
	setBeckgroundAndDraw(renderer);
	for (Card object : gameObjects)
	{
		object.draw(renderer);
	}
	// Update the screen
	SDL_RenderPresent(renderer);
}

void Scene::setBeckgroundAndDraw(SDL_Renderer *renderer) {
	Sprite water = Sprite(renderer, "images/water.png");
	Sprite tile  = Sprite(renderer, "images/tile.png");
	SDL_Rect rect;
	for(int y = 0; y < 10; ++y){
		for(int x = 0; x < 10; ++x){
			rect = {x * 50, y * 50, 50, 50};
			drawBackground(renderer, tile.getTexture(), rect);
			SDL_RenderDrawRect(renderer, &rect);
		}
	}
	rect = {100, 200, 100, 100};
	drawBackground(renderer, water.getTexture(), rect);
	SDL_RenderDrawRect(renderer, &rect);
	rect = {300, 200, 100, 100};
	drawBackground(renderer, water.getTexture(), rect);
	SDL_RenderDrawRect(renderer, &rect);

	Sprite side = Sprite(renderer, "images/sidebar.png");
	rect = {500, 0, 250, 500};
	drawBackground(renderer, side.getTexture(), rect);
	SDL_RenderDrawRect(renderer, &rect);

	for(int y = 0; y < 8; ++y){
		for(int x = 0; x < 5; ++x){
			rect = {500 + x * 50, 100 + y * 50, 50, 50};
			SDL_RenderDrawRect(renderer, &rect);
		}
	}

	SDL_SetRenderDrawColor(renderer, 177, 193, 216, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(renderer, 499, 0, 499, 500);
	SDL_RenderDrawLine(renderer, 500, 0, 500, 500);
	SDL_RenderDrawLine(renderer, 501, 0, 501, 500);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
}

void Scene::drawBackground(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect rect) {
	SDL_RenderCopy(renderer, texture, NULL, &rect);
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