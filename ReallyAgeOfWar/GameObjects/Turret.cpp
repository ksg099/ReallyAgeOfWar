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
	//���� ���� Ÿ��Ʋ���̶� �ȵ�
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

	if (targetEnemy != nullptr && targetEnemy->isAlive()) //Ÿ���� ��� ������, nullptr�� �ƴҶ�
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
