#pragma once
#include "Spawner.h"

class SceneGame;

class EnemySpawner : public Spawner
{
protected:
	std::vector
public:

	EnemySpawner(const std::string & = "");
	~EnemySpawner() override = default;

	GameObject* Create() override;
	void Reset() override;
};

