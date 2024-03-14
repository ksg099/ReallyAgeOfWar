#include "pch.h"
#include "Spawner.h"
#include "PlayerBuilding.h"
#include "EnemyBuilding.h"

Spawner::Spawner(const std::string& name) : GameObject(name)
{
}


void Spawner::Init()
{
	GameObject::Init();
}

void Spawner::Release()
{
	GameObject::Release();
}

void Spawner::Reset()
{
	GameObject::Reset();

	timer = 0.f;
	sceneGame = dynamic_cast<SceneGame*>(SCENE_MGR.GetCurrentScene());
}

void Spawner::Update(float dt)
{
	if (currentWave == nullptr)
		return;

	timer += dt;
	if (timer > currentWave->timeVec[index])
	{
		Age1Enemy* newEnemy = Age1Enemy::Create(currentWave->typeVec[index]);
		newEnemy->Init();
		newEnemy->Reset();
		sceneGame->AddGo(newEnemy);;

		++index;
		if (currentWave->timeVec.size() == index)
		{
			WaveEnd();
		}
	}

}

void Spawner::WaveStart(Wave* wave)
{
	currentWave = wave;
	timer = 0.f;
	index = 0;
}

void Spawner::WaveEnd()
{
	currentWave = nullptr;
	sceneGame->OnWaveEnd();
}
