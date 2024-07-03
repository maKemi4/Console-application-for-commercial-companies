#pragma once
#include <iostream>

using namespace std;

class CaseType 
{
private:
	int typeId;
	string name;
	double percent;

public:
	CaseType(int _typeId, string _name, double _precent);

	int getTypeId() const;
	string getName() const;
	double getPrecent() const;
	void setPrecent(double _precent);
	string getInfo() const;
};
