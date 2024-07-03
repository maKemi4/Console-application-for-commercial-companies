#include "datasourceFiller.h"
#include "Bank.h"
#include "insurCompany.h"


vector<CommercialOrg*> DataSourceFiller::getData()
{
	vector<CommercialOrg*> companies;

	Bank* bank = new Bank(1, "PrivatBank", "Ukraine", 100, 110, 110);
	
	bank->addNewEmployee("Maria", "Chuvaw", "Manager");
	bank->addNewEmployee("Mariana", "Omilio", "Client");
	bank->createClient("Omeloi", "Kuri");
	bank->createClient("Keyi", "Pepo");

	bank->addDepositType(1, 3);
	bank->addDepositType(3, 5.5);
	bank->addDepositType(12, 10);

	bank->addAbligationType(1, 12);
	bank->addAbligationType(12, 20);

	bank->createClient("Artem", "BRUH");
	bank->createClient("Brutulio", "Cloun");

	companies.push_back(bank);

	InsurCompany* inscom = new InsurCompany(2, "KAZKA", "Ukraine", 123, 321, 456);

	inscom->addNewEmployee("Artem", "Ivanovich", "Manager");
	inscom->addNewEmployee("Danya", "Sliw", "Client");
	inscom->createClient("Jake", "Bruist");
	inscom->createClient("John", "Leo");

	inscom->addCaseType("Insurance for car", 20000);
	inscom->addCaseType("Insurance for life", 100000);

	companies.push_back(inscom);

	return companies;
}
