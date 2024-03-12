#include "pch.h"
#include "UiHud.h"
#include "SceneGame.h"


UiHud::UiHud(const std::string& name) : SpriteGo(name)
{
}

void UiHud::Init()
{

	sf::Font& font = RES_MGR_FONT.Get("fonts/LiberationSans.ttf");
	textMoney.Set(font, "Exp : ", textSize, sf::Color::White);
	textMoney.SetPosition({ -250.f, -75.f });
	textMoney.SetOrigin(Origins::TL);
	
	textExp.Set(font, "Money : ", textSize, sf::Color::White);
	textExp.SetPosition({ -250.f, -175.f });
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
	
	age1UiUnit2 = new SpriteGo("unitUiSelect");
	age1UiUnit2->SetTexture("graphics/age1UiUnit2.png");
	age1UiUnit2->SetOrigin(Origins::TR);
	age1UiUnit2->SetPosition({ 550.f, -150.f });

	age1UiUnit3 = new SpriteGo("unitUiSelect");
	age1UiUnit3->SetTexture("graphics/age1UiUnit3.png");
	age1UiUnit3->SetOrigin(Origins::TR);
	age1UiUnit3->SetPosition({ 600.f, -150.f });

	turretUiSelect = new SpriteGo("unitUiSelect");
	turretUiSelect->SetTexture("graphics/turretUiSelect.png");
	turretUiSelect->SetPosition({ unitUiSelect->GetPosition().x + 50.f, unitUiSelect->GetPosition().y });
	turretUiSelect->SetOrigin(Origins::TR);
	//turretUiSelect.SetActive(false);

	age1UiTurret1 = new SpriteGo("unitUiSelect");
	age1UiTurret1->SetTexture("graphics/age1UiUnit1.png");
	age1UiTurret1->SetOrigin(Origins::TR);
	age1UiTurret1->SetPosition({ 500.f, -150.f });

	age1UiTurret2 = new SpriteGo("unitUiSelect");
	age1UiTurret2->SetTexture("graphics/age1UiUnit2.png");
	age1UiTurret2->SetOrigin(Origins::TR);
	age1UiTurret2->SetPosition({ 550.f, -150.f });

	age1UiTurret3 = new SpriteGo("unitUiSelect");
	age1UiTurret3->SetTexture("graphics/age1UiUnit3.png");
	age1UiTurret3->SetOrigin(Origins::TR);
	age1UiTurret3->SetPosition({ 600.f, -150.f });

	turretAdd = new SpriteGo("unitUiSelect");
	turretAdd->SetTexture("graphics/turretAdd.png");
	turretAdd->SetOrigin(Origins::TR);
	turretAdd->SetPosition({ unitUiSelect->GetPosition().x + 100.f, unitUiSelect->GetPosition().y });
	//turretAdd.SetActive(false);

	turretSell = new SpriteGo("unitUiSelect");
	turretSell->SetTexture("graphics/turretSell.png");
	turretSell->SetOrigin(Origins::TR);
	turretSell->SetPosition({ unitUiSelect->GetPosition().x + 150.f, unitUiSelect->GetPosition().y});
	//turretSell.SetActive(false);

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
	//if (spawnMenu.GetActive())
	//{
	//	spawnUnit.SetActive(false);
	//	spawnTurrent.SetActive(false);
	//}
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

	//turretCancelBtn = dynamic_cast<SpriteGo*>(sceneGame->FindGo("turretCancelBtn"));

	turretCancelBtn = dynamic_cast<SpriteGo*>(SCENE_MGR.GetCurrentScene()->FindGo("turretCancelBtn"));
}

void UiHud::Update(float dt)
{

	sf::Vector2f currMousePos = InputMgr::GetMousePos();
	//sf::Vector2f UiMousePos = ScreenToUi((sf::Vector2i)currMousePos);

	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	{

		//유닛 버튼 클릭시
		sf::FloatRect unitUiSelecttBounds = unitUiSelect->GetGlobalBounds();
		if (unitUiSelecttBounds.contains(currMousePos))
		{
			age1UiUnit1->SetActive(true);
			age1UiUnit1->SetActive(true);
			age1UiUnit1->SetActive(true);
			backBtn->SetActive(true);
		}

		//터렛 버튼 클릭시
		sf::FloatRect turretUiSelectBounds = turretUiSelect->GetGlobalBounds();
		if (turretUiSelectBounds.contains(currMousePos))
		{
			age1UiTurret1->SetActive(true);
			age1UiTurret2->SetActive(true);
			age1UiTurret3->SetActive(true);
			backBtn->SetActive(true);
		}

		//터렛 추가 받침대 버튼 클릭시
		sf::FloatRect turretAddtBounds = turretAdd->GetGlobalBounds();
		if (turretAddtBounds.contains(currMousePos))
		{
			turretAdd->SetTexture("graphics/Age1Turret.png");
			turretAdd->SetOrigin(Origins::TR);
			turretAdd->SetPosition({ 500.f, -150.f });
		}

		//터렛 되팔기 버튼 클릭시
		sf::FloatRect turretSelltBounds = turretSell->GetGlobalBounds();
		if (turretSelltBounds.contains(currMousePos))
		{

			//터렛을 클릭시 현재 돈 증가 및 해당 터렛 삭제 코드 추가

		}

		//터렛 되팔기 내에 있는 cancel버튼 클릭시
		sf::FloatRect turretCancelBtnBounds = turretCancelBtn->GetGlobalBounds();
		if (turretCancelBtnBounds.contains(currMousePos))
		{
			turretCancelBtn->SetActive(false);
			unitUiSelect->SetActive(true);
			turretUiSelect->SetActive(true);
			turretAdd->SetActive(true);
			turretSell->SetActive(true);
			upgrade->SetActive(true);
		}

		//업그레이드 버튼 클릭시
		sf::FloatRect upgradetBounds = upgrade->GetGlobalBounds();
		if (upgradetBounds.contains(currMousePos))
		{
			//업그레이드 함수 불러오기
		}

		//Ui내 닫기 버튼이 없다면
		//if (!backBtn->GetActive())
		//{
		//	backBtn->SetActive(true);
		//	unitUiSelect->SetActive(false);
		//	turretUiSelect->SetActive(false);
		//	turretAdd->SetActive(false);
		//	turretSell->SetActive(false);
		//	upgrade->SetActive(false);
		//}

	}

}


void UiHud::SetHp(int hp, int max)
{
	//float value = (float)hp / max;
	//hpBar.setSize({ hpBar.x * value, hpBar.y });
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
	unitUiSelect->Draw(window);
	turretUiSelect->Draw(window);
	turretAdd->Draw(window);
	turretSell->Draw(window);
	upgrade->Draw(window);
	textExp.Draw(window);
	textMoney.Draw(window);
	ultimate->Draw(window);

	if (pauseMsg->GetActive() || exitMsg->GetActive())
	{
		pauseMsg->Draw(window);
		exitMsg->Draw(window);
	}

	if (backBtn->GetActive())
	{
		backBtn->Draw(window);
	}


}