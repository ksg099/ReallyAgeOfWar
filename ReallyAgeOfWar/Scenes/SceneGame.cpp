#include "pch.h"
#include "SceneGame.h"
#include "SpriteGo.h"
#include "PlayerBuilding.h"
#include "EnemyBuilding.h"
#include "Turret.h"
#include "UiHud.h"
//#include "Age1Enemy.h"
#include "Spawner.h"

SceneGame::SceneGame(SceneIds id) : Scene(id)
{
}

void SceneGame::SetStatus(Status newStatus)
{
	currentStatus = newStatus;
	switch (currentStatus)
	{
	case SceneGame::Status::NextWave:
		FRAMEWORK.SetTimeScale(3.f);
		currentWave++;
		if (currentWave < waves.size())
		{
			enemySpawner->WaveStart(&waves[currentWave]);
		}
		else
		{
			//
		}

		break;
	case SceneGame::Status::Playing:
		FRAMEWORK.SetTimeScale(1.f);
		break;
	case SceneGame::Status::GameOver:
		FRAMEWORK.SetTimeScale(0.f);
		break;
	case SceneGame::Status::Pause:
		//���㽺������ 0�̴ϱ�
		FRAMEWORK.SetTimeScale(0.f);
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

	//Ui
	hud = new UiHud("Hud");
	AddGo(hud, Ui);

	pauseMsg = new TextGo("pauseMsg");
	pauseMsg->Set(fontResMgr.Get("fonts/LiberationSans.ttf"), "PAUSED Press space again to resume", 60, sf::Color::White);
	pauseMsg->SetPosition({ 0.f, 0.f });
	pauseMsg->SetOrigin(Origins::MC);
	pauseMsg->SetActive(false);
	AddGo(pauseMsg, Ui);


	loseMsg = new TextGo("loseMsg");
	loseMsg->Set(fontResMgr.Get("fonts/LiberationSans.ttf"), "Exit Press Esc to Title", 60, sf::Color::White);
	loseMsg->SetPosition({ 0.f, 0.f });
	loseMsg->SetOrigin(Origins::MC);
	loseMsg->SetActive(false);
	AddGo(loseMsg, Ui);


	winMsg = new TextGo("winMsg");
	winMsg->Set(fontResMgr.Get("fonts/LiberationSans.ttf"), "Exit Press Esc to Title", 60, sf::Color::White);
	winMsg->SetPosition({ 0.f, 0.f });
	winMsg->SetOrigin(Origins::MC);
	winMsg->SetActive(false);
	AddGo(winMsg, Ui);

	// ���̺� �ʱ�ȭ
	waves.resize(totalWave);


	waves[0].timeVec.push_back(3.f); //������ ���� Ÿ�̸�
	waves[0].typeVec.push_back(Age1Enemy::Age1Types::man);
	waves[0].timeVec.push_back(6.f);
	waves[0].typeVec.push_back(Age1Enemy::Age1Types::slingShot);
	waves[0].timeVec.push_back(9.f);
	waves[0].typeVec.push_back(Age1Enemy::Age1Types::Rider);


	waves[1].timeVec.push_back(3.f);
	waves[1].typeVec.push_back(Age1Enemy::Age1Types::man);
	waves[1].timeVec.push_back(6.f);
	waves[1].typeVec.push_back(Age1Enemy::Age1Types::man);
	waves[1].timeVec.push_back(9.f);
	waves[1].typeVec.push_back(Age1Enemy::Age1Types::slingShot);

	waves[2].timeVec.push_back(3.f);
	waves[2].typeVec.push_back(Age1Enemy::Age1Types::man);
	waves[2].timeVec.push_back(6.f);
	waves[2].typeVec.push_back(Age1Enemy::Age1Types::slingShot);
	waves[2].timeVec.push_back(9.f);
	waves[2].typeVec.push_back(Age1Enemy::Age1Types::slingShot);

	waves[3].timeVec.push_back(3.f);
	waves[3].typeVec.push_back(Age1Enemy::Age1Types::man);
	waves[3].timeVec.push_back(6.f);
	waves[3].typeVec.push_back(Age1Enemy::Age1Types::Rider);
	waves[3].timeVec.push_back(9.f);
	waves[3].typeVec.push_back(Age1Enemy::Age1Types::slingShot);
	waves[3].timeVec.push_back(12.f);
	waves[3].typeVec.push_back(Age1Enemy::Age1Types::slingShot);

	enemySpawner = new Spawner();
	AddGo(enemySpawner);

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

	pauseMsg->SetPosition({ viewcenter.x + 50.f, viewcenter.y + 270.f});
	pauseMsg->SetOrigin(Origins::MC); // �޽����� �߾��� ȭ�� �߾ӿ� ������ ����

	// Game Over �޽��� ��ġ ����
	loseMsg->SetPosition({ viewcenter.x + 50.f, viewcenter.y + 270.f });
	loseMsg->SetOrigin(Origins::MC); // �޽����� �߾��� ȭ�� �߾ӿ� ������ ����

	// Win �޽��� ��ġ ���� (�����ϰ� ����)
	winMsg->SetPosition({ viewcenter.x + 50.f, viewcenter.y + 270.f });
	winMsg->SetOrigin(Origins::MC);

	Scene::Enter();


	hud->SetMoney(175);
	hud->SetExp(0);


	currentWave = -1;

	SetStatus(Status::NextWave);

	//������

	//prevMousPos = InputMgr::GetMousePos();
}

void SceneGame::Exit()
{
	Scene::Exit();
	FRAMEWORK.GetWindow().setMouseCursorVisible(true);
}


void SceneGame::Update(float dt)
{
	enemyList.clear();
	FindGoAll("Enemy", enemyList);
	enemyList.sort([this](GameObject* lhs, GameObject* rhs)
		{
			float distLhs = Utils::Distance(lhs->GetPosition(), playerbuilding->GetPosition());
			float distRhs = Utils::Distance(rhs->GetPosition(), playerbuilding->GetPosition());
			return distLhs < distRhs;
		}
	);

	//���� �߽��� ������
	sf::Vector2f currentCenter = worldView.getCenter();
	sf::Vector2f windowSize = (sf::Vector2f)FRAMEWORK.GetWindowSize();

	//���콺 ��ġ ���� �� �̵� //
	sf::Vector2f currMousePos = InputMgr::GetMousePos();
	sf::Vector2f uiMousePos = ScreenToUi((sf::Vector2i)currMousePos);
	sf::Vector2f worldMousePos = ScreenToWorld((sf::Vector2i)currMousePos);

	age1Turrent1->SetPosition({ playerbuilding->GetPosition().x + 180.f, playerbuilding->GetPosition().y - 125.f });


	switch (currentStatus)
	{
	case SceneGame::Status::NextWave:
		SetStatus(Status::Playing);
		break;
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

	case SceneGame::Status::GameOver:
		loseMsg->SetActive(true);
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			sf::FloatRect exitMsgBounds = loseMsg->GetGlobalBounds();
			if (exitMsgBounds.contains(uiMousePos))
			{
				SCENE_MGR.ChangeScene(SceneIds::Title);
		
			}
		}
	case SceneGame::Status::GameWin:
		winMsg->SetActive(true);
		if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
		{
			sf::FloatRect exitMsgBounds = winMsg->GetGlobalBounds();
			if (exitMsgBounds.contains(uiMousePos))
			{
				SCENE_MGR.ChangeScene(SceneIds::Title);
			}
		}
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

	Scene::Update(dt);
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

void SceneGame::EnemyClear()
{
	//for (auto enemy : enemies)
	//{
	//	if (enemy->isAlive)
	//	{
	//		enemy->OnDie();
	//	}
	//}
}

void SceneGame::OnWaveEnd()
{
	SetStatus(SceneGame::Status::NextWave);
}

void SceneGame::Draw(sf::RenderWindow& window)
{
	Scene::Draw(window);

}

