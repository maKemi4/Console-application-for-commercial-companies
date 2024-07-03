#pragma once
#include <iostream>

using namespace std;

class AbligationType
{
private:
	int id;
	double persent;
	int monthCount;

public:
	AbligationType(int _id, int _monthCount, double _persent);
	string getInfo() const;
	int getId() const;
	double getPersent() const;
	int getMonthCount() const;
	void setPersent(double _persent);
};
