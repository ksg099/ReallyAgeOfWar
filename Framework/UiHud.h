#pragma once
#include "GameObject.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "SceneGame.h"

class UiHud : public SpriteGo
{
protected:

	std::string formatExp = "Exp : ";
	std::string formatMoney = "Money : ";

	TextGo textExp;
	TextGo textMoney;
	TextGo defaultMsg;

	SpriteGo unitUiSelect; //필살기랑 유닛 터렛 업그레이드 하는 ui부분
	SpriteGo turretUiSelect; //유닛 하는 ui부분
	SpriteGo turretAdd; //
	SpriteGo turretSell; //
	SpriteGo upgrade; //

	SpriteGo age1UiUnit1; //
	SpriteGo age1UiUnit2; //
	SpriteGo age1UiUnit3; //
	SpriteGo age1UiTurret1; //
	SpriteGo age1UiTurret2; //
	SpriteGo age1UiTurret3; //
	SpriteGo turretCancelBtn; //
	SpriteGo backBtn; //

	//SpriteGo* moneyExp; //현재 재화와 경험치를 보여주는 ui부분

	//sf::RectangleShape //유닛이 나오는 속도랑, 최대 소환 가능 유닛을 보여주는 부분

	float textSize = 50.f;
	int ExpCount = 0.f;
	int MoneyCount = 0.f;

	sf::Vector2f hpBar = { 30.f, 150.f };

public:


	UiHud(const std::string& name = "");
	~UiHud() override = default;
	void Update(float dt);

	void Init() override;
	void Reset() override;
	void Draw(sf::RenderWindow& window) override;

	void SetHp(int hp, int max);
	
	void SetExp(int s);
	void AddExp(int e);

	void SetMoney(int s);
	void AddMoney(int m);
};

