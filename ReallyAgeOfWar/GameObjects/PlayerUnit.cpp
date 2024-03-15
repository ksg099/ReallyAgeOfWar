#include "pch.h"
#include "PlayerUnit.h"
#include "SceneGame.h"

PlayerUnit* PlayerUnit::Create(Age1Types playerUnitTypes)
{
	PlayerUnit* playerUnit = new PlayerUnit("playerUnit");
	playerUnit->type = playerUnitTypes;

	switch (playerUnitTypes)
	{
	case PlayerUnit::Age1Types::pMan:
		playerUnit->textureId = "graphics/unit1.png";
		playerUnit->maxHp = 50;
		playerUnit->speed = 100;
		playerUnit->damage = 5;
		playerUnit->attackInterval = 1.f;
		break;
	case PlayerUnit::Age1Types::pSlingShot:
		playerUnit->textureId = "graphics/unit2.png";
		playerUnit->maxHp = 100;
		playerUnit->speed = 100;
		playerUnit->damage = 10;
		playerUnit->attackInterval = 1.f;
		break;
	case PlayerUnit::Age1Types::pRider:
		playerUnit->textureId = "graphics/unit3.png";
		playerUnit->maxHp = 150;
		playerUnit->speed = 100;
		playerUnit->damage = 25;
		playerUnit->attackInterval = 1.f;
		break;
	}
	return playerUnit;
}

PlayerUnit::PlayerUnit(const std::string& name) : SpriteGo(name)
{
}

void PlayerUnit::Init()
{
}

void PlayerUnit::Release()
{
}

void PlayerUnit::Reset()
{
	SpriteGo::Reset();

}

void PlayerUnit::Update(float dt)
{
	sceneGame = dynamic_cast<SceneGame*>(SCENE_MGR.GetCurrentScene());
}

void PlayerUnit::FixedUpdate(float dt)
{
}

void PlayerUnit::Draw(sf::RenderWindow& window)
{
}

void PlayerUnit::OnDamage(int damage)
{
}

void PlayerUnit::OnDie()
{
}
