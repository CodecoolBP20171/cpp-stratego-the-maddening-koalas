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
	for (auto player : neutralPlayers)
	{
		for (auto card : player->getCards()) {
			card->draw(renderer);
		}
	}
    highlight->draw(renderer);
}

void Scene::addNeutPlayer(std::shared_ptr<NeutralPlayer> neutralPlayers) {
	this->neutralPlayers.push_back(neutralPlayers);
}