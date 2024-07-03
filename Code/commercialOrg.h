#pragma once
#include <vector>
#include "employee.h"

#include "client.h"
#include "capital.h"
#include "companyTypes.h"

using namespace std;

class CommercialOrg 
{
protected:
	vector<Client> clients;
	vector<Employee> employees;
	string name_of_company;
	string country;
	Capital capital;
	int id;

public:
	virtual CompanyTypes getCompanyType() const = 0;

	CommercialOrg(int _id, string _name_of_company, string _country, double _priceImmovables, double _priceEquipment, double _revenue);

	void setName(string _name_of_company);
	string getName() const;
	void setCountry(string _country);
	string getCountry() const;
	void addNewEmployee(string _name, string _surname, string _position);
	virtual void fireEmployee(int _id);
	void createClient(string _name, string _surname);
	virtual string getInfo() const = 0;
	int getId() const;
	Capital getCapital() const;
	virtual void saveToFile() const = 0;

	vector<Client> getClients() const;
	vector<Employee> getEmployees() const;
	virtual ~CommercialOrg();
};
