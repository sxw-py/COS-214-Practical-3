#include "GeneralStall.h"

void GeneralStall::buyItem()
{
	revenue += unitCost();
}

int GeneralStall::getRevenue()
{
	return this->revenue;
}
