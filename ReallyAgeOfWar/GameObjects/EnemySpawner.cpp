#include "pch.h"
#include "EnemySpawner.h"

EnemySpawner::EnemySpawner(const std::string& name) : Spawner(name)
{
}

GameObject* EnemySpawner::Create()
{
	//���� ��� ������ ���� ���������� ������ �׸��Ѵ�.
	//���� ���� ������� Ǫ�����ؼ� �����µ� ��ȸ�� ������ �� �ε�������
	//�ش� �ε����� �ش��ϴ� ���� Ÿ���� ����ϰ� ++���༭ ��� �ݺ���
	// ���� �ε����� �������? null�� ��ȯ�Ͽ� �����Ѵ�.
	// 
	// �ð��� �߰��ؼ� ���� ���� �ð� ���ݿ� �ش��ϸ� ������ �Ѵ�.
	// �̷��� ���̺긦 �� 5������ ���� ���� ������ �ݺ���Ų��.
	//if (currentIndex >= age1Type.size())
	//{
	//	return nullptr;
	//}

	//currentIndex++;
}

void EnemySpawner::Reset()
{
	//1��° ���̺�
	Spawner::Reset();
	age1Type.clear();

	age1Type.push_back(Age1Enemy::Age1Types::man);
	age1Type.push_back(Age1Enemy::Age1Types::man);
	age1Type.push_back(Age1Enemy::Age1Types::man);
	age1Type.push_back(Age1Enemy::Age1Types::man);
	age1Type.push_back(Age1Enemy::Age1Types::man);
	age1Type.push_back(Age1Enemy::Age1Types::slingShot);

}
