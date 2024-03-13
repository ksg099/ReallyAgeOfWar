#pragma once
#include "DataTable.h"
#include "Age1Enemy.h"

struct DataAge1Ememy
{
	Age1Enemy::Age1Types id;

	std::string nameId;
	std::string descriptionId;

	std::string textureId;
	int maxHp;
	float speed;
	int damage;
	float attackInterval;
};


class Age1EmemyTable : public DataTable
{

public:
	std::unordered_map<Age1Enemy::Age1Types, DataAge1Ememy> table;
protected:
	static DataAge1Ememy Undefined;
public:
	Age1EmemyTable(DataTable::Types t);
	~Age1EmemyTable()override;

	const DataAge1Ememy& Get(Age1Enemy::Age1Types id);

	bool Load()override;
	void Release()override;
};

