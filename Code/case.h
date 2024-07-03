#pragma once
#include <iostream>

using namespace std;

class Case
{
private:
	int caseId;
	int id;
	int employeeId;
	int clientId;
	double curPrice;
	bool isRunning;

public:
	Case(int _id, int _caseId, int _clientId, int _employeeId, double _curPrice);

	void setState(bool _isRunning);
	void setEmployeeId(int _employeeId);
	double getPrice() const;
	int getEmployeeId() const;
	int getClientId() const;
	int getId() const;
	int getCaseId() const;
	bool getState() const;
};