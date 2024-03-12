#include "pch.h"
#include "EnemyBuilding.h"

EnemyBuilding::EnemyBuilding(const std::string& name) : SpriteGo(name)
{
}

void EnemyBuilding::Init()
{
	SpriteGo::Init();
	textureId = "graphics/Age2.png";

	hpBar.setSize(sf::Vector2f(30.f, 150.f));
	hpBar.setFillColor(sf::Color::Red);
}

void EnemyBuilding::Release()
{
	SpriteGo::Release();
}

void EnemyBuilding::Reset()
{
	SetTexture(textureId);
	SetPosition({ 730.f, 150.f });
	SetOrigin(Origins::MC);
	SetScale(sf::Vector2f(-1.f, 1.f));

	hpBar.setPosition(GetPosition().x - 5.f, GetPosition().y - 300.f);
}

void EnemyBuilding::Update(float dt)
{
	SpriteGo::Update(dt);
	if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		this->OnDamage(damage);
	}
}

void EnemyBuilding::OnDamage(int damage)
{

}
void EnemyBuilding::OnDie()
{
	SceneGame* gameScene = dynamic_cast<SceneGame*>(SCENE_MGR.GetCurrentScene());
	if (gameScene != nullptr)
	{
		gameScene->SetStatus(SceneGame::Status::GameWin);
	}
}

void EnemyBuilding::Draw(sf::RenderWindow& window)
{
	SpriteGo::Draw(window);
	window.draw(hpBar);
}