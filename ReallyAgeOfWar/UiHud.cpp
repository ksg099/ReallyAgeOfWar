#include "pch.h"
#include "UiHud.h"
#include "SceneGame.h"


UiHud::UiHud(const std::string& name) : SpriteGo(name)
{
}

void UiHud::Init()
{

	sf::Font& font = RES_MGR_FONT.Get("fonts/LiberationSans.ttf");
	textMoney.Set(font, "Exp : ", 35, sf::Color::White);
	textMoney.SetPosition({ -250.f, -100.f });
	textMoney.SetOrigin(Origins::TL);
	
	textExp.Set(font, "Money : ", 35, sf::Color::White);
	textExp.SetPosition({ textMoney.GetPosition().x, textMoney.GetPosition().y - 50.f });
	textExp.SetOrigin(Origins::TL);
	
	pauseMsg = new TextGo("PAUSED");
	pauseMsg->Set(font, "PAUSED Press space again to resume", 60, sf::Color::White);
	pauseMsg->SetPosition({ 100.f, 0.f });
	pauseMsg->SetOrigin(Origins::MC);
	pauseMsg->SetActive(false);

	exitMsg = new TextGo("exitMsg");
	exitMsg->Set(font, "Exit Press Esc to Title", 60, sf::Color::White);
	exitMsg->SetPosition({ 100.f, 0.f });
	exitMsg->SetOrigin(Origins::MC);
	exitMsg->SetActive(false);

	unitUiSelect = new SpriteGo("unitUiSelect");
	unitUiSelect->SetTexture("graphics/UnitUiSelect.png");
	unitUiSelect->SetOrigin(Origins::TR);
	unitUiSelect->SetPosition({ 750.f, -150.f });

	age1UiUnit1 = new SpriteGo("unitUiSelect");
	age1UiUnit1->SetTexture("graphics/age1UiUnit1.png");
	age1UiUnit1->SetOrigin(Origins::TR);
	age1UiUnit1->SetPosition({ 500.f, -150.f });
	age1UiUnit1->SetActive(false);
	
	age1UiUnit2 = new SpriteGo("unitUiSelect");
	age1UiUnit2->SetTexture("graphics/age1UiUnit2.png");
	age1UiUnit2->SetOrigin(Origins::TR);
	age1UiUnit2->SetPosition({ 550.f, -150.f });
	age1UiUnit2->SetActive(false);

	age1UiUnit3 = new SpriteGo("unitUiSelect");
	age1UiUnit3->SetTexture("graphics/age1UiUnit3.png");
	age1UiUnit3->SetOrigin(Origins::TR);
	age1UiUnit3->SetPosition({ 600.f, -150.f });
	age1UiUnit3->SetActive(false);

	turretUiSelect = new SpriteGo("unitUiSelect");
	turretUiSelect->SetTexture("graphics/turretUiSelect.png");
	turretUiSelect->SetPosition({ unitUiSelect->GetPosition().x + 50.f, unitUiSelect->GetPosition().y });
	turretUiSelect->SetOrigin(Origins::TR);

	age1UiTurret1 = new SpriteGo("unitUiSelect");
	age1UiTurret1->SetTexture("graphics/age1UiUnit1.png");
	age1UiTurret1->SetOrigin(Origins::TR);
	age1UiTurret1->SetPosition({ 650.f, -150.f });
	age1UiTurret1->SetActive(false);

	age1UiTurret2 = new SpriteGo("unitUiSelect");
	age1UiTurret2->SetTexture("graphics/age1UiUnit2.png");
	age1UiTurret2->SetOrigin(Origins::TR);
	age1UiTurret2->SetPosition({ 700.f, -150.f });
	age1UiTurret2->SetActive(false);

	age1UiTurret3 = new SpriteGo("unitUiSelect");
	age1UiTurret3->SetTexture("graphics/age1UiUnit3.png");
	age1UiTurret3->SetOrigin(Origins::TR);
	age1UiTurret3->SetPosition({ 750.f, -150.f });
	age1UiTurret3->SetActive(false);

	turretAdd = new SpriteGo("unitUiSelect");
	turretAdd->SetTexture("graphics/turretAdd.png");
	turretAdd->SetOrigin(Origins::TR);
	turretAdd->SetPosition({ unitUiSelect->GetPosition().x + 100.f, unitUiSelect->GetPosition().y });

	turretSell = new SpriteGo("unitUiSelect");
	turretSell->SetTexture("graphics/turretSell.png");
	turretSell->SetOrigin(Origins::TR);
	turretSell->SetPosition({ unitUiSelect->GetPosition().x + 150.f, unitUiSelect->GetPosition().y});

	upgrade = new SpriteGo("unitUiSelect");
	upgrade->SetTexture("graphics/upgrade.png");
	upgrade->SetOrigin(Origins::TR);
	upgrade->SetPosition({ unitUiSelect->GetPosition().x + 200.f, unitUiSelect->GetPosition().y});


	backBtn = new SpriteGo("backBtn");
	backBtn->SetTexture("graphics/backBtn.png");
	backBtn->SetOrigin(Origins::TR);
	backBtn->SetPosition({ unitUiSelect->GetPosition().x + 200.f, unitUiSelect->GetPosition().y });

	ultimate = new SpriteGo("ultimate");
	ultimate->SetTexture("graphics/ultimate.png");
	ultimate->SetOrigin(Origins::TR);
	ultimate->SetPosition({ unitUiSelect->GetPosition().x + 200.f, unitUiSelect->GetPosition().y + 50.f});

	turretCancelBtn = new SpriteGo("turretCancelBtn");
	turretCancelBtn->SetTexture("graphics/select.png");
	turretCancelBtn->SetOrigin(Origins::TR);
	turretCancelBtn->SetPosition({ 500.f, -150.f });
	turretCancelBtn->SetActive(false);


}

void UiHud::Reset()
{
	textExp.Reset();
	textMoney.Reset();
	turretAdd->Reset();
	turretSell->Reset();
	upgrade->Reset();
	ultimate->Reset();

	sceneGame = dynamic_cast<SceneGame*>(SCENE_MGR.GetCurrentScene());
}

void UiHud::Update(float dt)
{

	sf::Vector2f currMousePos = InputMgr::GetMousePos();
	sf::Vector2f UiMousePos = sceneGame->ScreenToUi((sf::Vector2i)currMousePos);

	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	{

		//���� ��ư Ŭ����
		sf::FloatRect unitUiSelecttBounds = unitUiSelect->GetGlobalBounds();
		if (unitUiSelecttBounds.contains(UiMousePos))
		{
			age1UiTurret1->SetActive(false);
			age1UiTurret2->SetActive(false);
			age1UiTurret3->SetActive(false);

			age1UiUnit1->SetActive(true);
			age1UiUnit2->SetActive(true);
			age1UiUnit3->SetActive(true);
			backBtn->SetActive(true);
			return;
		}

		//�ͷ� ��ư Ŭ����
		sf::FloatRect turretUiSelectBounds = turretUiSelect->GetGlobalBounds();
		if (turretUiSelectBounds.contains(UiMousePos))
		{

			age1UiUnit1->SetActive(false);
			age1UiUnit2->SetActive(false);
			age1UiUnit3->SetActive(false);

			age1UiTurret1->SetActive(true);
			age1UiTurret2->SetActive(true);
			age1UiTurret3->SetActive(true);
			backBtn->SetActive(true);
			return;
		}

		//�ͷ� �߰� ��ħ�� ��ư Ŭ����
		sf::FloatRect turretAddtBounds = turretAdd->GetGlobalBounds();
		if (turretAddtBounds.contains(UiMousePos))
		{
			turretAdd->SetTexture("graphics/Age1Turret.png");
			turretAdd->SetOrigin(Origins::TR);
			turretAdd->SetPosition({ 500.f, -150.f });
		}

		//�ͷ� ���ȱ� ��ư Ŭ����
		sf::FloatRect turretSelltBounds = turretSell->GetGlobalBounds();
		if (turretSelltBounds.contains(UiMousePos))
		{

			//�ͷ��� Ŭ���� ���� �� ���� �� �ش� �ͷ� ���� �ڵ� �߰�
			//Remove();
			sceneGame->AddMoney(100);

		}

		//�ͷ� ���ȱ� ���� �ִ� cancel��ư Ŭ����
		sf::FloatRect turretCancelBtnBounds = turretCancelBtn->GetGlobalBounds();
		if (turretCancelBtnBounds.contains(UiMousePos))
		{
			turretCancelBtn->SetActive(false);
			unitUiSelect->SetActive(true);
			turretUiSelect->SetActive(true);
			turretAdd->SetActive(true);
			turretSell->SetActive(true);
			upgrade->SetActive(true);
		}

		//���׷��̵� ��ư Ŭ����
		sf::FloatRect upgradetBounds = upgrade->GetGlobalBounds();
		if (upgradetBounds.contains(UiMousePos))
		{
			//���׷��̵� �Լ� �ҷ����� ���� ����ġ�� ������ ��쿡�� ���׷��̵� ����
		}
	}

}

void UiHud::SetExp(int s)
{
	textExp.SetString(formatExp + std::to_string(s));
}

void UiHud::SetMoney(int s)
{
	textMoney.SetString(formatMoney + std::to_string(s));
}

void UiHud::AddExp(int e)
{
	ExpCount += e;

}

void UiHud::AddMoney(int m)
{
	MoneyCount += m;
}

void UiHud::Draw(sf::RenderWindow& window)
{
	SpriteGo::Draw(window);



	unitUiSelect->Draw(window);
	turretUiSelect->Draw(window);
	turretCancelBtn->Draw(window);
	turretAdd->Draw(window);
	turretSell->Draw(window);
	upgrade->Draw(window);
	textExp.Draw(window);
	textMoney.Draw(window);
	ultimate->Draw(window);

	age1UiTurret1->Draw(window);
	age1UiTurret2->Draw(window);
	age1UiTurret3->Draw(window);

	if (pauseMsg->GetActive() || exitMsg->GetActive())
	{
		pauseMsg->Draw(window);
		exitMsg->Draw(window);
	}

	if (age1UiUnit1->GetActive() || age1UiUnit2->GetActive() || age1UiUnit3->GetActive())
	{
		age1UiUnit1->Draw(window);
		age1UiUnit2->Draw(window);
		age1UiUnit3->Draw(window);
	}

}