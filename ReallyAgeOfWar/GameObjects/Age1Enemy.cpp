#include "pch.h"
#include "Age1Enemy.h"
#include "SceneGame.h"
#include "UiHud.h"
#include "PlayerBuilding.h"

Age1Enemy* Age1Enemy::Create(Age1Types age1EnemyTypes)
{
	Age1Enemy* age1Enemy = new Age1Enemy("Zombie");
	age1Enemy->type = age1EnemyTypes;

	switch (age1EnemyTypes)
	{
	case Age1Enemy::Age1Types::man:
		age1Enemy->textureId = "graphics/unit1.png";
		age1Enemy->maxHp = 100;
		age1Enemy->speed = 100;
		age1Enemy->damage = 25;
		age1Enemy->attackInterval = 1.f;
		break;
	case Age1Enemy::Age1Types::slingShot:
		age1Enemy->textureId = "graphics/unit2.png";
		age1Enemy->maxHp = 150;
		age1Enemy->speed = 100;
		age1Enemy->damage = 50;
		age1Enemy->attackInterval = 1.f;
		break;
	case Age1Enemy::Age1Types::Rider:
		age1Enemy->textureId = "graphics/unit3.png";
		age1Enemy->maxHp = 200;
		age1Enemy->speed = 100;
		age1Enemy->damage = 75;
		age1Enemy->attackInterval = 1.f;
		break;
	}
	return age1Enemy;


	//Age1Enemy* Age1enemy = new Age1Enemy("Age1Enemy");
	//age1EnemyTypes->type = Age1Types;

	//const DataAge1Ememy& data = ZOMBIE_TABLE->Get(zombieType);
	//Age1enemy->textureId = data.textureId;
	//Age1enemy->enemyMaxHp = data.maxHp;
	//Age1enemy->enemySpeed = data.speed;
	//Age1enemy->enemyDamage = data.damage;
	//Age1enemy->enemyattackInterval = data.attackInterval;
	//return Age1enemy;
}

Age1Enemy::Age1Enemy(const std::string& name) : SpriteGo(name)
{
}

void Age1Enemy::Init()
{
	SpriteGo::Init();
	SetTexture(textureId);
	SetPosition({ 600.f, 200.f });
	SetScale({ -1.f, 1.f });
	SetOrigin(Origins::BR);
}

void Age1Enemy::Release()
{
	SpriteGo::Release();

}

void Age1Enemy::Reset()
{
	SpriteGo::Reset();

	//scene 찾기
	sceneGame = dynamic_cast<SceneGame*>(SCENE_MGR.GetCurrentScene());

	playerBuilding = dynamic_cast<PlayerBuilding*>(sceneGame->FindGo("playerbuilding"));

	isAlive = true;
	hp = maxHp;
	attackTimer = attackInterval;
}

void Age1Enemy::Update(float dt)
{
	SpriteGo::Update(dt);

	if (!isAlive || playerBuilding == nullptr || !playerBuilding->GetActive())
		return;

	attackTimer += dt;

	//충돌 검사
	bool isColliding = GetGlobalBounds().intersects(playerBuilding->GetGlobalBounds());
	if (isColliding)
	{
		if (attackTimer >= 1) // 공격 간격이 1보다 작을때
		{
			playerBuilding->OnDamage(damage);

			attackTimer = 0.f; //공격 타이머 리셋
		}
	}
	
	else //충돌하지 않을때만 움직이게 변경
	{
		direction = playerBuilding->GetPosition() - position;
		direction.y = 0.f;
		Utils::Normalize(direction);
		sf::Vector2f pos = position + direction * speed * dt;
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

	hp -= damage;
	if (hp <= 0)
	{
		hp = 0;
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
