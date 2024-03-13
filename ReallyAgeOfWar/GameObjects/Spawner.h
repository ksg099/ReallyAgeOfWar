#pragma once
#include "GameObject.h"

class SceneGame;

class Spawner : public GameObject
{

protected:
	float interval = 3.f; //생성 간격
	float timer = 0.f; //스폰되는 시간 쟤는 놈

	int spawnCount = 1; //한번에 나오는 놈

	SceneGame* sceneGame;



public:

	Spawner(const std::string& name = "");
	~Spawner() override = default;

	virtual GameObject* Create() = 0;

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
};

