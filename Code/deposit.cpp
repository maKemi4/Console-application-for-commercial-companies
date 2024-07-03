#include "deposit.h"

using namespace std;

DepositType::DepositType(int _id, int _monthCount, double _persent)
{
	id = _id;
	monthCount = _monthCount;
	persent = _persent;
}

string DepositType::getInfo() const
{
	return "Deposit to " + to_string(monthCount) + " month with " + to_string(persent) + "%";
}

int DepositType::getTypeId() const
{
	return id;
}

double DepositType::getPersent() const
{
	return persent;
}

int DepositType::getMonthCount() const
{
	return monthCount;
}

int DepositType::getId() const
{
	return id;
}

void DepositType::setPersent(double _persent)
{
	persent = _persent;
}