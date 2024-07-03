#include "menu.h"
#include <fstream>
#include <iostream>
#include "datasourceFiller.h"

using namespace std;

void Menu::run() 
{
    int operationId = 0;
    
    while (cout <<
        "1. Start the program.\n"
        "2. Exit the program.\n"
        "Enter: " && !(cin >> operationId)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong choice!\n"
                "Try again!\n";
        system("pause");
        system("CLS");
    }

    switch (operationId)
    {
    case 1:
        firstOperations();
        break;
    case 2:
        clearDeque();
        cout << "Deque was cleared." << endl;
        cout << "Goodbye!)";
        break;
    default:
        cout << "Wrong choice!\n"
                "Try again!\n";
        system("pause");
        system("CLS");
        run();
    }
}

void Menu::firstOperations()
{
    system("CLS");
    int operationId = 0;
    int companyId = 0;

    while (cout <<
        "1. Print all companies.\n"
        "2. Choose a company.\n"
        "3. Add new company.\n"
        "4. Remove an existing company.\n"
        "5. Find the company with capital below the given.\n"
        "6. Save data to file.\n"
        "7. Back.\n"
        "Enter: " && !(cin >> operationId)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong choice!\n"
                "Try again!\n";
        system("pause");
        system("CLS");
    }

    switch (operationId)
    {
    case 1: 
        printListCompanies();
        system("pause");
        system("CLS");
        firstOperations();
        break;
    case 2: 
        chooseCompany();
        secondOperations();
        break;
    case 3:
        addNewCompany();
        system("pause");
        system("CLS");
        firstOperations();
        break;
    case 4:
        removeExCompany();
        system("pause");
        system("CLS");
        firstOperations();
        break;
    case 5:
        findingCapital();
        system("pause");
        system("CLS");
        firstOperations(); 
        break;
    case 6:
        saveToFile();
        system("pause");
        system("CLS");
        firstOperations();
        break;
    case 7:
        system("CLS");
        run();
        break;
    default:
        cout << "Wrong choice!\n"
                "Try again!\n";
        system("pause");
        system("CLS");
        firstOperations();
    }
}

void Menu::secondOperations()
{
    system("CLS");
    CompanyTypes companyType = comorg->getCompanyType();
    if(companyType == CompanyTypes::BANK) {
        cout << "You have choosed bank." << endl;
    }
    else if (companyType == CompanyTypes::INSURANCECOMPANY) {
        cout << "You have choosed insurance company." << endl;
    }

    int operationId = 0;

    while (cout <<
        "1. Add new client\n"
        "2. Add new employee.\n"
        "3. Fire employee.\n"
        "4. Print list of employees.\n"
        "5. Print list of clients.\n"
        "6. Choose client.\n"
        "7. Change company settings.\n"
        "8. Back.\n"
        "Enter: " && !(cin >> operationId)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong choice!\n"
                "Try again!\n";
        system("pause");
        system("CLS");
    }

    switch (operationId)
    {
    case 1:
        addNewClient();
        system("pause");
        system("CLS");
        secondOperations();
        break;
    case 2:
        addNewEmployee();
        system("pause");
        system("CLS");
        secondOperations();
        break;
    case 3:
        fireEmployee();
        system("pause");
        system("CLS");
        secondOperations();
        break;
    case 4:
        printListEmployees();
        system("pause");
        system("CLS");
        secondOperations();
        break;
    case 5:
        printListClients();
        system("pause");
        system("CLS");
        secondOperations();
        break;
    case 6:
        chooseClient();
        if (companyType == CompanyTypes::BANK) {
            clientOperationsBank();
        }
        else if (companyType == CompanyTypes::INSURANCECOMPANY) {
            clientOperationsInsCom();
        }
        system("pause");
        system("CLS");
        secondOperations();
        break;
    case 7:
        if (companyType == CompanyTypes::BANK) {
            companySettingsBank();
        }
        else if (companyType == CompanyTypes::INSURANCECOMPANY) {
            companySettingsInsCom();
        }
        system("pause");
        system("CLS");
        secondOperations();
        break;
    case 8:
        system("CLS");
        firstOperations();
        break;
    default:
        cout << "Wrong choice!\n"
                "Try again!\n";
        system("pause");
        system("CLS");
        secondOperations();
    }
}

void Menu::clientOperationsBank()
{
    system("CLS");
    int operationId = 0;
    while (cout <<
        "1. Take deposit.\n"
        "2. Buy Abligation.\n"
        "3. Print list of opened deposits.\n"
        "4. Print list of opened abligations.\n"
        "5. Back.\n"
        "Enter: " && !(cin >> operationId)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong choice!\n"
                "Try again!\n";
        system("pause");
        system("CLS");
    }

    switch (operationId)
    {
    case 1:
        takeDeposit();
        system("pause");
        system("CLS");
        clientOperationsBank();
        break;
    case 2:
        takeAbligation();
        system("pause");
        system("CLS");
        clientOperationsBank();
        break;
    case 3:
        printListOpenedDeps(false);
        system("pause");
        system("CLS");
        clientOperationsBank();
        break;
    case 4:
        printListOpenedAbls(false);
        system("pause");
        system("CLS");
        clientOperationsBank();
        break;
    case 5:
        system("CLS");
        secondOperations();
        break;
    default:
        cout << "Wrong choice!\n"
                "Try again!\n";
        system("pause");
        system("CLS");
        clientOperationsBank();
    }
}

void Menu::clientOperationsInsCom()
{
    system("CLS");
    int operationId = 0;
 
    while (cout <<
        "1. Open case.\n"
        "2. Print list of opened cases.\n"
        "3. Calculate the money.\n"
        "4. Back.\n"
        "Enter: " && !(cin >> operationId)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong choice!\n"
                "Try again!\n";
        system("pause");
        system("CLS");
    }

    switch (operationId)
    {
    case 1:
        openCase();
        system("pause");
        system("CLS");
        clientOperationsInsCom();
        break;
    case 2:
        printListOpenedCases(false);
        system("pause");
        system("CLS");
        clientOperationsInsCom();
        break;
    case 3: 
        calculateMoney();
        system("pause");
        system("CLS");
        clientOperationsInsCom();
        break;
    case 4:
        system("CLS");
        secondOperations();
        break;
    default:
        cout << "Wrong choice!\n"
                "Try again!\n";
        system("pause");
        system("CLS");
        clientOperationsInsCom();
    }
}

void Menu::companySettingsBank()
{
    system("CLS");
    int operationId = 0;
 
    while (cout <<
        "1. Close the deposit.\n"
        "2. Close the abligation.\n"
        "3. Update the deposit type.\n"
        "4. Update the abligation type.\n"
        "5. Add deposit type.\n"
        "6. Add Abligation type.\n"
        "7. Print list of opened deposits.\n"
        "8. Print list of opened abligations.\n"
        "9. Print list of types abligation.\n"
        "10. Print list of types deposit.\n"
        "11. Back.\n"
        "Enter: " && !(cin >> operationId)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong choice!\n"
                "Try again!\n";
        system("pause");
        system("CLS");
    }

    switch (operationId)
    {
    case 1:
        closeDeposit();
        system("pause");
        system("CLS");
        companySettingsBank();
        break;
    case 2:
        closeAbligation();
        system("pause");
        system("CLS");
        companySettingsBank();
        break;
    case 3:
        updateDepType();
        system("pause");
        system("CLS");
        companySettingsBank();
        break;
    case 4:
        updateAblType();
        system("pause");
        system("CLS");
        companySettingsBank();
        break;
    case 5:
        addDepType();
        system("pause");
        system("CLS");
        companySettingsBank();
        break;
    case 6:
        addAblType();
        system("pause");
        system("CLS");
        companySettingsBank();
        break;
    case 7:
        printListOpenedDeps(true);
        system("pause");
        system("CLS");
        companySettingsBank();
        break;
    case 8:
        printListOpenedAbls(true);
        system("pause");
        system("CLS");
        companySettingsBank();
        break;
    case 9:
        printListTypesAbls();
        system("pause");
        system("CLS");
        companySettingsBank();
        break;
    case 10:
        printListTypesDeps();
        system("pause");
        system("CLS");
        companySettingsBank();
        break;
    case 11:
        system("CLS");
        secondOperations();
        break;
    default:
        cout << "Wrong choice!\n"
                "Try again!\n";
        system("pause");
        system("CLS");
        companySettingsBank();
    }
}

void Menu::companySettingsInsCom()
{
    system("CLS");
    int operationId = 0;
    
    while (cout <<
        "1. Close the case.\n"
        "2. Add new case type.\n"
        "3. Print list of oppened cases.\n"
        "4. Print list of types case.\n"
        "5. Back.\n"
        "Enter: " && !(cin >> operationId)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong choice!\n"
                "Try again!\n";
        system("pause");
        system("CLS");
    }

    switch (operationId)
    {
    case 1:
        closeCase();
        system("pause");
        system("CLS");
        companySettingsInsCom();
        break;
    case 2:
        addCaseType();
        system("pause");
        system("CLS");
        companySettingsInsCom();
        break;
    case 3:
        printListOpenedCases(true);
        system("pause");
        system("CLS");
        companySettingsInsCom();
    case 4:
        printListTypesCases();
        system("pause");
        system("CLS");
        companySettingsInsCom();
    case 5: 
        system("CLS");
        secondOperations();
        break;
    default:
        cout << "Wrong choice!\n"
                "Try again!\n";
        system("pause");
        system("CLS");
        companySettingsInsCom();
    }
}

Menu::Menu(bool fillDefault)
{
    comorg = nullptr;
    if (fillDefault) {
        DataSourceFiller datasorce;
        vector<CommercialOrg*> data = datasorce.getData();
        for (size_t i = 0; i < data.size(); i++)
            deque.push_back(data[i]);
    }
}

void Menu::chooseCompany()
{
    int selectedCompanyId = 0;
    printListCompanies();
    cout << "Choose the company: ";
    cin >> selectedCompanyId;

    comorg = deque.getById(selectedCompanyId);
}

void Menu::chooseClient()
{
    int selectedClientId = 0;
    printListClients();
    cout << "Choose the client: ";
    cin >> selectedClientId;
    vector <Client> clients = comorg->getClients();
    for (int i = 0; i < clients.size(); i++) {
        if (selectedClientId == clients[i].getClientId()) {
            client = clients[i];
        }
        else client = clients[0];
    }

    if (selectedClientId > clients.size()) {
        cout << "Your choice is wrong. Your selection will autocorrect to the first element!" << endl;
        system("pause");
        system("CLS");
    }

}

int Menu::chooseEmployee()
{
    int selectedEmployeeId = 0;
    printListEmployees();
    cout << "Choose the employee.\n"
            "Enter: ";
    cin >> selectedEmployeeId;

    return selectedEmployeeId;
}

int Menu::chooseDeposit(bool printOpD)
{
    int selectedDepId = 0;

    if (printOpD)
    {
        if (printListOpenedDeps(true)) { 
            cout << "No opened deposit!" << endl;
            return 0;
        }
        else {
            cout << "Choose the deposit.\n"
                    "Enter: ";
            cin >> selectedDepId;
            return selectedDepId;
        }
    }
    else
    {   
        printListTypesDeps();
        cout << "Choose the abligation type.\n"
                "Enter: ";
        cin >> selectedDepId;
        return selectedDepId;
    }
}

int Menu::chooseAbligation(bool printOpA)
{
    int selectedAblId = 0;

    if (printOpA)
    {
        if (printListOpenedAbls(true)) {
            cout << "No opened abligation!" << endl;
            return 0;
        }
        else {
            cout << "Choose the abligation.\n"
                    "Enter: ";
            cin >> selectedAblId;
            return selectedAblId;
        }
    }
    else
    {
        printListTypesAbls();
        cout << "Choose the abligation type.\n"
                "Enter: ";
        cin >> selectedAblId;
        return selectedAblId;
    }
}

int Menu::chooseCase(bool printOpC)
{
    int selectedCaseId = 0;

    if (printOpC) 
    {
        if (printListOpenedCases(true)) {
            cout << "No opened case!" << endl;
            return 0;
        }
        else {
            cout << "Choose the case.\n"
                    "Enter: ";
            cin >> selectedCaseId;

            return selectedCaseId;
        }
    }
    else
    {
        printListTypesCases();
        cout << "Choose the case.\n"
                "Enter: ";
        cin >> selectedCaseId;

        return selectedCaseId;
    }
}

void Menu::takeDeposit()
{
    int amount = 0;
    Bank* bnk = dynamic_cast<Bank*> (comorg);

    cout << "Enter the amount you want to deposit: ";
    cin >> amount;
   
    bnk->takeDeposit(client.getClientId(), chooseDeposit(false), amount);
}

void Menu::takeAbligation()
{
    int amount = 0;
    Bank* bnk = dynamic_cast<Bank*> (comorg);

    cout << "Enter the amount you want to buy abligations: ";
    cin >> amount;

    bnk->buyAbligation(client.getClientId(), chooseAbligation(false), amount);
}

void Menu::openCase()
{
    int price = 0;
    cout << "Enter the property price: ";
    cin >> price;
    InsurCompany* inscom = dynamic_cast<InsurCompany*> (comorg);
    
    inscom->openCase(chooseCase(false), client.getClientId(), chooseEmployee(), price);
}

void Menu::addNewCompany()
{
    string name;
    string country;
    int selectedType;
    int selectedMethodAdd;
    cout << "Enter the name of company: ";
    cin >> name;
    cout << "Enter the country of company: ";
    cin >> country;

    cout << "Choose type of company." << endl;
    cout << "For bank type - 1; for insure company type - 2\n"
            "Enter: ";
    cin >> selectedType;

    cout << "Where do you want to add: 1 - add to front / 2 - add to back\n"
            "Enter: ";
    cin >> selectedMethodAdd;

    Capital capital = settingCapital();

    CommercialOrg* comorg = nullptr;
    if (selectedType == 1)
        comorg = new Bank(deque.size() + 1, name, country, capital.getPriceImmovables(), capital.getPriceEquipment(), capital.getRevenue());
    else if (selectedType == 2)
        comorg = new InsurCompany(deque.size() + 1, name, country, capital.getPriceImmovables(), capital.getPriceEquipment(), capital.getRevenue());
    else 
    {
        cout << "Wrong value!\n";
                "Try again.\n";
        system("pause");
        system("CLS");
        addNewCompany();
    }

    if (selectedMethodAdd == 1) deque.push_front(comorg);
    else if (selectedMethodAdd == 2) deque.push_back(comorg);
    else 
    {
        cout << "Wrong value!\n";
                "Try again.\n";
        system("CLS");
        addNewCompany();
    }
}

void Menu::removeExCompany()
{
    printListCompanies();
    int selectedMethodPop;
    cout << "From where do you want to delete: 1 - del from front / 2 - del from back\n"
            "Enter: ";
    cin >> selectedMethodPop;
   
    
    if (selectedMethodPop == 1) {
        CommercialOrg* temp = deque.pop_front();
        delete temp;
    }
    else if (selectedMethodPop == 2) {
        CommercialOrg* temp = deque.pop_back();
        delete temp;
    }
    else 
    {
        cout << "Wrong value!\n";
                "Try again.\n";
        system("CLS");
        removeExCompany();
    }
}

void Menu::addDepType()
{
    double percent = 0;
    int mounth = 0;
    Bank* bnk = dynamic_cast<Bank*> (comorg);

    while (cout << "What the percent? (double values)\n"
        "Enter: " && !(cin >> percent)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong input; please re-enter!\n";
    }

    while (cout << "How many months? (int values)\n"
        "Enter: " && !(cin >> mounth)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong input; please re-enter!\n";
    }

    bnk->addDepositType(mounth, percent);
}

void Menu::addAblType()
{
    double percent = 0;
    int mounth = 0;
    Bank* bnk = dynamic_cast<Bank*> (comorg);

    while (cout << "What the percent? (double values)\n"
                   "Enter: " && !(cin >> percent)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong input; please re-enter!\n";
    }

    while (cout << "How many months? (int values)\n"
                   "Enter: " && !(cin >> mounth)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong input; please re-enter!\n";
    }

    bnk->addAbligationType(mounth, percent);
}

void Menu::addCaseType()
{
    string casename = "";
    double price = 0;
    InsurCompany* inscom = dynamic_cast<InsurCompany*> (comorg);

    cout << "What the case name? (string values)\n"
            "Enter: ";
    cin >> casename;

    while (cout << "What the price? (double values)\n"
                   "Enter: " && !(cin >> price)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong input; please re-enter!\n";
    }

    inscom->addCaseType(casename, price);
}

void Menu::saveToFile()
{
    deque.for_each([](const CommercialOrg *comorg) {
            comorg->saveToFile();
        });
}

void Menu::closeDeposit()
{
    int choosedDepId = 0;
    Bank* bnk = dynamic_cast<Bank*> (comorg);
    choosedDepId = chooseDeposit(true);
    if (choosedDepId != 0) cout << "Deposit was closed. Accumulation amount is: " << bnk->closeDeposit(choosedDepId) << "$" << endl;
    else cout << "Deposit wasn't found!" << endl;
}

void Menu::closeAbligation()
{
    int choosedAblId = 0;
    Bank* bnk = dynamic_cast<Bank*> (comorg);
    choosedAblId = chooseAbligation(true);
    if(choosedAblId != 0) cout << "Abligation was closed. Accumulation amount is: " << bnk->closeAbligation(choosedAblId) << "$" << endl;
    else cout << "Abligation wasn't found!" << endl;
}

void Menu::closeCase()
{
    int choosedCaseId = 0;
    InsurCompany& insc = dynamic_cast<InsurCompany&> (*comorg);
    choosedCaseId = chooseCase(true);
    if (choosedCaseId != 0) {
        insc.closeCase(choosedCaseId);
        cout << "Case was closed!" << endl;
    }
    else cout << "Case wasn't found!";
}

void Menu::calculateMoney()
{
    double curmoney = 0;
    int caseId = 0;
    InsurCompany& insc = dynamic_cast<InsurCompany&> (*comorg);
    while (cout << "What the money? (double values)\n"
        "Enter: " && !(cin >> curmoney)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong input; please re-enter!\n";
    }
    caseId = chooseCase(false);
    cout << "Predicted price will be: " << insc.calculateMoney(caseId, curmoney) << endl;
}

void Menu::updateDepType()
{
    Bank* bnk = dynamic_cast<Bank*> (comorg);
    double perсent = 0;
    int depositId = 0;
    depositId = chooseDeposit(false);
    while (cout << "What the new percent? (double values)\n"
        "Enter: " && !(cin >> perсent)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong input; please re-enter!\n";
    }

    bnk->updateDepositType(depositId, perсent);
}

void Menu::updateAblType()
{
    Bank* bnk = dynamic_cast<Bank*> (comorg);
    double perсent = 0;
    int abligtaionId = 0;
    abligtaionId = chooseAbligation(false);
    while (cout << "What the new percent? (double values)\n"
        "Enter: " && !(cin >> perсent)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong input; please re-enter!\n";
    }
    bnk->updateAbligationType(abligtaionId, perсent);
}

Capital Menu::settingCapital() 
{
    double priceImmovables = 0;
    double priceEquipment = 0;
    double revenue = 0;

    while (cout << "What the price of immovables? (double values)\n"
        "Enter: " && !(cin >> priceImmovables)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong input; please re-enter!\n";
    }
    while (cout << "What the price of equipment? (double values)\n"
        "Enter: " && !(cin >> priceEquipment)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong input; please re-enter!\n";
    }
    while (cout << "What the revenue? (double values)\n"
        "Enter: " && !(cin >> revenue)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Wrong input; please re-enter!\n";
    }

    Capital cap(priceImmovables, priceEquipment, revenue);

    return cap;
}

void Menu::findingCapital()
{
    Capital capital = settingCapital();
    deque.for_each([&capital](const CommercialOrg* comorg) {
        if (comorg->getCapital() <= capital) {
            cout << comorg->getId() << ". " << comorg->getName() << ". " << comorg->getCountry() << endl;
        }
        });
    cout << "These are all the companies that have been found!" << endl;
}

void Menu::addNewClient()
{
    string name;
    string surname;

    cout << "Enter the name of client: ";
    cin >> name;
    cout << "Enter the surname of client: ";
    cin >> surname;

    comorg->createClient(name, surname);
}

void Menu::addNewEmployee()
{
    string name;
    string surname;
    string position;

    cout << "Enter the name of employee: ";
    cin >> name;
    cout << "Enter the surname of employee: ";
    cin >> surname;
    cout << "Enter the position of employee: ";
    cin >> position;

    comorg->addNewEmployee(name, surname, position);
}

void Menu::fireEmployee()
{
    comorg->fireEmployee(chooseEmployee());
}

void Menu::printListEmployees()
{
    vector <Employee> employees = comorg->getEmployees();
    for (int i = 0; i < employees.size(); i++) {
        string status = employees[i].getFiredStatus() ? "Fired" : "Working";
        cout << employees[i].getId() << ". " << employees[i].getDataEmployee() << ". Status: " << status << endl;
    }
}

void Menu::printListClients()
{
    vector <Client> clients = comorg->getClients();
    for (int i = 0; i < clients.size(); i++) {
        cout << clients[i].getClientId() << ". " << clients[i].toString() << endl;
    }
}

bool Menu::printListOpenedDeps(bool printAll)
{
    Bank* bnk = dynamic_cast<Bank*> (comorg);
    vector <OpenedDeposit> opnd = bnk->getDeposits();
    vector <DepositType> dept = bnk->getDepTypes();
    vector <Client> clients = bnk->getClients();
    if (opnd.empty() == false) {
        if (printAll)
        {
            for (int i = 0; i < opnd.size(); i++)
            {
                string depositName = "";
                for (int j = 0; j < dept.size(); j++)
                {
                    if (dept[j].getId() == opnd[i].getDepositId())
                    {
                        depositName = dept[j].getInfo();
                        break;
                    }
                }
                string clientName = "";
                for (int g = 0; g < clients.size(); g++)
                {
                    if (clients[g].getClientId() == opnd[i].getClientId())
                    {
                        clientName = clients[g].toString();
                        break;
                    }
                }
                cout << opnd[i].getId() << ". " << depositName << ". Amount: " << opnd[i].getMoney() << "$"
                    << ". Date: " << opnd[i].getDate() << ". Status: " << opnd[i].getState() << ". " << clientName << endl;
            }
        }
        else
        {
            for (int i = 0; i < opnd.size(); i++) {
                string depositName = "";
                for (int j = 0; j < dept.size(); j++) {
                    if (dept[j].getId() == opnd[i].getDepositId()) {
                        depositName = dept[j].getInfo();
                        break;
                    }
                }
                cout << opnd[i].getId() << ". " << depositName << ". Amount: " << opnd[i].getMoney() << "$"
                    << ". Date: " << opnd[i].getDate() << ". Status: " << opnd[i].getState() << ". " << client.toString() << "." << endl;
            }
        }
    }
    else return true;
}

bool Menu::printListOpenedAbls(bool printAll)
{
    Bank* bnk = dynamic_cast<Bank*> (comorg);
    vector <OpenedAbligation> opna = bnk->getAbligations();
    vector <AbligationType> ablt = bnk->getAblTypes();
    vector <Client> clients = bnk->getClients();

    if (opna.empty() == false) {
        if (printAll)
        {
            for (int i = 0; i < opna.size(); i++)
            {
                string abligationName = "";
                for (int j = 0; j < ablt.size(); j++) {
                    if (ablt[j].getId() == opna[i].getAbligationId())
                    {
                        abligationName = ablt[j].getInfo();
                        break;
                    }
                }
                string clientName = "";
                for (int g = 0; g < clients.size(); g++)
                {
                    if (clients[g].getClientId() == opna[i].getClientId())
                    {
                        clientName = clients[g].toString();
                        break;
                    }
                }
                cout << opna[i].getId() << ". " << abligationName << ". Amount: " << opna[i].getCount() << "$"
                    << ". Date: " << opna[i].getDate() << ". Status: " << opna[i].getState() << ". " << clientName << endl;
            }
        }
        else
        {
            for (int i = 0; i < opna.size(); i++)
            {
                string abligationName = "";
                for (int j = 0; j < ablt.size(); j++)
                {
                    if (ablt[j].getId() == opna[i].getAbligationId())
                    {
                        abligationName = ablt[j].getInfo();
                        break;
                    }
                }
                cout << opna[i].getId() << ". " << abligationName << ". Amount: " << opna[i].getCount() << "$"
                    << ". Date: " << opna[i].getDate() << ". Status: " << opna[i].getState() << ". " << client.toString() << endl;
            }
        }
    }
    else return true;
}

bool Menu::printListOpenedCases(bool printAll)
{

    InsurCompany* insc = dynamic_cast<InsurCompany*> (comorg);
    vector<Employee> employees = insc->getEmployees();
    vector <Case> cases = insc->getСases();
    vector <Client> clients = insc->getClients();

    if (cases.empty() == false) {
        if (printAll)
        {
            for (int i = 0; i < cases.size(); i++)
            {
                string employeeName = "";
                for (int j = 0; j < employees.size(); j++)
                {
                    if (employees[j].getId() == cases[i].getEmployeeId())
                    {
                        employeeName = employees[j].getDataEmployee();
                        break;
                    }
                }
                string clientName = "";
                for (int g = 0; g < clients.size(); g++)
                {
                    if (clients[g].getClientId() == cases[i].getClientId())
                    {
                        clientName = clients[g].toString();
                        break;
                    }
                }
                string status = cases[i].getState() ? "Case is running" : "Case is not running";
                cout << cases[i].getId() << ". The property price: " << cases[i].getPrice() << "$" << ". " << status << ". Employee: " << employeeName << ". " << clientName << endl;
            }
        }
        else
        {
            for (int i = 0; i < cases.size(); i++)
            {
                string employeeName = "";
                for (int j = 0; j < employees.size(); j++)
                {
                    if (employees[j].getId() == cases[i].getEmployeeId())
                    {
                        employeeName = employees[j].getDataEmployee();
                        break;
                    }
                }
                string status = cases[i].getState() ? "Case is running" : "Case is not running";
                cout << cases[i].getId() << ". The property price: " << cases[i].getPrice() << "$" << ". " << status << ". Employee: " << employeeName << ". " << client.toString() << endl;
            }
        }
    }
    else return true;
}

void Menu::printListTypesAbls()
{
    Bank* bnk = dynamic_cast<Bank*> (comorg);
    vector <AbligationType> ablt = bnk->getAblTypes();
    for (int i = 0; i < ablt.size(); i++)
    {
        cout << ablt[i].getId() << ". " << ablt[i].getInfo() << endl;
    }
}

void Menu::printListTypesDeps()
{
    Bank* bnk = dynamic_cast<Bank*> (comorg);
    vector <DepositType> dept = bnk->getDepTypes();
    for (int i = 0; i < dept.size(); i++) {
        cout << dept[i].getTypeId() << ". " << dept[i].getInfo() << endl;
    }
}

void Menu::printListTypesCases()
{
    InsurCompany& insc = dynamic_cast<InsurCompany&> (*comorg);
    vector <CaseType> casetypes = insc.getCasesTypes();
    for (int i = 0; i < casetypes.size(); i++) {
        cout << casetypes[i].getTypeId() << ". " << casetypes[i].getName() << ". The price: " << casetypes[i].getPrecent() << endl;
    }
}

void Menu::printListCompanies()
{
    deque.for_each([](const CommercialOrg *comorg) {
        cout << comorg->getId() << ". " << comorg->getInfo() << "." << endl;
        });
}

void Menu::clearDeque()
{
    deque.clear();
}
