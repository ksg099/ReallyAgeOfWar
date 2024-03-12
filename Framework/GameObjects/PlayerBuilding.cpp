#include "pch.h"
#include "PlayerBuilding.h"
#include "TextGo.h"
#include "SceneGame.h"


PlayerBuilding::PlayerBuilding(const std::string& name) : SpriteGo(name)
{
}

void PlayerBuilding::Init()
{
	SpriteGo::Init();
	textureId = "graphics/Age1.png";

	hpBar.setSize(sf::Vector2f(30.f, hp));
	hpBar.setFillColor(sf::Color::Red);

	//sf::Font& font = RES_MGR_FONT.Get("fonts/zombiecontrol.ttf");
}

void PlayerBuilding::Release()
{
	SpriteGo::Release();
}

void PlayerBuilding::Reset()
{

	SetTexture(textureId);
	hp = maxHp;
	SetPosition({ -730.f, 150.f });
	SetOrigin(Origins::MC);

	hpBar.setPosition(GetPosition().x + 5.f, GetPosition().y - 300.f);
}

void PlayerBuilding::Update(float dt)
{
	//SpriteGo::Update(dt);
	//if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
	//{
	//	this->OnDamage(damage);
	//}

}

void PlayerBuilding::OnDamage(int damage)
{
	if (!isAlive)
		return;
	hp -= damage;
	std::cout << hp << std::endl;
	hpBar.setSize(sf::Vector2f(30.f, hp));

	if (hp <= 0)
	{
		hp = 0;
		hpBar.setSize(sf::Vector2f(30.f, hp));
		OnDefeat();

	}

}

void PlayerBuilding::OnDefeat()
{
	SceneGame* gameScene = dynamic_cast<SceneGame*>(SCENE_MGR.GetCurrentScene());
	if (gameScene != nullptr)
	{
		Reset();
		gameScene->SetStatus(SceneGame::Status::GameOver);
	}

}


void PlayerBuilding::Draw(sf::RenderWindow& window)
{
	SpriteGo::Draw(window);
	window.draw(hpBar);
}