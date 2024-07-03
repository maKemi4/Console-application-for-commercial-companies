#include <string>
#include "insurCompany.h"
#include <fstream>
#include <iostream>

using namespace std;

InsurCompany::InsurCompany(int _id, string _name_of_company, string _country, double _priceImmovables, double _priceEquipment, double _revenue)
	: CommercialOrg(_id, _name_of_company, _country, _priceImmovables, _priceEquipment, _revenue)
{
	vector<Case> lst_cases;
	cases = lst_cases;
	vector<CaseType> lst_insTypes;
	caseTypes = lst_insTypes;
};

string InsurCompany::getInfo() const
{
	return "The name of the insurance company is " + name_of_company + ". The location is " + country;
};

CompanyTypes InsurCompany::getCompanyType() const
{
	return CompanyTypes::INSURANCECOMPANY;
}

void InsurCompany::saveToFile() const
{
	ofstream myfile;
	myfile.open(name_of_company + ".txt");
	myfile << "Companies:" << endl;
	myfile << getInfo() << endl;

	myfile << "Available cases types:" << endl;
	for (int i = 0; i < caseTypes.size(); i++) myfile << i + 1 << ". " << caseTypes[i].getInfo() << endl;
	myfile << "Employees:" << endl;
	for (int i = 0; i < employees.size(); i++) myfile << i + 1 << ". " << employees[i].getDataEmployee() << endl;
	myfile << "Clients:" << endl;
	for (int i = 0; i < clients.size(); i++) myfile << i + 1 << ". " << clients[i].toString() << endl;
}

void InsurCompany::addCaseType(string _name, double _price)
{
	CaseType cst(caseTypes.size() + 1, _name, _price);
	caseTypes.push_back(cst);
}

void InsurCompany::openCase(int _caseId, int _clientId, int _employeeId, double _curPrice)
{
	Case cse(cases.size() + 1, _caseId, _clientId, _employeeId, _curPrice);
	cases.push_back(cse);
}

void InsurCompany::closeCase(int _caseId)
{
	auto is_curCase = [&_caseId](Case cses) {return cses.getId() == _caseId; };
	auto foundCase = find_if(cases.begin(), cases.end(), is_curCase);
	auto index = distance(cases.begin(), foundCase);
	cases[index].setState(false);
}

double InsurCompany::calculateMoney(int _typeId, double _curPrice)
{
	auto is_curCaseT = [&_typeId](CaseType cst) {return cst.getTypeId() == _typeId; };
	auto foundCaseT = find_if(caseTypes.begin(), caseTypes.end(), is_curCaseT);
	auto index = distance(caseTypes.begin(), foundCaseT);

	return caseTypes[index].getPrecent() * _curPrice / 100;
}

void InsurCompany::fireEmployee(int _id)
{
	int idEmployee = 0;
	for (int i = 0; i < employees.size(); i++) {
		if (employees[i].getFiredStatus() == false) {
			idEmployee = i;
		}
	}

	for (int i = 0; i < cases.size(); i++) {
		if (cases[i].getState() && cases[i].getEmployeeId() == _id) {
			cases[i].setEmployeeId(idEmployee);
		}
	}

	CommercialOrg::fireEmployee(_id);
}

vector<Case> InsurCompany::getСases() {
	return cases;
}

vector<CaseType> InsurCompany::getCasesTypes() {
	return caseTypes;
}

InsurCompany::~InsurCompany()
{
	cases.clear();
	caseTypes.clear();
}