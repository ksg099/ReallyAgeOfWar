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



	TextGo* textExp;
	TextGo* textMoney;
	TextGo* defaultMsg;

	SpriteGo* unitUiSelect; //�ʻ��� ���� �ͷ� ���׷��̵� �ϴ� ui�κ�
	SpriteGo* turretUiSelect; //���� �ϴ� ui�κ�
	SpriteGo* turretAdd; //
	SpriteGo* turretSell; //
	SpriteGo* upgrade; //

	SpriteGo* age1UiTurret1; //
	SpriteGo* age1UiTurret2; //
	SpriteGo* age1UiTurre3; //

	SpriteGo* age1UiUnit1; //
	SpriteGo* age1UiUnit2; //
	SpriteGo* age1UiUnit3; //

	SpriteGo* age1UiUnit1; //
	SpriteGo* age1UiUnit2; //
	SpriteGo* age1UiUnit3; //
	SpriteGo* age1UiTurret1; //
	SpriteGo* age1UiTurret2; //
	SpriteGo* age1UiTurret3; //
	SpriteGo* turretCancelBtn; //
	SpriteGo* backBtn; //

	//SpriteGo* moneyExp; //���� ��ȭ�� ����ġ�� �����ִ� ui�κ�

	//sf::RectangleShape //������ ������ �ӵ���, �ִ� ��ȯ ���� ������ �����ִ� �κ�

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

//�����ӿ��� �Ͻ������� �ȵ�
//
//uihud����
//sf::Vector2f currMousePos = InputMgr::GetMousePos();
//sf::Vector2f UiMousePos = ScreenToUi((sf::Vector2i)currMousePos);
//ScreenToUi�ȵ�
//
//uihud���� ui��ư Ŭ���� setactive�ϴ� �κ��� �ʹ� ������ �̰� �³�
//draw�Ҷ��� �ʹ� �������°� ����
//���� ���� ��ġ�� �ϴ� ��Ƶΰ� �ͷ��� ������ �Ÿ��� ���ؼ� ��Ÿ��� ������ �Ҹ� �߻��ϰ�
//
//�ͷ��� �ͷ� �߰� ��ħ�븦 �̸� �����صΰ� activefalse�ص��� ui������ �ش� �ͷ��� Ŭ���� �� ��ġ�� �ش� �ͷ���
//activetrue �ǵ���