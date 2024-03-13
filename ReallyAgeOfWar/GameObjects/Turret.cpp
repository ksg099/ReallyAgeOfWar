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
	std::cout << SCENE_MGR.GetCurrentScene() << std::endl;
	//현재 씬이 타이틀씬이라 안됨
	sceneGame = dynamic_cast<SceneGame*>(SCENE_MGR.GetCurrentScene());
	
	//SetPosition({ playerbuilding->GetPosition().x + 60.f, playerbuilding->GetPosition().y - 30.f });
	SetPosition({ -730.f, 150.f });
	SetOrigin(Origins::MC);

	isFiring = false;
	fireTimer = fireInterval;

	targetEnemy = dynamic_cast<Age1Enemy*>(sceneGame->FindGo("age1Enemy"));
}

void Turret::Update(float dt)
{
	SpriteGo::Update(dt);

	fireTimer += dt;

	if (targetEnemy != nullptr && targetEnemy->isAlive()) //타겟이 살아 있을때, nullptr이 아닐때
	{
		sf::Vector2f enemyPosition = targetEnemy->GetPosition();
		float distance = Utils::Distance(position, enemyPosition);

		if (distance <= firingRange) //유닛과 터렛사이의 거리 보다 터렛 발사 범위가 클때(범위 들어올때)
		{
			look = enemyPosition - position;
			Utils::Normalize(look);
			SetRotation(Utils::Angle(look));
			isFiring = true;
		}
		else //아니면 발사 안함
		{
			isFiring = false;
		}
		//fireTimer += dt;

		if (isFiring && fireTimer > fireInterval)
		{
			Fire();
			fireTimer = 0.f;
		}
	}
	else //!(타겟이 살아 있을때, nullptr이 아닐때)
	{
		isFiring = false;
	}
}

void Turret::Draw(sf::RenderWindow& window)
{
	SpriteGo::Draw(window);
}

void Turret::OnDamage(int damage)
{

}

void Turret::Fire()
{
	Bullet* bullet = new Bullet();
	bullet->Init();
	bullet->Reset();
	bullet->SetPosition(position);
	bullet->SetTargetEnemy(targetEnemy);
	bullet->Fire(look, bulletSpeed, bulletDamage);
	sceneGame->AddGo(bullet);

}
