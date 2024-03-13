#include "pch.h"
#include "Age1Enemy.h"
#include "SceneGame.h"
#include "UiHud.h"
#include "PlayerBuilding.h"

Age1Enemy::Age1Enemy(const std::string& name) : SpriteGo(name)
{
}

void Age1Enemy::Init()
{
	SpriteGo::Init();
	textureId = "graphics/Unit1.png";
}

void Age1Enemy::Release()
{
	SpriteGo::Release();

}

void Age1Enemy::Reset()
{
	SetTexture(textureId);
	SetPosition({ 600.f, 200.f });
	SetScale({ -1.f, 1.f });
	SetOrigin(Origins::BR);

	//scene ã��
	sceneGame = dynamic_cast<SceneGame*>(SCENE_MGR.GetCurrentScene());

	playerBuilding = dynamic_cast<PlayerBuilding*>(sceneGame->FindGo("playerbuilding"));

}

void Age1Enemy::Update(float dt)
{
	SpriteGo::Update(dt);

	if (!isAlive || playerBuilding == nullptr || !playerBuilding->GetActive())
		return;

	enemyAttackTimer += dt;

	//�浹 �˻�
	bool isColliding = GetGlobalBounds().intersects(playerBuilding->GetGlobalBounds());
	if (isColliding)
	{
		if (enemyAttackTimer >= 1) // ���� ������ 1���� ������
		{
			playerBuilding->OnDamage(enemyDamage);

			enemyAttackTimer = 0.f; //���� Ÿ�̸� ����
		}
	}
	
	else //�浹���� �������� �����̰� ����
	{
		direction = playerBuilding->GetPosition() - position;
		direction.y = 0.f;
		Utils::Normalize(direction);
		sf::Vector2f pos = position + direction * enemySpeed * dt;
		SetPosition(pos);
	}
}

void Age1Enemy::FixedUpdate(float dt)
{
	SpriteGo::FixedUpdate(dt);

}

void Age1Enemy::Draw(sf::RenderWindow& window)
{
	SpriteGo::Draw(window);
}

void Age1Enemy::OnDamage(int damage)
{
	if (!isAlive)
		return;

	enemyHp -= damage;
	if (enemyHp <= 0)
	{
		enemyHp = 0;
		OnDie();
	}
}

void Age1Enemy::OnDie()
{
	if (!isAlive)
		return;
	isAlive = false;
	SetActive(false);

	if (sceneGame != nullptr)
	{
		sceneGame->AddExp(100);
		sceneGame->AddMoney(50);
	}
}
