#include "employee.h"

using namespace std;

Employee::Employee(int _id, string _name, string _surname, string _position)
{
	id = _id;
	name = _name;
	surname = _surname;
	position = _position;
	isFired = false;
}

string Employee::getDataEmployee() const {
	return name + " " + surname + ". Position: " + position;
}

string Employee::getPositon() const {
	return position;
}

void Employee::setFiredStatus(bool _isFired){
	isFired = _isFired;
}

bool Employee::getFiredStatus() const{
	return isFired;
}

int Employee::getId() const {
	return id;
}