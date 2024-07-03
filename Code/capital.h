#pragma once
#include <iostream>

using namespace std;

class Capital 
{
private:
	double priceImmovables;
	double priceEquipment;
	double revenue;

	double getFullCapital() const;

public:
	Capital(double _priceImmovables, double _priceEquipment, double _revenue);
	Capital();

	double getPriceImmovables() const;
	void setPriceImmovables(double _priceImmovables);

	double getPriceEquipment() const;
	void setPriceEquipment(double _priceEquipment);

	double getRevenue() const;
	void setRevenue(double _revenue);

	string getCount() const;

	friend bool operator<= (const Capital& c1, const Capital& c2);
};
