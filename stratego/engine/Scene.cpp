#include "Scene.h"

Scene::Scene(){}

Scene::~Scene() {}

void Scene::addPlayer(std::shared_ptr<Player> player)
{
	players.push_back(player);
}

void Scene::addBackground(std::shared_ptr<Background> bg)
{
	this->background = bg;
}

void Scene::draw(SDL_Renderer* renderer, std::shared_ptr<HighLight>& highlight)
{

	this->background->draw(renderer);
	for (auto player : players)
	{
		for (auto card : player->getCards()) {
			card->draw(renderer);
		}
	}
    highlight->draw(renderer);
}


/*
 SDL_SetRenderDrawColor(renderer, 177, 193, 216, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(renderer, 499, 0, 499, 500);
	SDL_RenderDrawLine(renderer, 500, 0, 500, 500);
	SDL_RenderDrawLine(renderer, 501, 0, 501, 500);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
 */