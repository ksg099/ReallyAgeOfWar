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
	// TODO: ���⿡ return ���� �����մϴ�.
}

bool Age1EmemyTable::Load()
{
	return false;
}

void Age1EmemyTable::Release()
{
}
