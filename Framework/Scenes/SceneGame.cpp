#include "pch.h"
#include "SceneGame.h"
#include "SpriteGo.h"
#include "PlayerBuilding.h"
#include "EnemyBuilding.h"
#include "Turret.h"
#include "UiHud.h"
#include "Age1Enemy.h"

SceneGame::SceneGame(SceneIds id) : Scene(id)
{
}

void SceneGame::SetStatus(Status newStatus)
{
	currentStatus = newStatus;
	switch (currentStatus)
	{
	case SceneGame::Status::Playing:
		FRAMEWORK.SetTimeScale(1.f);
		break;
	case SceneGame::Status::GameOver:
		FRAMEWORK.SetTimeScale(0.f);
		break;
	case SceneGame::Status::Pause:
		FRAMEWORK.SetTimeScale(1.f);
		break;
	}
}

void SceneGame::Init() //����
{
	

	//���� ������ ��� ���
	background = new SpriteGo("BackGround");
	background->SetTexture("graphics/BackGround.png");
	background->SetPosition({ 0.f, 0.f }); //�̺κ� ���� ������
	background->SetOrigin(Origins::MC);
	AddGo(background, World);

	//
	worldLeft = background->GetGlobalBounds().left;
	worldRight = worldLeft + background->GetGlobalBounds().width;

	//�÷��̾� �ǹ� ���
	playerbuilding = new PlayerBuilding("playerbuilding");
	AddGo(playerbuilding, World);

	//���� ������ ���� �ǹ� ���
	enemybuilding = new EnemyBuilding("enemybuilding");
	AddGo(enemybuilding, World);

	//�ͷ� ���
	age1Turrent1 = new Turret("age1Turrent1");
	AddGo(age1Turrent1, World);

	//�� ���� ���
	age1Enemy = new Age1Enemy("age1Enemy");
	AddGo(age1Enemy, World);

	//Ui
	hud = new UiHud("Hud");
	AddGo(hud, Ui);

	pauseMsg = new TextGo("PAUSED");
	pauseMsg->Set(fontResMgr.Get("fonts/LiberationSans.ttf"), "PAUSED Press space again to resume", 60, sf::Color::White);
	pauseMsg->SetPosition({ 0.f, 0.f });
	pauseMsg->SetOrigin(Origins::MC);
	pauseMsg->SetActive(false);
	AddGo(pauseMsg, Ui);

	exitMsg = new TextGo("exitMsg");
	exitMsg->Set(fontResMgr.Get("fonts/LiberationSans.ttf"), "Exit Press Esc to Title", 60, sf::Color::White);
	exitMsg->SetPosition({ 0.f, 0.f });
	exitMsg->SetOrigin(Origins::MC);
	exitMsg->SetActive(false);
	AddGo(exitMsg, Ui);

	Scene::Init();
}

void SceneGame::Release()
{
}

void SceneGame::Enter() //����
{
	//���콺 Ŀ�� �Ⱥ��̰��ϴ� �κ� �ּ�ó��
	//FRAMEWORK.GetWindow().setMouseCursorVisible(false);

	sf::Vector2f windowSize = (sf::Vector2f)FRAMEWORK.GetWindowSize();

	//���� ���� ���̰� ī�޶� ȭ���� ���� �����Ŵϱ�
	//���̵� �� �������� �ҿ����̴ϱ� Y�� �״���ϰ� X�� �����ϰ� �ٲ��ָ� ��
	//���� ������ �� ������ 1280, 1024�� ������ �°� x��ǥ�� �ٲ��ָ� �ȴ�.
	sf::Vector2f viewSize = sf::Vector2f(630, 504);
	sf::Vector2f viewcenter(viewSize.x / 2, 0);


	worldView.setSize(viewSize);
	worldView.setCenter(viewcenter);


	Scene::Enter();


	hud->SetMoney(175);
	hud->SetExp(0);

	//SetStatus(Status::Playing);
	//������

	//prevMousPos = InputMgr::GetMousePos();
}

void SceneGame::Exit()
{
	Scene::Exit();
	FRAMEWORK.GetWindow().setMouseCursorVisible(true);
}

void SceneGame::Reset()
{
	pauseMsg->SetActive(false);
	exitMsg->SetActive(false);
	age1Turrent1->SetActive(false);

}

void SceneGame::Update(float dt)
{
	Scene::Update(dt);

	//���� �߽��� ������
	sf::Vector2f currentCenter = worldView.getCenter();
	sf::Vector2f windowSize = (sf::Vector2f)FRAMEWORK.GetWindowSize();

	//���콺 ��ġ ���� �� �̵� //
	sf::Vector2f currMousePos = InputMgr::GetMousePos();
	sf::Vector2f worldMousePos = ScreenToWorld((sf::Vector2i)currMousePos);

	age1Turrent1->SetPosition({ playerbuilding->GetPosition().x + 60.f, playerbuilding->GetPosition().y - 30.f });

	//if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	//{
	//	ispause = !ispause; // ���� ���
	//}

	//�Ͻ����� �Ҷ� ���� ���� ��Ȳ�� ���߰�
	//if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	//{
	//	ispause = true;

	//	//pauseshape.setPosition({currentCenter.x + 100.f, currentCenter.y + 300.f});
	//	//Utils::SetOrigin(pauseshape, Origins::MC);
	//	//pauseshape.setSize({ 500.f, 300.f });
	//	//pauseshape.setFillColor(sf::Color::Blue);
	//	//Utils::SetOrigin(pauseshape, Origins::MC); //SetOrigin�� ���ڸ� ������ ��ġ 2�� �޾ƾ���
	//	//
	//	////�˾�â �ݱ� ��ư�� ���ٸ�
	//	//if (!pauseclose->GetActive())
	//	//{
	//	//	pauseclose->SetActive(true);
	//	//}

	//	////���� �������� �˾�â �ݱⰡ �ȵ˴ϴ�.
	//	//sf::FloatRect closeBounds = pauseclose->GetGlobalBounds();
	//	//if (closeBounds.contains(worldMousePos) && ispause)
	//	//{
	//	//	pauseclose->SetActive(false);
	//	//}
	//}

	switch (currentStatus)
	{
	case SceneGame::Status::Playing:
		//������ ���¿��� Escape������ �Ͻ����� ���·� ��ȯ
		if (InputMgr::GetKeyDown(sf::Keyboard::Space))
		{
			SetStatus(Status::Pause);
			pauseMsg->SetActive(true);
		}
		break;

		//�ʻ��
		if (InputMgr::GetKeyDown(sf::Keyboard::Delete))
		{
			//UnitClear();
		}

		if (playerbuilding->GetHp() <= 0)
		{
			SetStatus(Status::GameOver);
		}

	case SceneGame::Status::Pause:
		// �Ͻ����� ���¿��� 'Space'�� ������ ���� �簳
		if (InputMgr::GetKeyDown(sf::Keyboard::Space))
		{
			pauseMsg->SetActive(false);
			SetStatus(Status::Playing);
		}
		break;

		//case SceneGame::Status::NextWave:
		//	player->SetPosition({ 0, 0 });
		//	SetStatus(Status::Title);
		//	hud->SetWave(++wave);
		//	zspawners[0]->Spawn(5 * wave);
		//	break;
	case SceneGame::Status::GameOver:
		exitMsg->SetActive(true);
		SCENE_MGR.ChangeScene(SceneIds::Title);

	}
	//----------------------------------ȭ�� ������ �䰡 ������ �ʵ��� �ϱ�----------------

//����ǥ�������� �Ѵ�.
	if (InputMgr::GetKey(sf::Keyboard::D))
	{
		currentCenter.x += viewMoveSpeed * dt; // ���������� �̵�
		if (currentCenter.x > worldRight - worldView.getSize().x / 2 - 50.f)
		{
			currentCenter.x = worldRight - worldView.getSize().x / 2 - 50.f;
		}
	}
	// �������� �̵��ϴ� ����
	if (InputMgr::GetKey(sf::Keyboard::A))
	{
		currentCenter.x -= viewMoveSpeed * dt; // �������� �̵�
		if (currentCenter.x < worldLeft + worldView.getSize().x / 2 + 50.f)
		{
			currentCenter.x = worldLeft + worldView.getSize().x / 2 + 50.f;
		}
	}


	worldView.setCenter(currentCenter);

	// ����� �並 �����쿡 �����մϴ�.
	FRAMEWORK.GetWindow().setView(worldView);
}


void SceneGame::FixedUpdate(float dt)
{
	Scene::FixedUpdate(dt);
}

void SceneGame::AddExp(int s)
{
	this->Exp += s;
	hud->SetExp(this->Exp);
}

void SceneGame::AddMoney(int s)
{
	this->Money += s;
	hud->SetMoney(this->Money);
}

void SceneGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);

}

