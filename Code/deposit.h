#pragma once
#include <iostream>
#include <string>

using namespace std;

class DepositType
{
private:
	int id;
	double persent;
	int monthCount;

public:
	DepositType(int _id, int _monthCount, double _persent);
	string getInfo() const;
	int getTypeId() const;
	double getPersent() const;
	int getMonthCount() const;
	int getId() const;
	void setPersent(double _persent);
};