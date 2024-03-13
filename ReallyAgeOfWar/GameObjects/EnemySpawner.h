#pragma once
#include "Spawner.h"
#include "Age1Enemy.h"

class SceneGame;

class EnemySpawner : public Spawner
{
protected:
	std::vector<Age1Enemy::Age1Types> age1types;

public:

	EnemySpawner(const std::string&  name = "");
	~EnemySpawner() override = default;

	virtual GameObject* Create();
	void Reset() override;
};

