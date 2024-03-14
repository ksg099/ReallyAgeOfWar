#pragma once
#include "SpriteGo.h"

class SceneGame;
class PlayerBuilding;
class UiHud;

class PlayerUnit : public SpriteGo
{
public:
	enum class Age1Types
	{
		pMan,
		pSlingShot,
		pRider,
	};

	static const int Age1TotalTypes = 3;
	static PlayerUnit* Create(Age1Types playerUnitTypes);

protected:
	Age1Types type;

	Age1Types age1Types;

	SceneGame* sceneGame;
	PlayerBuilding* playerBuilding;
	UiHud* uiHud;

	sf::Vector2f direction;

	int maxHp = 100.f;
	int hp = maxHp;
	int damage = 50.f;

	float speed = 100.f;
	float attackTimer = 0.f;
	float attackInterval = 1.f;

public:

	PlayerUnit(const std::string& name = "");

	bool isAlive = true;
	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void FixedUpdate(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void OnDamage(int damage);
	void OnDie();
};

