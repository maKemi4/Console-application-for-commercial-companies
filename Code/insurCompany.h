#pragma once
#include <iostream>
#include <vector>
#include "commercialOrg.h"
#include "caseType.h"
#include "case.h"

using namespace std;

class InsurCompany : public CommercialOrg
{
private:
	vector<Case> cases;
	vector<CaseType> caseTypes;

public:
	InsurCompany(int _id, string _name_of_company, string _country, double _priceImmovables, double _priceEquipment, double _revenue);

	string getInfo() const;
	CompanyTypes getCompanyType() const;
	void saveToFile() const;

	void openCase(int _caseId, int _clientId,  int _employeeId, double _curPrice);
	void closeCase(int _caseId);
	void fireEmployee(int _id) override;
	double calculateMoney(int _typeId, double _curPrice);
	void addCaseType(string _name, double _price);

	vector<Case> getСases();
	vector<CaseType> getCasesTypes();
	virtual ~InsurCompany();
};