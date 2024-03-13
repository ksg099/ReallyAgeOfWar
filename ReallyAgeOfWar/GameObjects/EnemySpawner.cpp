#include "pch.h"
#include "EnemySpawner.h"

EnemySpawner::EnemySpawner(const std::string& name) : Spawner(name)
{
}

GameObject* EnemySpawner::Create()
{
	//만약 모든 유형의 적을 생성했으면 생성을 그만한다.
	//내가 정한 순서대로 푸쉬백해서 나오는데 순회를 돌려서 매 인덱스마다
	//해당 인덱스에 해당하는 적군 타입을 출력하고 ++해줘서 계속 반복후
	// 만약 인덱스가 없을경우? null을 반환하여 종료한다.
	// 
	// 시간을 추가해서 내가 정한 시간 간격에 해당하면 나오게 한다.
	// 이러한 웨이브를 한 5개정도 만들어서 위의 사항을 반복시킨다.
	//if (currentIndex >= age1Type.size())
	//{
	//	return nullptr;
	//}

	//currentIndex++;
}

void EnemySpawner::Reset()
{
	//1번째 웨이브
	Spawner::Reset();
	age1Type.clear();

	age1Type.push_back(Age1Enemy::Age1Types::man);
	age1Type.push_back(Age1Enemy::Age1Types::man);
	age1Type.push_back(Age1Enemy::Age1Types::man);
	age1Type.push_back(Age1Enemy::Age1Types::man);
	age1Type.push_back(Age1Enemy::Age1Types::man);
	age1Type.push_back(Age1Enemy::Age1Types::slingShot);

}
