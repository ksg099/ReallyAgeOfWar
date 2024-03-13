#include "pch.h"
#include "Spawner.h"
#include "SceneGame.h"

Spawner::Spawner(const std::string& name) :GameObject(name)
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

	interval = 3.f;
	spawnCount = 1;

	timer = 0.f;

	sceneGame = dynamic_cast<SceneGame*>(SCENE_MGR.GetCurrentScene());
}

void Spawner::Update(float dt)
{
	GameObject::Update(dt);

	timer += dt;
	if (timer > interval) //시간을 쟀을때 지정 설정 시간 간격이 지나면
	{
		timer = 0.f;

		for (int i = 0; i < spawnCount; i++)
		{
			if (sceneGame != nullptr) //현재 씬이 유효한지 검사
			{
				sf::Vector2f pos = playerBuilding->GetPosition();
			}
			//GameObject* newGo = Create();
			//newGo->Init();
			//newGo->Reset();
			//newGo->SetPosition(pos);

			//SCENE_MGR.GetCurrentScene()->AddGo(newGo);
		}
	}
}
