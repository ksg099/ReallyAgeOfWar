#include "pch.h"
#include "Age1Enemy.h"
#include "SceneGame.h"
#include "UiHud.h"

Age1Enemy::Age1Enemy(const std::string& name) : SpriteGo(name)
{
}

void Age1Enemy::Init()
{
	SpriteGo::Init();
	SetTexture("graphics/age1UiUnit2.png");
	SetPosition({ 730.f, 150.f });
	SetOrigin(Origins::MC);
}

void Age1Enemy::Release()
{
	SpriteGo::Release();

}

void Age1Enemy::Reset()
{
	SpriteGo::Reset();

}

void Age1Enemy::Update(float dt)
{
	SpriteGo::Update(dt);

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
