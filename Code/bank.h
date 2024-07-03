#pragma once
#include <iostream>
#include <vector>
#include "commercialOrg.h"
#include "deposit.h"
#include "abligation.h"
#include "openedDeposit.h"
#include "openedAbligation.h"


class Bank : public CommercialOrg
{
private:
	vector<DepositType> availableDeposits;
	vector<AbligationType> availableAbligaions;
	vector<OpenedDeposit> openedDeposits;
	vector<OpenedAbligation> openedAbligations;

public:
	Bank(int _id, string _name_of_company, string _country, double _priceImmovables, double _priceEquipment, double _revenue);
	string getInfo() const;
	void saveToFile() const;
	CompanyTypes getCompanyType() const;

	void addDepositType(int _monthCount, double _persent);
	void addAbligationType(int _monthCount, double _persent);

	void takeDeposit(int _clientId, int _depositId, double _money);
	void buyAbligation(int _clientId, int _abligationId, double _count);
	
	void updateDepositType(int _depositId, double _persent);
	void updateAbligationType(int _abligationId, double _persent);
	
	double closeDeposit(int _depositId);
	double closeAbligation(int _abligationId);

	vector<OpenedDeposit> getDeposits();
	vector<OpenedAbligation> getAbligations();
	vector<DepositType> getDepTypes();
	vector<AbligationType> getAblTypes();
	virtual ~Bank();
};	
