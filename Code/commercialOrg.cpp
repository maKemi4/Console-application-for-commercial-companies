#include "commercialOrg.h"
#pragma warning(disable : 4834)


CommercialOrg::CommercialOrg(int _id, string _name_of_company, string _country, double _priceImmovables, double _priceEquipment, double _revenue)
{
	name_of_company = _name_of_company;
	country = _country;
	vector<Employee> lst_empl;
	employees = lst_empl;

	vector<Client> lst_clients;
	clients = lst_clients;

	Capital cap(_priceImmovables, _priceEquipment, _revenue);
	capital = cap;

	id = _id;
}

void CommercialOrg::addNewEmployee(string _name, string _surname, string _position)
{
	int id = employees.size() + 1;
	Employee empl(id, _name, _surname, _position);
	employees.push_back(empl);
}

void CommercialOrg::fireEmployee(int _id)
{
	auto is_curEmployee = [&_id](Employee e) {return e.getId() == _id; };
	auto foundEmpl = find_if(employees.begin(), employees.end(), is_curEmployee);
	auto index = distance(employees.begin(), foundEmpl);
	employees[index].setFiredStatus(true);
}

string CommercialOrg::getName() const 
{
	return name_of_company;
}

void CommercialOrg::setName(string _name_of_company)
{
	name_of_company = _name_of_company;
}

string CommercialOrg::getCountry() const
{
	return country;
}

void CommercialOrg::setCountry(string _country)
{
	country = _country;
}


void CommercialOrg::createClient(string _name, string _surname)
{
	Client client(clients.size() + 1, _name, _surname);
	clients.push_back(client);
}

int CommercialOrg::getId() const
{
	return id;
}

Capital CommercialOrg::getCapital() const
{
	return capital;
}

vector<Client> CommercialOrg::getClients() const
{
	return clients;
}

vector<Employee> CommercialOrg::getEmployees() const
{
	return employees;
}

CommercialOrg::~CommercialOrg()
{
	clients.clear();
	employees.clear();
}
