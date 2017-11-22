#ifndef STRATEGO_SCENE_H
#define STRATEGO_SCENE_H

#include "../Card.h"
#include "../Player.h"
#include <vector>

class Scene
{
public:
	Scene();
	~Scene();

	void addPlayer(std::shared_ptr<Player> player);
	void draw(SDL_Renderer* renderer);
    std::vector<std::shared_ptr<Player>> getPlayer() const { return players; }

private:
	std::vector<std::shared_ptr<Player>> players;
};

#endif // STRATEGO_SCENE_H