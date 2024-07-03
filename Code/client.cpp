#include "client.h"

using namespace std;

Client::Client(int _id, string _name, string _surname)
{
	id = _id;
	name = _name;
	surname = _surname;
}

Client::Client()
{
}

int Client::getClientId() const {
	return id;
}

string Client::toString() const {
	return "Client's name is " + name + ", the surname is " + surname;
}