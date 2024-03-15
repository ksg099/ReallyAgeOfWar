#pragma once
#include <fstream>
#include <iostream>
#include "GameObject.h"
#include "SpriteGo.h"
#include "TextGo.h"
#include "SceneGame.h"
#include "Turret.h"
#include "PlayerUnit.h"

class TextGo;
class SceneGame;
class PlayerUnit;
class PlayerBuilding;
class Turret;

class UiHud : public SpriteGo
{
protected:

	std::string formatExp = "Exp : ";
	std::string formatMoney = "$ : ";

	SceneGame* sceneGame;
	//PlayerUnit* playerUnit;
	PlayerBuilding* playerBuilding;

	Turret::Age1TurretTypes turretSelectMode;
	PlayerUnit::Age1Types unitSelectMode;

	TextGo textExp;
	TextGo textMoney;
	TextGo* pauseMsg;
	TextGo* exitMsg;

	TextGo* age1UiUnit1Msg;
	TextGo* age1UiUnit2Msg;
	TextGo* age1UiUnit3Msg;

	TextGo* age1UiTurret1Msg;
	TextGo* age1UiTurret2Msg;
	TextGo* age1UiTurret3Msg;

	TextGo* unitUiSelectMsg;
	TextGo* turretUiSelectMsg;
	TextGo* turretSellMsg;
	TextGo* turretAddMsg;
	TextGo* upgradeMsg;
	TextGo* backBtnMsg;


	SpriteGo* unitUiSelect; //�ʻ��� ���� �ͷ� ���׷��̵� �ϴ� ui�κ�
	SpriteGo* turretUiSelect; //���� �ϴ� ui�κ�
	SpriteGo* turretAdd; //
	SpriteGo* turretSell; //
	SpriteGo* upgrade; //

	SpriteGo* age1UiTurret1; //
	SpriteGo* age1UiTurret2; //
	SpriteGo* age1UiTurret3; //

	SpriteGo* age1UiUnit1; //
	SpriteGo* age1UiUnit2; //
	SpriteGo* age1UiUnit3; //

	SpriteGo* turretStand;
	SpriteGo* ultimate;
	SpriteGo* turretChoice;

	//SpriteGo* turretCancelBtn; //
	SpriteGo* backBtn; //

	//SpriteGo* moneyExp; //���� ��ȭ�� ����ġ�� �����ִ� ui�κ�

	//sf::RectangleShape //������ ������ �ӵ���, �ִ� ��ȯ ���� ������ �����ִ� �κ�

	float textSize = 50.f;
	int ExpCount = 0.f;
	int MoneyCount = 0.f;

	sf::Vector2f hpBar = { 30.f, 150.f };

	bool isPlaceTurret = false;

public:


	UiHud(const std::string& name = "");
	~UiHud() override = default;
	void Update(float dt);

	void Init() override;
	void Reset() override;
	void Draw(sf::RenderWindow& window) override;
	
	void SetExp(int s);
	void AddExp(int e);

	void SetMoney(int s);
	void AddMoney(int m);

	void AllMsgDelete();
	
	void UnitTrue();
	void UnitFalse();

	void TurretTrue();
	void TurretFalse();

	//void  SetTurretSelectMode(Turret::Age1TurretTypes mode);
	//void ProcessTurretButton(SpriteGo* turretButton, const sf::Vector2f& mousePos, Turret::Age1TurretTypes turretType, const sf::Vector2f& placementPosition);
};