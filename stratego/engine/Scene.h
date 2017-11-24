#ifndef STRATEGO_SCENE_H
#define STRATEGO_SCENE_H

#include "../GameObject/Card.h"
#include "../Player.h"
#include "../Resource/Background.h"
#include "../GameLogic/EventHandler.h"
#include <vector>

class Scene
{
public:
	Scene();
	~Scene();

	void addPlayer(std::shared_ptr<Player>& player);
	void addNeutPlayer(std::shared_ptr<NeutralPlayer>& neutralPlayers);

    void addBackground(std::shared_ptr<Background>& bg);
    void draw(SDL_Renderer* renderer, std::shared_ptr<HighLight>& highlight);

    std::vector<std::shared_ptr<Player>> getPlayer() const { return players; }
private:
    std::vector<std::shared_ptr<Player>> players;
	std::vector<std::shared_ptr<NeutralPlayer>> neutralPlayers;
	std::shared_ptr<Background> background;
};

#endif // STRATEGO_SCENE_H