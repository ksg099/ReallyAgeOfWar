#include "pch.h"
#include "SceneGame.h"
#include "Bullet.h"
#include "Turret.h"
#include "Age1Enemy.h"

Turret* Turret::Create(Age1TurretTypes age1TurretTypes)
{
	Turret* age1Turret = new Turret();

	switch (age1TurretTypes)
	{
	case Age1TurretTypes::RockSlingshot:
		age1Turret->SetTexture("graphics/age1turret1.png");
		age1Turret->fireInterval = 2.f;
		age1Turret->bulletDamage = 10;
		break;
	case Age1TurretTypes::EggAutomatic:
		age1Turret->SetTexture("graphics/age1turret2.png");
		age1Turret->fireInterval = 1.f;
		age1Turret->bulletDamage = 20;
		break;
	case Age1TurretTypes::PrimitiveCatapult:
		age1Turret->SetTexture("graphics/age1turret3.png");
		age1Turret->fireInterval = 3.f;
		age1Turret->bulletDamage = 50;
		break;
	}
	return age1Turret;
}

Turret::Turret(const std::string& name) :SpriteGo(name)
{
}

void Turret::Init()
{
	SpriteGo::Init();
	//SetTexture("graphics/age1turret1.png");
	//SetOrigin(Origins::MC);

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

	//SetPosition({ -730.f, 150.f });
	//SetOrigin(Origins::MC);

	isFiring = false;
	fireTimer = fireInterval;

}

void Turret::Update(float dt)
{
	SpriteGo::Update(dt);

	fireTimer += dt;

	sceneGame = dynamic_cast<SceneGame*>(SCENE_MGR.GetCurrentScene());


	const std::list<GameObject*>& enemyList = sceneGame->GetEnemyList();

	//SetPosition({ playerbuilding->GetPosition().x + 60.f, playerbuilding->GetPosition().y - 30.f });

	if (!enemyList.empty())
	{
		// ù ��° ������ Ÿ������ ����
		targetEnemy = dynamic_cast<Age1Enemy*>(enemyList.front());
	}
	else
	{
		// ���� ����Ʈ�� ��������� Ÿ���� nullptr�� ����
		targetEnemy = nullptr;
	}

	if (targetEnemy != nullptr && targetEnemy->isAlive) //Ÿ���� ��� ������, nullptr�� �ƴҶ�
	{
		sf::Vector2f enemyPosition = targetEnemy->GetPosition();
		float distance = Utils::Distance(position, enemyPosition);

		if (distance <= firingRange) //���ְ� �ͷ������� �Ÿ� ���� �ͷ� �߻� ������ Ŭ��(���� ���ö�)
		{
			look = enemyPosition - position;
			Utils::Normalize(look);
			SetRotation(Utils::Angle(look));
			isFiring = true;
		}
		else //�ƴϸ� �߻� ����
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
	else //!(Ÿ���� ��� ������, nullptr�� �ƴҶ�)
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
