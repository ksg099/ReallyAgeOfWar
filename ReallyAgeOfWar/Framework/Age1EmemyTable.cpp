#include "pch.h"
#include "Age1EmemyTable.h"
#include "rapidcsv.h"


Age1EmemyTable::Age1EmemyTable(DataTable::Types t) : DataTable(t)
{
}

Age1EmemyTable::~Age1EmemyTable()
{
}

const DataAge1Ememy& Age1EmemyTable::Get(Age1Enemy::Age1Types id)
{
	// TODO: 여기에 return 문을 삽입합니다.
}

bool Age1EmemyTable::Load()
{
	return false;
}

void Age1EmemyTable::Release()
{
}
