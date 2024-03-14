#pragma once
#include "Scene.h"
#include <fstream>
#include <iostream>
#include "Age1Enemy.h"

class SpriteGo;
class TextGo;
class UiHud;
class PlayerBuilding;
class EnemyBuilding;
//class Age1Enemy;
class Turret;
class Spawner;

struct Wave
{
	std::vector<float> timeVec;
	std::vector<Age1Enemy::Age1Types> typeVec;
};


class SceneGame : public Scene
{
public:
	enum class Status
	{
		Title,
		Playing,
		NextWave,
		GameOver,
		GameWin,
		Pause,
	};

protected:
	Status currentStatus;
	
	SceneGame* sceneGame;
	UiHud* hud;
	PlayerBuilding* playerbuilding;
	EnemyBuilding* enemybuilding;

	Turret* age1Turrent1;

	SpriteGo* background;

	//TextGo* pauseclose;
	TextGo* pauseMsg;
	TextGo* loseMsg;
	TextGo* winMsg;
	//sf::RectangleShape pauseshape;

	bool ispause = false;

	int Exp = 0.f;
	int Money = 175.f;

	float nextSpawnTime = 0.f;
	float viewMoveSpeed = 350.f;
	float worldLeft = 0.f;
	float worldRight = 0.f; 
	float worldWidth = worldView.getSize().x; //월드 너비

	//sf::Vector2f prevMousPos;

	// wave
	int totalWave = 4;
	int currentWave = 0;
	std::vector<Wave> waves;
	Spawner* enemySpawner;
	std::list<GameObject*> enemyList;

public:
	const std::list<GameObject*>& GetEnemyList() const { return enemyList; }

	SceneGame(SceneIds id);
	~SceneGame() override = default;

	Status GetStatus() const { return currentStatus; }
	void SetStatus(Status newStatus);

	//UiHud* GetHud() const
	//{
	//	return hud;
	//}

	void Init() override;
	void Release() override;

	void Enter() override;
	void Exit() override;
	

	void Update(float dt) override;
	void FixedUpdate(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void AddExp(int s);
	void AddMoney(int s);

	void EnemyClear();

	void OnWaveEnd();

	std::vector<Wave> GetWaves() { return waves; }
	//std::vector<Age1Enemy*> GetEnemies();
};

