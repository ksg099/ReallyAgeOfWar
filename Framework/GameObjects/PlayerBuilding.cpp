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

	hpBar.setSize(sf::Vector2f(30.f, 150.f));
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

	SetPosition({ -730.f, 150.f });
	SetOrigin(Origins::MC);

	hpBar.setPosition(GetPosition().x - 10.f, GetPosition().y - 300.f);
}

void PlayerBuilding::Update(float dt)
{
	SpriteGo::Update(dt);
	if (InputMgr::GetKeyDown(sf::Keyboard::Enter))
	{
		this->OnDamage(damage);
	}

	
}

void PlayerBuilding::OnDamage(int damage)
{
	if (!isAlive)
		return;

	hp -= damage;
	if (hp <= 0)
	{
		hp = 0;
		//uiHud->Set(hp, maxHp);
		OnDefeat();
	}
	//hpBar.setRotation(hpBar.setSize);


	hpBar.setSize(sf::Vector2f(30.f, hp - damage));

	//체력 - y, 더하기 로테이션
}

void PlayerBuilding::OnDefeat()
{
	//isAlive = false;
	//isDefeated = true;
	//defaultMsg = new TextGo("defaultMsg");
	//defaultMsg->Set(RES_MGR_FONT.Get("fonts/LiberationSans.ttf"), "Lose", 100, sf::Color::White);
	//defaultMsg->SetOrigin(Origins::MC);
	//defaultMsg->SetPosition(viewSize);
	//defaultMsg->SetActive(false);
	//AddGo(defaultMsg);

}

void PlayerBuilding::Draw(sf::RenderWindow& window)
{
	SpriteGo::Draw(window);
	window.draw(hpBar);
	//if (isDefeated)
	//{
	//	defaultMsg->Draw(window);
	//}
}