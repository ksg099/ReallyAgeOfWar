#pragma once
#include "GameObject.h"
#include "SceneGame.h"

class Spawner : public GameObject
{

protected:
	float timer = 0.f; //½ºÆùµÇ´Â ½Ã°£ À÷´Â ³ð
	SceneGame* sceneGame;

	Wave* currentWave = nullptr;
	int index = 0;

public:

	Spawner(const std::string& name = "");
	~Spawner() override = default;

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;

	void WaveStart(Wave* wave);
	void WaveEnd();
	void UnitDistance(Age1Enemy* newUnit);
};

