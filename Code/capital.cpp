#include <string>
#include "capital.h"

using namespace std;

Capital::Capital(double _priceImmovables, double _priceEquipment, double _revenue)
{
	priceImmovables = _priceImmovables;
	priceEquipment = _priceEquipment;
	revenue = _revenue;
}

Capital::Capital()
{
}

double Capital::getPriceImmovables() const
{
	return priceImmovables;
}

double Capital::getPriceEquipment() const
{
	return priceEquipment;
}

double Capital::getRevenue() const
{
	return revenue;
}

void Capital::setPriceImmovables(double _priceImmovables)
{
	priceImmovables = _priceImmovables;
}

void Capital::setPriceEquipment(double _priceEquipment)
{
	priceEquipment = _priceEquipment;
}

void Capital::setRevenue(double _revenue)
{
	revenue = _revenue;
}

string Capital::getCount() const
{
	return "The capital is " + to_string(priceImmovables + priceEquipment + revenue);
}

double Capital::getFullCapital() const
{
	return revenue + priceImmovables + priceEquipment;
}

bool operator<=(const Capital& c1, const Capital& c2)
{
	return c1.getFullCapital() <= c2.getFullCapital();
}
