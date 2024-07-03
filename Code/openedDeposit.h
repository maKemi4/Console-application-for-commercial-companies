#pragma once
#include <iostream>

using namespace std;

class OpenedDeposit {
private:
	int depositId;
	int clientId;
	int id;
	double money;
	bool state;
	string date;

public:
	OpenedDeposit(int _id, int _depositId, int _clientId, double _money, string _date);

	int getDepositId() const;
	int getClientId() const;
	double getMoney() const;
	int getId() const;
	string getDate() const;
	void setState(bool _state);
	string getState() const;
};