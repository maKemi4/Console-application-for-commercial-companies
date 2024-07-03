#pragma once

#include "deque.h"
#include "bank.h"
#include "insurCompany.h"


class Menu 
{
private:
	void chooseCompany();
	void chooseClient();
	int chooseEmployee();
	int chooseDeposit(bool printOpD);
	int chooseAbligation(bool printOpA);
	int chooseCase(bool printOpC);

	void addNewCompany();
	void removeExCompany();

	void firstOperations();
	void secondOperations();
	void clientOperationsBank();
	void clientOperationsInsCom();
	void companySettingsBank();
	void companySettingsInsCom();

	Capital settingCapital();
	void findingCapital();

	void addNewClient();

	void addNewEmployee();
	void fireEmployee();

	void printListEmployees();
	void printListClients();
	void printListCompanies();

	bool printListOpenedDeps(bool printAll);
	void printListTypesDeps();
	bool printListOpenedAbls(bool printAll);
	void printListTypesAbls();
	bool printListOpenedCases(bool printAll);
	void printListTypesCases();
	
	void saveToFile();

	void takeDeposit();
	void updateDepType();
	void closeDeposit();
	void addDepType();
	
	void takeAbligation();
	void updateAblType();
	void closeAbligation();
	void addAblType();

	void openCase();
	void closeCase();
	void calculateMoney();
	void addCaseType();

	void clearDeque();

	Deque deque;
	CommercialOrg* comorg;
	Client client;

public:
	Menu(bool fillDefault);
	void run();
};
