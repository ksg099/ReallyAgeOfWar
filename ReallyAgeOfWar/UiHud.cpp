#include "pch.h"
#include "UiHud.h"
#include "SceneGame.h"
#include "PlayerUnit.h"
#include "PlayerBuilding.h"
#include "Turret.h"


UiHud::UiHud(const std::string& name) : SpriteGo(name)
{
}

void UiHud::Init()
{

	sf::Font& font = RES_MGR_FONT.Get("fonts/LiberationSans.ttf");
	textMoney.Set(font, "", 35, sf::Color::White);
	textMoney.SetPosition({ -250.f, -100.f });
	textMoney.SetOrigin(Origins::TL);
	
	textExp.Set(font, "", 35, sf::Color::White);
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

	unitUiSelectMsg = new TextGo("unitUiSelectMsg");
	unitUiSelectMsg->Set(font, "unitUiMenu", 35, sf::Color::Blue);
	unitUiSelectMsg->SetPosition({ 300.f, -100.f });
	unitUiSelectMsg->SetOrigin(Origins::MC);
	unitUiSelectMsg->SetActive(false);

	age1UiUnit1Msg = new TextGo("age1UiUnit1Msg");
	age1UiUnit1Msg->Set(font, "15$ - club man", 35, sf::Color::Blue);
	age1UiUnit1Msg->SetPosition(unitUiSelectMsg->GetPosition());
	age1UiUnit1Msg->SetOrigin(Origins::MC);
	age1UiUnit1Msg->SetActive(false);

	age1UiUnit2Msg = new TextGo("age1UiUnit2Msg");
	age1UiUnit2Msg->Set(font, "50$ - slingshot man", 35, sf::Color::Blue);
	age1UiUnit2Msg->SetPosition(unitUiSelectMsg->GetPosition());
	age1UiUnit2Msg->SetOrigin(Origins::MC);
	age1UiUnit2Msg->SetActive(false);

	age1UiUnit3Msg = new TextGo("age1UiUnit3Msg");
	age1UiUnit3Msg->Set(font, "100$ - Dino rider", 35, sf::Color::Blue);
	age1UiUnit3Msg->SetPosition(unitUiSelectMsg->GetPosition());
	age1UiUnit3Msg->SetOrigin(Origins::MC);
	age1UiUnit3Msg->SetActive(false);

	turretUiSelectMsg = new TextGo("turretUiSelectMsg");
	turretUiSelectMsg->Set(font, "turretMenu", 35, sf::Color::Blue);
	turretUiSelectMsg->SetPosition(unitUiSelectMsg->GetPosition());
	turretUiSelectMsg->SetOrigin(Origins::MC);
	turretUiSelectMsg->SetActive(false);

	age1UiTurret1Msg = new TextGo("age1UiTurret1Msg");
	age1UiTurret1Msg->Set(font, "100$ - Rock slingshot", 35, sf::Color::Blue);
	age1UiTurret1Msg->SetPosition(unitUiSelectMsg->GetPosition());
	age1UiTurret1Msg->SetOrigin(Origins::MC);
	age1UiTurret1Msg->SetActive(false);

	age1UiTurret2Msg = new TextGo("age1UiTurret2Msg");
	age1UiTurret2Msg->Set(font, "200$ - Egg automatic", 35, sf::Color::Blue);
	age1UiTurret2Msg->SetPosition(unitUiSelectMsg->GetPosition());
	age1UiTurret2Msg->SetOrigin(Origins::MC);
	age1UiTurret2Msg->SetActive(false);

	age1UiTurret3Msg = new TextGo("exitMsg");
	age1UiTurret3Msg->Set(font, "500$ - Primitive Catapult", 35, sf::Color::Blue);
	age1UiTurret3Msg->SetPosition(unitUiSelectMsg->GetPosition());
	age1UiTurret3Msg->SetOrigin(Origins::MC);
	age1UiTurret3Msg->SetActive(false);

	turretSellMsg = new TextGo("turretSellMsg");
	turretSellMsg->Set(font, "sell to turret", 35, sf::Color::Blue);
	turretSellMsg->SetPosition(unitUiSelectMsg->GetPosition());
	turretSellMsg->SetOrigin(Origins::MC);
	turretSellMsg->SetActive(false);

	turretAddMsg = new TextGo("turretAddMsg");
	turretAddMsg->Set(font, "1000$ - Add a turret spot", 35, sf::Color::Blue);
	turretAddMsg->SetPosition(unitUiSelectMsg->GetPosition());
	turretAddMsg->SetOrigin(Origins::MC);
	turretAddMsg->SetActive(false);

	upgradeMsg = new TextGo("exitMsg");
	upgradeMsg->Set(font, "4000 Xp - Evolve to next age", 35, sf::Color::Blue);
	upgradeMsg->SetPosition(unitUiSelectMsg->GetPosition());
	upgradeMsg->SetOrigin(Origins::MC);
	upgradeMsg->SetActive(false);

	backBtnMsg = new TextGo("backBtnMsg");
	backBtnMsg->Set(font, "return to previous menu", 35, sf::Color::Blue);
	backBtnMsg->SetPosition(unitUiSelectMsg->GetPosition());
	backBtnMsg->SetOrigin(Origins::MC);
	backBtnMsg->SetActive(false);

	unitUiSelect = new SpriteGo("unitUiSelect");
	unitUiSelect->SetTexture("graphics/UnitUiSelect.png");
	unitUiSelect->SetOrigin(Origins::TR);
	unitUiSelect->SetPosition({ 750.f, -100.f });
	unitUiSelect->SetActive(true);

	age1UiUnit1 = new SpriteGo("unitUiSelect1");
	age1UiUnit1->SetTexture("graphics/age1UiUnit1.png");
	age1UiUnit1->SetOrigin(Origins::TR);
	age1UiUnit1->SetPosition({ unitUiSelect->GetPosition().x - 50.f, unitUiSelect->GetPosition().y - 50.f });
	age1UiUnit1->SetActive(false);
	
	age1UiUnit2 = new SpriteGo("unitUiSelect2");
	age1UiUnit2->SetTexture("graphics/age1UiUnit2.png");
	age1UiUnit2->SetOrigin(Origins::TR);
	age1UiUnit2->SetPosition({ unitUiSelect->GetPosition().x , unitUiSelect->GetPosition().y - 50.f });
	age1UiUnit2->SetActive(false);

	age1UiUnit3 = new SpriteGo("unitUiSelect3");
	age1UiUnit3->SetTexture("graphics/age1UiUnit3.png");
	age1UiUnit3->SetOrigin(Origins::TR);
	age1UiUnit3->SetPosition({ unitUiSelect->GetPosition().x + 50.f, unitUiSelect->GetPosition().y - 50.f });
	age1UiUnit3->SetActive(false);

	turretUiSelect = new SpriteGo("turretUiSelect");
	turretUiSelect->SetTexture("graphics/turretUiSelect.png");
	turretUiSelect->SetPosition({ unitUiSelect->GetPosition().x + 50.f, unitUiSelect->GetPosition().y });
	turretUiSelect->SetOrigin(Origins::TR);

	age1UiTurret1 = new SpriteGo("turretUiSelect1");
	age1UiTurret1->SetTexture("graphics/age1UiTurret1.png");
	age1UiTurret1->SetOrigin(Origins::TR);
	age1UiTurret1->SetPosition({ turretUiSelect->GetPosition().x - 50.f, turretUiSelect->GetPosition().y - 50.f});
	age1UiTurret1->SetActive(false);

	age1UiTurret2 = new SpriteGo("turretUiSelect2");
	age1UiTurret2->SetTexture("graphics/age1UiTurret2.png");
	age1UiTurret2->SetOrigin(Origins::TR);
	age1UiTurret2->SetPosition({ turretUiSelect->GetPosition().x, turretUiSelect->GetPosition().y - 50.f });
	age1UiTurret2->SetActive(false);

	age1UiTurret3 = new SpriteGo("turretUiSelect3");
	age1UiTurret3->SetTexture("graphics/age1UiTurret3.png");
	age1UiTurret3->SetOrigin(Origins::TR);
	age1UiTurret3->SetPosition({ turretUiSelect->GetPosition().x + 50.f, turretUiSelect->GetPosition().y - 50.f });
	age1UiTurret3->SetActive(false);

	turretAdd = new SpriteGo("turretAdd");
	turretAdd->SetTexture("graphics/turretAdd.png");
	turretAdd->SetOrigin(Origins::TR);
	turretAdd->SetPosition({ unitUiSelect->GetPosition().x + 100.f, unitUiSelect->GetPosition().y });

	turretSell = new SpriteGo("unitUiSelect");
	turretSell->SetTexture("graphics/turretSell.png");
	turretSell->SetOrigin(Origins::TR);
	turretSell->SetPosition({ unitUiSelect->GetPosition().x + 150.f, unitUiSelect->GetPosition().y});


	turretChoice = new SpriteGo("unitUiSelect");
	turretChoice->SetTexture("graphics/select.png");
	turretChoice->SetOrigin(Origins::TR);
	//turretChoice->SetPosition({ -700.f, 125.f });
	turretChoice->SetActive(false);

	turretStand = new SpriteGo("unitUiSelect");
	turretStand->SetTexture("graphics/select.png");
	turretStand->SetOrigin(Origins::TR);
	turretStand->SetPosition({ -700.f, 225.f });
	turretStand->SetActive(false);

	upgrade = new SpriteGo("unitUiSelect");
	upgrade->SetTexture("graphics/upgrade.png");
	upgrade->SetOrigin(Origins::TR);
	upgrade->SetPosition({ unitUiSelect->GetPosition().x + 200.f, unitUiSelect->GetPosition().y});


	backBtn = new SpriteGo("backBtn");
	backBtn->SetTexture("graphics/backBtn.png");
	backBtn->SetOrigin(Origins::TR);
	backBtn->SetPosition({ upgrade->GetPosition().x, upgrade->GetPosition().y - 50.f });
	backBtn->SetActive(false);

	ultimate = new SpriteGo("ultimate");
	ultimate->SetTexture("graphics/ultimate.png");
	ultimate->SetOrigin(Origins::TR);
	ultimate->SetPosition({ unitUiSelect->GetPosition().x + 200.f, unitUiSelect->GetPosition().y + 50.f});

	//turretCancelBtn = new SpriteGo("turretCancelBtn");
	//turretCancelBtn->SetTexture("graphics/cancelBtn.png");
	//turretCancelBtn->SetOrigin(Origins::TR);
	//turretCancelBtn->SetPosition({ turretSell->GetPosition().x + 0.f, turretSell->GetPosition().y - 65.f});
	//turretCancelBtn->SetActive(false);


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
	playerBuilding = dynamic_cast<PlayerBuilding*>(sceneGame->FindGo("playerbuilding"));

}

void UiHud::Update(float dt)
{

	//현재 선택상자가 ui 좌표에 존재하기에 건물처럼 월드좌표로 잡아주기
	auto choicePos = playerBuilding->GetPosition();
	choicePos.x += 150.f;
	choicePos.y -= 100.f;
	auto screenPos = sceneGame->WorldToScreen(choicePos);
	auto worldPos = sceneGame->ScreenToUi(screenPos);
	turretChoice->SetPosition(worldPos);

	sf::Vector2f currMousePos = InputMgr::GetMousePos();
	sf::Vector2f UiMousePos = sceneGame->ScreenToUi((sf::Vector2i)currMousePos);

	//---------------

	// 유닛 버튼에 커서가 위치할 경우
	sf::FloatRect unitUiSelectBounds = unitUiSelect->GetGlobalBounds();
	if (unitUiSelectBounds.contains(UiMousePos))
	{
		AllMsgDelete();
		unitUiSelectMsg->SetActive(true);

		//유닛 버튼을 클릭했을 경우
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			UnitTrue();
			TurretFalse();
		
			backBtn->SetActive(true);
		}
	}

	// 유닛1 버튼에 커서가 위치할 경우
	sf::FloatRect age1UiUnit1Bounds = age1UiUnit1->GetGlobalBounds();
	if (age1UiUnit1Bounds.contains(UiMousePos))
	{
		AllMsgDelete();
		age1UiUnit1Msg->SetActive(true);
		//유닛1 버튼을 클릭했을 경우
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			unitSelectMode = PlayerUnit::Age1Types::pMan;
			PlayerUnit* newUnit = nullptr;
			//위의 조건에 해당하는 타입이 나오면 break
			switch (unitSelectMode)
			{
			case PlayerUnit::Age1Types::pMan:
				newUnit = PlayerUnit::Create(PlayerUnit::Age1Types::pMan);
				break;
			case PlayerUnit::Age1Types::pSlingShot:
				newUnit = PlayerUnit::Create(PlayerUnit::Age1Types::pSlingShot);
				break;
			case PlayerUnit::Age1Types::pRider:
				newUnit = PlayerUnit::Create(PlayerUnit::Age1Types::pRider);
				break;
			}

			if (newUnit != nullptr)
			{
				//유닛1 플레이어 빌딩 위치에 소환
				newUnit->SetPosition({ playerBuilding->GetPosition().x + 100.f, playerBuilding->GetPosition().y - 100.f });
				sceneGame->AddGo(newUnit);
				age1UiUnit1Msg->SetActive(false);
			}
		}
	}
//-------
	// 유닛2 버튼에 커서가 위치할 경우
	sf::FloatRect age1UiUnit2Bounds = age1UiUnit2->GetGlobalBounds();
	if (age1UiUnit2Bounds.contains(UiMousePos))
	{
		AllMsgDelete();
		age1UiUnit2Msg->SetActive(true);
		//유닛2 버튼을 클릭했을 경우
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			unitSelectMode = PlayerUnit::Age1Types::pSlingShot;
			PlayerUnit* newUnit = nullptr;
			//위의 조건에 해당하는 타입이 나오면 break
			switch (unitSelectMode)
			{
			case PlayerUnit::Age1Types::pMan:
				newUnit = PlayerUnit::Create(PlayerUnit::Age1Types::pMan);
				break;
			case PlayerUnit::Age1Types::pSlingShot:
				newUnit = PlayerUnit::Create(PlayerUnit::Age1Types::pSlingShot);
				break;
			case PlayerUnit::Age1Types::pRider:
				newUnit = PlayerUnit::Create(PlayerUnit::Age1Types::pRider);
				break;
			}

			if (newUnit != nullptr)
			{
				//유닛3 플레이어 빌딩 위치에 소환
				newUnit->SetPosition({ playerBuilding->GetPosition().x + 100.f, playerBuilding->GetPosition().y - 100.f });
				sceneGame->AddGo(newUnit);
			}
		}
	}
//------
	// 유닛3 버튼에 커서가 위치할 경우
	sf::FloatRect age1UiUnit3Bounds = age1UiUnit3->GetGlobalBounds();
	if (age1UiUnit3Bounds.contains(UiMousePos))
	{
		AllMsgDelete();
		age1UiUnit3Msg->SetActive(true);
		//유닛3 버튼을 클릭했을 경우
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			unitSelectMode = PlayerUnit::Age1Types::pRider;
			PlayerUnit* newUnit = nullptr;
			//위의 조건에 해당하는 타입이 나오면 break
			switch (unitSelectMode)
			{
			case PlayerUnit::Age1Types::pMan:
				newUnit = PlayerUnit::Create(PlayerUnit::Age1Types::pMan);
				break;
			case PlayerUnit::Age1Types::pSlingShot:
				newUnit = PlayerUnit::Create(PlayerUnit::Age1Types::pSlingShot);
				break;
			case PlayerUnit::Age1Types::pRider:
				newUnit = PlayerUnit::Create(PlayerUnit::Age1Types::pRider);
				break;
			}

			if (newUnit != nullptr)
			{
				//유닛3 플레이어 빌딩 위치에 소환
				newUnit->SetPosition({ playerBuilding->GetPosition().x + 100.f, playerBuilding->GetPosition().y - 100.f });
				sceneGame->AddGo(newUnit);
				//std::cout << "ddd" << std::endl;
			}
		}
	}

	//// 유닛2 버튼에 커서가 위치할 경우
	//sf::FloatRect age1UiUnit2Bounds = age1UiUnit2->GetGlobalBounds();
	//if (age1UiUnit2Bounds.contains(UiMousePos))
	//{
	//	AllMsgDelete();
	//	age1UiUnit2Msg->SetActive(true);
	//
	//	//마우스 커서를 유닛2로 바꾸고
	//	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	//	{
	//		PlayerUnit* age1PlayerUnit2 = PlayerUnit::Create(PlayerUnit::Age1Types::pSlingShot);
	//		if (age1PlayerUnit2 != nullptr)
	//		{
	//			//유닛2 플레이어 빌딩 위치에 소환
	//			age1PlayerUnit2->SetPosition(playerBuilding->GetPosition());
	//			sceneGame->AddGo(age1PlayerUnit2);
	//		}
	//	}
	//}

	//// 유닛3 버튼에 커서가 위치할 경우
	//sf::FloatRect age1UiUnit3Bounds = age1UiUnit3->GetGlobalBounds();
	//if (age1UiUnit3Bounds.contains(UiMousePos))
	//{
	//	AllMsgDelete();
	//	age1UiUnit3Msg->SetActive(true);
	//	//유닛3 버튼을 클릭했을 경우
	//	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	//	{
	//		PlayerUnit* age1PlayerUnit3 = PlayerUnit::Create(PlayerUnit::Age1Types::pRider);
	//		if (age1PlayerUnit3 != nullptr)
	//		{
	//			//유닛3 플레이어 빌딩 위치에 소환
	//			age1PlayerUnit3->SetPosition(playerBuilding->GetPosition());
	//			sceneGame->AddGo(age1PlayerUnit3);
	//		}
	//	}
	//}

	//터렛 버튼에 마우스 커서가 위치 할 경우
	sf::FloatRect turretUiSelectBounds = turretUiSelect->GetGlobalBounds();
	if (turretUiSelectBounds.contains(UiMousePos))
	{
		AllMsgDelete();
		turretUiSelectMsg->SetActive(true);
	
		//터렛 버튼을 클릭했을 경우 Ui창 설정
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			TurretTrue();
			UnitFalse();

			backBtn->SetActive(true);
		}
	}

	//터렛 
	sf::FloatRect turretChoiceBounds = turretChoice->GetGlobalBounds();
	sf::Vector2f turretPlacementPosition = { playerBuilding->GetPosition().x + 100.f, playerBuilding->GetPosition().y - 100.f };
	//터렛1번 영역에 마우스 커서가 들어갔을때
	sf::FloatRect age1UiTurret1Bounds = age1UiTurret1->GetGlobalBounds();
	if (age1UiTurret1Bounds.contains(UiMousePos))
	{
		//터렛 1번 설명 메시지 출력
		AllMsgDelete();
		age1UiTurret1Msg->SetActive(true);

		//터렛 1번 영역을 클릭시 터렛 선택단계 스프라이트를 true로 변경
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left) &&
			sceneGame->TurretPlaceCheck(turretPlacementPosition))
		{
			turretChoice->SetActive(true);

			turretSelectMode = Turret::Age1TurretTypes::RockSlingshot;
		}
	}

	//마우스 왼쪽을 누르고, 터렛 선택모드가 RockSlingshot이며, 현재 터렛이 설치되어 있지 않을 때
	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left) &&
		turretChoiceBounds.contains(UiMousePos) &&
		turretChoice->GetActive() &&
		turretSelectMode == Turret::Age1TurretTypes::RockSlingshot &&
		sceneGame->TurretPlaceCheck(turretPlacementPosition))
	{
		Turret* newTurret = nullptr;

		//위의 조건에 해당하는 타입이 나오면 break
		switch (turretSelectMode)
		{
		case Turret::Age1TurretTypes::RockSlingshot:
			newTurret = Turret::Create(Turret::Age1TurretTypes::RockSlingshot);
			break;
		case Turret::Age1TurretTypes::EggAutomatic:
			newTurret = Turret::Create(Turret::Age1TurretTypes::EggAutomatic);
			break;
		case Turret::Age1TurretTypes::PrimitiveCatapult:
			newTurret = Turret::Create(Turret::Age1TurretTypes::PrimitiveCatapult);
			break;
		}

		//null값이 아니면 위의 조건의 터렛을 설치한후 설치 상태 스프라이트를 false로 한다.
		if (newTurret != nullptr)
		{
			newTurret->SetPosition(turretPlacementPosition);
			sceneGame->AddTurret(newTurret);
			sceneGame->AddGo(newTurret);
			turretChoice->SetActive(false);
			//sceneGame->AddGo(turretChoice);
		}
	}

	//-------------------------------------
	sf::FloatRect age1UiTurret2Bounds = age1UiTurret2->GetGlobalBounds();
	if (age1UiTurret2Bounds.contains(UiMousePos))
	{
		//터렛 2번 설명 메시지 출력
		AllMsgDelete();
		age1UiTurret2Msg->SetActive(true);

		//터렛 번 영역을 클릭시 터렛 선택단계 스프라이트를 true로 변경
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left) &&
			sceneGame->TurretPlaceCheck(turretPlacementPosition))
		{
			turretChoice->SetActive(true);
			turretSelectMode = Turret::Age1TurretTypes::EggAutomatic;
		}
	}

	//마우스 왼쪽을 누르고, 터렛 선택모드가 RockSlingshot이며, 현재 터렛이 설치되어 있지 않을 때
	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left) &&
		turretChoice->GetActive() &&
		turretChoiceBounds.contains(UiMousePos) &&
		turretSelectMode == Turret::Age1TurretTypes::EggAutomatic &&
		sceneGame->TurretPlaceCheck(turretPlacementPosition))
	{
		Turret* newTurret = nullptr;

		//위의 조건에 해당하는 타입이 나오면 break
		switch (turretSelectMode)
		{
		case Turret::Age1TurretTypes::RockSlingshot:
			newTurret = Turret::Create(Turret::Age1TurretTypes::RockSlingshot);
			break;
		case Turret::Age1TurretTypes::EggAutomatic:
			newTurret = Turret::Create(Turret::Age1TurretTypes::EggAutomatic);
			break;
		case Turret::Age1TurretTypes::PrimitiveCatapult:
			newTurret = Turret::Create(Turret::Age1TurretTypes::PrimitiveCatapult);
			break;
		}

		//null값이 아니면 위의 조건의 터렛을 설치한후 설치 상태 스프라이트를 false로 한다.
		if (newTurret != nullptr)
		{
			newTurret->SetPosition(turretPlacementPosition);
			sceneGame->AddTurret(newTurret);
			sceneGame->AddGo(newTurret);
			turretChoice->SetActive(false);
			//sceneGame->AddGo(turretChoice);
		}
	}
	//-----------------------------
	sf::FloatRect age1UiTurret3Bounds = age1UiTurret3->GetGlobalBounds();
	if (age1UiTurret3Bounds.contains(UiMousePos))
	{
		//터렛 3번 설명 메시지 출력
		AllMsgDelete();
		age1UiTurret3Msg->SetActive(true);

		//터렛 3번 영역을 클릭시 터렛 선택단계 스프라이트를 true로 변경
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left) &&
			sceneGame->TurretPlaceCheck(turretPlacementPosition))
		{
			turretChoice->SetActive(true);
			turretSelectMode = Turret::Age1TurretTypes::PrimitiveCatapult;
		}
	}

	//마우스 왼쪽을 누르고, 터렛 선택모드가 RockSlingshot이며, 현재 터렛이 설치되어 있지 않을 때
	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left) &&
		turretChoice->GetActive() &&
		turretChoiceBounds.contains(UiMousePos) &&
		turretSelectMode == Turret::Age1TurretTypes::PrimitiveCatapult &&
		sceneGame->TurretPlaceCheck(turretPlacementPosition))
	{
		Turret* newTurret = nullptr;

		//위의 조건에 해당하는 타입이 나오면 break
		switch (turretSelectMode)
		{
		case Turret::Age1TurretTypes::RockSlingshot:
			newTurret = Turret::Create(Turret::Age1TurretTypes::RockSlingshot);
			break;
		case Turret::Age1TurretTypes::EggAutomatic:
			newTurret = Turret::Create(Turret::Age1TurretTypes::EggAutomatic);
			break;
		case Turret::Age1TurretTypes::PrimitiveCatapult:
			newTurret = Turret::Create(Turret::Age1TurretTypes::PrimitiveCatapult);
			break;
		}

		//null값이 아니면 위의 조건의 터렛을 설치한후 설치 상태 스프라이트를 false로 한다.
		if (newTurret != nullptr)
		{
			newTurret->SetPosition(turretPlacementPosition);
			sceneGame->AddTurret(newTurret);
			sceneGame->AddGo(newTurret);
			turretChoice->SetActive(false);
			//sceneGame->AddGo(turretChoice);
		}
	}
	//---------------------------
	//if (InputMgr::GetMouseButtonDown(sf::Mouse::Left) &&
	//	turretSelectMode == Turret::Age1TurretTypes::RockSlingshot &&
	//	turretChoice->GetActive() &&
	//	sceneGame->TurretPlaceCheck({ playerBuilding->GetPosition().x + 100.f, playerBuilding->GetPosition().y - 100.f }))
	//{
	//	Turret* age1Turret1 = Turret::Create(Turret::Age1TurretTypes::RockSlingshot);
	//	if (age1Turret1 != nullptr)
	//	{
	//		age1Turret1->SetPosition({ playerBuilding->GetPosition().x + 100.f, playerBuilding->GetPosition().y - 100.f });
	//		sceneGame->AddTurret(age1Turret1);
	//		sceneGame->AddGo(age1Turret1);
	//		//sceneGame->AddGo(turretChoice);
	//		turretChoice->SetActive(false);
	//	}
	//}

	////터렛1 버튼에 커서가 위치할 경우
	//sf::FloatRect age1UiTurret1Bounds = age1UiTurret1->GetGlobalBounds();
	//if (age1UiTurret1Bounds.contains(UiMousePos))
	//{
	//	AllMsgDelete();
	//	age1UiTurret1Msg->SetActive(true);
	//	//터렛1 버튼을 클릭했을 경우
	//	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	//	{
	//		turretChoice->SetActive(true);
	//	}
	//}
	//////----

	////터렛 2번 버튼을 누르고 turretChoice가 존재하고 이미 생긴 포탑이 없을 경우에 포탑 생성
	//if (InputMgr::GetMouseButtonDown(sf::Mouse::Left) &&
	//	turretChoice->GetActive() &&
	//	sceneGame->TurretPlaceCheck({ playerBuilding->GetPosition().x + 100.f, playerBuilding->GetPosition().y - 100.f }))
	//{
	//	Turret* age1Turret2 = Turret::Create(Turret::Age1TurretTypes::EggAutomatic);
	//	if (age1Turret2 != nullptr)
	//	{
	//		age1Turret2->SetPosition({ playerBuilding->GetPosition().x + 100.f, playerBuilding->GetPosition().y - 100.f });
	//		sceneGame->AddTurret(age1Turret2);
	//		sceneGame->AddGo(age1Turret2);
	//		//sceneGame->AddGo(turretChoice);
	//		turretChoice->SetActive(false);
	//	}
	//}

	////터렛2 버튼에 커서가 위치할 경우
	//sf::FloatRect age1UiTurret2Bounds = age1UiTurret2->GetGlobalBounds();
	//if (age1UiTurret2Bounds.contains(UiMousePos))
	//{
	//	AllMsgDelete();
	//	age1UiTurret2Msg->SetActive(true);
	//	//터렛1 버튼을 클릭했을 경우
	//	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	//	{
	//		turretChoice->SetActive(true);
	//	}
	//}

	////// 터렛2 버튼에 커서가 위치할 경우
	//sf::FloatRect age1UiTurret2Bounds = age1UiTurret2->GetGlobalBounds();
	//if (age1UiTurret2Bounds.contains(UiMousePos))
	//{
	//	AllMsgDelete();
	//	age1UiTurret2Msg->SetActive(true);
	//	
	//	//터렛2 버튼을 클릭했을 경우
	//	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	//	{
	//		if (turretChoice->GetActive() && InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	//		{
	//			if (sceneGame->TurretPlaceCheck({ playerBuilding->GetPosition().x + 100.f, playerBuilding->GetPosition().y - 100.f }))
	//			{
	//				Turret* age1Turret2 = Turret::Create(Turret::Age1TurretTypes::EggAutomatic);
	//				if (age1Turret2 != nullptr)
	//				{
	//					age1Turret2->SetPosition({ playerBuilding->GetPosition().x + 100.f, playerBuilding->GetPosition().y - 100.f });
	//					sceneGame->AddTurret(age1Turret2);
	//					sceneGame->AddGo(age1Turret2);
	//					sceneGame->AddGo(turretChoice);
	//					turretChoice->SetActive(false);
	//				}
	//			}
	//		}
	//	}
	//}


	//	//터렛 2번 버튼을 누르고 turretChoice가 존재하고 이미 생긴 포탑이 없을 경우에 포탑 생성
	//if (InputMgr::GetMouseButtonDown(sf::Mouse::Left) &&
	//	turretChoice->GetActive() &&
	//	sceneGame->TurretPlaceCheck({ playerBuilding->GetPosition().x + 100.f, playerBuilding->GetPosition().y - 100.f }))
	//{
	//	Turret* age1Turret2 = Turret::Create(Turret::Age1TurretTypes::EggAutomatic);
	//	if (age1Turret2 != nullptr)
	//	{
	//		age1Turret2->SetPosition({ playerBuilding->GetPosition().x + 100.f, playerBuilding->GetPosition().y - 100.f });
	//		sceneGame->AddTurret(age1Turret2);
	//		sceneGame->AddGo(age1Turret2);
	//		sceneGame->AddGo(turretChoice);
	//		turretChoice->SetActive(false);
	//	}
	//}

	////터렛2 버튼에 커서가 위치할 경우
	//sf::FloatRect age1UiTurret2Bounds = age1UiTurret2->GetGlobalBounds();
	//if (age1UiTurret2Bounds.contains(UiMousePos))
	//{
	//	AllMsgDelete();
	//	age1UiTurret2Msg->SetActive(true);
	//	//터렛1 버튼을 클릭했을 경우
	//	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	//	{
	//		turretChoice->SetActive(true);
	//	}
	//}



	// 터렛3 버튼에 커서가 위치할 경우
	//sf::FloatRect age1UiTurret3Bounds = age1UiTurret3->GetGlobalBounds();
	//if (age1UiTurret3Bounds.contains(UiMousePos))
	//{
	//	AllMsgDelete();
	//	age1UiTurret3Msg->SetActive(true);

	//	//터렛3 버튼을 클릭했을 경우
	//	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	//	{
	//		//터렛리스트를 순회를 돌아서 설치 할 수 있을 경우에만 터렛을 생성
	//		if (turretChoice->GetActive() && InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	//		{
	//			if (turretChoice->GetActive() && InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	//			{
	//				if (sceneGame->TurretPlaceCheck({ playerBuilding->GetPosition().x + 100.f, playerBuilding->GetPosition().y - 100.f }))
	//				{
	//					Turret* age1Turret3 = Turret::Create(Turret::Age1TurretTypes::PrimitiveCatapult);
	//					if (age1Turret3 != nullptr)
	//					{
	//						age1Turret3->SetPosition({ playerBuilding->GetPosition().x + 100.f, playerBuilding->GetPosition().y - 100.f });
	//						sceneGame->AddTurret(age1Turret3);
	//						sceneGame->AddGo(age1Turret3);
	//						turretChoice->SetActive(false);
	//					}
	//				}
	//			}
	//		}
	//	}
	//}

	//터렛 추가 위치 버튼에 마우스 커서가 위치 할 경우
	sf::FloatRect turretAddtBounds = turretAdd->GetGlobalBounds();
	if (turretAddtBounds.contains(UiMousePos))
	{
		AllMsgDelete();
		turretAddMsg->SetActive(true);
		//터렛 추가 위치 버튼을 클릭했을 경우
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			UnitFalse();
			TurretFalse();

			turretUiSelect->SetActive(false);
			turretAdd->SetActive(false);
			turretSell->SetActive(false);
			//turretCancelBtn->SetActive(false);
			turretStand->SetActive(true);
			backBtn->SetActive(true);
		}
	}

	// 터렛 되팔기 버튼에 커서가 위치할 경우
	sf::FloatRect turretSelltBounds = turretSell->GetGlobalBounds();
	if (turretSelltBounds.contains(UiMousePos))
	{
		AllMsgDelete();
		turretSellMsg->SetActive(true);

		//터렛 되팔기 버튼을 클릭했을 경우
		//마우스 커서를 터렛sell이미지로 바꾸고
		//터렛이 설치 되어 있는 위치(플레이어 빌딩 위치 && 터렛 추가 발판
		//추가 발판이없으면 제외한 위치)에 설치 되어 있지 않으면 수행 하지 않게
		//터렛 클릭시 터렛을 active(false)하고 해당 터렛의 가격만큼 현재 돈 증가 되게
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			//turretCancelBtn->SetActive(true);

			UnitFalse();
			TurretFalse();


			turretUiSelect->SetActive(false);
			turretAdd->SetActive(false);
			turretSell->SetActive(false);

			backBtn->SetActive(true);
			
			//터렛3을 제거 후 그만큼 돈 증가 추가 코드 수정 필요
			//if(터렛 타입이 a일경우)
			//{
			//	a의 가격만큼 돈을 돌려준다.
			//}
		//else if
		//{

		//}
		//else
		//{

		//}
			sceneGame->AddMoney(100);
		}
	}

	//업그레이드 버튼에 마우스 커서가 위치 할 경우
	sf::FloatRect upgradeBounds = upgrade->GetGlobalBounds();
	if (upgradeBounds.contains(UiMousePos))
	{
		AllMsgDelete();
		upgradeMsg->SetActive(true);

		//업그레이드 버튼을 클릭했을 경우
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			//ex) 4000경험치에 도달시 업그레이드가 가능할 경우
			//현재 경험치를 확인하고 4000을 <=일 경우 업그레이드 함수 실행

		}
	}


	//필살기 버튼 위에 커서가 존재하여 클릭 했을 경우
	sf::FloatRect ultimateBounds = ultimate->GetGlobalBounds();
	if (ultimateBounds.contains(UiMousePos))
	{

		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			//살아있는 적군 유닛들을 전부 제거
			//쿨타임을 추가해야 하지 않을까
			sceneGame->EnemyClear();
		}
	}

	//뒤로가기 버튼에 마우스 커서가 위치 할 경우
	sf::FloatRect backBtnBounds = backBtn->GetGlobalBounds();
	if (backBtnBounds.contains(UiMousePos))
	{
		AllMsgDelete();
		backBtnMsg->SetActive(true);

		//뒤로가기 버튼을 클릭했을 경우
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			//turretCancelBtn->SetActive(false);
			UnitFalse();
			TurretFalse();

			turretUiSelect->SetActive(false);
			turretAdd->SetActive(false);
			turretSell->SetActive(false);

			backBtn->SetActive(false);
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

void UiHud::AllMsgDelete()
{
	unitUiSelectMsg->SetActive(false);
	age1UiUnit1Msg->SetActive(false);
	age1UiUnit2Msg->SetActive(false);
	age1UiUnit3Msg->SetActive(false);
	turretUiSelectMsg->SetActive(false);
	age1UiTurret1Msg->SetActive(false);
	age1UiTurret2Msg->SetActive(false);
	age1UiTurret3Msg->SetActive(false);
	turretSellMsg->SetActive(false);
	turretAddMsg->SetActive(false);
	upgradeMsg->SetActive(false);
	backBtnMsg->SetActive(false);
}

void UiHud::UnitTrue()
{
	age1UiUnit1->SetActive(true);
	age1UiUnit2->SetActive(true);
	age1UiUnit3->SetActive(true);
}

void UiHud::UnitFalse()
{
	age1UiUnit1->SetActive(false);
	age1UiUnit2->SetActive(false);
	age1UiUnit3->SetActive(false);
}

void UiHud::TurretTrue()
{
	age1UiTurret1->SetActive(true);
	age1UiTurret2->SetActive(true);
	age1UiTurret3->SetActive(true);
}

void UiHud::TurretFalse()
{
	age1UiTurret1->SetActive(false);
	age1UiTurret2->SetActive(false);
	age1UiTurret3->SetActive(false);
}

//void UiHud::ProcessTurretButton(SpriteGo* turretButton, const sf::Vector2f& mousePos, Turret::Age1TurretTypes turretType, const sf::Vector2f& placementPosition)
//{
//	sf::FloatRect buttonBounds = turretButton->GetGlobalBounds();
//	if (buttonBounds.contains(mousePos))
//	{
//		AllMsgDelete();
//
//		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left) && sceneGame->TurretPlaceCheck(placementPosition))
//		{
//			turretChoice->SetActive(true);
//			turretSelectMode = turretType;
//		}
//	}
//}

void UiHud::Draw(sf::RenderWindow& window)
{
	SpriteGo::Draw(window);

	textMoney.Draw(window);
	textExp.Draw(window);
	unitUiSelect->Draw(window);
	turretUiSelect->Draw(window);
	turretAdd->Draw(window);
	turretSell->Draw(window);
	upgrade->Draw(window);
	ultimate->Draw(window);

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

	if (age1UiTurret1->GetActive() || age1UiTurret2->GetActive() || age1UiTurret3->GetActive())
	{
		age1UiTurret1->Draw(window);
		age1UiTurret2->Draw(window);
		age1UiTurret3->Draw(window);
	}

	//if (turretCancelBtn->GetActive())
	//{
	//	turretCancelBtn->Draw(window);
	//}

	if (backBtn->GetActive())
	{
		backBtn->Draw(window);
	}
	if (unitUiSelectMsg->GetActive())
	{
		unitUiSelectMsg->Draw(window);
	}

	if (age1UiUnit1Msg->GetActive())
	{
		age1UiUnit1Msg->Draw(window);
	}

	if (age1UiUnit2Msg->GetActive())
	{
		age1UiUnit2Msg->Draw(window);
	}

	if (age1UiUnit3Msg->GetActive())
	{
		age1UiUnit3Msg->Draw(window);
	}

	if (turretUiSelectMsg->GetActive())
	{
		turretUiSelectMsg->Draw(window);
	}

	if (age1UiTurret1Msg->GetActive())
	{
		age1UiTurret1Msg->Draw(window);
	}

	if (age1UiTurret2Msg->GetActive())
	{
		age1UiTurret2Msg->Draw(window);
	}

	if (age1UiTurret3Msg->GetActive())
	{
		age1UiTurret3Msg->Draw(window);
	}

	if (turretSellMsg->GetActive())
	{
		turretSellMsg->Draw(window);
	}

	if (turretAddMsg->GetActive())
	{
		turretAddMsg->Draw(window);
	}

	if (upgradeMsg->GetActive())
	{
		upgradeMsg->Draw(window);
	}

	if (backBtnMsg->GetActive())
	{
		backBtnMsg->Draw(window);
	}
	if (turretChoice->GetActive())
	{
		turretChoice->Draw(window);
	}
}
