#pragma once
#include "SpriteGo.h"
#include "UiHud.h"

class UiHud;


class Age1Enemy : public SpriteGo
{
public:
	enum class Age1Types
	{
		Human,
		thrower,
		Rider,
	};



	static const int Age1TotalTypes = 3;
	static Age1Enemy* Create(Age1Types age1Types);

protected:
	Age1Types Age1Types;
	UiHud* uiHud;

	int enemyMaxHp;
	int enemyHp = 100.f;
	int enemyDamage;

	float enemySpeed = 100.f;
	float enemyAttackTimer = 0.f;

	bool isAlive = true;

	Age1Enemy(const std::string& name = "");

public:

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void FixedUpdate(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void OnDamage(int damage);
	void OnDie();
};

