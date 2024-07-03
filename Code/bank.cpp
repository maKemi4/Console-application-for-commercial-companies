#include <fstream>
#include <iostream>
#include "bank.h"
#include <ctime>

#pragma warning(disable : 4996)

using namespace std;

Bank::Bank(int _id, string _name_of_company, string _country, double _priceImmovables, double _priceEquipment, double _revenue)
	: CommercialOrg(_id, _name_of_company, _country, _priceImmovables,  _priceEquipment,  _revenue)
{
	vector<DepositType> lst_deposits;
	availableDeposits = lst_deposits;
	vector<AbligationType> lst_abligations;
	availableAbligaions = lst_abligations;
	vector<OpenedDeposit> lst_openedDeposits;
	openedDeposits = lst_openedDeposits;
	vector<OpenedAbligation> lst_openedAbligrations;
	openedAbligations = lst_openedAbligrations;
};

string Bank::getInfo() const
{
	return "The name of the bank is " + name_of_company + ". The location is " + country;
}

void Bank::saveToFile() const
{
	ofstream myfile;
	myfile.open(name_of_company + ".txt");
	myfile << "Companies:" << endl;
	myfile << getInfo() << endl;

	myfile << "Available deposit types:" << endl;
	for (int i = 0; i < availableDeposits.size(); i++) myfile << i + 1 << ". " << availableDeposits[i].getInfo() << endl;
	myfile << "Available abligations types:" << endl;
	for (int i = 0; i < availableAbligaions.size(); i++) myfile << i + 1 << ". " << availableAbligaions[i].getInfo() << endl;
	myfile << "Employees:" << endl;
	for (int i = 0; i < employees.size(); i++) myfile << i + 1 << ". " << employees[i].getDataEmployee() << endl;
	myfile << "Clients:" << endl;
	for (int i = 0; i < clients.size(); i++) myfile << i + 1 << ". " << clients[i].toString() << endl;
}

CompanyTypes Bank::getCompanyType() const
{
	return CompanyTypes::BANK;
};

const string currentDateTime()
{
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
	return buf;
}

void Bank::takeDeposit(int _clientId, int _depositId, double _money)
{	
	int id = openedDeposits.size() + 1;
	string date = currentDateTime();
	OpenedDeposit opd(id, _depositId, _clientId, _money, date);
	openedDeposits.push_back(opd);
}

void Bank::buyAbligation(int _clientId, int _abligationId, double _count)
{
	int id = openedAbligations.size() + 1;
	string date = currentDateTime();
	OpenedAbligation opd(id, _abligationId, _clientId, _count, date);
	openedAbligations.push_back(opd);
}

double Bank::closeDeposit(int _depositId)
{	
	auto is_curDeposit = [&_depositId](OpenedDeposit opndDep) {return opndDep.getId() == _depositId; };
	auto foundDep = find_if(openedDeposits.begin(), openedDeposits.end(), is_curDeposit);
	auto index = distance(openedDeposits.begin(), foundDep);
	openedDeposits[index].setState(false);
	
	int depositTypeId = openedDeposits[index].getDepositId();
	auto is_curDepositType = [&depositTypeId](DepositType deptype) {return deptype.getId() == depositTypeId; };
	auto depType = find_if(availableDeposits.begin(), availableDeposits.end(), is_curDepositType);
	DepositType depT = *depType;

	return openedDeposits[index].getMoney() * depT.getPersent() / 100;
}

double Bank::closeAbligation(int _abligationId)
{	
	auto is_curAbligation = [&_abligationId](OpenedAbligation opndAbl) {return opndAbl.getId() == _abligationId; };
	auto foundAbl = find_if(openedAbligations.begin(), openedAbligations.end(), is_curAbligation);
	auto index = distance(openedAbligations.begin(), foundAbl);
	openedAbligations[index].setState(false);

	int abligationTypeId = openedAbligations[index].getAbligationId();
	auto is_curAblType = [&abligationTypeId](AbligationType abltype) {return abltype.getId() == abligationTypeId; };
	auto ablType = find_if(availableAbligaions.begin(), availableAbligaions.end(), is_curAblType);
	AbligationType ablT = *ablType;

	return openedAbligations[index].getCount() * ablT.getPersent() / 100;
}

void Bank::updateDepositType(int _depositId, double _persent)
{	
	auto is_curDep = [&_depositId](DepositType depT) {return depT.getId() == _depositId; };
	auto foundDepT = find_if(availableDeposits.begin(), availableDeposits.end(), is_curDep);
	auto index = distance(availableDeposits.begin(), foundDepT);
	availableDeposits[index].setPersent(_persent);
}

void Bank::updateAbligationType(int _abligationId, double _persent)
{	
	auto is_curAbl = [&_abligationId](AbligationType abliT) {return abliT.getId() == _abligationId; };
	auto foundAblT = find_if(availableAbligaions.begin(), availableAbligaions.end(), is_curAbl);
	auto index = distance(availableAbligaions.begin(), foundAblT);
	availableAbligaions[index].setPersent(_persent);
}

void Bank::addDepositType(int _monthCount, double _persent)
{
	DepositType dpt(availableDeposits.size() + 1, _monthCount, _persent);
	availableDeposits.push_back(dpt);
}

void Bank::addAbligationType(int _monthCount, double _persent)
{
	AbligationType ablt(availableAbligaions.size() + 1, _monthCount, _persent);
	availableAbligaions.push_back(ablt);
}

vector<OpenedDeposit> Bank::getDeposits() 
{
	return openedDeposits;
}

vector<OpenedAbligation> Bank::getAbligations()
{
	return openedAbligations;
}

vector<DepositType> Bank::getDepTypes()
{
	return availableDeposits;
}

vector<AbligationType> Bank::getAblTypes()
{
	return availableAbligaions;
}

Bank::~Bank()
{
	availableAbligaions.clear();
	availableDeposits.clear();
	openedDeposits.clear();
	openedAbligations.clear();
}
