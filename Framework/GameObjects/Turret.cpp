#include "pch.h"
#include "SceneGame.h"
#include "Bullet.h"
#include "Turret.h"
#include "Age1Enemy.h"

Turret::Turret(const std::string& name) :SpriteGo(name)
{
}

void Turret::Init()
{
	SpriteGo::Init();
	SetTexture("graphics/age1turret1.png");
	SetOrigin(Origins::MC);

	isFiring = false;
	fireTimer = fireInterval;


}

void Turret::Release()
{
	SpriteGo::Release();

}

void Turret::Reset()
{
	SpriteGo::Reset();
	sceneGame = dynamic_cast<SceneGame*>(SCENE_MGR.GetCurrentScene());
	//SetPosition({ playerbuilding->GetPosition().x + 60.f, playerbuilding->GetPosition().y - 30.f });
	SetPosition({ -730.f, 150.f });
	SetOrigin(Origins::MC);

	isFiring = false;
	fireTimer = fireInterval;

	age1Enemy = dynamic_cast<Age1Enemy*>(sceneGame->FindGo("age1Enemy"));
}

void Turret::Update(float dt)
{
	SpriteGo::Update(dt);
	sf::Vector2f enemyPosition = age1Enemy->GetPosition();

	float distance = Utils::Distance(position, enemyPosition);

	if (distance <= firingRange)
	{
		look = enemyPosition - position;
		Utils::Normalize(look);
		SetRotation(Utils::Angle(look));
		isFiring = true;
	}
	else
	{
		isFiring = false;
	}

	fireTimer += dt;
	if (isFiring && fireTimer > fireInterval)
	{
		Fire();
		fireTimer = 0.f;
	}
}

void Turret::Draw(sf::RenderWindow& window)
{
	SpriteGo::Draw(window);
}

void Turret::Fire()
{
	Bullet* bullet = new Bullet();
	bullet->Init();
	bullet->Reset();
	bullet->SetPosition(position);
	bullet->Fire(look, bulletSpeed, bulletDamage);
	sceneGame->AddGo(bullet);

}
