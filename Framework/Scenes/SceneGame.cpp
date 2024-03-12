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

void SceneGame::Init() //차이
{
	

	//게임 씬에서 배경 출력
	background = new SpriteGo("BackGround");
	background->SetTexture("graphics/BackGround.png");
	background->SetPosition({ 0.f, 0.f }); //이부분 문제 같은데
	background->SetOrigin(Origins::MC);
	AddGo(background, World);

	//
	worldLeft = background->GetGlobalBounds().left;
	worldRight = worldLeft + background->GetGlobalBounds().width;

	//플레이어 건물 출력
	playerbuilding = new PlayerBuilding("playerbuilding");
	AddGo(playerbuilding, World);

	//게임 씬에서 적군 건물 출력
	enemybuilding = new EnemyBuilding("enemybuilding");
	AddGo(enemybuilding, World);

	//터렛 출력
	age1Turrent1 = new Turret("age1Turrent1");
	AddGo(age1Turrent1, World);

	//적 유닛 출력
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

void SceneGame::Enter() //차이
{
	//마우스 커서 안보이게하는 부분 주석처리
	//FRAMEWORK.GetWindow().setMouseCursorVisible(false);

	sf::Vector2f windowSize = (sf::Vector2f)FRAMEWORK.GetWindowSize();

	//지금 내가 보이고 카메라 화면을 띄우고 싶은거니까
	//사이드 뷰 게임으로 할예정이니까 Y는 그대로하고 X만 적절하게 바꿔주면 됨
	//현재 윈도우 뷰 사이즈 1280, 1024의 비율에 맞게 x좌표도 바꿔주면 된다.
	sf::Vector2f viewSize = sf::Vector2f(630, 504);
	sf::Vector2f viewcenter(viewSize.x / 2, 0);


	worldView.setSize(viewSize);
	worldView.setCenter(viewcenter);


	Scene::Enter();


	hud->SetMoney(175);
	hud->SetExp(0);

	//SetStatus(Status::Playing);
	//머할지

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

	//뷰의 중심을 가져옴
	sf::Vector2f currentCenter = worldView.getCenter();
	sf::Vector2f windowSize = (sf::Vector2f)FRAMEWORK.GetWindowSize();

	//마우스 위치 따라 뷰 이동 //
	sf::Vector2f currMousePos = InputMgr::GetMousePos();
	sf::Vector2f worldMousePos = ScreenToWorld((sf::Vector2i)currMousePos);

	age1Turrent1->SetPosition({ playerbuilding->GetPosition().x + 60.f, playerbuilding->GetPosition().y - 30.f });

	//if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	//{
	//	ispause = !ispause; // 상태 토글
	//}

	//일시정지 할때 게임 진행 상황도 멈추게
	//if (InputMgr::GetKeyDown(sf::Keyboard::Escape))
	//{
	//	ispause = true;

	//	//pauseshape.setPosition({currentCenter.x + 100.f, currentCenter.y + 300.f});
	//	//Utils::SetOrigin(pauseshape, Origins::MC);
	//	//pauseshape.setSize({ 500.f, 300.f });
	//	//pauseshape.setFillColor(sf::Color::Blue);
	//	//Utils::SetOrigin(pauseshape, Origins::MC); //SetOrigin이 인자를 도형과 위치 2개 받아야함
	//	//
	//	////팝업창 닫기 버튼이 없다면
	//	//if (!pauseclose->GetActive())
	//	//{
	//	//	pauseclose->SetActive(true);
	//	//}

	//	////게임 씬내에서 팝업창 닫기가 안됩니다.
	//	//sf::FloatRect closeBounds = pauseclose->GetGlobalBounds();
	//	//if (closeBounds.contains(worldMousePos) && ispause)
	//	//{
	//	//	pauseclose->SetActive(false);
	//	//}
	//}

	switch (currentStatus)
	{
	case SceneGame::Status::Playing:
		//게임중 상태에서 Escape누르면 일시정지 상태로 전환
		if (InputMgr::GetKeyDown(sf::Keyboard::Space))
		{
			SetStatus(Status::Pause);
			pauseMsg->SetActive(true);
		}
		break;

		//필살기
		if (InputMgr::GetKeyDown(sf::Keyboard::Delete))
		{
			//UnitClear();
		}

		if (playerbuilding->GetHp() <= 0)
		{
			SetStatus(Status::GameOver);
		}

	case SceneGame::Status::Pause:
		// 일시정지 상태에서 'Space'를 누르면 게임 재개
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
	//----------------------------------화면 밖으로 뷰가 나가지 않도록 하기----------------

//뷰좌표기준으로 한다.
	if (InputMgr::GetKey(sf::Keyboard::D))
	{
		currentCenter.x += viewMoveSpeed * dt; // 오른쪽으로 이동
		if (currentCenter.x > worldRight - worldView.getSize().x / 2 - 50.f)
		{
			currentCenter.x = worldRight - worldView.getSize().x / 2 - 50.f;
		}
	}
	// 왼쪽으로 이동하는 조건
	if (InputMgr::GetKey(sf::Keyboard::A))
	{
		currentCenter.x -= viewMoveSpeed * dt; // 왼쪽으로 이동
		if (currentCenter.x < worldLeft + worldView.getSize().x / 2 + 50.f)
		{
			currentCenter.x = worldLeft + worldView.getSize().x / 2 + 50.f;
		}
	}


	worldView.setCenter(currentCenter);

	// 변경된 뷰를 윈도우에 적용합니다.
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

