#pragma once
#include "SpriteGo.h"
#include "SceneGame.h"
class EnemyBuilding : public SpriteGo
{
protected:
	sf::RectangleShape hpBar;
	sf::Vector2f viewSize;

	SceneGame* scenegame;

	float maxHp = 100, f;
	float hp = maxHp;
	float damage = 10.f;

	bool isAlive = true;
	bool isDefeated = false;

public:
	EnemyBuilding(const std::string& name = "");
	~EnemyBuilding() override = default;

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void OnDamage(int damage);
	void OnDie();
	int GetHp() { return hp; }
};