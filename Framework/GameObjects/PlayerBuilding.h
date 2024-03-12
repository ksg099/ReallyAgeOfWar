#pragma once
#include "SpriteGo.h"
#include "TextGo.h"



class PlayerBuilding : public SpriteGo
{
protected:

	sf::RectangleShape hpBar;
	sf::Vector2f viewSize;



	float maxHp = 200.f;
	float hp = maxHp;
	//float damage = 10.f;

	bool isAlive = true;
	bool isDefeated = false;

	TextGo* defaultMsg;

public:
	PlayerBuilding(const std::string& name = "");
	~PlayerBuilding() override = default;

	void Init() override;
	void Release() override;
	void Reset() override;
	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void OnDamage(int damage);
	void OnDefeat();

	int GetHp() { return hp; }
};

