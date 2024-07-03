#include "openedDeposit.h"

using namespace std;

OpenedDeposit::OpenedDeposit(int _id, int _depositId, int _clientId, double _money, string _date)
{
	depositId = _depositId;
	id = _id;
	clientId = _clientId;
	money = _money;
	date = _date;
	state = true;
}

int OpenedDeposit::getDepositId() const {
	return depositId;
}

int OpenedDeposit::getClientId() const {
	return clientId;
}

string OpenedDeposit::getDate() const {
	return date;
}

double OpenedDeposit::getMoney() const {
	return money;
}

int OpenedDeposit::getId() const {
	return id;
}

void OpenedDeposit::setState(bool _state) {
	state = _state;
}

string OpenedDeposit::getState() const
{
	if (state)
	{
		return "Opened";
	}
	else return "Closed";
}