#include "pch.h"
#include "TitleScene.h"
#include "SpriteGo.h"
#include "TextGo.h"


TitleScene::TitleScene(SceneIds id) : Scene(id)
{
}


void TitleScene::Enter()
{
	Scene::Enter();

	//sf::Vector2f windowSize = (sf::Vector2f)FRAMEWORK.GetWindowSize();

	//��� �̹��� ��������
	sf::Vector2f viewSize = sf::Vector2f(1577, 504);
	sf::Vector2f centerPos = viewSize * 0.f;

	uiView.setSize(viewSize);
	uiView.setCenter(centerPos);

	FRAMEWORK.GetWindow().setView(uiView);

}
void TitleScene::Init()
{

	//Ÿ��Ʋ �� ��� ���
	titleTexture = new SpriteGo("TitleBackGround");
	titleTexture->SetTexture("graphics/BackGround.png");
	titleTexture->SetPosition({0.f, 0.f});
	titleTexture->SetOrigin(Origins::MC);
	//titleText->sortLayer = 1;
	AddGo(titleTexture, Ui);

	//Ÿ��Ʋ �� ���� ���
	titleText = new TextGo("Title");
	titleText->Set(fontResMgr.Get("fonts/LiberationSans.ttf"), "Age Of War", 100, sf::Color::White);
	titleText->SetPosition({ 0.f, -180.f });
	//titleText->SetPosition(centerPos->GetPosition());
	titleText->SetOrigin(Origins::MC);
	//titleText->sortLayer = 1;
	AddGo(titleText, Ui);

	//Ÿ��Ʋ �� ���ӽ��� ��ư ���
	titlestart = new TextGo("titlestart");
	titlestart->Set(fontResMgr.Get("fonts/LiberationSans.ttf"), "Start", 80, sf::Color::White);
	titlestart->SetPosition({ 0.f, -50.f });
	titlestart->SetOrigin(Origins::MC);
	//titleText->sortLayer = 1;
	AddGo(titlestart, Ui);

	//Ÿ��Ʋ �� �ɼ� ��ư ���
	titleoption = new TextGo("titleoption");
	titleoption->Set(fontResMgr.Get("fonts/LiberationSans.ttf"), "Options", 80, sf::Color::White);
	titleoption->SetPosition({ 0.f, 70.f });
	titleoption->SetOrigin(Origins::MC);
	//titleText->sortLayer = 1;
	AddGo(titleoption, Ui);

	//Ÿ��Ʋ �� �ɼ� â ���
	//optionsWindow = new SpriteGo("TitleBackGround");
	//optionsWindow->SetTexture("graphics/BackGround.png");
	//optionsWindow->SetPosition({ 0.f, 0.f });
	//optionsWindow->SetOrigin(Origins::MC);
	//AddGo(optionsWindow);

	//�ɼ� ��ư�� �ݱ� ��ư
	optionclose = new TextGo("optionclose");
	optionclose->Set(fontResMgr.Get("fonts/LiberationSans.ttf"), "Close", 80, sf::Color::White);
	optionclose->SetPosition({ titleoption->GetPosition().x, titleoption->GetPosition().y + 50.f });
	optionclose->SetOrigin(Origins::MC);
	optionclose->SetActive(false);
	//AddGo(optionclose, Ui); draw�ʿ��� ���༭ �ɼǹ�ư�� �˾�â�� �������� �ʰ� ����
	//Ȥ�� �˾�â�� Ŭ������ ���� ��ġ�� �ٲ��ָ� �����ϴ�.

	Scene::Init();
}

void TitleScene::Release()
{
	Scene::Release();
}


void TitleScene::Update(float dt)
{
	Scene::Update(dt);

	FRAMEWORK.GetWindow().setView(worldView);
	//���콺 ��ǥ�� ���ӳ� ������ ��ǥ�� ��ȯ
	sf::Vector2f currMousePos = InputMgr::GetMousePos();
	sf::Vector2f UiMousePos = ScreenToUi((sf::Vector2i)currMousePos);




	//mousecursor->SetPosition(ScreenToUi((sf::Vector2i)InputMgr::GetMousePos()));

	if (InputMgr::GetMouseButtonDown(sf::Mouse::Left))
	{

		//���ӽ��� ��ư Ŭ����
		//��� ������ �����ͼ� ���콺�� ������ �˻��ϱ�
		sf::FloatRect titlestartBounds = titlestart->GetGlobalBounds();
		if (titlestartBounds.contains(UiMousePos))
		{
			SCENE_MGR.ChangeScene(SceneIds::SceneGame);
		}

		//�ɼǹ�ư Ŭ����
		//��� ������ �����ͼ� ���콺�� ������ �˻��ϱ�
		sf::FloatRect titleoptionBounds = titleoption->GetGlobalBounds();
		if (titleoptionBounds.contains(UiMousePos))
		{
			optionsShape.setPosition(titleoption->GetPosition());
			optionsShape.setSize({500.f, 250.f});
			optionsShape.setFillColor(sf::Color::Blue);
			Utils::SetOrigin(optionsShape, Origins::MC);
			optionclose->SetActive(false);

		}

		//�ɼ� �ݱ� ��ư�� ���ٸ�
		if (!optionclose->GetActive())
		{
			optionclose->SetActive(true);
			titleoption->SetActive(false);
			titlestart->SetActive(false);
		}

		//�˾�â�� ������ �����ͼ� ���콺 Ŭ����
		sf::FloatRect optioncloseBounds = optionclose->GetGlobalBounds();
		if (optioncloseBounds.contains(UiMousePos))
		{
			optionclose->SetActive(false);
			titleoption->SetActive(true);
			titlestart->SetActive(true);
		}

	}

}

void TitleScene::Draw(sf::RenderWindow& window)
{
	
	Scene::Draw(window);

	//�ɼ� â�� ������ ��� ������� �ݱ� ��ư�� �׷���
	//draw���� �˾�â�� �׷��ֱ� �ֱ⋚���� ���ǿ��� �˾��ݱ⸸ ������ â�� ������.
	if(optionclose->GetActive())
	{
		window.draw(optionsShape);
		optionclose->Draw(window);
	}
	
	//shape->Draw(window);
	//Draw(titleTexture);
	

}
