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
	if (timer > interval) //�ð��� ������ ���� ���� �ð� ������ ������
	{
		timer = 0.f;

		for (int i = 0; i < spawnCount; i++)
		{
			sf::Vector2f pos = position + ;
		}
	}
}
