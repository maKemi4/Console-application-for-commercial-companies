#include <string>
#include "caseType.h"

using namespace std;

CaseType::CaseType(int _typeId, string _name, double _precent)
{
	typeId = _typeId;
	name = _name;
	percent = _precent;
}

int CaseType::getTypeId() const {
	return typeId;
}

string CaseType::getName() const {
	return name;
}

double CaseType::getPrecent() const {
	return percent;
}

void CaseType::setPrecent(double _percent)
{
	percent = _percent;
}

string CaseType::getInfo() const
{
	return name + " with insurance amount of " + to_string(percent) + "%";
}
