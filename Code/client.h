#pragma once
#include <iostream>

using namespace std;

class Client {
private:
	int id;
	string name;
	string surname;

public:
	Client(int _id, string _name, string _surname);
	Client();

	int getClientId() const;
	string toString() const;
};