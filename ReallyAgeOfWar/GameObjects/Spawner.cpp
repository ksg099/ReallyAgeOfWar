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
	if (timer >= currentWave->timeVec[index])
	{
		Age1Enemy* newEnemy = Age1Enemy::Create(currentWave->typeVec[index]);
		newEnemy->name = "Enemy";
		newEnemy->Init();
		newEnemy->Reset();

		sceneGame->AddGo(newEnemy);

		index++;
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

//현재 웨이브의 거리를 검사해서 그 바운드만큼 간격을 두도록 설정하기
void Spawner::UnitDistance(Age1Enemy* newUnit)
{
	//if (sceneGame == nullptr)
	//	return;
	//
	//for (size_t i = 0; currentWave->timeVec.size(); i++)
	//{

	//	Age1Enemy* existingUnit = Age1Enemy::Create(currentWave->typeVec[i]);

	//	float distance = newUnit->GetPosition().x - existingUnit->GetPosition().x;

	//	float spacing = existingUnit->GetGlobalBounds().width;

	//	if (distance < spacing)
	//	{
	//		float newX = existingUnit->GetPosition().x + spacing;
	//		newUnit->SetPosition({ newUnit->GetPosition().x, newX });
	//	}
	//}
}
