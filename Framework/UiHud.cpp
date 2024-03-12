#include "pch.h"
#include "UiHud.h"
#include "SceneGame.h"


UiHud::UiHud(const std::string& name) : SpriteGo(name)
{
}

void UiHud::Init()
{
	textExp.Init();
	textMoney.Init();

	sf::Font& font = RES_MGR_FONT.Get("fonts/LiberationSans.ttf");
	
	textMoney.Set(font, "Exp : ", textSize, sf::Color::White);
	textMoney.SetPosition({ -250.f, -75.f });
	textMoney.SetOrigin(Origins::TL);
	
	textExp.Set(font, "Money : ", textSize, sf::Color::White);
	textExp.SetOrigin(Origins::TL);
	textExp.SetPosition({ -250.f, -175.f });
	
	unitUiSelect.SetTexture("graphics/UnitUiSelect.png");
	unitUiSelect.SetOrigin(Origins::TR);
	unitUiSelect.SetPosition({ 750.f, -150.f });

	turretUiSelect.SetTexture("graphics/turretUiSelect.png");
	turretUiSelect.SetPosition({ unitUiSelect.GetPosition().x + 50.f, unitUiSelect.GetPosition().y });
	turretUiSelect.SetOrigin(Origins::TR);
	//turretUiSelect.SetActive(false);
	
	turretAdd.SetTexture("graphics/turretAdd.png");
	turretAdd.SetOrigin(Origins::TR);
	turretAdd.SetPosition({ unitUiSelect.GetPosition().x + 100.f, unitUiSelect.GetPosition().y });
	//turretAdd.SetActive(false);

	turretSell.SetTexture("graphics/turretSell.png");
	turretSell.SetOrigin(Origins::TR);
	turretSell.SetPosition({ unitUiSelect.GetPosition().x + 150.f, unitUiSelect.GetPosition().y});
	//turretSell.SetActive(false);

	upgrade.SetTexture("graphics/upgrade.png");
	upgrade.SetOrigin(Origins::TR);
	upgrade.SetPosition({ unitUiSelect.GetPosition().x + 200.f, unitUiSelect.GetPosition().y});
	//upgrade.SetActive(false);

	age1UiUnit1.SetTexture("graphics/age1UiUnit1.png");
	age1UiUnit1.SetOrigin(Origins::TR);
	age1UiUnit1.SetPosition({ 500.f, -150.f });

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
	turretAdd.Reset();
	turretSell.Reset();
	upgrade.Reset();
}

void UiHud::Update(float dt)
{

	//sf::Vector2f currMousePos = InputMgr::GetMousePos();
	//sf::Vector2f UiMousePos = ScreenToUi((sf::Vector2i)currMousePos);

	//if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	//{

	//	//유닛 버튼 클릭시
	//	sf::FloatRect unitUiSelecttBounds = unitUiSelect.GetGlobalBounds();
	//	if (unitUiSelecttBounds.contains(UiMousePos))
	//	{
	//		
	//	}

	//	//터렛 버튼 클릭시
	//	sf::FloatRect turretUiSelectBounds = turretUiSelect.GetGlobalBounds();
	//	if (turretUiSelectBounds.contains(UiMousePos))
	//	{
	//		//optionsShape.setPosition(titleoption->GetPosition());
	//		//optionsShape.setSize({ 500.f, 250.f });
	//		//optionsShape.setFillColor(sf::Color::Blue);
	//		//Utils::SetOrigin(optionsShape, Origins::MC);
	//		//optionclose->SetActive(false);

	//	}

	//	//터렛 추가 받침대 버튼 클릭시
	//	sf::FloatRect turretAddtBounds = turretAdd.GetGlobalBounds();
	//	if (turretAddtBounds.contains(UiMousePos))
	//	{
	//		turretCancelBtn.SetTexture("graphics/Age1Turret.png");
	//		turretCancelBtn.SetOrigin(Origins::TR);
	//		turretCancelBtn.SetPosition({ 500.f, -150.f });
	//	}

	//	//터렛 되팔기 버튼 클릭시
	//	sf::FloatRect turretSelltBounds = turretSell.GetGlobalBounds();
	//	if (turretSelltBounds.contains(UiMousePos))
	//	{
	//		turretCancelBtn.SetTexture("graphics/select.png");
	//		turretCancelBtn.SetOrigin(Origins::TR);
	//		turretCancelBtn.SetPosition({ 500.f, -150.f });
	//	}

	//	//cancel버튼 클릭시
	//	sf::FloatRect turretCancelBtnBounds = turretCancelBtn.GetGlobalBounds();
	//	if (turretCancelBtnBounds.contains(UiMousePos))
	//	{
	//		turretCancelBtn.SetActive(false);
	//		unitUiSelect.SetActive(true);
	//		turretUiSelect.SetActive(true);
	//		turretAdd.SetActive(true);
	//		turretSell.SetActive(true);
	//		upgrade.SetActive(true);
	//	}

	//	//업그레이드 버튼 클릭시
	//	sf::FloatRect upgradetBounds = upgrade.GetGlobalBounds();
	//	if (upgradetBounds.contains(UiMousePos))
	//	{
	//		//업그레이드 함수 불러오기
	//	}

	//	//옵션 닫기 버튼이 없다면
	//	if (!backBtn.GetActive())
	//	{
	//		backBtn.SetActive(true);
	//		unitUiSelect.SetActive(false);
	//		turretUiSelect.SetActive(false);
	//		turretAdd.SetActive(false);
	//		turretSell.SetActive(false);
	//		upgrade.SetActive(false);
	//	}

	//}

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
	unitUiSelect.Draw(window);
	turretUiSelect.Draw(window);
	turretAdd.Draw(window);
	turretSell.Draw(window);
	upgrade.Draw(window);
	textExp.Draw(window);
	textMoney.Draw(window);

	if (backBtn.GetActive())
	{
		backBtn.Draw(window);
	}
}