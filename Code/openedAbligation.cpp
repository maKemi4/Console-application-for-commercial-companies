#include "openedAbligation.h"

using namespace std;

OpenedAbligation::OpenedAbligation(int _id, int _abligationId, int _clientId, double _count, string _date)
{
	abligationId = _abligationId;
	id = _id;
	clientId = _clientId;
	count = _count;
	date = _date;
	state = true;
}

int OpenedAbligation::getAbligationId() const {
	return abligationId;
}

int OpenedAbligation::getClientId() const {
	return clientId;
}

string OpenedAbligation::getDate() const {
	return date;
}

double OpenedAbligation::getCount() const {
	return count;
}

int OpenedAbligation::getId() const {
	return id;
}

void OpenedAbligation::setState(bool _state) {
	state = _state;
}

string OpenedAbligation::getState() const
{
	if (state)
	{
		return "Opened";
	}
	else return "Closed";
}
