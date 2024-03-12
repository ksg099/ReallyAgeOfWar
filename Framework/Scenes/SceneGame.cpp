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
		//멈춤스케일이 0이니까
		FRAMEWORK.SetTimeScale(0.f);
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
	playerbuilding->Reset();


	//게임 씬에서 적군 건물 출력
	enemybuilding = new EnemyBuilding("enemybuilding");
	AddGo(enemybuilding, World);
	enemybuilding->Reset();


	//터렛 출력
	age1Turrent1 = new Turret("age1Turrent1");
	AddGo(age1Turrent1, World);
	age1Turrent1->Reset();

	//적 유닛 출력
	age1Enemy1 = new Age1Enemy("age1Enemy");
	AddGo(age1Enemy1, World);
	age1Enemy1->Reset();
	//Ui
	hud = new UiHud("Hud");
	AddGo(hud, Ui);
	hud->Reset();

	pauseMsg = new TextGo("PAUSED");
	pauseMsg->Set(fontResMgr.Get("fonts/LiberationSans.ttf"), "PAUSED Press space again to resume", 60, sf::Color::White);
	pauseMsg->SetPosition({ 0.f, 0.f });
	pauseMsg->SetOrigin(Origins::MC);
	pauseMsg->SetActive(false);
	AddGo(pauseMsg, Ui);
	pauseMsg->Reset();


	loseMsg = new TextGo("exitMsg");
	loseMsg->Set(fontResMgr.Get("fonts/LiberationSans.ttf"), "Exit Press Esc to Title", 60, sf::Color::White);
	loseMsg->SetPosition({ 0.f, 0.f });
	loseMsg->SetOrigin(Origins::MC);
	loseMsg->SetActive(false);
	AddGo(loseMsg, Ui);
	loseMsg->Reset();


	winMsg = new TextGo("exitMsg");
	winMsg->Set(fontResMgr.Get("fonts/LiberationSans.ttf"), "Exit Press Esc to Title", 60, sf::Color::White);
	winMsg->SetPosition({ 0.f, 0.f });
	winMsg->SetOrigin(Origins::MC);
	winMsg->SetActive(false);
	AddGo(winMsg, Ui);
	winMsg->Reset();

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

	pauseMsg->SetPosition({ viewcenter.x + 50.f, viewcenter.y + 270.f});
	pauseMsg->SetOrigin(Origins::MC); // 메시지의 중앙이 화면 중앙에 오도록 설정

	// Game Over 메시지 위치 설정
	loseMsg->SetPosition({ viewcenter.x + 50.f, viewcenter.y + 270.f });
	loseMsg->SetOrigin(Origins::MC); // 메시지의 중앙이 화면 중앙에 오도록 설정

	// Win 메시지 위치 설정 (동일하게 적용)
	winMsg->SetPosition({ viewcenter.x + 50.f, viewcenter.y + 270.f });
	winMsg->SetOrigin(Origins::MC);

	Scene::Enter();


	hud->SetMoney(175);
	hud->SetExp(0);

	SetStatus(Status::Playing);
	//머할지

	//prevMousPos = InputMgr::GetMousePos();
}

void SceneGame::Exit()
{
	Scene::Exit();
	FRAMEWORK.GetWindow().setMouseCursorVisible(true);
}


void SceneGame::Update(float dt)
{
	Scene::Update(dt);

	//뷰의 중심을 가져옴
	sf::Vector2f currentCenter = worldView.getCenter();
	sf::Vector2f windowSize = (sf::Vector2f)FRAMEWORK.GetWindowSize();

	//마우스 위치 따라 뷰 이동 //
	sf::Vector2f currMousePos = InputMgr::GetMousePos();
	sf::Vector2f uiMousePos = ScreenToUi((sf::Vector2i)currMousePos);
	sf::Vector2f worldMousePos = ScreenToWorld((sf::Vector2i)currMousePos);

	age1Turrent1->SetPosition({ playerbuilding->GetPosition().x + 60.f, playerbuilding->GetPosition().y - 30.f });


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

