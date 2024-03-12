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
	textureId = "graphics/attack.png";
	//SetTexture("graphics/age1UiUnit2.png");
	SetPosition({ 730.f, 150.f });
	SetScale({ -1.f, 1.f });
	SetOrigin(Origins::MC);

}

void Age1Enemy::Release()
{
	SpriteGo::Release();

}

void Age1Enemy::Reset()
{
	SetTexture(textureId);
	SetPosition({ 730.f, 200.f });
	SetOrigin(Origins::MC);

	//scene Ã£±â
	sceneGame = dynamic_cast<SceneGame*>(SCENE_MGR.GetCurrentScene());

	playerBuilding = dynamic_cast<PlayerBuilding*>(sceneGame->FindGo("playerbuilding"));

}

void Age1Enemy::Update(float dt)
{
	SpriteGo::Update(dt);

	enemyAttackTimer += dt;

	if (!isAlive)
		return;
	direction = playerBuilding->GetPosition() - position;
	Utils::Normalize(direction);

	SetRotation(Utils::Angle(direction));
	sf::Vector2f pos = position + direction * enemySpeed * dt;
	SetPosition(pos);

	if (playerBuilding != nullptr && playerBuilding->GetActive())
	{
		if (GetGlobalBounds().intersects(playerBuilding->GetGlobalBounds()) && enemyAttackTimer >= 1)
		{
			playerBuilding->OnDamage(enemyDamage);

			enemyAttackTimer = 0.f;
			//SetActive(false);
			return;
		}
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
}
