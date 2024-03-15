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

	//���� ���û��ڰ� ui ��ǥ�� �����ϱ⿡ �ǹ�ó�� ������ǥ�� ����ֱ�
	auto choicePos = playerBuilding->GetPosition();
	choicePos.x += 150.f;
	choicePos.y -= 100.f;
	auto screenPos = sceneGame->WorldToScreen(choicePos);
	auto worldPos = sceneGame->ScreenToUi(screenPos);
	turretChoice->SetPosition(worldPos);

	sf::Vector2f currMousePos = InputMgr::GetMousePos();
	sf::Vector2f UiMousePos = sceneGame->ScreenToUi((sf::Vector2i)currMousePos);

	//---------------

	// ���� ��ư�� Ŀ���� ��ġ�� ���
	sf::FloatRect unitUiSelectBounds = unitUiSelect->GetGlobalBounds();
	if (unitUiSelectBounds.contains(UiMousePos))
	{
		AllMsgDelete();
		unitUiSelectMsg->SetActive(true);

		//���� ��ư�� Ŭ������ ���
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			UnitTrue();
			TurretFalse();
		
			backBtn->SetActive(true);
		}
	}

	// ����1 ��ư�� Ŀ���� ��ġ�� ���
	sf::FloatRect age1UiUnit1Bounds = age1UiUnit1->GetGlobalBounds();
	if (age1UiUnit1Bounds.contains(UiMousePos))
	{
		AllMsgDelete();
		age1UiUnit1Msg->SetActive(true);
		//����1 ��ư�� Ŭ������ ���
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			unitSelectMode = PlayerUnit::Age1Types::pMan;
			PlayerUnit* newUnit = nullptr;
			//���� ���ǿ� �ش��ϴ� Ÿ���� ������ break
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
				//����1 �÷��̾� ���� ��ġ�� ��ȯ
				newUnit->SetPosition({ playerBuilding->GetPosition().x + 100.f, playerBuilding->GetPosition().y - 100.f });
				sceneGame->AddGo(newUnit);
				age1UiUnit1Msg->SetActive(false);
			}
		}
	}
//-------
	// ����2 ��ư�� Ŀ���� ��ġ�� ���
	sf::FloatRect age1UiUnit2Bounds = age1UiUnit2->GetGlobalBounds();
	if (age1UiUnit2Bounds.contains(UiMousePos))
	{
		AllMsgDelete();
		age1UiUnit2Msg->SetActive(true);
		//����2 ��ư�� Ŭ������ ���
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			unitSelectMode = PlayerUnit::Age1Types::pSlingShot;
			PlayerUnit* newUnit = nullptr;
			//���� ���ǿ� �ش��ϴ� Ÿ���� ������ break
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
				//����3 �÷��̾� ���� ��ġ�� ��ȯ
				newUnit->SetPosition({ playerBuilding->GetPosition().x + 100.f, playerBuilding->GetPosition().y - 100.f });
				sceneGame->AddGo(newUnit);
			}
		}
	}
//------
	// ����3 ��ư�� Ŀ���� ��ġ�� ���
	sf::FloatRect age1UiUnit3Bounds = age1UiUnit3->GetGlobalBounds();
	if (age1UiUnit3Bounds.contains(UiMousePos))
	{
		AllMsgDelete();
		age1UiUnit3Msg->SetActive(true);
		//����3 ��ư�� Ŭ������ ���
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			unitSelectMode = PlayerUnit::Age1Types::pRider;
			PlayerUnit* newUnit = nullptr;
			//���� ���ǿ� �ش��ϴ� Ÿ���� ������ break
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
				//����3 �÷��̾� ���� ��ġ�� ��ȯ
				newUnit->SetPosition({ playerBuilding->GetPosition().x + 100.f, playerBuilding->GetPosition().y - 100.f });
				sceneGame->AddGo(newUnit);
				//std::cout << "ddd" << std::endl;
			}
		}
	}

	//// ����2 ��ư�� Ŀ���� ��ġ�� ���
	//sf::FloatRect age1UiUnit2Bounds = age1UiUnit2->GetGlobalBounds();
	//if (age1UiUnit2Bounds.contains(UiMousePos))
	//{
	//	AllMsgDelete();
	//	age1UiUnit2Msg->SetActive(true);
	//
	//	//���콺 Ŀ���� ����2�� �ٲٰ�
	//	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	//	{
	//		PlayerUnit* age1PlayerUnit2 = PlayerUnit::Create(PlayerUnit::Age1Types::pSlingShot);
	//		if (age1PlayerUnit2 != nullptr)
	//		{
	//			//����2 �÷��̾� ���� ��ġ�� ��ȯ
	//			age1PlayerUnit2->SetPosition(playerBuilding->GetPosition());
	//			sceneGame->AddGo(age1PlayerUnit2);
	//		}
	//	}
	//}

	//// ����3 ��ư�� Ŀ���� ��ġ�� ���
	//sf::FloatRect age1UiUnit3Bounds = age1UiUnit3->GetGlobalBounds();
	//if (age1UiUnit3Bounds.contains(UiMousePos))
	//{
	//	AllMsgDelete();
	//	age1UiUnit3Msg->SetActive(true);
	//	//����3 ��ư�� Ŭ������ ���
	//	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	//	{
	//		PlayerUnit* age1PlayerUnit3 = PlayerUnit::Create(PlayerUnit::Age1Types::pRider);
	//		if (age1PlayerUnit3 != nullptr)
	//		{
	//			//����3 �÷��̾� ���� ��ġ�� ��ȯ
	//			age1PlayerUnit3->SetPosition(playerBuilding->GetPosition());
	//			sceneGame->AddGo(age1PlayerUnit3);
	//		}
	//	}
	//}

	//�ͷ� ��ư�� ���콺 Ŀ���� ��ġ �� ���
	sf::FloatRect turretUiSelectBounds = turretUiSelect->GetGlobalBounds();
	if (turretUiSelectBounds.contains(UiMousePos))
	{
		AllMsgDelete();
		turretUiSelectMsg->SetActive(true);
	
		//�ͷ� ��ư�� Ŭ������ ��� Uiâ ����
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			TurretTrue();
			UnitFalse();

			backBtn->SetActive(true);
		}
	}

	//�ͷ� 
	sf::FloatRect turretChoiceBounds = turretChoice->GetGlobalBounds();
	sf::Vector2f turretPlacementPosition = { playerBuilding->GetPosition().x + 100.f, playerBuilding->GetPosition().y - 100.f };
	//�ͷ�1�� ������ ���콺 Ŀ���� ������
	sf::FloatRect age1UiTurret1Bounds = age1UiTurret1->GetGlobalBounds();
	if (age1UiTurret1Bounds.contains(UiMousePos))
	{
		//�ͷ� 1�� ���� �޽��� ���
		AllMsgDelete();
		age1UiTurret1Msg->SetActive(true);

		//�ͷ� 1�� ������ Ŭ���� �ͷ� ���ôܰ� ��������Ʈ�� true�� ����
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left) &&
			sceneGame->TurretPlaceCheck(turretPlacementPosition))
		{
			turretChoice->SetActive(true);

			turretSelectMode = Turret::Age1TurretTypes::RockSlingshot;
		}
	}

	//���콺 ������ ������, �ͷ� ���ø�尡 RockSlingshot�̸�, ���� �ͷ��� ��ġ�Ǿ� ���� ���� ��
	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left) &&
		turretChoiceBounds.contains(UiMousePos) &&
		turretChoice->GetActive() &&
		turretSelectMode == Turret::Age1TurretTypes::RockSlingshot &&
		sceneGame->TurretPlaceCheck(turretPlacementPosition))
	{
		Turret* newTurret = nullptr;

		//���� ���ǿ� �ش��ϴ� Ÿ���� ������ break
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

		//null���� �ƴϸ� ���� ������ �ͷ��� ��ġ���� ��ġ ���� ��������Ʈ�� false�� �Ѵ�.
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
		//�ͷ� 2�� ���� �޽��� ���
		AllMsgDelete();
		age1UiTurret2Msg->SetActive(true);

		//�ͷ� �� ������ Ŭ���� �ͷ� ���ôܰ� ��������Ʈ�� true�� ����
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left) &&
			sceneGame->TurretPlaceCheck(turretPlacementPosition))
		{
			turretChoice->SetActive(true);
			turretSelectMode = Turret::Age1TurretTypes::EggAutomatic;
		}
	}

	//���콺 ������ ������, �ͷ� ���ø�尡 RockSlingshot�̸�, ���� �ͷ��� ��ġ�Ǿ� ���� ���� ��
	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left) &&
		turretChoice->GetActive() &&
		turretChoiceBounds.contains(UiMousePos) &&
		turretSelectMode == Turret::Age1TurretTypes::EggAutomatic &&
		sceneGame->TurretPlaceCheck(turretPlacementPosition))
	{
		Turret* newTurret = nullptr;

		//���� ���ǿ� �ش��ϴ� Ÿ���� ������ break
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

		//null���� �ƴϸ� ���� ������ �ͷ��� ��ġ���� ��ġ ���� ��������Ʈ�� false�� �Ѵ�.
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
		//�ͷ� 3�� ���� �޽��� ���
		AllMsgDelete();
		age1UiTurret3Msg->SetActive(true);

		//�ͷ� 3�� ������ Ŭ���� �ͷ� ���ôܰ� ��������Ʈ�� true�� ����
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left) &&
			sceneGame->TurretPlaceCheck(turretPlacementPosition))
		{
			turretChoice->SetActive(true);
			turretSelectMode = Turret::Age1TurretTypes::PrimitiveCatapult;
		}
	}

	//���콺 ������ ������, �ͷ� ���ø�尡 RockSlingshot�̸�, ���� �ͷ��� ��ġ�Ǿ� ���� ���� ��
	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left) &&
		turretChoice->GetActive() &&
		turretChoiceBounds.contains(UiMousePos) &&
		turretSelectMode == Turret::Age1TurretTypes::PrimitiveCatapult &&
		sceneGame->TurretPlaceCheck(turretPlacementPosition))
	{
		Turret* newTurret = nullptr;

		//���� ���ǿ� �ش��ϴ� Ÿ���� ������ break
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

		//null���� �ƴϸ� ���� ������ �ͷ��� ��ġ���� ��ġ ���� ��������Ʈ�� false�� �Ѵ�.
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

	////�ͷ�1 ��ư�� Ŀ���� ��ġ�� ���
	//sf::FloatRect age1UiTurret1Bounds = age1UiTurret1->GetGlobalBounds();
	//if (age1UiTurret1Bounds.contains(UiMousePos))
	//{
	//	AllMsgDelete();
	//	age1UiTurret1Msg->SetActive(true);
	//	//�ͷ�1 ��ư�� Ŭ������ ���
	//	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	//	{
	//		turretChoice->SetActive(true);
	//	}
	//}
	//////----

	////�ͷ� 2�� ��ư�� ������ turretChoice�� �����ϰ� �̹� ���� ��ž�� ���� ��쿡 ��ž ����
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

	////�ͷ�2 ��ư�� Ŀ���� ��ġ�� ���
	//sf::FloatRect age1UiTurret2Bounds = age1UiTurret2->GetGlobalBounds();
	//if (age1UiTurret2Bounds.contains(UiMousePos))
	//{
	//	AllMsgDelete();
	//	age1UiTurret2Msg->SetActive(true);
	//	//�ͷ�1 ��ư�� Ŭ������ ���
	//	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	//	{
	//		turretChoice->SetActive(true);
	//	}
	//}

	////// �ͷ�2 ��ư�� Ŀ���� ��ġ�� ���
	//sf::FloatRect age1UiTurret2Bounds = age1UiTurret2->GetGlobalBounds();
	//if (age1UiTurret2Bounds.contains(UiMousePos))
	//{
	//	AllMsgDelete();
	//	age1UiTurret2Msg->SetActive(true);
	//	
	//	//�ͷ�2 ��ư�� Ŭ������ ���
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


	//	//�ͷ� 2�� ��ư�� ������ turretChoice�� �����ϰ� �̹� ���� ��ž�� ���� ��쿡 ��ž ����
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

	////�ͷ�2 ��ư�� Ŀ���� ��ġ�� ���
	//sf::FloatRect age1UiTurret2Bounds = age1UiTurret2->GetGlobalBounds();
	//if (age1UiTurret2Bounds.contains(UiMousePos))
	//{
	//	AllMsgDelete();
	//	age1UiTurret2Msg->SetActive(true);
	//	//�ͷ�1 ��ư�� Ŭ������ ���
	//	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	//	{
	//		turretChoice->SetActive(true);
	//	}
	//}



	// �ͷ�3 ��ư�� Ŀ���� ��ġ�� ���
	//sf::FloatRect age1UiTurret3Bounds = age1UiTurret3->GetGlobalBounds();
	//if (age1UiTurret3Bounds.contains(UiMousePos))
	//{
	//	AllMsgDelete();
	//	age1UiTurret3Msg->SetActive(true);

	//	//�ͷ�3 ��ư�� Ŭ������ ���
	//	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	//	{
	//		//�ͷ�����Ʈ�� ��ȸ�� ���Ƽ� ��ġ �� �� ���� ��쿡�� �ͷ��� ����
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

	//�ͷ� �߰� ��ġ ��ư�� ���콺 Ŀ���� ��ġ �� ���
	sf::FloatRect turretAddtBounds = turretAdd->GetGlobalBounds();
	if (turretAddtBounds.contains(UiMousePos))
	{
		AllMsgDelete();
		turretAddMsg->SetActive(true);
		//�ͷ� �߰� ��ġ ��ư�� Ŭ������ ���
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

	// �ͷ� ���ȱ� ��ư�� Ŀ���� ��ġ�� ���
	sf::FloatRect turretSelltBounds = turretSell->GetGlobalBounds();
	if (turretSelltBounds.contains(UiMousePos))
	{
		AllMsgDelete();
		turretSellMsg->SetActive(true);

		//�ͷ� ���ȱ� ��ư�� Ŭ������ ���
		//���콺 Ŀ���� �ͷ�sell�̹����� �ٲٰ�
		//�ͷ��� ��ġ �Ǿ� �ִ� ��ġ(�÷��̾� ���� ��ġ && �ͷ� �߰� ����
		//�߰� �����̾����� ������ ��ġ)�� ��ġ �Ǿ� ���� ������ ���� ���� �ʰ�
		//�ͷ� Ŭ���� �ͷ��� active(false)�ϰ� �ش� �ͷ��� ���ݸ�ŭ ���� �� ���� �ǰ�
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			//turretCancelBtn->SetActive(true);

			UnitFalse();
			TurretFalse();


			turretUiSelect->SetActive(false);
			turretAdd->SetActive(false);
			turretSell->SetActive(false);

			backBtn->SetActive(true);
			
			//�ͷ�3�� ���� �� �׸�ŭ �� ���� �߰� �ڵ� ���� �ʿ�
			//if(�ͷ� Ÿ���� a�ϰ��)
			//{
			//	a�� ���ݸ�ŭ ���� �����ش�.
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

	//���׷��̵� ��ư�� ���콺 Ŀ���� ��ġ �� ���
	sf::FloatRect upgradeBounds = upgrade->GetGlobalBounds();
	if (upgradeBounds.contains(UiMousePos))
	{
		AllMsgDelete();
		upgradeMsg->SetActive(true);

		//���׷��̵� ��ư�� Ŭ������ ���
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			//ex) 4000����ġ�� ���޽� ���׷��̵尡 ������ ���
			//���� ����ġ�� Ȯ���ϰ� 4000�� <=�� ��� ���׷��̵� �Լ� ����

		}
	}


	//�ʻ�� ��ư ���� Ŀ���� �����Ͽ� Ŭ�� ���� ���
	sf::FloatRect ultimateBounds = ultimate->GetGlobalBounds();
	if (ultimateBounds.contains(UiMousePos))
	{

		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			//����ִ� ���� ���ֵ��� ���� ����
			//��Ÿ���� �߰��ؾ� ���� ������
			sceneGame->EnemyClear();
		}
	}

	//�ڷΰ��� ��ư�� ���콺 Ŀ���� ��ġ �� ���
	sf::FloatRect backBtnBounds = backBtn->GetGlobalBounds();
	if (backBtnBounds.contains(UiMousePos))
	{
		AllMsgDelete();
		backBtnMsg->SetActive(true);

		//�ڷΰ��� ��ư�� Ŭ������ ���
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
