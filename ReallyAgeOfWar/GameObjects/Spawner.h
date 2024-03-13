#pragma once
#include "GameObject.h"

class SceneGame;

class Spawner : public GameObject
{

protected:
	float interval = 3.f; //���� ����
	float timer = 0.f; //�����Ǵ� �ð� ���� ��

	int spawnCount = 1; //�ѹ��� ������ ��

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

