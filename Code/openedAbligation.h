#pragma once
#include <iostream>

using namespace std;

class OpenedAbligation {
private:
	int abligationId;
	int clientId;
	int id;
	double count;
	bool state;
	string date;

public:
	OpenedAbligation(int _id, int _abligationId, int _clientId, double _count, string _date);

	int getAbligationId() const;
	int getClientId() const;
	double getCount() const;
	int getId() const;
	string getDate() const;
	void setState(bool _state);
	string getState() const;
};
