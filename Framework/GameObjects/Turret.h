#pragma once
#include "SpriteGo.h"

class SceneGame;
class Age1Enemy;

class Turret : public SpriteGo
{

protected:
	sf::Vector2f direction = { 0.f, 0.f };
	sf::Vector2f look = { 1.0f, 0.f };

	SceneGame* sceneGame;
	Age1Enemy* targetEnemy;

	float bulletSpeed = 1000.f;
	float fireInterval = 0.5f;
	float firingRange = 400.f;

	int damage = 50;
	int bulletDamage = 50;

	bool isFiring = false;
	float fireTimer = 0.f;
public:
	Turret(const std::string& name = "");
	~Turret() override = default;


	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;
	void OnDamage(int damage);
	void SetTargetEnemy(Age1Enemy* enemy) { targetEnemy = enemy; }
	void Fire();
};

