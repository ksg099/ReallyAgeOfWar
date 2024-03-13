#include "pch.h"
#include "UiHud.h"
#include "SceneGame.h"


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
}

void UiHud::Update(float dt)
{

	sf::Vector2f currMousePos = InputMgr::GetMousePos();
	sf::Vector2f UiMousePos = sceneGame->ScreenToUi((sf::Vector2i)currMousePos);


	// ���� ��ư�� Ŀ���� ��ġ�� ���
	sf::FloatRect unitUiSelectBounds = unitUiSelect->GetGlobalBounds();
	if (unitUiSelectBounds.contains(UiMousePos))
	{
		AllMsgDelete();
		unitUiSelectMsg->SetActive(true);

		//���� ��ư�� Ŭ������ ���
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			age1UiTurret1->SetActive(false);
			age1UiTurret2->SetActive(false);
			age1UiTurret3->SetActive(false);

			age1UiUnit1->SetActive(true);
			age1UiUnit2->SetActive(true);
			age1UiUnit3->SetActive(true);
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
			//����1 �÷��̾� ��ġ�� ��ȯ
		}
	}

	// ����2 ��ư�� Ŀ���� ��ġ�� ���
	sf::FloatRect age1UiUnit2Bounds = age1UiUnit2->GetGlobalBounds();
	if (age1UiUnit2Bounds.contains(UiMousePos))
	{
		AllMsgDelete();
		age1UiUnit2Msg->SetActive(true);
	
		//����2 ��ư�� Ŭ������ ���
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			//����2 �÷��̾� ��ġ�� ��ȯ
		}
	}

	// ����3 ��ư�� Ŀ���� ��ġ�� ���
	sf::FloatRect age1UiUnit3Bounds = age1UiUnit3->GetGlobalBounds();
	if (age1UiUnit3Bounds.contains(UiMousePos))
	{
		AllMsgDelete();
		age1UiUnit3Msg->SetActive(true);
		//����3 ��ư�� Ŭ������ ���
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			//����3 �÷��̾� ��ġ�� ��ȯ
		}
	}

	//�ͷ� ��ư�� ���콺 Ŀ���� ��ġ �� ���
	sf::FloatRect turretUiSelectBounds = turretUiSelect->GetGlobalBounds();
	if (turretUiSelectBounds.contains(UiMousePos))
	{
		AllMsgDelete();
		//TurretMsgDelete();
		turretUiSelectMsg->SetActive(true);
	
		//�ͷ� ��ư�� Ŭ������ ���
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			age1UiUnit1->SetActive(false);
			age1UiUnit2->SetActive(false);
			age1UiUnit3->SetActive(false);

			age1UiTurret1->SetActive(true);
			age1UiTurret2->SetActive(true);
			age1UiTurret3->SetActive(true);

			backBtn->SetActive(true);
		}
	}

	//�ͷ�1 ��ư�� Ŀ���� ��ġ�� ���
	sf::FloatRect age1UiTurret1Bounds = age1UiTurret1->GetGlobalBounds();
	if (age1UiTurret1Bounds.contains(UiMousePos))
	{
		AllMsgDelete();
		age1UiTurret1Msg->SetActive(true);
		
		//�ͷ�1 ��ư�� Ŭ������ ���
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			//�ͷ�1 �÷��̾� ���� ��ġ�� ��ȯ
		}
	}



	// �ͷ�2 ��ư�� Ŀ���� ��ġ�� ���
	sf::FloatRect age1UiTurret2Bounds = age1UiTurret2->GetGlobalBounds();
	if (age1UiTurret2Bounds.contains(UiMousePos))
	{
		AllMsgDelete();
		age1UiTurret2Msg->SetActive(true);
		
		//�ͷ�2 ��ư�� Ŭ������ ���
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			//�ͷ�2 �÷��̾� ���� ��ġ�� ��ȯ
		}
	}


	// �ͷ�3 ��ư�� Ŀ���� ��ġ�� ���
	sf::FloatRect age1UiTurret3Bounds = age1UiTurret3->GetGlobalBounds();
	if (age1UiTurret3Bounds.contains(UiMousePos))
	{
		AllMsgDelete();
		age1UiTurret3Msg->SetActive(true);
	
		//�ͷ�3 ��ư�� Ŭ������ ���
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			//�ͷ�3 �÷��̾� ���� ��ġ�� ��ȯ
		}
	}

	//�ͷ� �߰� ��ġ ��ư�� ���콺 Ŀ���� ��ġ �� ���
	sf::FloatRect turretAddtBounds = turretAdd->GetGlobalBounds();
	if (turretAddtBounds.contains(UiMousePos))
	{
		AllMsgDelete();
		turretAddMsg->SetActive(true);

		//�ͷ� �߰� ��ġ ��ư�� Ŭ������ ���
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			turretUiSelect->SetActive(false);
			age1UiUnit1->SetActive(false);
			age1UiUnit2->SetActive(false);
			age1UiUnit3->SetActive(false);
			
			age1UiTurret1->SetActive(false);
			age1UiTurret2->SetActive(false);
			age1UiTurret3->SetActive(false);

			turretAdd->SetActive(false);
			turretSell->SetActive(false);
			//turretCancelBtn->SetActive(false);

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
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			//turretCancelBtn->SetActive(true);
			backBtn->SetActive(true);

			turretUiSelect->SetActive(false);
			age1UiUnit1->SetActive(false);
			age1UiUnit2->SetActive(false);
			age1UiUnit3->SetActive(false);
			turretAdd->SetActive(false);
			turretSell->SetActive(false);
			age1UiTurret1->SetActive(false);
			age1UiTurret2->SetActive(false);
			age1UiTurret3->SetActive(false);
			//�ͷ�3�� ���� �� �׸�ŭ �� ����
			sceneGame->AddMoney(100);
		}

		//�ͷ� ���ȱ� ���� �ִ� cancel��ư Ŭ����
		//sf::FloatRect turretCancelBtnBounds = turretCancelBtn->GetGlobalBounds();
		//if (turretCancelBtnBounds.contains(UiMousePos))
		//{
		//	//�ͷ� ���ȱ� ��� ������ �ڵ� �߰�
		//	AllMsgDelete();

		//}
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
			//���׷��̵� �Լ� �ҷ����� ���� ����ġ�� ������ ��쿡�� ���׷��̵� ����
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
			turretUiSelect->SetActive(false);
			age1UiUnit1->SetActive(false);
			age1UiUnit2->SetActive(false);
			age1UiUnit3->SetActive(false);
			turretAdd->SetActive(false);
			turretSell->SetActive(false);

			age1UiTurret1->SetActive(false);
			age1UiTurret2->SetActive(false);
			age1UiTurret3->SetActive(false);
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

void UiHud::Ui1unitMsg()
{
}

void UiHud::Ui1turretMsg()
{
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

void UiHud::UnitMsgDelete()
{
	age1UiUnit1Msg->SetActive(false);
	age1UiUnit2Msg->SetActive(false);
	age1UiUnit3Msg->SetActive(false);
}

void UiHud::TurretMsgDelete()
{
	age1UiTurret1Msg->SetActive(false);
	age1UiTurret2Msg->SetActive(false);
	age1UiTurret3Msg->SetActive(false);
}

void UiHud::Ui1unitClick()
{
}

void UiHud::Ui1turretClick()
{
}

void UiHud::UiBack()
{
}

void UiHud::Draw(sf::RenderWindow& window)
{
	SpriteGo::Draw(window);

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
}
