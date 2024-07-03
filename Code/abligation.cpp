#include <string>
#include "abligation.h"

using namespace std;

AbligationType::AbligationType(int _id, int _monthCount, double _persent)
{
	id = _id;
	monthCount = _monthCount;
	persent = _persent;
}

string AbligationType::getInfo() const
{
	return "Abligation to " + to_string(monthCount) + " month " + "with " + to_string(persent) + " % ";
}

int AbligationType::getId() const
{
	return id;
}

double AbligationType::getPersent() const
{
	return persent;
}

int AbligationType::getMonthCount() const
{
	return monthCount;
}

void AbligationType::setPersent(double _persent)
{
	persent = _persent;
}