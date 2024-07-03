#include <string>
#include "case.h"

using namespace std;

Case::Case(int _id, int _caseId, int _clientId, int _employeeId, double _curPrice)
{
	id = _id;
	caseId = _caseId;
	curPrice = _curPrice;
	employeeId = _employeeId;
	clientId = _clientId;
	isRunning = true;
}

double Case::getPrice() const
{
	return curPrice;
}

int Case::getId() const
{
	return id;
}

int Case::getCaseId() const
{
	return caseId;
}

bool Case::getState() const
{
	return isRunning;
}

int Case::getClientId() const
{
	return clientId;
}

int Case::getEmployeeId() const
{
	return employeeId;
}

void Case::setEmployeeId(int _employeeId) 
{
	employeeId = _employeeId;
}


void Case::setState(bool _isRunning)
{
	isRunning = _isRunning;
}
