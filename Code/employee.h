#pragma once
#include <iostream>

using namespace std;

class Employee 
{
private:
	string name;
	string surname;
	string position;
	bool isFired;
	int id;

public:
	Employee(int _id, string _name, string _surname, string _position);
	string getDataEmployee() const;
	string getPositon() const;
	void setFiredStatus(bool _isFired);
	bool getFiredStatus() const;
	int getId() const; 
};
